#ifndef FAQDIALOG_H
#define FAQDIALOG_H

#include <QDialog>
#include "Utils.h"

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
    void env();
    void init();
    void retranslateUi();

private:
    Ui::FAQDialog *ui;
    QWidget *m_MainWindow;
};
#endif // FAQDIALOG_H
