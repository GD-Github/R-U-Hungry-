#include "mainwindow.h"
#include <QApplication>




int main(int argc, char *argv[])
{    User * currentUser = new User("Charles");

    QApplication a(argc, argv);
    MainWindow* mw = new MainWindow(currentUser,nullptr);
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->setAttribute(Qt::WA_TranslucentBackground);
    mw->show();

    return a.exec();
}


