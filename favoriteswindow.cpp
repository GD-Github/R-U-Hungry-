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
    parentWidget()->show();
    this->hide();
}

void FavoritesWindow::bannedBtnAction()
{
    bw->show();
    this->hide();
}

void FavoritesWindow::exit()
{
    close();
}

void FavoritesWindow::likedAsChanged(int id){
    if(currentUser->favoritesContain(id)) currentUser->removeFavorite(id);
    else currentUser->addFavorite(id);
    updateLists();

}

void FavoritesWindow::bannedAsChanged(int id){
    if(currentUser->bannedContain(id)) currentUser->removeBanned(id);
    else currentUser->addBanned(id);
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
        if(currentUser->favoritesContain((*it)->getId())) mealLikedList->addWidget(new MealItem(this,*it));
    }

    update();
}
