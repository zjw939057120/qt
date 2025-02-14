#include "recorddialog.h"
#include "./ui_recorddialog.h"

RecordDialog::RecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    m_RecordDialogEx = new RecordDialogEx(parent);
    InitEnv();
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

void RecordDialog::InitEnv() {
    Init();
}

void RecordDialog::Init() {
    QToolkit::LineEditBorder(this);
    QToolkit::MinMaxButtonsHint(this);
}

void RecordDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void RecordDialog::on_pushButton_Close_clicked()
{
    close();
}

