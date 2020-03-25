#ifndef MEALITEM_H
#define MEALITEM_H

#include <QListWidgetItem>
#include <QJsonObject>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QDebug>
#include "meal.h"
#include "meal_window.h"

/*
 Widget affichant les données d'un plat ( pour mettre dans une liste)
*/

class MealItem : public QWidget
{

    Q_OBJECT

public:
    MealItem(Meal_Window* parent, Meal * item);
    Meal * getMeal() {return meal;}

private:
    Meal_Window * parent;
    Meal * meal;

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void likedAsChanged();
    void bannedAsChanged();
};

#endif // MEALITEM_H
