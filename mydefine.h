#ifndef _MYDEFINE_H
#define _MYDEFINE_H

#include <shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

#include "Pcomm.h"

#define CAP_DATA_SHOW_LENGHT    0x1ff    //总共显示的点个数
#define CAP_DATA_SHOW_X_AXIS    0x1ff   //X轴显示的点最大值


#define RES_DATA_SHOW_LENGHT    0x1ff  //总共显示的点个数
#define RES_DATA_SHOW_X_AXIS    0x1ff   //X轴显示的点最大值

#define VOL_DATA_SHOW_LENGHT    0x1ff    //总共显示的点个数
#define VOL_DATA_SHOW_X_AXIS    0x1ff   //X轴显示的点最大值

#define DEVICE_TOTAL        32            //设备总数
#define SAMPLE_VALUE_TOTAL    128            //最大128个采样值

#define MODE_UDP        0
#define MODE_TCP        1

#define CHAN_NUM        0X02

#define CHAN_COMM        0X00
#define CHAN_UDP        0X01

#define MODBUS_ADDR_MAX        1280
#define MODBUS_REG_MAX        128            //寄存器最大个数

#define ORDER_TIME        100                //每条指令最大独占时间 毫秒
#define STATUS_REGISTER_NUM        10

#define QUEUE_ITEM_TOTAL    800
#define QUEUE_TOTAL            100

#define CALIBRATE_DATA_DEEP        0XFF    //标定最大个数
#define SAMPLE_DATA_DEEP        0X7FFF    //采样最大个数

#define SYSTEM_PARA_TOTAL        64        //系统参数最大个数
#define RECV_BUFF_LEN            0X3FF
typedef struct {
    char Debug[64];
    unsigned char DebugOut;            //=1 输出DEBUG内容

    unsigned char RecvBuff[CHAN_NUM][RECV_BUFF_LEN + 1];        //接收缓存区
    unsigned char SendBuff[CHAN_NUM][RECV_BUFF_LEN + 1];        //发送缓存区
    unsigned char HandBuff[CHAN_NUM][RECV_BUFF_LEN + 1];        //处理缓存区
    unsigned short WritePtr[CHAN_NUM];                            //接收指针
    unsigned short ReadPtr[CHAN_NUM];                            //处理指针
    unsigned short SendBuffLen[CHAN_NUM];                        //待发送数据长度

    float SystemPara[SYSTEM_PARA_TOTAL];
    unsigned short ItemPos;                //滚动位置
    unsigned char SelectSignal;            //选择队列显示信号类型 bit0~2 对应硫 氮 氯,置1 不显示
    unsigned long ConfigTime;                //配置保护参数周期=0 开始配置

    char ReportName[32];
    char FileType;                //=0 XML =1 CSV
    char XML_USER[32];
    char XML_PASS[32];
    unsigned short ItemList[QUEUE_ITEM_TOTAL];        //列表行数对应的实际存储位置

    unsigned short ItemNumber;                //项目序号
    unsigned short MethodNumber;            //方法序号
    unsigned short QueueNumber;            //队列序号
    unsigned char InsertMode;                //=1 上方插入记录
    unsigned char ItemFree;                //队列空标志

    unsigned short AnalyStartSerial;        //分析开始序号
    unsigned short AnalyNowSerial;            //当前分析序号
    short AnalyNextSerial;        //下一次分析序号
    short AnalyNextItemNumber;    //下一次分析编号 -1 没有下一行

    short AnalyNowBitNumber;        //当前分析位号
    short AnalyNextBitNumber;        //下一次分析位号
    short AnalyLastBitNumber;        //上一次分析位号

    unsigned short AnalyItemNumber;        //正在分析的项目序号
    unsigned short AnalyQueueNumber;        //正在分析的队列序号
    unsigned char AnalySignalNumber;        //正在分析的信号序号

    unsigned short AnalyState;                //分析状态
    unsigned short AnalyControl;            //机械臂控制状态

    unsigned char AnalyLastArm;            //上一个进样器类型
    unsigned char AnalyNowArm;            //当前进样器类型
    unsigned char AnalyNextArm;            //下一行进样器类型

    unsigned char AnalyStartSignal;    //分析开始信号类型
    unsigned char AnalyStopSignal;    //分析结束信号类型
    unsigned char AnalyNowSignal;        //正在分析信号类型

    unsigned char ResultCopy;                //=1 需要将结果复制到指定项目，那个项目不再进行分析
    unsigned short AnalyCopyNumber;        //不需要分析可以直接复制

    unsigned char ManEnterFlag;            //人工确认信号
    unsigned char ManCancelFlag;            //人工取消信号
    unsigned char ManRequestFlag;            //人工请求发出信号

    unsigned long AnalySampleTime;        //分析采样时长

    unsigned char ArgonChangeFlag;        //=1 氧氩切换 =0 不切换
    unsigned long ArgonChangeTime;        //氧氩切换时间
    unsigned char ArgonChangeFinish;        //=1 切换完成
    unsigned char ArgonManChange;            //=1 强制切换
    unsigned char ResultListChange;        //=1 结果列表发生改变
    unsigned char AnalyNoWait;            //=1 已经收到288，不用等待
    unsigned long SendCount;                //重发次数
    unsigned short TaskNumber;                //任务当前队列序号
    unsigned short ErrorCode;                //错误代码

    unsigned short CleanCount;                //清洗次数
    unsigned char BitNumber;                //位号
    unsigned char BitCount;                //该位号的取样次数 =0 首次
    unsigned short NextSample;                //进样量

    char RightChosenMethodName[32];        //右键选中的方法名称
    char RightChosenQueueName[32];        //右键选中的队列名称

    char SelDeviceName[64];
    char LocalIP[17];        //本机IP地址
    unsigned char UartPort;            //本机串口号 =0 打开串口失败
    SOCKET LocalSocket;        //本地SOCKET
    unsigned char UartState;            //=0 通信中断
    unsigned char FristFlag;            //=1 第一次启动液体

    SYSTEMTIME SystemTime;            //系统时间
    unsigned char SampleOut;            // =1 刷新采样数据
    unsigned char OrderBusy;            //=0 可以处理新的指令
    unsigned long OrderTime;            //正在处理的指令占用的时间
    unsigned char OrderResult;        //
    unsigned char OrderLost;            //指令连续无返回次数

    unsigned char OrderAddr;
    unsigned char OrderCode;            //正在处理的指令类型
    unsigned short StartAddr;            //寄存器开始地址
    unsigned short RegNumber;            //寄存器个数

    unsigned short MethodTotal;                                //方法总数
    char MethodName[1024][16];                        //方法名称

    unsigned short Register[MODBUS_ADDR_MAX];
    unsigned long ReadTime[DEVICE_TOTAL];

    unsigned char Decide;                                        // =1 已经选中某一项 =0 为选中任何一行
    unsigned char DisplayList;                                //列表显示选择
    int MonitorSize[2];                                //=0 宽 =1 高

    unsigned char ReadAddrIdex;                                //读地址序号
    unsigned long SampleDataReadTime;                            //测试数据读取周期，单位毫秒
    unsigned char StartSample;                                //=1 开始采样
    unsigned char StartDisplay;                                //=1 显示
    double XValue;
    double YValue;

    unsigned short ManQueueNumber;
    unsigned short ManItemNumber;

    unsigned char DisplayLineType;                            //显示曲线类型=0 历史曲线 =1 标定点 =2 实时曲线
    unsigned char StandLineType;                                //标定曲线类型=0 绝对值 =1 一次 =2 二次

    unsigned char SignalLineType;                                //当前信号线显示的是什么
    double SampleDataBuff[3][SAMPLE_DATA_DEEP + 1];        //采样数据缓存区[硫30:31 氮34:35 氯36:37]
    double SampleDataTimer[SAMPLE_DATA_DEEP + 1];            //采样数据对应横坐标
    unsigned short SampleDataLength;
    unsigned short LineDataTimer;                                //曲线数据间隔

    double DispWaveBuff[SAMPLE_DATA_DEEP + 1];                //历史曲线缓存区
    double DispWaveTimer[SAMPLE_DATA_DEEP + 1];
    unsigned short DispWaveLength;                                //缓存区数据长度

    unsigned char BaseLineFlag;                                //=1 可以显示或修改基线
    double BaseLineValue[SAMPLE_DATA_DEEP + 1];            //基线纵坐标
    double BaseLineStartPoint[2];
    double BaseLineStopPoint[2];                        //结束坐标

    double FillLineValue[SAMPLE_DATA_DEEP + 1];            //填充线数据
    double MouseStartPoint[2];                            //第一个鼠标坐标
    double MouseStopPoint[2];                            //第二个鼠标坐标
    unsigned char ShiftDown;                                    //=1 shift键按下
    double CalibrateDataBuff[CALIBRATE_DATA_DEEP][2];    //标定数据缓存区  0=标定浓度 1=面积

    unsigned char SampleNumber;                                //采样设备序号
    unsigned short DeviceNumber;                                //当前选择的设备序号

    SOCKADDR_IN ServerSocketAddr[DEVICE_TOTAL];                // 与服务器连接的SOCKET地址
    int ServerSocketLen[DEVICE_TOTAL];

    SOCKADDR_IN RecvSocketAddr;
    int RecvSocketLen;

    float SampleValue[DEVICE_TOTAL][SAMPLE_VALUE_TOTAL];        //设备采样值
    float SampleBuff[SAMPLE_VALUE_TOTAL];                        //需要显示的数据

    unsigned char AdjustListUpdata;                //=1 刷新校准列表
    unsigned char WaitAdjustTime;                    //等待校准完成
    unsigned char AdjustCount;
    char LogRowBuff[256];                //一行log日志
    unsigned char AdjustState;                    //校正状态机
    unsigned char AdjustNumber;                    //校准序号

    unsigned char PointType;                        //校准点类型
    unsigned char ArmType;                        //进样器类型

    long LiquidPointValue[10][4];        //进样器标定值
    long AirPointValue[10][4];
    long SolidPointValue[10][4];


} STRVARIABLE;


typedef struct {
    char Name[24];                //设备名称
    unsigned char Addr;                    //通信ID
    unsigned char Type;                    //设备类型
    unsigned long Time;                    //采集周期
    char IP[17];                    //IP地址
    unsigned short Port;                    //端口号
    unsigned char Comm;                    //=0 网络

    unsigned short SampleTime;                //平台数据刷新周期
    unsigned char DataType;                //数据类型
    unsigned char FileSize;                //存储长度
} STRDEVICE;

#define PARA_BUFF_DEEP    0X0F

typedef struct {
    unsigned char Addr;            //设备地址
    unsigned char Code;            //功能码
    unsigned short StartAddr;        //开始地址
    unsigned short RegNumber;        //寄存器个数
    unsigned char Busy;            //=1 忙
    unsigned char Result;            //=1 设备返回指令
    unsigned long WaitTime;        //等待应答时间，单位毫秒
    unsigned char Chan;            //通道类型选择
} STRGROUP;

typedef struct {
    STRGROUP ParaBuff[PARA_BUFF_DEEP + 1];

    unsigned char WritePtr;
    unsigned char ReadPtr;
} STRTASK;

typedef struct {
    unsigned short Register[520];
} STRMODBUS;

#define METHOD_TOTAL    128        //128个方法

#define HEATOR_TOTAL    16
#define FLOW_TOTAL        16
#define PASS_TOTAL        16
#define EITHER_TOTAL    16
#define ARM_TOTAL        32

typedef struct {
    unsigned short Valid;                        //=1 有效标志位
    unsigned char Type;                        // 方法类型{"硫","氮","氯","硫氮","CELL","待机","启动"};
    char Name[30];                    // 方法名称
    char ArmType;                    // 进样器类型 =0 AJ  =1 液体  =2 气体  =3 固体 =4 无
    char SolidType;                    // 固体进样器类型 [=0液体 =1气体 =2 固体]

    float Heat[HEATOR_TOTAL];            //温度（炉温(℃)，氮加热(℃)，氮制冷(℃)，催化剂温度(℃)，电解池温度(℃)）
    float Flow[FLOW_TOTAL];            //流量[载气，氧气，臭氧,裂解氧(%)]
    float Pass[PASS_TOTAL];            //压力[系统压力，氯压力]
    float Either[EITHER_TOTAL];        //其他参数[采样时间,裂解时间,氮高压,硫高压,氙灯高压]
    float ARM[ARM_TOTAL];                //进样器参数 [0:清洗次数1,清洗次数2,置换次数,3:提取速度,4:排出速度,5:进样速度,6:注射器容积,7:清洗体积,8:容差体积,9:返回速度，10:总行程，11:快进速度，12:减速位，13:燃烧位，14:冷却温度,15加热温度,16扎入比例]
} STRMETHOD;

typedef struct {
    unsigned char Valid;                //=1 有效
    unsigned char Finish;                //=1 已经做完

    unsigned short Serial;                //序号
    unsigned char BitNumber;            //位号
    unsigned char Signal;                //信号 [硫，氮，氯]
    unsigned char Type;                //类型  =0 采样 =1 标定
    char StandLine[32];        //标定曲线名称
    char Method[32];            //方法的名称
    float StandDensity;        //标定浓度

    unsigned char ResultUnit;            //结果单位
    unsigned char SampleUnit;            //样品单位
    char Name[32];            //样品名称
    char ID[32];                //ID号
    unsigned char SubID;                //ID采样次数编码
    char Date[20];            //日期

    float Area;                //面积
    float Result;                //结果
    float Average;            //平均值
    float SD;                    //
    float RSD;                //
    float Sample;                //样品量
    float Density;            //密度

    unsigned char BaseType;            //基线类型
    float BaseStart[2];        //基线开始坐标
    float BaseStop[2];        //基线结束坐标

    unsigned short LineTimer;            //采样点周期
    unsigned short LineLength;            //采样点个数
    char LineName[64];        //采样曲线对应的文件名
    float ConversionRate;        //转化率
    unsigned char Hide;                //=1 隐藏 平均值，SD，RSD

    unsigned char Mark[27];            //备注
} STRITEM;

#define LINE_POINT            64
typedef struct {
    double Para[4];                    //标定曲线的计算参数0=A;1=B;2=C
    double PointX[LINE_POINT];            //标定浓度
    double PointY[LINE_POINT];            //单位面积
    unsigned char Count;                        //标定点个数
    unsigned char Unit[2];                    //=0 标定浓度单位 =1 面积单位
} STRLINE;


typedef struct {
    unsigned char Valid;                        //=1 有效
    char Name[32];                    //队列名称
    STRLINE Line[3];                    //硫 氮 氯的标定曲线
    unsigned char LineType[3];                //=0 绝对值 =1 一次 =2 二次
    unsigned short ItemTotal;                    //Item的有效数量
    STRITEM Item[QUEUE_ITEM_TOTAL];        //项目
} STRQUEUE;

typedef struct {
    char ID[32];
    char Name[32];
    char StandLine[32];
    float Density;
    float Sample;
    char Signal;
    unsigned char SubID[256];
    float Result[256];
    unsigned char Count;
} STRREPORT;

typedef struct {
    char StandLine[3][128];    //=0 硫标线 =1氮  =2 氯
    char Method[3][128];        //同上
    char Signal[3];            //信号
    char Type[3];                //类型
    float StandDensity[3];        //标定浓度
    float Sample[3];            //样品量
    char ID[32];                //ID号
    char BitNumber;            //位号
    char Name[32];            //样品名称
    long Count;                //采样次数
    float Density;                //密度
    char ResultUnit;            //结果单位
    char SampleUnit;            //样品单位
    float ConversionRate;        //转化率
    char ReportName[64];
    char ReportType;
    char ReportUSER[64];
    char ReportPass[64];
} STRLOG;

static STRQUEUE QueueDlg[QUEUE_TOTAL];
static STRMETHOD MethodDlg[METHOD_TOTAL];
static STRTASK TaskDlg;
static STRDEVICE DeviceDlg[DEVICE_TOTAL];
static STRVARIABLE VariaDlg;
static STRREPORT ReportDlg;
static STRLOG LogDlg;

extern void ModbusGetRegMap(unsigned short QueueNumber, unsigned short Serial);

extern void Modbus_MasterRecvProcess(unsigned char chan, unsigned char addr);

extern unsigned short
Modbus_MasterMakeProcess(unsigned char chan, unsigned char addr, char CMDType, unsigned short StartAddr,
                         unsigned short RegNumber);

extern void Modbus_MasterSendProcess(void);

extern char WriteFile(char *path, unsigned char *buff, unsigned long nlen);

extern char ReadFile(char *path, unsigned char *buff, unsigned long nlen);

extern unsigned char GetLocalIP(char *nIP);

extern unsigned short UartRecvBuff(unsigned char nPort, unsigned char *buff);

extern void UartSendBuff(unsigned char nPort, unsigned char *buff, unsigned short nlen);

extern unsigned char CreateUart(int nPort, int nBaut);

extern void Modbus_SendBuff(unsigned char chan, unsigned char *buff, unsigned short nlen, unsigned char nAddr);

extern unsigned short GetDeviceAddr(char *name);

extern SOCKET SocketCreate(char *mainIP, unsigned short mainPort, unsigned char type);

extern void SocketConfig(SOCKADDR_IN *nSocket, char *ip, unsigned short port);

extern int
SocketSendBuff(SOCKET nSocket, unsigned char type, unsigned char *SBuff, unsigned short nLen, SOCKADDR_IN ServerAddr);

extern int SocketRecvBuff(SOCKET nSocket, unsigned char type, unsigned char *Buff, SOCKADDR_IN ServerAddr);

extern short GetQueueAddr(char *name);

extern short GetMethodAddr(char *name);

extern short GetQueueItemAddr(unsigned short Number, unsigned short serial);

extern short SampleAnalyFSM(void);

extern float CalculateResult(unsigned short QueueNumber, unsigned short ItemNumber, char nType, unsigned char Signal);

extern void MultiLine(double *arrX, double *arrY, int length, int dimension, double *nPara);

extern double GetCompute(double inData, char type, double *para);

extern float R_Squared(double *arrX, double *arrY, unsigned short Count, unsigned char LineType, double *Para);

extern void UpdataOneQueue(unsigned short QueueNumber);

extern void MakeReport(char *path, char nType, unsigned short QueueNumber);

extern char RemoveFile(char *path);

extern char FindFile(char *path);

extern void WriteLogFile(char *nText);

extern int AdjustFSM(void);

extern UINT DataRecvThread(LPVOID pParam);

extern UINT DataSendThread(LPVOID pParam);

extern UINT DataProcThread(LPVOID pParam);

extern UINT BaseTimeThread(LPVOID pParam);

extern UINT UserTaskThread(LPVOID pParam);


#endif