#include "recorddialog.h"
#include "./ui_recorddialog.h"

RecordDialog::RecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

void RecordDialog::init() {

}

void RecordDialog::retranslateUi() {
    ui->retranslateUi(this);
}

