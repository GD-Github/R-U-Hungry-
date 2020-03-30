#include "startwindow.h"
#include "ui_startwindow.h"
#include <iostream>
using namespace std;

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->windowButton,SIGNAL(clicked()),this,SLOT(launchMain()));
    User * currentUser = new User("charles");
    mw = new MainWindow(currentUser,nullptr);
    mw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mw->setAttribute(Qt::WA_TranslucentBackground);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::launchMain(){
    mw->show();
    this->hide();
}
