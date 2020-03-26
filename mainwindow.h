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
#include "meal.h"
#include "mealitem.h"
#include "user.h"
#include "utils.h"
#include "meal_window.h"

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

    QVector<Meal*> * availableMeal;

    User * currentUser;


public slots:

    void rechargeBtnAction();
    void favoritesBtnAction();
    void bannedBtnAction();
    void exit();
    void likedAsChanged(int id) override;
    void bannedAsChanged(int id) override;
};
#endif // MAINWINDOW_H
