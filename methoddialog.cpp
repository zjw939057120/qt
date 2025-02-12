#include "methoddialog.h"
#include "./ui_methoddialog.h"

MethodDialog::MethodDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MethodDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

MethodDialog::~MethodDialog()
{
    delete ui;
}

void MethodDialog::env() {
    init();
}

void MethodDialog::init() {
    Utils::lineEditBorder(this);
    Utils::windowMinMaxButtonsHint(this);
}

void MethodDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void MethodDialog::on_pushButton_Save_clicked()
{
    close();
}

void MethodDialog::on_pushButton_Stage_clicked()
{
    close();
}

