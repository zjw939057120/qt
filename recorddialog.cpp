#include "recorddialog.h"
#include "./ui_recorddialog.h"

RecordDialog::RecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

void RecordDialog::env() {
    init();
}

void RecordDialog::init() {
    Utils::lineEditBorder(this);
    Utils::windowMinMaxButtonsHint(this);
}

void RecordDialog::retranslateUi() {
    ui->retranslateUi(this);
}
