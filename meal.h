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
    float getPrice() {return price;}
    bool getIsVegetarian() {return isVegetarian;}
    bool getContainAllergene() {return containAllergene;}
    bool getIsLiked() {return isLiked;}
    bool getIsBanned() {return isBanned;}
    void setIsLiked(bool isLiked) {this->isLiked = isLiked;}
    void setIsBanned(bool isBanned) {this->isBanned = isBanned;}
private:
    QString name;
    float price;
    bool isVegetarian;
    bool containAllergene;
    bool isLiked;
    bool isBanned;
};

#endif // MEAL_H
