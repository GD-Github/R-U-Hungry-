#ifndef MEAL_H
#define MEAL_H

#include <QString>


/*
 Class qui contient les données de chaque plats
*/

class Meal
{
public:
    Meal(QString name, float price, bool isVegetarian, bool containAllergene);
    QString getName() {return name;}
private:
    QString name;
    float price;
    bool isVegetarian;
    bool containAllergene;
};

#endif // MEAL_H
