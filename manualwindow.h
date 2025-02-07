#ifndef MANUALWINDOW_H
#define MANUALWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ManualWindow;
}
QT_END_NAMESPACE

class ManualWindow : public QMainWindow
{
    Q_OBJECT

public:
    ManualWindow(QWidget *parent = nullptr);
    ~ManualWindow();

private:
    Ui::ManualWindow *ui;
};
#endif // MANUALWINDOW_H
