#include <QTranslator>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manualdialog.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionMethod_triggered() {
    qDebug() << __FUNCTION__;
    m_MethodDialog->show();
}

void MainWindow::on_actionQueue_triggered() {
    qDebug() << __FUNCTION__;
    m_QueueDialog->show();
}

void MainWindow::on_actionSample_triggered() {
    qDebug() << __FUNCTION__;
    m_SampleDialog->show();
}

void MainWindow::on_actionRecord_triggered() {
    qDebug() << __FUNCTION__;
    m_RecordDialog->show();
}

void MainWindow::on_actionQuit_triggered() {
    qDebug() << __FUNCTION__;
    close();
}

void MainWindow::on_actionCut_triggered() {
    qDebug() << __FUNCTION__;
}

void MainWindow::on_actionCopy_triggered() {
    qDebug() << __FUNCTION__;
}

void MainWindow::on_actionPaste_triggered() {
    qDebug() << __FUNCTION__;
}

void MainWindow::on_actionEnglish_triggered() {
    qDebug() << __FUNCTION__;
    retranslateUi("en_US");
}

void MainWindow::on_actionChinese_triggered() {
    qDebug() << __FUNCTION__;
    retranslateUi("zh_CN");
}

void MainWindow::on_actionRevise_triggered() {
    qDebug() << __FUNCTION__;
    m_ReviseDialog->show();
}

void MainWindow::on_actionManual_triggered() {
    qDebug() << __FUNCTION__;
    m_ManualDialog->show();
}

void MainWindow::on_actionFAQ_triggered() {
    qDebug() << __FUNCTION__;
    m_FAQDialog->show();
}

void MainWindow::on_actionAbout_triggered() {
    qDebug() << __FUNCTION__;
    m_AboutDialog->show();
}

void MainWindow::retranslateUi(const QString &lang) {
    QTranslator translator;
    if (translator.load(":/i18n/widget_" + lang)) {
        qDebug() << __FUNCTION__;
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

void MainWindow::init() {
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
    Utils::lineEditBorder(this);

}

