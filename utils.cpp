#include "utils.h"

void Utils::readMealFromJson(QString filePath, QVector<Meal*>* availableMeal){
    QString json_string;
    QFile file;

    file.setFileName(":/"+filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    json_string = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(json_string.toUtf8());
    QJsonArray jsonArray = doc.array();
    for(auto it = jsonArray.begin() ; it!=jsonArray.end() ; ++it){
        QJsonObject mealObject = it->toObject();
        availableMeal->append(new Meal(mealObject["name"].toString(),mealObject["type"].toInt(),(float)mealObject["price"].toDouble(),false,false));
    }
}
