#include "meal.h"

Meal::Meal(int id, QString name,int type, float price, int kCal, bool isVegetarian, bool containAllergene, bool isFavorite, bool isBanned, std::vector<bool> filters, QString description, int quantity):id(id),name(name),type(type),kCal(kCal),price(price),isVegetarian(isVegetarian),containAllergene(containAllergene),isFavorite(isFavorite),isBanned(isBanned),filters(filters),description(description), quantity(quantity)
{

}

void Meal::plusQuantity(){
    if (quantity==1){
        quantity+=1;
    }else if(quantity==2){
        quantity+=1;
    }
}

void Meal::lessQuantity(){
    if (quantity==3){
        quantity-=1;
    }else if (quantity==2){
        quantity-=1;
    }
}
