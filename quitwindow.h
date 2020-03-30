#ifndef QUITWINDOW_H
#define QUITWINDOW_H
#include<QMainWindow>
#include <QWidget>

namespace Ui {
class QuitWindow;
}

class QuitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuitWindow(QWidget *parent = nullptr);
    ~QuitWindow();

private:
    Ui::QuitWindow *ui;
};

#endif // QUITWINDOW_H
