#include "rechargewindow.h"
#include "ui_rechargewindow.h"
#include <iostream>
#include <string>
using namespace std;
RechargeWindow::RechargeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RechargeWindow)
{
    ui->setupUi(this);
    connect(ui->rechargeSlider,SIGNAL(valueChanged(int)),this,SLOT(updatePrice(int)));
}


void RechargeWindow::updatePrice(int price){
   QString str = QString::fromStdString(to_string(price/5*5) + " ") + QChar(0x20AC); // QChar(0x20AC) est l'UTF-16 pour le symbole €
   ui->amountTxt->setText(str);
   update();
}

RechargeWindow::~RechargeWindow()
{
    delete ui;
}


