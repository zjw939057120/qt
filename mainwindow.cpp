#include <QTranslator>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_debugdialog.h"
#include <QApplication>
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionMethod_triggered() {
    m_MethodDialog->show();
}

void MainWindow::on_actionQueue_triggered() {
    m_QueueDialog->show();
}

void MainWindow::on_actionSample_triggered() {
    m_SampleDialog->show();
}

void MainWindow::on_actionRecord_triggered() {
    m_RecordDialog->show();
}

void MainWindow::on_actionQuit_triggered() {
    close();
}

void MainWindow::on_actionCut_triggered() {

}

void MainWindow::on_actionCopy_triggered() {

}

void MainWindow::on_actionPaste_triggered() {

}

void MainWindow::on_actionEnglish_triggered() {
    retranslateUi("en_US");
}

void MainWindow::on_actionChinese_triggered() {
    retranslateUi("zh_CN");
}

void MainWindow::on_actionRevise_triggered() {
    m_ReviseDialog->show();
}

void MainWindow::on_actionManual_triggered() {
    m_ManualDialog->show();
}

void MainWindow::on_actionFAQ_triggered() {
    m_FAQDialog->show();
}

void MainWindow::on_actionAbout_triggered() {
    m_AboutDialog->show();
}

void MainWindow::on_actionDebug_triggered() {
    m_DebugDialog->show();
}

void MainWindow::retranslateUi(const QString &lang) {
    QTranslator translator;
    if (translator.load(":/i18n/widget_" + lang)) {
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        m_AboutDialog->retranslateUi();
        m_FAQDialog->retranslateUi();
        m_ManualDialog->retranslateUi();
        m_MethodDialog->retranslateUi();
        m_QueueDialog->retranslateUi();
        m_QueueSettingDialog->retranslateUi();
        m_RecordDialog->retranslateUi();
        m_ReviseDialog->retranslateUi();
        m_SampleDialog->retranslateUi();
        m_DebugDialog->retranslateUi();
    }
}

void MainWindow::Init() {
    m_Toolkit = new Toolkit(this);
    m_AboutDialog = new AboutDialog(this);
    m_FAQDialog = new FAQDialog(this);
    m_ManualDialog = new ManualDialog(this);
    m_MethodDialog = new MethodDialog(this);
    m_QueueDialog = new QueueDialog(this);
    m_QueueSettingDialog = new QueueSettingDialog(m_QueueDialog);
    m_RecordDialog = new RecordDialog(this);
    m_ReviseDialog = new ReviseDialog(this);
    m_ReviseDialog = new ReviseDialog(this);
    m_SampleDialog = new SampleDialog(this);
    m_DebugDialog = new DebugDialog(this);

    m_Toolkit->LineEditBorder(this);
#ifdef __linux__
    Utils::windowMinMaxButtonsHint(this);
#endif

    m_Toolkit->CreatePath(CONFIG_PATH);
    m_Toolkit->CreatePath(QUEUE_PATH);
    m_Toolkit->CreatePath(METHOD_PATH);
    m_Toolkit->CreatePath(LOG_PATH);
    m_Toolkit->CreatePath(REPORT_PATH);
    m_Toolkit->CreatePath(WAVE_PATH);

    m_DebugDialog->WriteLogFile("打开软件");
    uint8_t nFlag;
    nFlag = m_Toolkit->ReadFile(QUEUE_PATH_DATA, (unsigned char *) &QueueDlg, sizeof(STRQUEUE) * QUEUE_TOTAL);
    if (!nFlag) m_DebugDialog->WriteLogFile("没有找到队列文件");        //添加log日志
    nFlag = m_Toolkit->ReadFile(METHOD_PATH_DATA, (unsigned char *) &MethodDlg,
                                sizeof(STRMETHOD) * METHOD_TOTAL);
    if (!nFlag) m_DebugDialog->WriteLogFile("没有找到方法文件");        //添加log日志
    nFlag = m_Toolkit->ReadConfigFile(CONFIG_PATH_DATA, VariaDlg.SystemPara);
    if (!nFlag) {
        m_DebugDialog->WriteLogFile("没有找到系统配置文件");        //添加log日志
        QMessageBox::warning(nullptr, "错误", "读取配置文件失败,请检查文件");
        exit(0);
    }
#ifdef _DEBUG_ENV
    for (int i = 0; i < SYSTEM_PARA_TOTAL; ++i) {
        m_DebugDialog->WriteLogFile(std::to_string(VariaDlg.SystemPara[i]).data());
    }
#endif

    ModbusGetRegMap(0, 0);

    VariaDlg.UartPort = m_Toolkit->CreateUart((unsigned char) VariaDlg.SystemPara[0], VariaDlg.SystemPara[1]);
    if (!VariaDlg.UartPort) m_DebugDialog->WriteLogFile("打开指定串口失败");        //添加log日志
}
