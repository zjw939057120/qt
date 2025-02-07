#include "methoddialog.h"
#include "./ui_methoddialog.h"

MethodDialog::MethodDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MethodDialog)
{
    ui->setupUi(this);
}

MethodDialog::~MethodDialog()
{
    delete ui;
}

void MethodDialog::retranslateUi() {
    ui->retranslateUi(this);
}
