#include "queuesettingdialog.h"
#include "./ui_queuesettingdialog.h"

QueueSettingDialog::QueueSettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueSettingDialog)
{
    ui->setupUi(this);
}

QueueSettingDialog::~QueueSettingDialog()
{
    delete ui;
}

void QueueSettingDialog::retranslateUi() {
    ui->retranslateUi(this);
}
