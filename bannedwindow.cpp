#include "bannedwindow.h"
#include "ui_bannedwindow.h"



BannedWindow::BannedWindow(User * currentUser, QWidget *parent) :
    Meal_Window(parent),
    ui(new Ui::BannedWindow)
{
    this->currentUser = currentUser;
    ui->setupUi(this);
    ui->usernameLbl->setText(currentUser->getName());


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
    updateLists();
    parentWidget()->show();
    this->hide();
}

void BannedWindow::exit()
{
    close();
}

void BannedWindow::favoritesBtnAction()
{
    updateLists();
    fw->show();
    this->hide();
}

Meal* BannedWindow::getMeal(int id){
    for (int i=0; i<allMeal->length();i++){
        if ((allMeal->at(i))->getId()==id){
            return allMeal->at(i);
        }
    }
    return allMeal->at(0);
}

void BannedWindow::likedAsChanged(int id){
    Meal* selected_meal = getMeal(id);
    if(currentUser->favoritesContain(id)){
        currentUser->removeFavorite(id);
        selected_meal->setIsFavorite(false);
    }
    else{
        currentUser->addFavorite(id);
        selected_meal->setIsFavorite(true);
    }
    updateLists();
    emit(updateFav());
}

void BannedWindow::bannedAsChanged(int id){
    Meal* selected_meal = getMeal(id);
    if(currentUser->bannedContain(id)){
        currentUser->removeBanned(id);
        selected_meal->setIsBanned(false);
    }
    else{
        currentUser->addBanned(id);
        selected_meal->setIsBanned(true);
    }
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
