#include "mainwindow.h"
#include <QApplication>
#include "startwindow.h"
#include<iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow* sw = new StartWindow(nullptr);
    sw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    sw->setAttribute(Qt::WA_TranslucentBackground);
    sw->show();
    return a.exec();
}


