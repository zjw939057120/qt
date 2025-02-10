#include "methoddialog.h"
#include "./ui_methoddialog.h"

MethodDialog::MethodDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MethodDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

MethodDialog::~MethodDialog()
{
    delete ui;
}

void MethodDialog::init() {

}

void MethodDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void MethodDialog::on_pushButton_Save_clicked()
{

}


void MethodDialog::on_pushButton_Reset_clicked()
{

}


void MethodDialog::on_pushButton_ReviseReset_clicked()
{

}
