#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class ManualDialog;
}
QT_END_NAMESPACE

class ManualDialog : public QDialog {
Q_OBJECT

public:
    ManualDialog(QWidget *parent = nullptr);

    ~ManualDialog();

    void Init();

    void retranslateUi();

private slots:

    void on_pushButton_Close_clicked();

public:
    Ui::ManualDialog *ui;
    QWidget *m_MainWindow;

};

#endif // MANUALDIALOG_H
