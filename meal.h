#ifndef MEAL_H
#define MEAL_H

#include <QString>


/*
 Class qui contient les données de chaque plats
*/

class Meal
{
public:
    Meal(int id, QString name,int type, float price, int kCal, bool isVegetarian, bool containAllergene, bool isFavorite=false, bool isBanned=false);
    int getId() {return id;}
    QString getName() {return name;}
    float getPrice() {return price;}
    bool getIsVegetarian() {return isVegetarian;}
    bool getContainAllergene() {return containAllergene;}
    int getType() {return type;}
    bool getFavorite(){return isFavorite;}
    bool getBanned(){return isBanned;}
    void setIsFavorite(bool new_status){this->isFavorite=new_status;}
    void setIsBanned(bool status){this->isBanned=status;}

private:
    int id;
    QString name;
    int kCal;
    float price;
    bool isVegetarian;
    bool containAllergene;
    int type = 0;
    bool isFavorite;
    bool isBanned;
};

#endif // MEAL_H
