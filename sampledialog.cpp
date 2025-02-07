#include "sampledialog.h"
#include "./ui_sampledialog.h"

SampleDialog::SampleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SampleDialog)
{
    ui->setupUi(this);
}

SampleDialog::~SampleDialog()
{
    delete ui;
}

void SampleDialog::retranslateUi() {
    ui->retranslateUi(this);
}
