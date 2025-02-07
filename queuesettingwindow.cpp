#include "queuesettingwindow.h"
#include "./ui_queuesettingwindow.h"

QueueSettingWindow::QueueSettingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QueueSettingWindow)
{
    ui->setupUi(this);
}

QueueSettingWindow::~QueueSettingWindow()
{
    delete ui;
}
