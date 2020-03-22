#ifndef FAVORITESWINDOW_H
#define FAVORITESWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVector>
#include "meal.h"
#include "mealitem.h"

namespace Ui {
class FavoritesWindow;
}

class FavoritesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FavoritesWindow( QVector<Meal*> * availableMeal, QWidget *parent = nullptr);
    ~FavoritesWindow();

private:
    Ui::FavoritesWindow *ui;
    QVector<Meal*> * availableMeal;
public slots:
    void homeBtnAction();
    void bannedBtnAction();
    void exit();
    void updateLists();
};

#endif // FAVORITESWINDOW_H
