#include "paywindow.h"
#include "ui_paywindow.h"
#include <iostream>
using namespace std;
PayWindow::PayWindow(QWidget *parent) :
    Meal_Window(parent),
    ui(new Ui::PayWindow)
{
    ui->setupUi(this);
    connect(ui->windowButton,SIGNAL(clicked()),this,SLOT(processPaiement()));
}

PayWindow::~PayWindow()
{
    delete ui;
}

void PayWindow::likedAsChanged(int id){

}

void PayWindow::bannedAsChanged(int id){

}

void PayWindow::processPaiement(){
    parentWidget()->show();
    this->hide();
}
