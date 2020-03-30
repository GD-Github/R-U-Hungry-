#ifndef PAYWINDOW_H
#define PAYWINDOW_H

#include <QWidget>

namespace Ui {
class PayWindow;
}

class PayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PayWindow(QWidget *parent = nullptr);
    ~PayWindow();

private:
    Ui::PayWindow *ui;
};

#endif // PAYWINDOW_H
