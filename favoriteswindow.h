#ifndef FAVORITESWINDOW_H
#define FAVORITESWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVector>
#include "meal.h"
#include "mealitem.h"
#include "utils.h"
#include "meal_window.h"


namespace Ui {
class FavoritesWindow;
}

class FavoritesWindow : public Meal_Window
{
    Q_OBJECT

public:
    explicit FavoritesWindow(User * currentUser = nullptr, QWidget *parent = nullptr);
    ~FavoritesWindow();
    void updateLists();
    void setBw(QMainWindow* bw){this->bw =bw;}

private:
    Ui::FavoritesWindow *ui;
    QVector<Meal*> * allMeal;
    QVBoxLayout * mealLikedList = nullptr;
    User * currentUser;
    QMainWindow* bw;

public slots:
    void homeBtnAction();
    void bannedBtnAction();
    void exit();
    void likedAsChanged(int id) override;
    void bannedAsChanged(int id) override;
};

#endif // FAVORITESWINDOW_H
