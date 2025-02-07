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
    void retranslateUi();

private:
    Ui::QueueSettingDialog *ui;
};
#endif // QUEUESETTINGDIALOG_H
