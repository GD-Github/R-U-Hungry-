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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QVector<Meal*> * m_availableMeal = nullptr);
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


public slots:
    void updateLists();
    void rechargeBtnAction();
    void favoritesBtnAction();
    void bannedBtnAction();
    void exit();
};
#endif // MAINWINDOW_H
