#include "rechargewindow.h"

#include "ui_rechargewindow.h"
#include <iostream>
#include <string>



using namespace std;
RechargeWindow::RechargeWindow(User * currentUser, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RechargeWindow)
{
    this->currentUser = currentUser;
    ui->setupUi(this);
    connect(ui->cancelBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));

    connect(ui->homeBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->rechargeSlider,SIGNAL(valueChanged(int)),this,SLOT(updatePrice(int)));

    connect(ui->payBtn,SIGNAL(clicked()),this,SLOT(pay()));
}


void RechargeWindow::updatePrice(int price){
   QString str = QString::fromStdString(to_string(price/5*5) + " ") + QChar(0x20AC); // QChar(0x20AC) est l'UTF-16 pour le symbole €
   ui->amountTxt->setText(str);
   update();
}

void RechargeWindow::homeBtnAction(){
    parentWidget()->show();
    this->hide();
}

void RechargeWindow::favoritesBtnAction(){
    this->hide();
    this->fw->show();
}

void RechargeWindow::bannedBtnAction(){
    this->hide();
    this->bw->show();
}

void RechargeWindow::pay(){
    currentUser->addSolde(ui->rechargeSlider->value()/5*5);
    emit(soldeChanged(currentUser->getSolde()));
    this->hide();
    parentWidget()->show();
}

RechargeWindow::~RechargeWindow()
{
    delete ui;
}


