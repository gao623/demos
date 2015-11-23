#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
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

bool Connect(int sock_fd, struct sockaddr *pSrvAddr, int *pAddrLen)
{
    assert(pSrvAddr && pAddrLen);
    if (0 > connect(sock_fd, pSrvAddr, *pAddrLen))
    {
        if (EISCONN == errno)
        {
            printf("%s:%d, connect socket completed.\n", __FILE__,__LINE__);
            return true;
        }
        if (EINPROGRESS != errno && EALREADY != errno && EWOULDBLOCK != errno)
        {
            printf("%s:%d, connect socket failed.\n", __FILE__, __LINE__);
            return false;
        }
        else
        {
            printf("%s:%d, connect socket does not completed.\n", __FILE__, __LINE__);
        }
    }
    else
    {
        printf("%s:%d, connect socket completed.\n", __FILE__, __LINE__);
        return true;
    }

    int ntryTimes = 0;
    int retSelect = 0;
    fd_set fdsetRead, fdsetWrite;
    struct timeval tval;
    tval.tv_sec = 3;
    tval.tv_usec = 0;

    while(1 && ntryTimes < MAX_CONNECT_TIMES)
    {
        FD_ZERO(&fdsetRead);
        FD_SET(sock_fd, &fdsetRead);

        FD_ZERO(&fdsetWrite);
        FD_SET(sock_fd, &fdsetWrite);
        printf("%s:%d, prepare for select ok.\n", __FILE__, __LINE__);

        retSelect = select(sock_fd + 1, &fdsetRead, &fdsetWrite, NULL, &tval);
        printf("%s:%d, after select", __FILE__, __LINE__);

        if (0 > retSelect)
        {
            if (EINTR ==errno)
            {
                ++ntryTimes;
                continue;
            }
            else
            {
                printf("%s:%d, connect socket failed.\n", __FILE__, __LINE__);
                return false;
            }
        }
        else if (0 == retSelect)
        {
            printf("%s:%d, connect socket timeout ...\n", __FILE__, __LINE__);
            ++ntryTimes;
            continue;
        }
        else
        {
            printf("%s:%d, select default.\n", __FILE__, __LINE__);

            if (FD_ISSET(sock_fd, &fdsetRead) || FD_ISSET(sock_fd, &fdsetWrite))
            {
                int error = 0;
                int errLen = sizeof(error);
                int rc = getsockopt(sock_fd, SOL_SOCKET, SO_ERROR, &error, &errLen);

                if (-1 == rc)
                {
                    printf("%s:%d, connect socket is closed.\n", __FILE__, __LINE__);
                    return false;
                }
                if (error)
                {
                    printf("%s:%d, connect socket is closed.\n", __FILE__, __LINE__);
                    return false;
                }
                printf("%s:%d, connect socket is ok", __FILE__, __LINE__);
                return true;
            }
            else
            {
                printf("%s:%d, no descriptor is ready.\n", __FILE__, __LINE__);
                continue;
            }
        }
    }

    return false;
}

int Recv(int sock_fd, char *recvBuf, int recvBufLen)
{
    int retSelect = 0;
    fd_set fdsetRead;
    struct timeval tval;
    tval.tv_sec = 3;
    tval.tv_usec = 0;

    FD_ZERO(&fdsetRead);
    FD_SET(sock_fd, &fdsetRead);
    printf("%s:%d:%S, select ready.\n", __FILE__, __LINE__, __FUNCTION__);

    retSelect = select(sock_fd + 1, &fdsetRead, NULL, NULL, &tval);
    printf("%s:%d:%s, after ready.\n", __FILE__, __LINE__, __FUNCTION__);

    if (0 > retSelect)
    {
        if (EINTR == errno)
        {
            return 0;
        }
        else
        {
            printf("%s:%d:%s, select failed", __FILE__, __LINE__, __FUNCTION__);
            return -1;
        }
    }
    else if (0 == retSelect)
    {
        printf("%s:%d:%s, select timeout, no descriptors can be read or written.\n");
        return 0;
    }
    else
    {
        printf("%s:%d:%s, select default.\n", __FILE__, __LINE__, __FUNCTION__);

        if (FD_ISSET(sock_fd, &fdsetRead))
        {
            printf("%s:%d:%s, receive data.\n", __FILE__, __LINE__, __FUNCTION__);

            int recvLen = 0;
            int retRecvLen = 0;
            int leftRecvLen = recvBufLen - 1;
            char *pRecv = recvBuf;

            do
            {
                printf("%s:%d:%sready for recv.\n", __FILE__, __LINE__, __FUNCTION__);
                retRecvLen = recv(sock_fd, pRecv, leftRecvLen, 0);
                printf("%s:%d:%s, after recv, and retRecvLen is %d, errno is %d.\n", __FILE__, __LINE__, __FUNCTION__, retRecvLen, errno);

                if (0 > retRecvLen)
                {
                    if (EAGAIN == errno || EWOULDBLOCK == errno)
                    {
                        break;
                    }
                    else if (EINTR == errno)
                    {
                        retRecvLen = 0;
                    }
                    else
                    {
                        printf("%s:%d:%s, recv data error, errno is %d.\n", __FILE__, __LINE__, __FUNCTION__, errno);
                        return -1;
                    }
                }
                else if (0 == retRecvLen)
                {
                    printf("%s:%d:%s, socket is closed.\n", __FILE__, __LINE__, __FUNCTION__);
                    return -1;
                }
                else
                {
                    printf("%s:%d:%s, recv success.\n", __FILE__, __LINE__, __FUNCTION__);
                    recvLen += retRecvLen;
                    leftRecvLen -= retRecvLen;
                    pRecv += retRecvLen;
                }
            }
            while (leftRecvLen);

            printf("%s:%d:%s, recv data is [%s]", __FILE__, __LINE__, __FUNCTION__, recvBuf);
            return recvLen;
        }
        else
        {
            return -1;
        }
    }
}

int Send(int sock_fd, char *sendBuf, int sendBufLen)
{
    assert(sendBuf);
    sprintf(sendBuf, "hello server\n");
    int sendLen = strlen(sendBuf) + 1;
    int retSendLen = 0;
    int leftSendLen = sendLen;
    char *pSend = sendBuf;

    int retSelect = 0;
    fd_set fdsetWrite;
    struct timeval tval;
    tval.tv_sec = 3;
    tval.tv_usec = 0;

    printf("%s:%d:%s, ready for send.\n", __FILE__, __LINE__, __FUNCTION__);

    retSendLen = send(sock_fd, pSend, sendLen, 0);
    printf("%s:%d:%s, after send.\n", __FILE__, __LINE__, __FUNCTION__);

    if (retSendLen < sendLen)
    {
        if (0 > retSendLen)
        {
            if (EWOULDBLOCK != errno && ENOBUFS != errno && EAGAIN != errno && EINTR != errno)
            {
                printf("%s:%d:%s, send data failed.\n", __FILE__, __LINE__, __FUNCTION__);
                return -1;
            }
            else
            {
                return 0;
            }
        }

        while(1)
        {
            FD_ZERO(&fdsetWrite);
            FD_SET(sock_fd, &fdsetWrite);
            printf("%s:%d:%s, ready for select.\n", __FILE__, __LINE__, __FUNCTION__);

            retSelect = select(sock_fd + 1, NULL, &fdsetWrite, NULL, &tval);
            printf("%s:%d:%s, after select.\n", __FILE__, __LINE__, __FUNCTION__);

            if (0 > retSelect)
            {
                if (EINTR ==errno)
                {
                    continue;
                }
                else
                {
                    printf("%s:%d:%s, select failed.\n", __FILE__, __LINE__, __FUNCTION__);
                    return -1;
                }
            }
            else if (0 == retSelect)
            {
                printf("%s:%d:%s, select timeout, no descriptors can be read or written.\n", __FILE__, __LINE__, __FUNCTION__);
                continue;
            }
            else
            {
                if (FD_ISSET(sock_fd, &fdsetWrite))
                {
                    leftSendLen -= retSendLen;
                    sendLen = leftSendLen;
                    pSend += retSendLen;

                    printf("%s:%d:%s, send data.\n", __FILE__, __LINE__, __FUNCTION__);
                    do
                    {
                        retSendLen = send(sock_fd, pSend, sendLen, 0);
                        if (0 > retSendLen)
                        {
                            if (EAGAIN == errno || EWOULDBLOCK == errno)
                            {
                                break;
                            }
                            else if (EINTR == errno)
                            {
                                retSendLen = 0;
                            }
                            else
                            {
                                printf("%s:%d:%s, recv data error, erron is %d.\n", __FILE__, __LINE__, __FUNCTION__, errno);
                            }
                            leftSendLen -= retSendLen;
                            sendLen = leftSendLen;
                            pSend += retSendLen;
                        }
                    }
                    while (leftSendLen);
                }
                else
                {
                    return -1;
                }
            }
        }
    }
    return sendLen;
}

int simpleClientAsync()
{
    int sock_fd = 0;
    char recvBuf[RECV_BUF_SIZE];
    char sendBuf[SEND_BUF_SIZE];

    int recvBufLen = RECV_BUF_SIZE;
    int sendBufLen = SEND_BUF_SIZE;

    int recvLen = 0;
    int retRecvLen = 0;
    int leftRecvLen = 0;
    char *pRecv = NULL;

    int sendLen = 0;
    int retSendLen = 0;
    int leftSendLen = 0;
    char *pSend = NULL;

    int fdFlags = 0;
    bool bIsConn = false;
    struct sockaddr_in srvAddr;
    int addrLen = sizeof(srvAddr);

    memset(&srvAddr, 0, addrLen);
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_port = htons(SERVER_PORT);
    inet_aton(SERVER_IP, &srvAddr.sin_addr);

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > sock_fd)
    {
        printf("%s:%d:%s, create socket failed.\n", __FILE__, __LINE__, __FUNCTION__);
        shutdown(sock_fd, SHUT_RDWR);
        exit(1);
    }

    fdFlags = fcntl(sock_fd, F_GETFL, 0);
    if (0 > fcntl(sock_fd, F_SETFL, fdFlags | O_NONBLOCK))
    {
        printf("%s:%d:%s, fcntl set  nonblock failed.\n", __FILE__, __LINE__, __FUNCTION__);
        shutdown(sock_fd, SHUT_RDWR);
        exit(1);
    }
    if (!Connect(sock_fd, &srvAddr, &addrLen))
    {
        printf("%s:%d:%s, Connect socket failed.\n", __FILE__, __LINE__, __FUNCTION__);
        shutdown(sock_fd, SHUT_RDWR);
        exit(1);
    }

    while (1)
    {
        retRecvLen = Recv(sock_fd, recvBuf, recvBufLen);
        if (0 > retRecvLen)
        {
            printf("%s:%d:%s, Recv socket failed.\n", __FILE__, __LINE__, __FUNCTION__);
            break;
        }
        else if (0 < retRecvLen)
        {
            retSendLen = Send(sock_fd, sendBuf, sendBufLen);
            if (0 > retSendLen)
            {
                printf("%s:%d:%s, Send socket failed.\n", __FILE__, __LINE__, __FUNCTION__);
                break;
            }
        }
    }
    shutdown(sock_fd, SHUT_RDWR);
    return 0;
}

int main()
{
    simpleClient();
    printf("Hello World\n");
    return 0;
}
