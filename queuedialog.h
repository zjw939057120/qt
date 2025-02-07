#ifndef QUEUEDIALOG_H
#define QUEUEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class QueueDialog;
}
QT_END_NAMESPACE

class QueueDialog : public QDialog
{
    Q_OBJECT

public:
    QueueDialog(QWidget *parent = nullptr);
    ~QueueDialog();
    void retranslateUi();


private:
    Ui::QueueDialog *ui;
};
#endif // QUEUEDIALOG_H
