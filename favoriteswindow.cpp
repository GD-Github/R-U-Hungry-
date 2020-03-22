#include "favoriteswindow.h"
#include "ui_favoriteswindow.h"

#include "mainwindow.h"
#include "bannedwindow.h"

FavoritesWindow::FavoritesWindow(QVector<Meal*> * availableMeal, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FavoritesWindow)
{
    this->availableMeal = availableMeal;
    ui->setupUi(this);

    connect(ui->homeBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    QVBoxLayout * listLayout = ui->likedList;
    for(Meal * meal: (*availableMeal)){
        if(meal->getIsLiked()){
            listLayout->addWidget(new MealItem(this,meal));
        }
    }
}

FavoritesWindow::~FavoritesWindow()
{
    delete ui;
}

void FavoritesWindow::homeBtnAction()
{
    MainWindow * w = new MainWindow(this,availableMeal);
    w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w->setAttribute(Qt::WA_TranslucentBackground);
    w->show();
    this->hide();
}

void FavoritesWindow::bannedBtnAction()
{
    BannedWindow * bw = new BannedWindow(availableMeal,this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}

void FavoritesWindow::exit()
{
    close();
}

void FavoritesWindow::updateLists(){
    QVBoxLayout * likedList = ui->likedList;
    QLayoutItem *childLiked;
    while ((childLiked = likedList->takeAt(0)) != 0) {
        QWidget* stepchild;
        stepchild=childLiked->widget();
        delete stepchild;
        delete childLiked;
    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        if((*it)->getIsLiked()&&(!(*it)->getIsBanned())) likedList->addWidget(new MealItem(this,*it));
    }
}
