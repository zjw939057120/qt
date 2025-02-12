#include "queuesettingdialog.h"
#include "./ui_queuesettingdialog.h"

QueueSettingDialog::QueueSettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueSettingDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    InitEnv();
}

QueueSettingDialog::~QueueSettingDialog()
{
    delete ui;
}

void QueueSettingDialog::InitEnv() {
    this->setModal(true);
    Init();
}

void QueueSettingDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
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
