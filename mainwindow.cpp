#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>



MainWindow::MainWindow(User* currentUser,QWidget *parent)
    : Meal_Window(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* confirmBtn = new QPushButton(tr("Confirmer"),this);
    QPushButton* cancelBtn = new QPushButton(tr("Annuler"),this);
    confirmationBox = new QMessageBox(this);
    confirmationBox->setWindowFlags((Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint) & ~Qt::WindowCloseButtonHint);

    //confirmationBox->setAttribute(Qt::WA_TranslucentBackground);
    confirmationBox->setIcon(QMessageBox::Warning);
    confirmationBox->addButton(cancelBtn,QMessageBox::NoRole);
    confirmationBox->addButton(confirmBtn,QMessageBox::YesRole);
    confirmationBox->setText(QString("Êtes vous sûr de vouloir commander?"));
    confirmationBox->setWindowTitle(QString("Confirmation"));

    QPushButton* cancelBtn2 = new QPushButton(tr("Annuler"),this);
    QPushButton* rechargeBtn = new QPushButton(tr("Recharger"),this);
    rechargeBox = new QMessageBox(this);
    rechargeBox->setIcon(QMessageBox::Warning);
    rechargeBox->setWindowFlags((Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint) & ~Qt::WindowCloseButtonHint);
    rechargeBox->addButton(cancelBtn2,QMessageBox::NoRole);
    rechargeBox->addButton(rechargeBtn,QMessageBox::YesRole);
    rechargeBox->setText(QString("Vous n'avez pas assez d'argent, voulez vous recharger?"));
    rechargeBox->setWindowTitle(QString("Oups !"));

    QPushButton* ouiBtn = new QPushButton(tr("Oui"),this);
    QPushButton* nonBtn = new QPushButton(tr("Non"),this);
    tooExpansiveBox = new QMessageBox(this);
    tooExpansiveBox->setIcon(QMessageBox::Warning);
    tooExpansiveBox->setWindowFlags((Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint) & ~Qt::WindowCloseButtonHint);
    tooExpansiveBox->addButton(nonBtn,QMessageBox::NoRole);
    tooExpansiveBox->addButton(ouiBtn,QMessageBox::YesRole);
    tooExpansiveBox->setText(QString("Si vous selectionnez cet item, le prix de votre commande dépassera le prix maximum que vous avez fixé. Continuez ?"));
    tooExpansiveBox->setWindowTitle(QString("Oups !"));


    connect(ui->rechargeBtn,SIGNAL(clicked()),this,SLOT(rechargeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    connect(ui->maxPriceSlider,SIGNAL(valueChanged(int)),this,SLOT(updateMaxPrice(int)));

    connect(ui->commandBtn,SIGNAL(clicked()),this,SLOT(command()));

     this->currentUser = currentUser;


    ui->usernameLbl->setText(currentUser->getName());

    BannedWindow* bw = new BannedWindow(this->currentUser,this);
     bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
     bw->setAttribute(Qt::WA_TranslucentBackground);
    RechargeWindow* rw = new RechargeWindow(this->currentUser,this);
     rw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
     rw->setAttribute(Qt::WA_TranslucentBackground);
     FavoritesWindow* fw = new FavoritesWindow(this->currentUser,this);
      fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
      fw->setAttribute(Qt::WA_TranslucentBackground);

     this->bw = bw;
     this->rw = rw;
     this->fw = fw;

     rw->setBw(bw);
     rw->setFw(fw);

     fw->setBw(bw);

     bw->setFw(fw);
     connect(rw,SIGNAL(soldeChanged(double)),this,SLOT(updateSolde(double)));
     connect(this,SIGNAL(soldeChanged(double)),this,SLOT(updateSolde(double)));

     connect(fw,SIGNAL(updateBanned()),this,SLOT(updateBanFromFav()));
     connect(bw,SIGNAL(updateFav()),this,SLOT(updateFavFromBan()));

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
    startersLikedList->setAlignment(Qt::AlignTop);
    widget5->setLayout( startersLikedList );
    QWidget *widget6 = new QWidget();
    dishesLikedScrollArea->setWidget( widget6 );
    dishesLikedList = new QVBoxLayout();
    dishesLikedList->setAlignment(Qt::AlignTop);
    widget6->setLayout( dishesLikedList );
    QWidget *widget7 = new QWidget();
    sidesLikedScrollArea->setWidget( widget7 );
    sidesLikedList = new QVBoxLayout();
    sidesLikedList->setAlignment(Qt::AlignTop);
    widget7->setLayout( sidesLikedList );
    QWidget *widget8 = new QWidget();
    desertsLikedScrollArea->setWidget( widget8 );
    desertsLikedList = new QVBoxLayout();
    desertsLikedList->setAlignment(Qt::AlignTop);
    widget8->setLayout( desertsLikedList );
    QWidget *widget9 = new QWidget();
    drinksLikedScrollArea->setWidget( widget9 );
    drinksLikedList = new QVBoxLayout();
    drinksLikedList->setAlignment(Qt::AlignTop);
    widget9->setLayout( drinksLikedList );

    QWidget *widget = new QWidget();
    startersScrollArea->setWidget( widget );
    startersList = new QVBoxLayout();
    startersList->setAlignment(Qt::AlignTop);
    widget->setLayout( startersList );
    QWidget *widget1 = new QWidget();
    dishesScrollArea->setWidget( widget1 );
    dishesList = new QVBoxLayout();
    dishesList->setAlignment(Qt::AlignTop);
    widget1->setLayout( dishesList );
    QWidget *widget2 = new QWidget();
    sidesScrollArea->setWidget( widget2 );
    sidesList = new QVBoxLayout();
    sidesList->setAlignment(Qt::AlignTop);
    widget2->setLayout( sidesList );
    QWidget *widget3 = new QWidget();
    desertsScrollArea->setWidget( widget3 );
    desertsList = new QVBoxLayout();
    desertsList->setAlignment(Qt::AlignTop);
    widget3->setLayout( desertsList );
    QWidget *widget4 = new QWidget();
    drinksScrollArea->setWidget( widget4 );
    drinksList = new QVBoxLayout();
    drinksList->setAlignment(Qt::AlignTop);
    widget4->setLayout( drinksList );


    QScrollArea *commandScrollArea = ui->commandScrollArea;
    commandScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    commandScrollArea->setWidgetResizable( true );

    QWidget *widget10 = new QWidget();
    commandScrollArea->setWidget( widget10 );
    commandList = new QVBoxLayout();
    commandList->setAlignment(Qt::AlignTop);
    widget10->setLayout( commandList );

    currentCommand = new QVector<int>();
    availableMeal = new QVector<Meal*>();
    Utils::readMealFromIndexFile("availableMeal.txt",availableMeal);

    updateTotalPrice();
    updateLists();
    updateSolde(currentUser->getSolde());
    fw->setAllMeal(availableMeal);
    bw->setAllMeal(availableMeal);

}

MainWindow::~MainWindow()
{
    delete currentUser;
    delete availableMeal;
    delete ui;
}

void MainWindow::rechargeBtnAction()
{
    rw->show();
    this->hide();
}

void MainWindow::favoritesBtnAction()
{
    fw->updateLists();
    bw->updateLists();
    fw->show();    
    this->hide();
}

void MainWindow::bannedBtnAction()
{
    bw->updateLists();
    fw->updateLists();
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

Meal* MainWindow::getMeal(int id){
    for (int i=0; i<availableMeal->length();i++){
        if ((availableMeal->at(i))->getId()==id){
            return availableMeal->at(i);
        }
    }
    return availableMeal->at(0);
}

void MainWindow::likedAsChanged(int id) {
    Meal* selected_meal = getMeal(id);
    if(currentUser->favoritesContain(id)){
        currentUser->removeFavorite(id);
        selected_meal->setIsFavorite(false);
    }
    else {
        currentUser->addFavorite(id);
        selected_meal->setIsFavorite(true);
    }
    updateLists();
    fw->updateLists();

}

void MainWindow::bannedAsChanged(int id){
    Meal* selected_meal = getMeal(id);
    if(currentUser->bannedContain(id)){
        selected_meal->setIsBanned(false);
        currentUser->removeBanned(id);
    }
    else{
        selected_meal->setIsBanned(true);
        currentUser->addBanned(id);
    }
    updateLists();
    bw->updateLists();

}

void MainWindow::cartAsChanged(int id){
    if(currentCommand->contains(id)){
        currentCommand->removeAll(id);
    } else{
        currentCommand->append(id);
    }
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

    clearLayout(commandList);

    totalPrice = 0;

    for(int i = 0;i < currentCommand->size();i++)  {
    int selectedItem = currentCommand->at(i);
    Meal* meal = availableMeal->at(selectedItem-1);
    if(totalPrice+ meal->getPrice() < maximumPrice){
    commandList->addWidget(new MealItem(this,meal,true,false,false));
    totalPrice+=meal->getPrice();            }
    else{
        if(i == currentCommand->size()-1){
        int val = tooExpansiveBox->exec();
        if(val ==0)
        {
            currentCommand->remove(i);
        }
        else{
        commandList->addWidget(new MealItem(this,meal,true,false,false));
        totalPrice+= meal->getPrice();    }}
        else{
            commandList->addWidget(new MealItem(this,meal,true,false,false));
            totalPrice+= meal->getPrice();
        }

    }

    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){


        switch ((*it)->getType()) {
        case 1:
            if(!currentUser->bannedContain((*it)->getId())) startersList->addWidget(new MealItem(this,*it,true));
            if(currentUser->favoritesContain((*it)->getId())&&(!currentUser->bannedContain((*it)->getId()))) startersLikedList->addWidget(new MealItem(this,*it,true));
            break;
        case 2:
            if(!currentUser->bannedContain((*it)->getId())) dishesList->addWidget(new MealItem(this,*it,true));
            if(currentUser->favoritesContain((*it)->getId())&&(!currentUser->bannedContain((*it)->getId()))) dishesLikedList->addWidget(new MealItem(this,*it,true));
            break;
        case 3:
            if(!currentUser->bannedContain((*it)->getId())) sidesList->addWidget(new MealItem(this,*it,true));
            if(currentUser->favoritesContain((*it)->getId())&&(!currentUser->bannedContain((*it)->getId()))) sidesLikedList->addWidget(new MealItem(this,*it,true));
            break;
        case 4:
            if(!currentUser->bannedContain((*it)->getId())) desertsList->addWidget(new MealItem(this,*it,true));
            if(currentUser->favoritesContain((*it)->getId())&&(!currentUser->bannedContain((*it)->getId()))) desertsLikedList->addWidget(new MealItem(this,*it,true));
            break;
        case 5:
            if(!currentUser->bannedContain((*it)->getId())) drinksList->addWidget(new MealItem(this,*it,true));
            if(currentUser->favoritesContain((*it)->getId())&&(!currentUser->bannedContain((*it)->getId()))) drinksLikedList->addWidget(new MealItem(this,*it,true));
            break;
        }
    }
    updateTotalPrice();
    update();
}

void MainWindow::updateTotalPrice(){
    QString totalStr;
    if(totalPrice<10)
    totalStr = QString::fromStdString(std::to_string(totalPrice).substr(0,4) + " ") +  QChar(0x20AC);
    else
    totalStr = QString::fromStdString(std::to_string(totalPrice).substr(0,5) + " ") +  QChar(0x20AC);

    ui->totalTxt->setText(totalStr);
}


void MainWindow::updateMaxPrice(int value){
QString str = QString::fromStdString(std::to_string((30+5*value)/10)+ "." + std::to_string(30+5*value-(30+5*value)/10*10)+ " ") + QChar(0x20AC);
ui->maxPrice->setText(str);
update();
maximumPrice = 3 +0.5*value;
}

void MainWindow::updateSolde(double value){
    double rounded = qRound(value * 100);
    QString str;
    if (rounded >=1000)
        str = QString::fromStdString(std::to_string(rounded).substr(0,2) + "." + std::to_string(rounded).substr(2,2) + " ") +QChar(0x20AC);
    else
        str = QString::fromStdString(std::to_string(rounded).substr(0,1) + "." + std::to_string(rounded).substr(1,2) +" ") +QChar(0x20AC);

    ui->balanceTxt->setText(str);
    update();
}

void MainWindow::updateFavFromBan(){
    this->updateLists();
    fw->updateLists();
}

void MainWindow::updateBanFromFav(){
    this->updateLists();
    bw->updateLists();
}

void MainWindow::command(){
    if(currentUser->getSolde()>= this->totalPrice){
    int val = confirmationBox->exec();
    if(val ==1){
    currentUser->removeSolde(totalPrice);
    emit(soldeChanged(currentUser->getSolde()));
    update();}}
    else{
    int val = rechargeBox->exec();
    if (val == 1){
        rw->show();
        this->hide();    }
    }
    currentCommand->clear();
    updateLists();
}
void MainWindow::exit()
{
    close();
}
