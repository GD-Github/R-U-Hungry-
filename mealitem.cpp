#include "mealitem.h"
#include <iostream>

MealItem::MealItem(Meal_Window * parent , Meal * item, bool canBeChecked, bool hasFavoriteBtn, bool hasBannedBtn,bool hasArrowBtn, bool isChecked,bool hasQuantity) :QWidget()
{
    this->hasBannedBtn = hasBannedBtn;
    this->hasFavoriteBtn = hasFavoriteBtn;
    this->hasArrowBtn = hasArrowBtn;
    this->parent = parent;
    this->meal = item;
    this->isChecked = isChecked;
    this->hasQuantity=hasQuantity;
    /*vLayout = new QVBoxLayout();*/
    QHBoxLayout *layout = new QHBoxLayout;

    QVBoxLayout *main_layout= new QVBoxLayout;
    QHBoxLayout * info_layout=new QHBoxLayout;
    main_layout->addLayout(layout);
    main_layout->addLayout(info_layout);

    descrip = new QLabel(item->getDescription());
    kcal = new QLabel("kCal: "+QString::number(item->getkCal()));
    info_layout->addWidget(descrip, 7);
    info_layout->addWidget(kcal ,4);
    descrip->hide();
    kcal->hide();

    if(canBeChecked){
        addToCart = new QCheckBox();
        if(isChecked)
            addToCart->setChecked(true);
        layout->addWidget(addToCart, 1);
        connect(addToCart,&QCheckBox::stateChanged,[=]{
            this->isChecked = !this->isChecked;
            parent->cartAsChanged(this->meal->getId());});
    }


    if (this->hasQuantity){
        layout->addWidget(new QLabel(item->getName()), 3);

        QHBoxLayout * quantityLayout = new QHBoxLayout;
        plusButton = new QPushButton(QIcon(":/icons/plus.png"),"",this);
        lessButton = new QPushButton(QIcon(":/icons/less.png"),"",this);
        quantityIcon = new QPushButton(QIcon(":/icons/medium.png"),"",this);
        updateQuantityIcon();
        quantityIcon->setFlat(false);
        quantityIcon->setCheckable(false);
        quantityIcon->setDown(false);
        QLabel * qtt = new QLabel("Quantité : ");
        quantityLayout->addWidget(qtt);
        quantityLayout->setAlignment(qtt, Qt::AlignRight);
        quantityLayout->addWidget(plusButton);
        quantityLayout->addWidget(quantityIcon);
        quantityLayout->addWidget(lessButton);
        layout->addLayout(quantityLayout, 5);
        connect(plusButton, SIGNAL(clicked()), this, SLOT(plusQuantity()));
        connect(lessButton, SIGNAL(clicked()), this, SLOT(lessQuantity()));
        QLabel* lbl = new QLabel(QString::fromStdString(std::to_string(meal->getPrice()).substr(0,4))+" "+QChar(0x20AC));
        layout->addWidget(lbl, 3);
        layout->setAlignment(lbl,Qt::AlignCenter);
    }else{
        layout->addWidget(new QLabel(item->getName()), 8);
        QLabel* lbl = new QLabel(QString::fromStdString(std::to_string(meal->getPrice()).substr(0,4))+" "+QChar(0x20AC));
        layout->addWidget(lbl, 3);
        layout->setAlignment(lbl,Qt::AlignCenter);
    }

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
    if(this->hasArrowBtn){
        infoButton = new QPushButton(QIcon(":/icons/info+.png"),"",this);
        layout->addWidget(infoButton, 1);
        connect(infoButton, SIGNAL(clicked()), this, SLOT(displayInfo()));
    }
    this->setLayout(main_layout);

}

void MealItem::updateQuantityIcon(){
    switch (meal->getQuantity()) {
    case 1:
        quantityIcon->setIcon(QIcon(":/icons/low.png"));
        break;
    case 2:
        quantityIcon->setIcon(QIcon(":/icons/medium.png"));
        break;
    case 3:
        quantityIcon->setIcon(QIcon(":/icons/high.png"));
        break;
    }
}

void MealItem::plusQuantity(){
    meal->plusQuantity();
    updateQuantityIcon();
}

void MealItem::lessQuantity(){
    meal->lessQuantity();
    updateQuantityIcon();
}

void MealItem::mousePressEvent(QMouseEvent *event)
{
    this->isChecked = !this->isChecked;
    parent->cartAsChanged(this->meal->getId());
}

void MealItem::displayInfo(){
    if (descrip->isHidden()){
        descrip->show();
        kcal->show();
        infoButton->setIcon(QIcon(":/icons/info-.png"));
    }else{
        descrip->hide();
        kcal->hide();
        infoButton->setIcon(QIcon(":/icons/info+.png"));
    }
}
