#include "faqdialog.h"
#include "ui_faqdialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

FAQDialog::FAQDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::FAQDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

FAQDialog::~FAQDialog() {
    delete ui;
}

void FAQDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void FAQDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void FAQDialog::on_pushButton_Close_clicked() {
    close();
}

