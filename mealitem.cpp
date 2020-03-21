#include "mealitem.h"

MealItem::MealItem(QWidget * parent , Meal item) :QWidget()
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(new QLabel(item.getName()));
    layout->addWidget(new QPushButton(QIcon(":/icons/heart.png"),"",this));
    this->setLayout(layout);
}
