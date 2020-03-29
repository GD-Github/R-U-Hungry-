#ifndef MEALITEM_H
#define MEALITEM_H

#include <QListWidgetItem>
#include <QJsonObject>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QDebug>
#include <QCheckBox>
#include "meal.h"
#include "meal_window.h"

/*
 Widget affichant les données d'un plat ( pour mettre dans une liste)
*/

class MealItem : public QWidget
{

    Q_OBJECT

public:
    MealItem(Meal_Window* parent, Meal * item, bool canBeChecked = false, bool hasFavoriteBtn = true, bool hasBannedBtn = true,bool isChecked = false);
    Meal * getMeal() {return meal;}
    bool getIsChecked(){return isChecked;}

private:
    Meal_Window * parent;
    Meal * meal;
    bool isChecked = false;
    bool hasFavoriteBtn = true;
    bool hasBannedBtn = true;
    bool showMore = false;
    QCheckBox* addToCart;
    QVBoxLayout* vLayout;

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void likedAsChanged();
    void bannedAsChanged();
    void selectedChanged(int id);
};

#endif // MEALITEM_H
