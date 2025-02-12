#include "sampledialog.h"
#include "./ui_sampledialog.h"

SampleDialog::SampleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SampleDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

SampleDialog::~SampleDialog()
{
    delete ui;
}

void SampleDialog::env() {
    init();
}

void SampleDialog::init() {
    Utils::lineEditBorder(this);
    Utils::windowMinMaxButtonsHint(this);
}

void SampleDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void SampleDialog::on_pushButton_Close_clicked()
{
    close();
}

