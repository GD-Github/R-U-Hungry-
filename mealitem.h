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

/*
 Widget affichant les données d'un plat ( pour mettre dans une liste)
*/

class MealItem : public QWidget
{

    Q_OBJECT

public:
    MealItem(QWidget* parent, Meal * item);

private:
    QWidget * parent;
    Meal * meal;

public slots:
    void changeLiked();
    void changeBanned();
signals:
    void likedAsChanged();
    void bannedAsChanged();
};

#endif // MEALITEM_H
