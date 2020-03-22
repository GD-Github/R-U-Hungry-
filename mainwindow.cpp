#include "mainwindow.h"
#include "ui_mainwindow.h"



#include "rechargewindow.h"
#include "favoriteswindow.h"
#include "bannedwindow.h"

MainWindow::MainWindow(QWidget *parent, QVector<Meal*> * m_availableMeal)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rechargeBtn,SIGNAL(clicked()),this,SLOT(rechargeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    if(m_availableMeal == nullptr){
        QString json_string;
        QFile file;
        this->availableMeal = new QVector<Meal*>();

        QVBoxLayout * mealList = ui->mealList;
        file.setFileName(":/mealList.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        json_string = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(json_string.toUtf8());
        QJsonArray jsonArray = doc.array();
        for(auto it = jsonArray.begin() ; it!=jsonArray.end() ; ++it){
            QJsonObject mealObject = it->toObject();
            availableMeal->append(new Meal(mealObject["name"].toString(),(float)mealObject["price"].toDouble(),false,false));
            mealList->addWidget(new MealItem(this,availableMeal->last()));
        }
    }else{
        availableMeal = m_availableMeal;
        updateLists();
    }

}

MainWindow::~MainWindow()
{
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
    FavoritesWindow * fw = new FavoritesWindow(availableMeal,this);
    fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    fw->setAttribute(Qt::WA_TranslucentBackground);
    fw->show();
    this->hide();
}

void MainWindow::bannedBtnAction()
{
    BannedWindow * bw = new BannedWindow(availableMeal, this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}

void MainWindow::updateLists(){
    QVBoxLayout * likedList = ui->likedMeal;
    QLayoutItem *childMeal;
    QVBoxLayout * mealList = ui->mealList;
    QLayoutItem *childLiked;
    while ((childMeal = mealList->takeAt(0)) != 0) {
        QWidget* stepchild;
        stepchild=childMeal->widget();
        delete stepchild;
        delete childMeal;
    }
    while ((childLiked = likedList->takeAt(0)) != 0) {
        QWidget* stepchild;
        stepchild=childLiked->widget();
        delete stepchild;
        delete childLiked;
    }

    for(auto it=availableMeal->begin() ; it!=availableMeal->end() ; ++it){
        if(!(*it)->getIsBanned()) mealList->addWidget(new MealItem(this,*it));
        if((*it)->getIsLiked()&&(!(*it)->getIsBanned())) likedList->addWidget(new MealItem(this,*it));
    }

    update();
}

void MainWindow::exit()
{
    close();
}
