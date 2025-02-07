#ifndef FAQDIALOG_H
#define FAQDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class FAQDialog;
}
QT_END_NAMESPACE

class FAQDialog : public QDialog
{
    Q_OBJECT

public:
    FAQDialog(QWidget *parent = nullptr);
    ~FAQDialog();
    void retranslateUi();

private:
    Ui::FAQDialog *ui;
};
#endif // FAQDIALOG_H
