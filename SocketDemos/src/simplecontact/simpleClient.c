#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include "simpleCommon.h"

int simpleClient()
{
    int sock_fd = 0;
    char recvBuf[RECV_BUF_SIZE];
    char sendBuf[SEND_BUF_SIZE];

    int recvLen = 0;
    int retRecvLen = 0;
    int leftRecvLen = 0;
    char *pRecv = NULL;

    int sendLen = 0;
    int retSendLen = 0;
    int leftSendLen = 0;
    char *pSend = NULL;

    struct sockaddr_in srvAddr;
    int sockAddrLen = sizeof(struct sockaddr_in);

    memset(&srvAddr, 0, sockAddrLen);
    srvAddr.sin_family = AF_INET;
    inet_aton(SERVER_IP, &srvAddr.sin_addr);
    in_addr_t s_addr = (inet_addr(SERVER_IP));
    srvAddr.sin_port = htons(SERVER_PORT);
    printf("-----------------------------\n");
    printf("server infomation:\n");
    printf("family:%d\n", srvAddr.sin_family);
    printf("addr[inet_aton]:%ld\n", srvAddr.sin_addr.s_addr);
    printf("addr[inet_addr]:%ld\n", s_addr);
    printf("port:%d\n", srvAddr.sin_port);
    printf("-----------------------------\n");

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > sock_fd)
    {
        printf("%s:%d, create socket failed.\n", __FILE__, __LINE__);
        printf("Error No:%d.\n", errno);
        exit(1);
    }
    printf("%s:%d,create client socket[%d] success.\n", __FILE__, __LINE__, sock_fd);

    int ret = 0;
    if (0 > (ret = connect(sock_fd, (__CONST_SOCKADDR_ARG)&srvAddr, sockAddrLen)))
    {
        printf("%s:%d, connet socket failed[%d].\n", __FILE__, __LINE__, ret);
        printf("Error No:%s[%d].\n", strerror(errno), errno);
        exit(1);
    }
    printf("%s:%d,connet socket success.\n", __FILE__, __LINE__);

    recvLen = 0;
    retRecvLen = 0;
    leftRecvLen = RECV_BUF_SIZE - 1;
    pRecv = recvBuf;

    // receive
    retRecvLen = recv(sock_fd, pRecv, leftRecvLen, 0);
    if (0 > retRecvLen)
    {
        printf("%s:%d,recv socket success.\n", __FILE__, __LINE__);

        if (EINTR == errno)
        {
            retRecvLen = 0;
        }
        else
        {
            exit(0);
        }
    }
    recvLen += retRecvLen;
    leftRecvLen -= retRecvLen;
    pRecv += retRecvLen;

    printf("receive data is : %s\n", recvBuf);

    // send
    gets(sendBuf);
    //sprintf(sendBuf, "hello server\n");
    sendLen = strlen(sendBuf) + 1;
    retSendLen = 0;
    leftSendLen = sendLen;
    pSend = sendBuf;


    retSendLen = send(sock_fd, pSend, sendLen, 0);
    if (0 > retSendLen)
    {
            if (EINTR ==errno)
            {
                retSendLen = 0;
            }
            else
            {
                exit(1);
            }
    }
    leftSendLen -= retSendLen;
    pSend += retSendLen;
    printf("send data is : %s\n", sendBuf);
    
    shutdown(sock_fd, SHUT_RDWR);

    return 0;
}

int main()
{
    simpleClient();
    printf("Hello World\n");
    return 0;
}
