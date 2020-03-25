#include "favoriteswindow.h"
#include "ui_favoriteswindow.h"

#include "mainwindow.h"
#include "bannedwindow.h"

FavoritesWindow::FavoritesWindow(User * currentUser, QWidget *parent) :
    Meal_Window(parent),
    ui(new Ui::FavoritesWindow)
{
    this->currentUser = currentUser;
    currentUser->showFavorite();
    ui->setupUi(this);

    this->availableMeal = new QVector<Meal*>();
    Utils::readMealFromJson("mealList.json",availableMeal);

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
    MainWindow * w = new MainWindow(this,currentUser);
    w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w->setAttribute(Qt::WA_TranslucentBackground);
    w->show();
    this->hide();
}

void FavoritesWindow::bannedBtnAction()
{
    BannedWindow * bw = new BannedWindow(currentUser,this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}

void FavoritesWindow::exit()
{
    close();
}

void FavoritesWindow::likedAsChanged(QString name){
    if(currentUser->favoritesContain(name)) currentUser->removeFavorite(name);
    else currentUser->addFavorite(name);
    updateLists();
}

void FavoritesWindow::bannedAsChanged(QString name){
    if(currentUser->bannedContain(name)) currentUser->removeBanned(name);
    else currentUser->addBanned(name);
    updateLists();
}

void FavoritesWindow::updateLists(){

    QLayoutItem *childLiked;
    while ((childLiked = mealLikedList->takeAt(0)) != 0) {
        delete childLiked->widget();
        delete childLiked;
    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        if(currentUser->favoritesContain((*it)->getName())) mealLikedList->addWidget(new MealItem(this,*it));
    }

    update();
}
