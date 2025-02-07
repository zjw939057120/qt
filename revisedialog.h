#ifndef REVISEDIALOG_H
#define REVISEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ReviseDialog;
}
QT_END_NAMESPACE

class ReviseDialog : public QDialog
{
    Q_OBJECT

public:
    ReviseDialog(QWidget *parent = nullptr);
    ~ReviseDialog();
    void retranslateUi();

private:
    Ui::ReviseDialog *ui;
};
#endif // REVISEDIALOG_H
