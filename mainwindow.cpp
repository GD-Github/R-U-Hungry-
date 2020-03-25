#include "mainwindow.h"
#include "ui_mainwindow.h"



#include "rechargewindow.h"
#include "favoriteswindow.h"
#include "bannedwindow.h"

MainWindow::MainWindow(QWidget *parent, User* currentUser)
    : Meal_Window(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rechargeBtn,SIGNAL(clicked()),this,SLOT(rechargeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    if(currentUser == nullptr){
        this->currentUser = new User("charles");
    }
    else{
        this->currentUser = currentUser;
    }

    QScrollArea *startersLikedScrollArea = ui->startersScrollArea_1;
    startersLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    startersLikedScrollArea->setWidgetResizable( true );
    QScrollArea *dishesLikedScrollArea = ui->dishesScrollArea_1;
    dishesLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    dishesLikedScrollArea->setWidgetResizable( true );
    QScrollArea *sidesLikedScrollArea = ui->sidesScrollArea_1;
    sidesLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    sidesLikedScrollArea->setWidgetResizable( true );
    QScrollArea *desertsLikedScrollArea = ui->desertsScrollArea_1;
    desertsLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    desertsLikedScrollArea->setWidgetResizable( true );
    QScrollArea *drinksLikedScrollArea = ui->drinksScrollArea_1;
    drinksLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    drinksLikedScrollArea->setWidgetResizable( true );


    QScrollArea *startersScrollArea = ui->startersScrollArea_2;
    startersScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    startersScrollArea->setWidgetResizable( true );
    QScrollArea *dishesScrollArea = ui->dishesScrollArea_2;
    dishesScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    dishesScrollArea->setWidgetResizable( true );
    QScrollArea *sidesScrollArea = ui->sidesScrollArea_2;
    sidesScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    sidesScrollArea->setWidgetResizable( true );
    QScrollArea *desertsScrollArea = ui->desertsScrollArea_2;
    desertsScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    desertsScrollArea->setWidgetResizable( true );
    QScrollArea *drinksScrollArea = ui->drinksScrollArea_2;
    drinksScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    drinksScrollArea->setWidgetResizable( true );

    QWidget *widget5 = new QWidget();
    startersLikedScrollArea->setWidget( widget5 );
    startersLikedList = new QVBoxLayout();
    widget5->setLayout( startersLikedList );
    QWidget *widget6 = new QWidget();
    dishesLikedScrollArea->setWidget( widget6 );
    dishesLikedList = new QVBoxLayout();
    widget6->setLayout( dishesLikedList );
    QWidget *widget7 = new QWidget();
    sidesLikedScrollArea->setWidget( widget7 );
    sidesLikedList = new QVBoxLayout();
    widget7->setLayout( sidesLikedList );
    QWidget *widget8 = new QWidget();
    desertsLikedScrollArea->setWidget( widget8 );
    desertsLikedList = new QVBoxLayout();
    widget8->setLayout( desertsLikedList );
    QWidget *widget9 = new QWidget();
    drinksLikedScrollArea->setWidget( widget9 );
    drinksLikedList = new QVBoxLayout();
    widget9->setLayout( drinksLikedList );

    QWidget *widget = new QWidget();
    startersScrollArea->setWidget( widget );
    startersList = new QVBoxLayout();
    widget->setLayout( startersList );
    QWidget *widget1 = new QWidget();
    dishesScrollArea->setWidget( widget1 );
    dishesList = new QVBoxLayout();
    widget1->setLayout( dishesList );
    QWidget *widget2 = new QWidget();
    sidesScrollArea->setWidget( widget2 );
    sidesList = new QVBoxLayout();
    widget2->setLayout( sidesList );
    QWidget *widget3 = new QWidget();
    desertsScrollArea->setWidget( widget3 );
    desertsList = new QVBoxLayout();
    widget3->setLayout( desertsList );
    QWidget *widget4 = new QWidget();
    drinksScrollArea->setWidget( widget4 );
    drinksList = new QVBoxLayout();
    widget4->setLayout( drinksList );

    availableMeal = new QVector<Meal*>();
    Utils::readMealFromJson("mealList.json",availableMeal);

    updateLists();

}

MainWindow::~MainWindow()
{
    delete currentUser;
    delete availableMeal;
    delete ui;
}

void MainWindow::rechargeBtnAction()
{
    RechargeWindow * rw = new RechargeWindow(this);
    rw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    rw->setAttribute(Qt::WA_TranslucentBackground);
    rw->show();
    this->hide();
}

void MainWindow::favoritesBtnAction()
{
    FavoritesWindow * fw = new FavoritesWindow(currentUser,this);
    fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    fw->setAttribute(Qt::WA_TranslucentBackground);
    fw->show();
    this->hide();
}

void MainWindow::bannedBtnAction()
{
    BannedWindow * bw = new BannedWindow(currentUser, this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}

void MainWindow::clearLayout(QVBoxLayout * layout){
    QLayoutItem *child;
    while((child = layout->takeAt(0)) != 0)  {
      delete child->widget();
      delete child;
    }
}

void MainWindow::likedAsChanged(QString name) {
    if(currentUser->favoritesContain(name)) currentUser->removeFavorite(name);
    else currentUser->addFavorite(name);
    updateLists();
}

void MainWindow::bannedAsChanged(QString name){
    if(currentUser->bannedContain(name)) currentUser->removeBanned(name);
    else currentUser->addBanned(name);
    updateLists();
}

void MainWindow::updateLists(){

    clearLayout(startersList);
    clearLayout(dishesList);
    clearLayout(sidesList);
    clearLayout(desertsList);
    clearLayout(drinksList);
    clearLayout(startersLikedList);
    clearLayout(dishesLikedList);
    clearLayout(sidesLikedList);
    clearLayout(desertsLikedList);
    clearLayout(drinksLikedList);

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        switch ((*it)->getType()) {
        case 1:
            if(!currentUser->bannedContain((*it)->getName())) startersList->addWidget(new MealItem(this,*it));
            if(currentUser->favoritesContain((*it)->getName())&&(!currentUser->bannedContain((*it)->getName()))) startersLikedList->addWidget(new MealItem(this,*it));
            break;
        case 2:
            if(!currentUser->bannedContain((*it)->getName())) dishesList->addWidget(new MealItem(this,*it));
            if(currentUser->favoritesContain((*it)->getName())&&(!currentUser->bannedContain((*it)->getName()))) dishesLikedList->addWidget(new MealItem(this,*it));
            break;
        case 3:
            if(!currentUser->bannedContain((*it)->getName())) sidesList->addWidget(new MealItem(this,*it));
            if(currentUser->favoritesContain((*it)->getName())&&(!currentUser->bannedContain((*it)->getName()))) sidesLikedList->addWidget(new MealItem(this,*it));
            break;
        case 4:
            if(!currentUser->bannedContain((*it)->getName())) desertsList->addWidget(new MealItem(this,*it));
            if(currentUser->favoritesContain((*it)->getName())&&(!currentUser->bannedContain((*it)->getName()))) desertsLikedList->addWidget(new MealItem(this,*it));
            break;
        case 5:
            if(!currentUser->bannedContain((*it)->getName())) drinksList->addWidget(new MealItem(this,*it));
            if(currentUser->favoritesContain((*it)->getName())&&(!currentUser->bannedContain((*it)->getName()))) drinksLikedList->addWidget(new MealItem(this,*it));
            break;
        }
    }

    update();
}

void MainWindow::exit()
{
    close();
}
