#include "bannedwindow.h"
#include "ui_bannedwindow.h"

#include "mainwindow.h"
#include "favoriteswindow.h"

BannedWindow::BannedWindow(User * currentUser, QWidget *parent) :
    Meal_Window(parent),
    ui(new Ui::BannedWindow)
{
    this->currentUser = currentUser;
    ui->setupUi(this);

    this->allMeal = new QVector<Meal*>();
    Utils::readMealFromJson(allMeal);

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
    MainWindow * w = new MainWindow(currentUser,this);
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
    FavoritesWindow * fw = new FavoritesWindow(currentUser,this);
    fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    fw->setAttribute(Qt::WA_TranslucentBackground);
    fw->show();
    this->hide();
}

void BannedWindow::likedAsChanged(int id){
    if(currentUser->favoritesContain(id)) currentUser->removeFavorite(id);
    else currentUser->addFavorite(id);
    updateLists();
}

void BannedWindow::bannedAsChanged(int id){
    if(currentUser->bannedContain(id)) currentUser->removeBanned(id);
    else currentUser->addBanned(id);
    updateLists();
}

void BannedWindow::updateLists(){

    QLayoutItem *childBanned;
    while ((childBanned = mealBannedList->takeAt(0)) != 0) {
        delete childBanned->widget();
        delete childBanned;
    }

    for(auto it=allMeal->begin() ; it!=allMeal->end() ; ++it){
        if(currentUser->bannedContain((*it)->getId())) mealBannedList->addWidget(new MealItem(this,*it));
    }

    update();
}
