#include "utils.h"
#include <iostream>
void Utils::readMealFromJson(QVector<Meal*>* allMeal){
    QString json_string;
    QFile file;

    file.setFileName(":/mealList.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    json_string = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(json_string.toUtf8());
    QJsonArray jsonArray = doc.array();
    for(auto it = jsonArray.begin() ; it!=jsonArray.end() ; ++it){
        QJsonObject mealObject = it->toObject();
        bool vege = mealObject["vege"].toBool();
        bool halal = mealObject["halal"].toBool();
        bool aller = mealObject["aller"].toBool();
        bool gluten = mealObject["gluten"].toBool();
        std::vector<bool> vec = {vege,halal,aller,gluten};
        allMeal->append(new Meal(mealObject["id"].toInt(),mealObject["name"].toString(),mealObject["type"].toInt(),(float)mealObject["price"].toDouble(),mealObject["kcal"].toInt(),false,false,false,false,vec,mealObject["description"].toString()));
    }
}

void Utils::readMealFromIndexFile(QString filePath, QVector<Meal*> * availableMeal){

    QString line;
    QFile file;
    file.setFileName(":/"+filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    line = file.readAll();
    file.close();
    QStringList list = line.split(";");
    QVector<Meal*>* allMeal = new QVector<Meal*>();
    Utils::readMealFromJson(allMeal);
    qDebug() << line;
    for(auto it=allMeal->begin();it!=allMeal->end();++it){
        if(list.contains(QString::number((*it)->getId()))){
                availableMeal->append(*it);

    }
    }
}
