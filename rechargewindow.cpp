#include "rechargewindow.h"
#include "ui_rechargewindow.h"

RechargeWindow::RechargeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RechargeWindow)
{
    ui->setupUi(this);
}

RechargeWindow::~RechargeWindow()
{
    delete ui;
}

