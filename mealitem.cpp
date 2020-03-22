#include "mealitem.h"

MealItem::MealItem(QWidget * parent , Meal * item) :QWidget()
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

    connect(likeButton,SIGNAL(clicked()),this,SLOT(changeLiked()));
    connect(bannedButton,SIGNAL(clicked()),this,SLOT(changeBanned()));
}

void MealItem::changeLiked(){
    qWarning() << "liked";
    meal->setIsLiked(!meal->getIsLiked());
    emit likedAsChanged();
}

void MealItem::changeBanned(){
    meal->setIsBanned(!meal->getIsBanned());
    emit bannedAsChanged();
}
