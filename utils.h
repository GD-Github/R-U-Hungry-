#ifndef UTILS_H
#define UTILS_H
#include <vector>

#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonDocument>
#include "user.h"
#include "meal.h"

namespace Utils {
    void readMealFromJson(QVector<Meal*> * allMeal);
    void readMealFromIndexFile(QString filePath, QVector<Meal*> * availableMeal);
}
Q_DECLARE_METATYPE(std::vector<bool>);

#endif // UTILS_H
