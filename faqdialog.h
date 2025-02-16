#ifndef FAQDIALOG_H
#define FAQDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class FAQDialog;
}
QT_END_NAMESPACE

class FAQDialog : public QDialog {
Q_OBJECT

public:
    FAQDialog(QWidget *parent = nullptr);

    ~FAQDialog();

    void Init();

    void retranslateUi();

private slots:

    void on_pushButton_Close_clicked();

private:
    Ui::FAQDialog *ui;
    QWidget *m_MainWindow;
};

#endif // FAQDIALOG_H
