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
    connect(this,SIGNAL(likedAsChanged()),parent,SLOT(updateLists()));
    connect(this,SIGNAL(bannedAsChanged()),parent,SLOT(updateLists()));
}

void MealItem::changeLiked(){
    qWarning() << "like clicked";
    bool state = !meal->getIsLiked();
    meal->setIsLiked(state);
    emit likedAsChanged();
}

void MealItem::changeBanned(){
    qWarning() << "banned clicked";
    meal->setIsBanned(!meal->getIsBanned());
    emit bannedAsChanged();
}

void MealItem::mousePressEvent(QMouseEvent *event)
{

}
