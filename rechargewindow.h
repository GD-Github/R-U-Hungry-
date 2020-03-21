#ifndef RECHARGEWINDOW_H
#define RECHARGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class RechargeWindow;
}

class RechargeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RechargeWindow(QWidget *parent = nullptr);
    ~RechargeWindow();

private:
    Ui::RechargeWindow *ui;
};

#endif // RECHARGEWINDOW_H
