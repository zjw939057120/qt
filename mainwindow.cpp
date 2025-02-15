#include <QTranslator>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "Toolkit.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_MainWindowEx = new MainWindowEx(parent);
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
    }
}

void MainWindow::Init() {
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

    Toolkit::LineEditBorder(this);
#ifdef __linux__
    Utils::windowMinMaxButtonsHint(this);
#endif
}

