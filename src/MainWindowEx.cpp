//
// Created by Administrator on 2025/2/15.
//

#include <QMessageBox>
#include "MainWindowEx.h"
#include "Toolkit.h"
#include "mydefine.h"

MainWindowEx::MainWindowEx(QWidget *parent) {
    Init();
}

void MainWindowEx::Init() {
    Toolkit::CreatePath(DATA_PATH);
    Toolkit::CreatePath(LOG_PATH);
    Toolkit::WriteLogFile("打开软件");
    uint8_t nFlag;
    nFlag = Toolkit::ReadFile(QUEUE_FILE_PATH, (unsigned char *) &QueueDlg, sizeof(STRQUEUE) * QUEUE_TOTAL);
    if (!nFlag) Toolkit::WriteLogFile("没有找到队列文件");        //添加log日志

    nFlag = Toolkit::ReadFile(METHOD_FILE_PATH, (unsigned char *) &MethodDlg,
                              sizeof(STRMETHOD) * METHOD_TOTAL);
    if (!nFlag) Toolkit::WriteLogFile("没有找到方法文件");        //添加log日志
    nFlag = Toolkit::ReadConfigFile(SETTING_FILE_PATH, VariaDlg.SystemPara);
    if (!nFlag) {
        Toolkit::WriteLogFile("没有找到系统配置文件");        //添加log日志
        QMessageBox::warning(nullptr, "错误", "读取配置文件失败,请检查文件");
        exit(0);
    }
    ModbusGetRegMap(0, 0);

    VariaDlg.UartPort = CreateUart((unsigned char) VariaDlg.SystemPara[0], VariaDlg.SystemPara[1]);
    if (!VariaDlg.UartPort) Toolkit::WriteLogFile("打开指定串口失败");        //添加log日志
}
