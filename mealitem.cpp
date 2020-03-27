#include "mealitem.h"

MealItem::MealItem(Meal_Window * parent , Meal * item, bool canBeChecked) :QWidget()
{
    this->parent = parent;
    this->meal = item;
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

    QPushButton * likeButton = new QPushButton(QIcon(":/icons/heart.png"),"",this);
    QPushButton * bannedButton = new QPushButton(QIcon(":/icons/banned.png"),"",this);

    layout->addWidget(likeButton);
    layout->addWidget(bannedButton);
    this->setLayout(layout);

    connect(likeButton, &QPushButton::clicked, [=]{ parent->likedAsChanged(this->meal->getId() ); });
    connect(bannedButton, &QPushButton::clicked, [=]{ parent->bannedAsChanged(this->meal->getId() ); });
}


void MealItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "test";
}
