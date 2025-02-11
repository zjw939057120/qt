#include "queuesettingdialog.h"
#include "./ui_queuesettingdialog.h"

QueueSettingDialog::QueueSettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueSettingDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

QueueSettingDialog::~QueueSettingDialog()
{
    delete ui;
}

void QueueSettingDialog::init() {
    Utils::lineEditBorder(this);
    this->setModal(true);

}

void QueueSettingDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void QueueSettingDialog::on_pushButton_Submit_clicked()
{

}

