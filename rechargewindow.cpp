#include "rechargewindow.h"
#include "favoriteswindow.h"
#include "bannedwindow.h"
#include "mainwindow.h"
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

    connect(ui->homeBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(close()));



    connect(ui->rechargeSlider,SIGNAL(valueChanged(int)),this,SLOT(updatePrice(int)));
}


void RechargeWindow::updatePrice(int price){
   QString str = QString::fromStdString(to_string(price/5*5) + " ") + QChar(0x20AC); // QChar(0x20AC) est l'UTF-16 pour le symbole €
   ui->amountTxt->setText(str);
   update();
}

void RechargeWindow::homeBtnAction(){
    MainWindow * hw = new MainWindow(currentUser,this);
    hw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    hw->setAttribute(Qt::WA_TranslucentBackground);
    hw->show();
    this->hide();
}

void RechargeWindow::favoritesBtnAction(){
    FavoritesWindow * fw = new FavoritesWindow(currentUser,this);
    fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    fw->setAttribute(Qt::WA_TranslucentBackground);
    fw->show();
    this->hide();
}

void RechargeWindow::bannedBtnAction(){
    BannedWindow * bw = new BannedWindow(currentUser,this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}


RechargeWindow::~RechargeWindow()
{
    delete ui;
}


