#ifndef SAMPLEDIALOG_H
#define SAMPLEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class SampleDialog;
}
QT_END_NAMESPACE

class SampleDialog : public QDialog {
Q_OBJECT

public:
    SampleDialog(QWidget *parent = nullptr);

    ~SampleDialog();

    void Init();

    void RetranslateUi();

private slots:

    void on_pushButton_Close_clicked();

public:
    Ui::SampleDialog *ui;
    QWidget *m_MainWindow;
};

#endif // SAMPLEDIALOG_H
