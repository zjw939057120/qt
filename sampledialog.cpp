#include "sampledialog.h"
#include "ui_sampledialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

SampleDialog::SampleDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::SampleDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

SampleDialog::~SampleDialog() {
    delete ui;
}

void SampleDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void SampleDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void SampleDialog::on_pushButton_Close_clicked() {
    close();
}

