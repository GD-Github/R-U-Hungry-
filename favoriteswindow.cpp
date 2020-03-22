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

    QScrollArea *mealLikedScrollArea = ui->favoriteMealArea;
    mealLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    mealLikedScrollArea->setWidgetResizable( true );

    QWidget *widget = new QWidget();
    mealLikedScrollArea->setWidget( widget );
    mealLikedList = new QVBoxLayout();
    widget->setLayout( mealLikedList );

    updateLists();
}

FavoritesWindow::~FavoritesWindow()
{
    delete availableMeal;
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

    QLayoutItem *childLiked;
    while ((childLiked = mealLikedList->takeAt(0)) != 0) {
        delete childLiked->widget();
        delete childLiked;
    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        if((*it)->getIsLiked()&&(!(*it)->getIsBanned())) mealLikedList->addWidget(new MealItem(this,*it));
    }

    update();
}
