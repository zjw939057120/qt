#include "revisedialog.h"
#include "./ui_revisedialog.h"

ReviseDialog::ReviseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReviseDialog)
{
    ui->setupUi(this);
}

ReviseDialog::~ReviseDialog()
{
    delete ui;
}

void ReviseDialog::retranslateUi() {
    ui->retranslateUi(this);
}
