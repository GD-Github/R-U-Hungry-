#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private:
    Ui::StartWindow *ui;
    MainWindow* mw = nullptr;

public slots:
    void launchMain();
};

#endif // STARTWINDOW_H
