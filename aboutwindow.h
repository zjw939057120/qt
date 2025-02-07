#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class AboutWindow;
}
QT_END_NAMESPACE

class AboutWindow : public QMainWindow
{
    Q_OBJECT

public:
    AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private:
    Ui::AboutWindow *ui;
};
#endif // ABOUTWINDOW_H
