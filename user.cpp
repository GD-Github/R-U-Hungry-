#include "user.h"

User::User(QString name) : name(name)
{
    QString json_string;
    QFile file;

    favoriteMeal = new QVector<int>();
    bannedMeal = new QVector<int>();

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
                favoriteMeal->append(it->toInt());
            }
        }
        value = user.value("banned");
        if(value!=QJsonValue::Undefined){
            QJsonArray bannedArray = value.toArray();
            for(auto it = bannedArray.begin() ; it!= bannedArray.end() ; ++it){
                bannedMeal->append(it->toInt());
            }
        }

    }
}

void User::showFavorite(){
    for(auto it=favoriteMeal->begin();it!=favoriteMeal->end();++it){
        qDebug() << (*it);
    }
}

void User::addFavorite(int id)
{
    favoriteMeal->append(id);
}

void User::removeFavorite(int id){
    favoriteMeal->removeAll(id);
}

void User::addBanned(int id){
    bannedMeal->append(id);
}

void User::removeBanned(int id){
    bannedMeal->removeAll(id);
}

bool User::favoritesContain(int id){
    return favoriteMeal->contains(id);
}

bool User::bannedContain(int id){
    return bannedMeal->contains(id);
}
