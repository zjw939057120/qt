#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class AboutDialog;
}
QT_END_NAMESPACE

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();
    void init();
    void retranslateUi();

private:
    Ui::AboutDialog *ui;
    QWidget *m_MainWindow;
};
#endif // ABOUTDIALOG_H
