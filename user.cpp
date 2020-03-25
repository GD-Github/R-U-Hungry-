#include "user.h"

User::User(QString name) : name(name)
{
    QString json_string;
    QFile file;

    favoriteMeal = new QVector<QString>();
    bannedMeal = new QVector<QString>();

    file.setFileName(":/user.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    json_string = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(json_string.toUtf8());
    QJsonObject jsonObject = doc.object();
    QJsonValue value = jsonObject.value(name);
    if(value != QJsonValue::Undefined){
        QJsonObject user = value.toObject();
        value = user.value("liked");
        if(value!=QJsonValue::Undefined){
            QJsonArray likedArray = value.toArray();
            for(auto it = likedArray.begin() ; it!= likedArray.end() ; ++it){
                favoriteMeal->append(it->toString());
            }
        }
        value = user.value("banned");
        if(value!=QJsonValue::Undefined){
            QJsonArray bannedArray = value.toArray();
            for(auto it = bannedArray.begin() ; it!= bannedArray.end() ; ++it){
                bannedMeal->append(it->toString());
            }
        }

    }
}

void User::showFavorite(){
    for(auto it=favoriteMeal->begin();it!=favoriteMeal->end();++it){
        qDebug() << (*it);
    }
}

void User::addFavorite(QString name)
{
    favoriteMeal->append(name);
}

void User::removeFavorite(QString name){
    favoriteMeal->removeAll(name);
}

void User::addBanned(QString name){
    bannedMeal->append(name);
}

void User::removeBanned(QString name){
    bannedMeal->removeAll(name);
}

bool User::favoritesContain(QString name){
    return favoriteMeal->contains(name);
}

bool User::bannedContain(QString name){
    return bannedMeal->contains(name);
}
