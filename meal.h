#ifndef MEAL_H
#define MEAL_H

#include <QString>
#include <vector>
using namespace std;


/*
 Class qui contient les données de chaque plats
*/

class Meal
{
public:
    Meal(int id, QString name,int type, float price, int kCal, bool isVegetarian, bool containAllergene, bool isFavorite, bool isBanned, std::vector<bool> filters, QString description);
    int getId() {return id;}
    QString getName() {return name;}
    float getPrice() {return price;}
    int getkCal(){return kCal;}
    bool getIsVegetarian() {return isVegetarian;}
    bool getContainAllergene() {return containAllergene;}
    int getType() {return type;}
    bool getFavorite(){return isFavorite;}
    bool getBanned(){return isBanned;}
    QString getDescription(){return description;}
    void setIsFavorite(bool new_status){this->isFavorite=new_status;}
    void setIsBanned(bool status){this->isBanned=status;}
    void setFilters(std::vector<bool> new_filters){this->filters=new_filters;}
    int getQuantity(){return quantity;}
    void plusQuantity();
    void lessQuantity();
    std::vector<bool> getFilters(){return filters;}

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
    int quantity = 2;
    QString description;
    std::vector<bool> filters = {false,false,false,false}; //index 0 for vege, 1 for halal, 2 for free allergens, 3 for free gluten
};

#endif // MEAL_H
