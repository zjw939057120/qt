#include "mydefine.h"

//===================================================================
//常用数据转换
unsigned short GetWORDBuffer(unsigned char *buf, char flag) {
    if (flag) {
        return (buf[0] << 8) + buf[1];
    } else {
        return buf[0] + (buf[1] << 8);
    }
}

long GetUINTBuffer(unsigned char *buf, char flag) {
    if (flag) {
        return buf[3] + (buf[2] << 8) + (buf[1] << 16) + (buf[0] << 24);
    } else {
        return buf[0] + (buf[1] << 8) + (buf[2] << 16) + (buf[3] << 24);
    }
}

void PutWORDBuffer(unsigned char *buf, unsigned short value, char flag) {
    if (flag) {
        buf[1] = (unsigned char) (value & 0xFF);
        buf[0] = (unsigned char) ((value >> 8) & 0xFF);
    } else {
        buf[0] = (unsigned char) (value & 0xFF);
        buf[1] = (unsigned char) ((value >> 8) & 0xFF);
    }
}

void PutUINTBuffer(unsigned char *buf, long value, char flag) {
    if (flag) {
        buf[3] = (unsigned char) (value & 0xFF);
        buf[2] = (unsigned char) ((value >> 8) & 0xFF);
        buf[1] = (unsigned char) ((value >> 16) & 0xFF);
        buf[0] = (unsigned char) ((value >> 24) & 0xFF);
    } else {
        buf[0] = (unsigned char) (value & 0xFF);
        buf[1] = (unsigned char) ((value >> 8) & 0xFF);
        buf[2] = (unsigned char) ((value >> 16) & 0xFF);
        buf[3] = (unsigned char) ((value >> 24) & 0xFF);
    }
}

//====================================================================
//	modbus crc计算函数
//====================================================================
unsigned short ModbusCRC(unsigned char *buff, unsigned short len) {
    unsigned short crc = 0xFFFF;
    unsigned char i;
    while (len--) {
        crc ^= *buff++;
        for (i = 0; i < 8; i++) {
            if (crc & 0x01) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

//===================================================================================================
//	modbus 发送字符串
//===================================================================================================
void Modbus_SendBuff(unsigned char chan, unsigned char *buff, unsigned short nlen, unsigned char nAddr) {
    if (chan == CHAN_COMM) {
        UartSendBuff(VariaDlg.UartPort, buff, nlen);
    } else if (chan == CHAN_UDP) {
        SocketConfig(&VariaDlg.ServerSocketAddr[nAddr], DeviceDlg[nAddr].IP, DeviceDlg[nAddr].Port);
        SocketSendBuff(VariaDlg.LocalSocket, MODE_UDP, buff, nlen, VariaDlg.ServerSocketAddr[nAddr]);
    }
}

//=================================================================================
//	modbus  主机接收处理函数
//=================================================================================
void Modbus_MasterRecvProcess(unsigned char chan, unsigned char addr) {
    unsigned short i, nlen;
    unsigned short HandPtr, crc1, crc2;
    unsigned short StartAddr, RegNumber, PacketSize, EndAddr, nSize;


    nlen = (VariaDlg.WritePtr[chan] - VariaDlg.ReadPtr[chan]) & RECV_BUFF_LEN;
    while (nlen >= 0x08) {
        if ((VariaDlg.RecvBuff[chan][VariaDlg.ReadPtr[chan]] == addr) &&
            (VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN] == 0x06))        //写单个寄存器
        {
            StartAddr = (unsigned short) VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 2) & RECV_BUFF_LEN] * 256 +
                        VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 3) & RECV_BUFF_LEN];    //开始地址
            if (StartAddr > MODBUS_ADDR_MAX)        //判断报文有效性
            {
                VariaDlg.ReadPtr[chan] = (VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN;
                nlen--;
            } else {
                HandPtr = VariaDlg.ReadPtr[chan];
                for (i = 0; i < 8; i++) {
                    VariaDlg.HandBuff[chan][i] = VariaDlg.RecvBuff[chan][HandPtr];
                    HandPtr = (HandPtr + 1) & RECV_BUFF_LEN;
                }

                crc1 = ModbusCRC(VariaDlg.HandBuff[chan], 6);
                crc2 = VariaDlg.HandBuff[chan][6] + (unsigned short) VariaDlg.HandBuff[chan][7] * 256;
                if (crc1 == crc2)                                //计算CRC
                {
                    VariaDlg.ReadPtr[chan] = HandPtr;
                    TaskDlg.ParaBuff[TaskDlg.ReadPtr].Result = 1;
                    return;
                } else {
                    VariaDlg.ReadPtr[chan] = (VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN;
                    nlen--;
                }
            }
        } else if ((VariaDlg.RecvBuff[chan][VariaDlg.ReadPtr[chan]] == addr) &&
                   (VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN] == 0x10))        //写多个寄存器
        {
            StartAddr = (unsigned short) VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 2) & RECV_BUFF_LEN] * 256 +
                        VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 3) & RECV_BUFF_LEN];    //开始地址
            RegNumber = (unsigned short) VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 4) & RECV_BUFF_LEN] * 256 +
                        VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 5) &
                                                RECV_BUFF_LEN];    //寄存器个数
            EndAddr =
                    StartAddr + RegNumber - 1;                                                                //寄存器的结束地址

            if ((RegNumber > MODBUS_REG_MAX) || (EndAddr > MODBUS_ADDR_MAX))        //判断报文有效性
            {
                VariaDlg.ReadPtr[chan] = (VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN;
                nlen--;
            } else {
                HandPtr = VariaDlg.ReadPtr[chan];
                for (i = 0; i < 8; i++) {
                    VariaDlg.HandBuff[chan][i] = VariaDlg.RecvBuff[chan][HandPtr];
                    HandPtr = (HandPtr + 1) & RECV_BUFF_LEN;
                }

                crc1 = ModbusCRC(VariaDlg.HandBuff[chan], 6);
                crc2 = VariaDlg.HandBuff[chan][6] + (unsigned short) VariaDlg.HandBuff[chan][7] * 256;
                if (crc1 == crc2)                                //计算CRC
                {
                    VariaDlg.ReadPtr[chan] = HandPtr;
                    TaskDlg.ParaBuff[TaskDlg.ReadPtr].Result = 1;

                    return;
                } else {
                    VariaDlg.ReadPtr[chan] = (VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN;
                    nlen--;
                }
            }
        } else if ((VariaDlg.RecvBuff[chan][VariaDlg.ReadPtr[chan]] == addr) &&
                   (VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN] == 0x03))        //读多个寄存器
        {
            PacketSize = VariaDlg.RecvBuff[chan][(VariaDlg.ReadPtr[chan] + 2) & RECV_BUFF_LEN] + 5;    //总字节数
            if (PacketSize == 5) PacketSize = 256 + 5;

            nlen = (VariaDlg.WritePtr[chan] - VariaDlg.ReadPtr[chan]) & RECV_BUFF_LEN;            //此刻缓存区数据长度
            if (nlen < PacketSize) return;

            HandPtr = VariaDlg.ReadPtr[chan];
            for (i = 0; i < PacketSize; i++) {
                VariaDlg.HandBuff[chan][i] = VariaDlg.RecvBuff[chan][HandPtr];
                HandPtr = (HandPtr + 1) & RECV_BUFF_LEN;
            }

            crc1 = ModbusCRC(VariaDlg.HandBuff[chan], (PacketSize - 2));
            crc2 = VariaDlg.HandBuff[chan][PacketSize - 2] +
                   (unsigned short) VariaDlg.HandBuff[chan][PacketSize - 1] * 256;
            if (crc1 == crc2)                                //计算CRC
            {
                VariaDlg.ReadPtr[chan] = HandPtr;

                nSize = VariaDlg.HandBuff[chan][2] / 2;

                if (nSize == VariaDlg.RegNumber) {
                    StartAddr = VariaDlg.StartAddr;
                    RegNumber = VariaDlg.RegNumber;

                    for (i = 0; i < RegNumber; i++) {
                        VariaDlg.Register[StartAddr + i] = GetWORDBuffer(
                                (unsigned char *) &VariaDlg.HandBuff[chan][3 + 2 * i], 1);
                    }
                }


                VariaDlg.OrderResult = 1;        //数据返回

                VariaDlg.SampleOut = 1;
                return;

            } else {
                VariaDlg.ReadPtr[chan] = (VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN;
                nlen--;
            }
        } else {
            VariaDlg.ReadPtr[chan] = (VariaDlg.ReadPtr[chan] + 1) & RECV_BUFF_LEN;
            nlen--;
        }
    }
}


//================================================================================================================
//	生成modbus协议数据流
//================================================================================================================
unsigned short Modbus_MasterMakeProcess(unsigned char chan, unsigned char addr, char CMDType, unsigned short StartAddr,
                                        unsigned short RegNumber) {
    unsigned short i, crc;

    if (CMDType == 0x03)        //读数据
    {
        VariaDlg.SendBuff[chan][0] = addr;
        VariaDlg.SendBuff[chan][1] = CMDType;
        PutWORDBuffer(&VariaDlg.SendBuff[chan][2], StartAddr, 1);
        PutWORDBuffer(&VariaDlg.SendBuff[chan][4], RegNumber, 1);

        crc = ModbusCRC(VariaDlg.SendBuff[chan], 6);        //计算CRC
        PutWORDBuffer(&VariaDlg.SendBuff[chan][6], crc, 0);

        return 8;
    } else if (CMDType == 0x10)    //写多寄存器
    {
        VariaDlg.SendBuff[chan][0] = addr;
        VariaDlg.SendBuff[chan][1] = CMDType;
        PutWORDBuffer(&VariaDlg.SendBuff[chan][2], StartAddr, 1);
        PutWORDBuffer(&VariaDlg.SendBuff[chan][4], RegNumber, 1);
        VariaDlg.SendBuff[chan][6] = RegNumber * 2;

        for (i = 0; i < RegNumber; i++) {
            PutWORDBuffer(&VariaDlg.SendBuff[chan][7 + 2 * i], VariaDlg.Register[StartAddr + i], 1);
        }

        crc = ModbusCRC(VariaDlg.SendBuff[chan], (RegNumber * 2 + 7));
        PutWORDBuffer(&VariaDlg.SendBuff[chan][RegNumber * 2 + 7], crc, 0);
        return (RegNumber * 2 + 9);
    } else if (CMDType == 0x06)    //写单寄存器
    {
        VariaDlg.SendBuff[chan][0] = addr;
        VariaDlg.SendBuff[chan][1] = CMDType;
        PutWORDBuffer(&VariaDlg.SendBuff[chan][2], StartAddr, 1);
        PutWORDBuffer(&VariaDlg.SendBuff[chan][4], VariaDlg.Register[StartAddr], 1);

        crc = ModbusCRC(VariaDlg.SendBuff[chan], 6);
        PutWORDBuffer(&VariaDlg.SendBuff[chan][6], crc, 0);

        return 8;
    }

    return 0;
}


//=======================================================
//	modbus 协议发送函数
//  当指令队列里面没有指令后才循环读数据
//=======================================================
void Modbus_MasterSendProcess(void) {
    unsigned short i;
    static unsigned char idex = 0;
    unsigned short StartAddr[7] = {0, 120, 240, 340, 390};
    unsigned char RegNumber[7] = {60, 30, 10, 10, 10};
    unsigned char ModbusCode[7] = {3, 3, 3, 3, 3, 3};

    unsigned long nTime;
    float nValueS, nValueN, nValueCI;
    double tempValue;

    ModbusGetRegMap(VariaDlg.AnalyQueueNumber, VariaDlg.AnalyItemNumber);            //更新寄存器

    if (TaskDlg.WritePtr != TaskDlg.ReadPtr)                //有指令需要发送
    {
        if (!TaskDlg.ParaBuff[TaskDlg.ReadPtr].Busy) {
            TaskDlg.ParaBuff[TaskDlg.ReadPtr].Busy = 1;
            TaskDlg.ParaBuff[TaskDlg.ReadPtr].WaitTime = 0;
            TaskDlg.ParaBuff[TaskDlg.ReadPtr].Result = 0;
            VariaDlg.OrderAddr = TaskDlg.ParaBuff[TaskDlg.ReadPtr].Addr;

            VariaDlg.StartAddr = TaskDlg.ParaBuff[TaskDlg.ReadPtr].StartAddr;
            VariaDlg.RegNumber = TaskDlg.ParaBuff[TaskDlg.ReadPtr].RegNumber;

            VariaDlg.SendBuffLen[TaskDlg.ParaBuff[TaskDlg.ReadPtr].Chan] = Modbus_MasterMakeProcess(
                    TaskDlg.ParaBuff[TaskDlg.ReadPtr].Chan, TaskDlg.ParaBuff[TaskDlg.ReadPtr].Addr,
                    TaskDlg.ParaBuff[TaskDlg.ReadPtr].Code, TaskDlg.ParaBuff[TaskDlg.ReadPtr].StartAddr,
                    TaskDlg.ParaBuff[TaskDlg.ReadPtr].RegNumber);
            Modbus_SendBuff(TaskDlg.ParaBuff[TaskDlg.ReadPtr].Chan,
                            VariaDlg.SendBuff[TaskDlg.ParaBuff[TaskDlg.ReadPtr].Chan],
                            VariaDlg.SendBuffLen[TaskDlg.ParaBuff[TaskDlg.ReadPtr].Chan],
                            TaskDlg.ParaBuff[TaskDlg.ReadPtr].Addr);
        } else {
            if (TaskDlg.ParaBuff[TaskDlg.ReadPtr].Result == 1) {
                TaskDlg.ParaBuff[TaskDlg.ReadPtr].Busy = 0;
                TaskDlg.ReadPtr = (TaskDlg.ReadPtr + 1) & PARA_BUFF_DEEP;
            } else {
                if (TaskDlg.ParaBuff[TaskDlg.ReadPtr].WaitTime >= VariaDlg.SystemPara[52])    //500m秒没有返回
                {
                    TaskDlg.ParaBuff[TaskDlg.ReadPtr].Busy = 0;
                    TaskDlg.ReadPtr = (TaskDlg.ReadPtr + 1) & PARA_BUFF_DEEP;
                }
            }
        }
    } else {
        if (!VariaDlg.OrderBusy) {
            nTime = 1000 / VariaDlg.SystemPara[40] / 5;
            if (VariaDlg.SampleDataReadTime >= nTime)            //读数据
            {
                VariaDlg.OrderBusy = 1;
                VariaDlg.OrderResult = 0;
                VariaDlg.OrderTime = 0;
                VariaDlg.SampleDataReadTime = 0;

                VariaDlg.OrderAddr = 0x01;                        //设备地址
                VariaDlg.OrderCode = ModbusCode[VariaDlg.ReadAddrIdex];

                VariaDlg.StartAddr = StartAddr[VariaDlg.ReadAddrIdex];
                VariaDlg.RegNumber = RegNumber[VariaDlg.ReadAddrIdex];
                if (VariaDlg.ReadAddrIdex < 4) {
                    VariaDlg.ReadAddrIdex++;
                } else {
                    VariaDlg.ReadAddrIdex = 0;
                }

                VariaDlg.SendBuffLen[CHAN_COMM] = Modbus_MasterMakeProcess(CHAN_COMM, VariaDlg.OrderAddr,
                                                                           VariaDlg.OrderCode, VariaDlg.StartAddr,
                                                                           VariaDlg.RegNumber);
                Modbus_SendBuff(CHAN_COMM, VariaDlg.SendBuff[CHAN_COMM], VariaDlg.SendBuffLen[CHAN_COMM],
                                VariaDlg.OrderAddr);
            }
        } else {
            if (VariaDlg.OrderResult == 1)    //通道超时退出使用
            {
                VariaDlg.OrderBusy = 0;
                VariaDlg.OrderLost = 0;
                VariaDlg.UartState = 1;
            } else if (VariaDlg.OrderTime >= VariaDlg.SystemPara[52])        //通信中断
            {
                VariaDlg.OrderBusy = 0;

                VariaDlg.OrderLost++;
                if (VariaDlg.OrderLost >= 5) VariaDlg.UartState = 0;
            }
        }
    }
}

//===========================================================================
//	刷新MODBUS寄存器列表
//===========================================================================
void ModbusGetRegMap(unsigned short QueueNumber, unsigned short ItemNumber) {
    unsigned short idex = 0;
    int nMethod = 0;

    nMethod = GetMethodAddr(QueueDlg[QueueNumber].Item[ItemNumber].Method);
    if (nMethod == -1) return;

    //AJ进样器
    VariaDlg.Register[3] = MethodDlg[nMethod].ARM[9] * 10;                    //返回速度
    VariaDlg.Register[4] = MethodDlg[nMethod].ARM[5] * 10;                    //进样速度
    VariaDlg.Register[6] = MethodDlg[nMethod].ARM[6];                        //注射器容积
    VariaDlg.Register[8] = QueueDlg[QueueNumber].Item[ItemNumber].Sample;    //采样容积

    VariaDlg.Register[40] = (short) (MethodDlg[nMethod].Pass[1]);            //氯压力
    VariaDlg.Register[41] = (short) (MethodDlg[nMethod].Pass[0]);            //系统压力
    VariaDlg.Register[42] = MethodDlg[nMethod].Flow[2] * 10;                //臭氧
    VariaDlg.Register[43] = MethodDlg[nMethod].Flow[0] * 10;                //氩气
    VariaDlg.Register[44] = MethodDlg[nMethod].Flow[1] * 10;                //氧气
    VariaDlg.Register[45] = (short) (MethodDlg[nMethod].Heat[4] * 10);        //电解池温度
    VariaDlg.Register[46] = (short) (MethodDlg[nMethod].Heat[2] * 10);        //氮制冷
    VariaDlg.Register[47] = (short) (MethodDlg[nMethod].Heat[1] * 10);        //氮加热
    VariaDlg.Register[48] = (short) (MethodDlg[nMethod].Heat[0] * 10);        //炉温
    VariaDlg.Register[49] = (short) (MethodDlg[nMethod].Heat[3] * 10);        //催化剂温度

    VariaDlg.Register[61] = VariaDlg.SystemPara[47];                        //氧氩混合启动流量值
    VariaDlg.Register[62] = VariaDlg.SystemPara[10] * 10;                        //臭氧流量低保护
    VariaDlg.Register[63] = (short) (VariaDlg.SystemPara[11] * 10);            //氯压力低保护
    VariaDlg.Register[64] = (short) (VariaDlg.SystemPara[12]);                //主压力高保护
    VariaDlg.Register[65] = (short) (VariaDlg.SystemPara[13]);                //主压力低保护
    VariaDlg.Register[66] = (short) VariaDlg.SystemPara[14] * 10;                //炉温高保护
    VariaDlg.Register[67] = (short) VariaDlg.SystemPara[15] * 10;                //设备温度高保护
    VariaDlg.Register[68] = VariaDlg.SystemPara[48];                        //
    VariaDlg.Register[69] = VariaDlg.SystemPara[17];                        //AJ 的行程长度

    VariaDlg.Register[70] = VariaDlg.SystemPara[51] * MethodDlg[nMethod].Flow[3] / 100;            //K3动作计数值
    VariaDlg.Register[71] = VariaDlg.SystemPara[51];

    VariaDlg.Register[91] = MethodDlg[nMethod].Either[2];                    //氮高压
    VariaDlg.Register[92] = MethodDlg[nMethod].Either[3];                    //硫高压
    VariaDlg.Register[93] = MethodDlg[nMethod].Either[4];                    //氙灯高压
    VariaDlg.Register[94] = VariaDlg.SystemPara[18];                        //氙灯频率
    VariaDlg.Register[95] = VariaDlg.SystemPara[19];                        //氙灯频率

    VariaDlg.Register[122] = VariaDlg.SystemPara[49];                        //AJ 总行程步
    //液体进样器
    VariaDlg.Register[150] = MethodDlg[nMethod].ARM[7];                        //清洗体积
    VariaDlg.Register[152] = MethodDlg[nMethod].ARM[3] * 10;                    //提取速度
    VariaDlg.Register[153] = MethodDlg[nMethod].ARM[4] * 10;                    //排出速度
    VariaDlg.Register[154] = MethodDlg[nMethod].ARM[5] * 10;                    //进样速度
    VariaDlg.Register[155] = MethodDlg[nMethod].ARM[8];                        //容差体积
    VariaDlg.Register[156] = MethodDlg[nMethod].ARM[6];                        //注射器容积

    //固体进样器
    VariaDlg.Register[250] = MethodDlg[nMethod].ARM[12] * 10;                    //减速位
    VariaDlg.Register[252] = MethodDlg[nMethod].ARM[11] * 10;                    //快进速度
    VariaDlg.Register[253] = MethodDlg[nMethod].ARM[5] * 10;                    //进样速度
    VariaDlg.Register[254] = MethodDlg[nMethod].ARM[14] * 10;                    //冷却温度
    VariaDlg.Register[255] = MethodDlg[nMethod].ARM[15] * 10;                    //加热温度
    VariaDlg.Register[256] = MethodDlg[nMethod].ARM[6];                        //注射器容积

    if (MethodDlg[nMethod].SolidType == 2)                    //固体
    {
        VariaDlg.Register[251] = MethodDlg[nMethod].ARM[13] * 10;                    //燃烧位
    } else {
        VariaDlg.Register[251] = MethodDlg[nMethod].ARM[10] * 10;                    //总行程
    }

    //气体进样器
    VariaDlg.Register[352] = MethodDlg[nMethod].ARM[3];                        //提取速度
    VariaDlg.Register[353] = MethodDlg[nMethod].ARM[5];                        //进样速度
    VariaDlg.Register[354] = QueueDlg[QueueNumber].Item[ItemNumber].Sample;        //注入容积（样品量）
    VariaDlg.Register[355] = MethodDlg[nMethod].ARM[15];                    //加热温度
}

