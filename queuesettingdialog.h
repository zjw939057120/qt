#ifndef QUEUESETTINGDIALOG_H
#define QUEUESETTINGDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class QueueSettingDialog;
}
QT_END_NAMESPACE

class QueueSettingDialog : public QDialog {
Q_OBJECT

public:
    QueueSettingDialog(QWidget *parent = nullptr);

    ~QueueSettingDialog();

    void Init();

    void retranslateUi();

private slots:

    void on_pushButton_Save_clicked();

    void on_pushButton_Stage_clicked();

public:
    Ui::QueueSettingDialog *ui;
    QWidget *m_MainWindow;
};

#endif // QUEUESETTINGDIALOG_H
