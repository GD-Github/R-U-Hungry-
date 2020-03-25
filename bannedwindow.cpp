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

    this->availableMeal = new QVector<Meal*>();
    Utils::readMealFromJson("mealList.json",availableMeal);

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
    MainWindow * w = new MainWindow(this,currentUser);
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

void BannedWindow::likedAsChanged(QString name){
    if(currentUser->favoritesContain(name)) currentUser->removeFavorite(name);
    else currentUser->addFavorite(name);
    updateLists();
}

void BannedWindow::bannedAsChanged(QString name){
    if(currentUser->bannedContain(name)) currentUser->removeBanned(name);
    else currentUser->addBanned(name);
    updateLists();
}

void BannedWindow::updateLists(){

    QLayoutItem *childBanned;
    while ((childBanned = mealBannedList->takeAt(0)) != 0) {
        delete childBanned->widget();
        delete childBanned;
    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        if(currentUser->bannedContain((*it)->getName())) mealBannedList->addWidget(new MealItem(this,*it));
    }

    update();
}
