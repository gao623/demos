#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include "simpleCommon.h"

int simpleServer()
{
    int listen_socket = 0;
    int app_socket = 0;

    struct sockaddr_in hostAddr;
    struct sockaddr_in clientAddr;
    int socketLen = sizeof(clientAddr);

    char sendBuf[SEND_BUF_SIZE];
    char recvBuf[RECV_BUF_SIZE];
    int sendLen = 0;
    int recvLen = 0;
    int retRecvLen = 0;
    int retSendLen = 0;
    int leftRecvLen = 0;
    int leftSendLen = 0;
    char *pSend = NULL;
    char *pRecv = NULL;

    memset(&hostAddr, 0, socketLen);
    memset(&clientAddr, 0, socketLen);

    hostAddr.sin_family = AF_INET;
    hostAddr.sin_port = htons(SERVER_PORT);
    hostAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    printf("-----------------------------\n");
    printf("server infomation:\n");
    printf("family:%d\n", hostAddr.sin_family);
    printf("addr:%d\n", hostAddr.sin_addr.s_addr);
    printf("port:%d\n", hostAddr.sin_port);
    printf("-----------------------------\n");

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > listen_socket)
    {
        printf("%s:%d,create socket failed.\n", __FILE__, __LINE__);
        printf("Error No:%d.\n", errno);
        exit(1);
    }
    printf("%s:%d,create server socket[%d] success.\n", __FILE__, __LINE__, listen_socket);

    int flags = 1;
    int flagLen = sizeof(flags);
    if (0 > setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &flags, flagLen))
    {
        printf("%s:%d, setsockopt failed\n", __FILE__, __LINE__);
        exit(1);
    }
    printf("%s:%d,setsockopt success.\n", __FILE__, __LINE__);

    if (0 > bind(listen_socket, (struct sockaddr *)&hostAddr, sizeof(hostAddr)))
    {
        printf("%s:%d,bind socket failed.\n", __FILE__, __LINE__);
        printf("Error No:%d.\n", errno);
        exit(1);
    }
    printf("%s:%d,bind socket success.\n", __FILE__, __LINE__);

    if (0 > listen(listen_socket, MAX_LISTEN_NUM))
    {
        printf("%s:%d, listen socket failed.\n", __FILE__, __LINE__);
        printf("Error No:%d.\n", errno);
        exit(1);
    }
    printf("%s:%d,listen socket success.\n", __FILE__, __LINE__);

    while(1)
    {
        app_socket = accept(listen_socket, (__SOCKADDR_ARG)&clientAddr, &socketLen);
        if (0 > app_socket)
        {
            printf("%s:%d, accept socket failed.\n", __FILE__, __LINE__);
            exit(1);
        }
        printf("%s:%d,accept socket success.\n", __FILE__, __LINE__);

        sprintf(sendBuf, "welcome %s:%d here!\n", 
            inet_ntoa(clientAddr.sin_addr), clientAddr.sin_port);
            //inet_ntoa(clientAddr.sin_addr.s_addr), clientAddr.sin_port);

        sendLen = strlen(sendBuf) + 1;
        retSendLen = 0;
        pSend = sendBuf;

        // send data
        retSendLen = send(app_socket, pSend, sendLen, 0);
        if (0 > retSendLen)
        {
            if (EINTR == errno)
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
        printf("%s:%d,send data success.\n", __FILE__, __LINE__);
        printf("send data is : %s\n", sendBuf);

        // receive data
        recvLen = 0;
        retRecvLen = 0;
        leftRecvLen = RECV_BUF_SIZE - 1;
        pRecv = recvBuf;

        retRecvLen = recv(app_socket, pRecv, leftRecvLen, 0);
        if (0 > retRecvLen)
        {
            if (EINTR == errno)
            {
                retRecvLen = 0;
            }
            else
            {
                exit(1);
            }
        }
        recvLen += retRecvLen;
        leftRecvLen -= retRecvLen;
        pRecv += retRecvLen;
        printf("%s:%d,receive data success.\n", __FILE__, __LINE__);
        printf("receive data is : %s\n", recvBuf);
        shutdown(app_socket, SHUT_RDWR);
    }
    shutdown(listen_socket, SHUT_RDWR);
    return 0;
}

int main()
{
    simpleServer();
    printf("Hello World\n");
    return 0;
}
