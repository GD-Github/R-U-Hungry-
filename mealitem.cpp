#include "mealitem.h"

MealItem::MealItem(Meal_Window * parent , Meal * item) :QWidget()
{
    this->parent = parent;
    this->meal = item;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(new QLabel(item->getName()));

    QPushButton * likeButton = new QPushButton(QIcon(":/icons/heart.png"),"",this);
    QPushButton * bannedButton = new QPushButton(QIcon(":/icons/banned.png"),"",this);

    layout->addWidget(likeButton);
    layout->addWidget(bannedButton);
    this->setLayout(layout);

    connect(likeButton, &QPushButton::clicked, [=]{ parent->likedAsChanged(this->meal->getName() ); });
    connect(bannedButton, &QPushButton::clicked, [=]{ parent->bannedAsChanged(this->meal->getName() ); });
}


void MealItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "test";
}
