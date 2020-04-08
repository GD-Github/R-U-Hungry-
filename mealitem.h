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
    MealItem(Meal_Window* parent, Meal * item, bool canBeChecked = false, bool hasFavoriteBtn = true, bool hasBannedBtn = true, bool hasArrowBtn = true ,bool isChecked = false, bool hasQuantity=false);
    Meal * getMeal() {return meal;}
    bool getIsChecked(){return isChecked;}
    void changeHasQuantity(){if (hasQuantity){this->hasQuantity=false;}else{this->hasQuantity=true;}}

public slots:
    void displayInfo();
    void plusQuantity();
    void lessQuantity();

private:
    Meal_Window * parent;
    Meal * meal;
    bool isChecked = false;
    bool hasArrowBtn = true;
    bool hasFavoriteBtn = true;
    bool hasBannedBtn = true;
    bool showMore = false;
    QCheckBox* addToCart;
    QLabel* descrip;
    QLabel* kcal;
    QPushButton * infoButton;
    int quantity = 2;
    QPushButton * plusButton;
    QPushButton * lessButton;
    bool hasQuantity = false;
    QPushButton* quantityIcon;

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void likedAsChanged();
    void bannedAsChanged();
    void selectedChanged(int id);
};

#endif // MEALITEM_H
