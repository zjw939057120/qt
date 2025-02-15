#ifndef SAMPLEDIALOG_H
#define SAMPLEDIALOG_H

#include <QDialog>

#include "SampleDialogEx.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class SampleDialog;
}
QT_END_NAMESPACE

class SampleDialog : public QDialog {
Q_OBJECT

public:
    SampleDialog(QWidget *parent = nullptr);

    ~SampleDialog();

    void Init();

    void retranslateUi();

private slots:

    void on_pushButton_Close_clicked();

private:
    Ui::SampleDialog *ui;
    QWidget *m_MainWindow;
    SampleDialogEx *m_SampleDialogEx;
};

#endif // SAMPLEDIALOG_H
