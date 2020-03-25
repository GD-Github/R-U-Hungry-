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
    explicit FavoritesWindow(User * currentUser, QWidget *parent = nullptr);
    ~FavoritesWindow();
    void updateLists();

private:
    Ui::FavoritesWindow *ui;
    QVector<Meal*> * availableMeal;
    QVBoxLayout * mealLikedList = nullptr;
    User * currentUser;

public slots:
    void homeBtnAction();
    void bannedBtnAction();
    void exit();
    void likedAsChanged(QString name) override;
    void bannedAsChanged(QString name) override;
};

#endif // FAVORITESWINDOW_H
