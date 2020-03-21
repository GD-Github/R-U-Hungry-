#include "favoriteswindow.h"
#include "ui_favoriteswindow.h"

#include "mainwindow.h"
#include "bannedwindow.h"

FavoritesWindow::FavoritesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FavoritesWindow)
{
    ui->setupUi(this);

    connect(ui->homeBtn,SIGNAL(clicked()),this,SLOT(homeBtnAction()));
    connect(ui->bannedBtn,SIGNAL(clicked()),this,SLOT(bannedBtnAction()));
    connect(ui->logoutBtn,SIGNAL(clicked()),this,SLOT(exit()));
}

FavoritesWindow::~FavoritesWindow()
{
    delete ui;
}

void FavoritesWindow::homeBtnAction()
{
    MainWindow * w = new MainWindow(this);
    w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w->setAttribute(Qt::WA_TranslucentBackground);
    w->show();
    this->hide();
}

void FavoritesWindow::bannedBtnAction()
{
    BannedWindow * bw = new BannedWindow(this);
    bw->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    bw->setAttribute(Qt::WA_TranslucentBackground);
    bw->show();
    this->hide();
}

void FavoritesWindow::exit()
{
    close();
}
