#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mealitem.h"


#include "rechargewindow.h"
#include "favoriteswindow.h"
#include "bannedwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rechargeBtn,SIGNAL(clicked()),this,SLOT(rechargeBtnAction()));
    connect(ui->favoritesBtn,SIGNAL(clicked()),this,SLOT(favoritesBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));

    QString json_string;
    QFile file;
    availableMeal = new QVector<Meal*>();
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
}

MainWindow::~MainWindow()
{
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
    FavoritesWindow * fw = new FavoritesWindow(this);
    fw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    fw->setAttribute(Qt::WA_TranslucentBackground);
    fw->show();
    this->hide();
}

void MainWindow::bannedBtnAction()
{
    BannedWindow * bw = new BannedWindow(this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}

void MainWindow::exit()
{
    close();
}
