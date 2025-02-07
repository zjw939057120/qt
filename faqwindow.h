#ifndef FAQWINDOW_H
#define FAQWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FAQWindow;
}
QT_END_NAMESPACE

class FAQWindow : public QMainWindow
{
    Q_OBJECT

public:
    FAQWindow(QWidget *parent = nullptr);
    ~FAQWindow();

private:
    Ui::FAQWindow *ui;
};
#endif // FAQWINDOW_H
