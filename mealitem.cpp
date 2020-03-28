#include "mealitem.h"

MealItem::MealItem(Meal_Window * parent , Meal * item, bool canBeChecked, bool hasFavoriteBtn, bool hasBannedBtn) :QWidget()
{
    this->hasBannedBtn = hasBannedBtn;
    this->hasFavoriteBtn = hasFavoriteBtn;
    this->parent = parent;
    this->meal = item;
    this->setFixedHeight(50);
    QHBoxLayout *layout = new QHBoxLayout;

    if(canBeChecked){
        QCheckBox * addToCart = new QCheckBox();
        layout->addWidget(addToCart);
        connect(addToCart,&QCheckBox::stateChanged,[=]{
            isChecked = !isChecked;
            parent->cartAsChanged(this->meal->getId());});
    }
    layout->addWidget(new QLabel(item->getName()));
    layout->addWidget(new QLabel(QString::fromStdString(std::to_string(meal->getPrice()).substr(0,4))+" "+QChar(0x20AC)));


    if(this->hasFavoriteBtn){
    QPushButton * likeButton = new QPushButton(QIcon(":/icons/heart.png"),"",this);
    layout->addWidget(likeButton);
    connect(likeButton, &QPushButton::clicked, [=]{ parent->likedAsChanged(this->meal->getId() ); });
    }
    if(this->hasBannedBtn){
    QPushButton * bannedButton = new QPushButton(QIcon(":/icons/banned.png"),"",this);
    layout->addWidget(bannedButton);
    connect(bannedButton, &QPushButton::clicked, [=]{ parent->bannedAsChanged(this->meal->getId() ); });
    }
    this->setLayout(layout);

}


void MealItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "test";
}
