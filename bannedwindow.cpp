#include "bannedwindow.h"
#include "ui_bannedwindow.h"

#include "mainwindow.h"
#include "favoriteswindow.h"

BannedWindow::BannedWindow(QVector<Meal*> * availableMeal, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BannedWindow)
{
    this->availableMeal = availableMeal;
    ui->setupUi(this);

    connect(ui->homeBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    QScrollArea * mealBannedScrollArea = ui->bannedMealArea;
    mealBannedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    mealBannedScrollArea->setWidgetResizable( true );

    QWidget *widget = new QWidget();
    mealBannedScrollArea->setWidget( widget );
    mealBannedList = new QVBoxLayout();
    widget->setLayout( mealBannedList );

    updateLists();
}

BannedWindow::~BannedWindow()
{
    delete ui;
}

void BannedWindow::homeBtnAction()
{
    MainWindow * w = new MainWindow(this,availableMeal);
    w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w->setAttribute(Qt::WA_TranslucentBackground);
    w->show();
    this->hide();
}

void BannedWindow::exit()
{
    close();
}

void BannedWindow::favoritesBtnAction()
{
    FavoritesWindow * fw = new FavoritesWindow(availableMeal,this);
    fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    fw->setAttribute(Qt::WA_TranslucentBackground);
    fw->show();
    this->hide();
}

void BannedWindow::updateLists(){

    QLayoutItem *childBanned;
    while ((childBanned = mealBannedList->takeAt(0)) != 0) {
        delete childBanned->widget();
        delete childBanned;
    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        if((*it)->getIsBanned()) mealBannedList->addWidget(new MealItem(this,*it));
    }

    update();
}
