#include "favoriteswindow.h"
#include "ui_favoriteswindow.h"



FavoritesWindow::FavoritesWindow(User * currentUser, QWidget *parent) :
    Meal_Window(parent),
    ui(new Ui::FavoritesWindow)
{
    this->currentUser = currentUser;
    currentUser->showFavorite();

    ui->setupUi(this);
    ui->usernameLbl->setText(currentUser->getName());

    this->allMeal = new QVector<Meal*>();
    Utils::readMealFromJson(allMeal);

    connect(ui->homeBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    QScrollArea *mealLikedScrollArea = ui->favoriteMealArea;
    mealLikedScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    mealLikedScrollArea->setWidgetResizable( true );

    QWidget *widget = new QWidget();
    mealLikedScrollArea->setWidget( widget );
    mealLikedList = new QVBoxLayout();
    mealLikedList->setAlignment(Qt::AlignTop);
    widget->setLayout( mealLikedList );

    updateLists();
}

FavoritesWindow::~FavoritesWindow()
{
    delete allMeal;
    delete ui;
}

void FavoritesWindow::homeBtnAction()
{
    updateLists();
    parentWidget()->show();
    this->hide();
}

void FavoritesWindow::bannedBtnAction()
{
    updateLists();
    bw->show();
    this->hide();
}

void FavoritesWindow::exit()
{
    close();
}

Meal* FavoritesWindow::getMeal(int id){
    for (int i=0; i<allMeal->length();i++){
        if ((allMeal->at(i))->getId()==id){
            return allMeal->at(i);
        }
    }
    return allMeal->at(0);
}

void FavoritesWindow::likedAsChanged(int id){
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

}

void FavoritesWindow::bannedAsChanged(int id){
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
    emit(updateBanned());
}

void FavoritesWindow::updateLists(){

    QLayoutItem *childLiked;
    while ((childLiked = mealLikedList->takeAt(0)) != 0) {
        delete childLiked->widget();
        delete childLiked;
    }

    for(auto it=allMeal->begin() ; it!=allMeal->end() ; ++it){
        if(currentUser->favoritesContain((*it)->getId())) mealLikedList->addWidget(new MealItem(this,*it,false,true,false));
    }
    emit(updateBanned());
    update();
}
