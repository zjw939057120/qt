#include "queuedialog.h"
#include "./ui_queuedialog.h"

QueueDialog::QueueDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueDialog)
{
    ui->setupUi(this);
}

QueueDialog::~QueueDialog()
{
    delete ui;
}

void QueueDialog::retranslateUi() {
    ui->retranslateUi(this);
}
