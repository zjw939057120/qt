#include <QTranslator>
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    ui->stackedWidget->setCurrentWidget(ui->page_Method);
}

void MainWindow::on_actionQueue_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Queue);
}

void MainWindow::on_actionSample_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Sample);
}

void MainWindow::on_actionRecord_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Record);
}

void MainWindow::on_actionQuit_triggered() {
    qDebug() << __FUNCTION__;
    close();
}

void MainWindow::on_actionCut_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Cut);
}

void MainWindow::on_actionCopy_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Copy);
}

void MainWindow::on_actionPaste_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Paste);
}

void MainWindow::on_actionEnglish_triggered() {
    qDebug() << __FUNCTION__;
    changeLanguage("en_US");
}

void MainWindow::on_actionChinese_triggered() {
    qDebug() << __FUNCTION__;
    changeLanguage("zh_CN");
}

void MainWindow::on_actionRevise_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Revise);
}

void MainWindow::on_actionManual_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Manual);
}

void MainWindow::on_actionFAQ_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_FAQ);
}

void MainWindow::on_actionVersion_triggered() {
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(ui->page_Version);
}

void MainWindow::changeLanguage(const QString &lang) {
    QTranslator translator;
    if (translator.load(":/i18n/widget_" + lang)) {
        qDebug() << __FUNCTION__;
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
    }
}

void MainWindow::init() {
    ui->stackedWidget->setCurrentWidget(ui->page_Main);
}

