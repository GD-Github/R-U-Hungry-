#include "paywindow.h"
#include "ui_paywindow.h"

PayWindow::PayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PayWindow)
{
    ui->setupUi(this);
}

PayWindow::~PayWindow()
{
    delete ui;
}
