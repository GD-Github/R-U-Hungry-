#ifndef MEALITEM_H
#define MEALITEM_H

#include <QListWidgetItem>
#include <QJsonObject>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include "meal.h"

/*
 Widget affichant les données d'un plat ( pour mettre dans une liste)
*/

class MealItem : public QWidget
{

    Q_OBJECT

public:
    MealItem(QWidget* parent, Meal item);
};

#endif // MEALITEM_H
