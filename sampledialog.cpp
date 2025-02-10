#include "sampledialog.h"
#include "./ui_sampledialog.h"

SampleDialog::SampleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SampleDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

SampleDialog::~SampleDialog()
{
    delete ui;
}

void SampleDialog::init() {

}

void SampleDialog::retranslateUi() {
    ui->retranslateUi(this);
}
