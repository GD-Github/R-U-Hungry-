#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QVector>
#include <QtGlobal>
#include "meal.h"
#include "mealitem.h"
#include "user.h"
#include "utils.h"
#include "meal_window.h"
#include"bannedwindow.h"
#include"favoriteswindow.h"
#include"rechargewindow.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public Meal_Window
{
    Q_OBJECT

public:
    MainWindow(User * currentUser = nullptr, QWidget *parent = nullptr );
    User * getUser() {return currentUser;}
    void updateLists();
    ~MainWindow();

private:

    QMessageBox * confirmationBox;
    QMessageBox* rechargeBox;
    QMessageBox* tooExpansiveBox;

    Ui::MainWindow *ui;

    void clearLayout(QVBoxLayout * layout);

    QVBoxLayout * startersLikedList = nullptr;
    QVBoxLayout * dishesLikedList = nullptr;
    QVBoxLayout * sidesLikedList = nullptr;
    QVBoxLayout * desertsLikedList = nullptr;
    QVBoxLayout * drinksLikedList = nullptr;

    QVBoxLayout * startersList = nullptr;
    QVBoxLayout * dishesList = nullptr;
    QVBoxLayout * sidesList = nullptr;
    QVBoxLayout * desertsList = nullptr;
    QVBoxLayout * drinksList = nullptr;

    QVBoxLayout * commandList = nullptr;

    QVector<Meal*> * availableMeal;

    QVector<int> * currentCommand;

    User * currentUser;
    FavoritesWindow* fw;
    BannedWindow* bw;
    RechargeWindow* rw;


    double maximumPrice = 5;
    double totalPrice ;


public slots:
    void updateSolde(double);
    void updateMaxPrice(int);
    void rechargeBtnAction();
    void favoritesBtnAction();
    void bannedBtnAction();
    void exit();
    void likedAsChanged(int id) override;
    void bannedAsChanged(int id) override;
    void cartAsChanged(int id) override;
    void updateBanFromFav();
    void updateFavFromBan();
    void updateTotalPrice();
    void command();
    Meal* getMeal(int id);

signals:
    void soldeChanged(double);
};
#endif // MAINWINDOW_H
