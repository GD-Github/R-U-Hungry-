#include "mainwindow.h"
#include <QApplication>
#include "startwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    User * currentUser = new User("charles");
    MainWindow* mw = new MainWindow(currentUser,nullptr);
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->setAttribute(Qt::WA_TranslucentBackground);
    mw->show();

    return a.exec();
}


