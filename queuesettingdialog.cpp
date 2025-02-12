#include "queuesettingdialog.h"
#include "./ui_queuesettingdialog.h"

QueueSettingDialog::QueueSettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueSettingDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

QueueSettingDialog::~QueueSettingDialog()
{
    delete ui;
}

void QueueSettingDialog::env() {
    this->setModal(true);
    init();
}

void QueueSettingDialog::init() {
    Utils::lineEditBorder(this);
    Utils::windowMinMaxButtonsHint(this);
}

void QueueSettingDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void QueueSettingDialog::on_pushButton_Save_clicked()
{
    close();
}


void QueueSettingDialog::on_pushButton_Stage_clicked()
{
    close();
}
