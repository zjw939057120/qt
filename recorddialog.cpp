#include "recorddialog.h"
#include "ui_recorddialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

RecordDialog::RecordDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::RecordDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

RecordDialog::~RecordDialog() {
    delete ui;
}

void RecordDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void RecordDialog::RetranslateUi() {
    ui->retranslateUi(this);
}

void RecordDialog::on_pushButton_Close_clicked() {
    close();
}

