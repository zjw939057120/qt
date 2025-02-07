#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class RecordDialog;
}
QT_END_NAMESPACE

class RecordDialog : public QDialog
{
    Q_OBJECT

public:
    RecordDialog(QWidget *parent = nullptr);
    ~RecordDialog();
    void retranslateUi();

private:
    Ui::RecordDialog *ui;
};
#endif // RECORDDIALOG_H
