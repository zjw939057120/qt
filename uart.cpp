#include "mydefine.h"

//=========================================================
//	创建串口
//=========================================================
unsigned char CreateUart(int nPort, int nBaut) {
    if (sio_open(nPort) == SIO_OK)    //串口号
    {
        int ret = sio_ioctl(nPort, nBaut, BIT_8 | STOP_1 | P_NONE);

        if (ret == SIO_OK) {
            sio_SetReadTimeouts(nPort, 3, 0);
            return nPort;
        }
    }

    return 0;
}

//==============================================================================
//	发送数据
//==============================================================================
void UartSendBuff(unsigned char nPort, unsigned char *buff, unsigned short nlen) {
    if (!nPort) return;

    sio_write(nPort, (char *) buff, nlen);
}


//=============================================================================
//	接收数据
//=============================================================================
unsigned short UartRecvBuff(unsigned char nPort, unsigned char *buff) {
    int nRecv;

    if (!nPort) return 0;

    nRecv = sio_read(nPort, (char *) buff, 4096);
    if (nRecv <= 0) return 0;

    return nRecv;
}