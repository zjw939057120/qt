#ifndef QUEUESETTINGDIALOG_H
#define QUEUESETTINGDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class QueueSettingDialog;
}
QT_END_NAMESPACE

class QueueSettingDialog : public QDialog
{
    Q_OBJECT

public:
    QueueSettingDialog(QWidget *parent = nullptr);
    ~QueueSettingDialog();
    void init();
    void retranslateUi();

private slots:
    void on_pushButton_Submit_clicked();

private:
    Ui::QueueSettingDialog *ui;
    QWidget *m_MainWindow;
};
#endif // QUEUESETTINGDIALOG_H
