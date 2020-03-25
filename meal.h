#ifndef MEAL_H
#define MEAL_H

#include <QString>


/*
 Class qui contient les données de chaque plats
*/

class Meal
{
public:
    Meal(QString name,int type, float price, bool isVegetarian, bool containAllergene);
    QString getName() {return name;}
    float getPrice() {return price;}
    bool getIsVegetarian() {return isVegetarian;}
    bool getContainAllergene() {return containAllergene;}
    int getType() {return type;}

private:
    QString name;
    float price;
    bool isVegetarian;
    bool containAllergene;
    int type = 0;
};

#endif // MEAL_H
