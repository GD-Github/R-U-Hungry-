#include "mealitem.h"

MealItem::MealItem(Meal_Window * parent , Meal * item, bool canBeChecked, bool hasFavoriteBtn, bool hasBannedBtn, bool isChecked) :QWidget()
{
    this->hasBannedBtn = hasBannedBtn;
    this->hasFavoriteBtn = hasFavoriteBtn;
    this->parent = parent;
    this->meal = item;
    this->isChecked = isChecked;
    QHBoxLayout *layout = new QHBoxLayout;

    if(canBeChecked){
        addToCart = new QCheckBox();
        if(isChecked)
            addToCart->setChecked(true);
        layout->addWidget(addToCart, 1);
        connect(addToCart,&QCheckBox::stateChanged,[=]{
            this->isChecked = !this->isChecked;
            parent->cartAsChanged(this->meal->getId());});
    }
    layout->addWidget(new QLabel(item->getName()), 8);
    layout->addWidget(new QLabel(QString::fromStdString(std::to_string(meal->getPrice()).substr(0,4))+" "+QChar(0x20AC)), 2);

    if(this->hasFavoriteBtn){
    QPushButton * likeButton = new QPushButton(QIcon(":/icons/heart.png"),"",this);
    if(item->getFavorite()==false){
        likeButton->setIcon(QIcon(":/icons/empty_heart.png"));
    }else{
        likeButton->setIcon(QIcon(":/icons/heart.png"));
    }
    layout->addWidget(likeButton, 1);
    connect(likeButton, &QPushButton::clicked, [=]{ parent->likedAsChanged(this->meal->getId() ); });
    }
    if(this->hasBannedBtn){
    QPushButton * bannedButton = new QPushButton(QIcon(":/icons/banned.png"),"",this);
    if(item->getBanned()==false){
        bannedButton->setIcon(QIcon(":/icons/empty_banned.png"));
    }else{
        bannedButton->setIcon(QIcon(":/icons/banned.png"));
    }
    layout->addWidget(bannedButton, 1);
    connect(bannedButton, &QPushButton::clicked, [=]{ parent->bannedAsChanged(this->meal->getId() ); });
    }
    this->setLayout(layout);

}


void MealItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "test";
}
