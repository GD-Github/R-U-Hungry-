#include "meal.h"

Meal::Meal(int id, QString name,int type, float price, int kCal, bool isVegetarian, bool containAllergene, bool isFavorite, bool isBanned, std::vector<bool> filters, QString description):id(id),name(name),type(type),kCal(kCal),price(price),isVegetarian(isVegetarian),containAllergene(containAllergene),isFavorite(isFavorite),isBanned(isBanned),filters(filters),description(description)
{

}
