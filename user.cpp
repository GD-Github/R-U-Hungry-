#include "user.h"

User::User(QString name) : name(name)
{
    QString json_string;
    if (solde < 0) solde =0;


    favoriteMeal = new QVector<int>();
    bannedMeal = new QVector<int>();
    QFile file;
    file.setFileName(QCoreApplication::applicationDirPath()+"/user.json");
    QString errMsg;
    QFileDevice::FileError err = QFileDevice::NoError;
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        errMsg = file.errorString();
        err = file.error();
    }

    json_string = file.readAll();
    if(json_string == ""){
        QFile templateFile;
        templateFile.setFileName(":/user.json");
        templateFile.open(QFile::ReadOnly | QFile::Text);
        QString templateString = templateFile.readAll();
        templateFile.close();
        QTextStream stream(&file);
        stream << templateString;

    }
    file.close();
    file.open(QFile::ReadOnly | QFile::Text);
    json_string = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(json_string.toUtf8());
    QJsonObject jsonObject = doc.object();
    QJsonValue value = jsonObject.value(name);
    if(value != QJsonValue::Undefined){
        QJsonObject user = value.toObject();
        value = user.value("solde");
        if(value!=QJsonValue::Undefined){
            solde = value.toDouble();
        }
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
    file.close();

}

void User::saveUser(){
    QString json_string;
    QFile file(QCoreApplication::applicationDirPath()+"/user.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    json_string = file.readAll();

    QJsonDocument doc = QJsonDocument::fromJson(json_string.toUtf8());
    QJsonObject jsonObject = doc.object();
    QJsonValueRef value = jsonObject.find(name).value();
    if(value != QJsonValue::Undefined){
        QJsonObject user = value.toObject();
        QJsonArray liked;
        QJsonArray banned;
        for(auto it=favoriteMeal->begin(); it!=favoriteMeal->end() ; ++it){
            liked.push_back(*it);
        }
        for(auto it=bannedMeal->begin(); it!=bannedMeal->end() ; ++it){
            banned.push_back(*it);
        }
        user.insert("liked",liked);
        user.insert("banned",banned);
        user.insert("solde",solde);
        value = user;
    }

    file.resize(0);

    doc.setObject(jsonObject);
    file.write(doc.toJson());
    file.close();
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
