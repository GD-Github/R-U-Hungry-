#ifndef USER_H
#define USER_H

#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>
#include <QFile>

class User
{
public:
    User(QString name);
    void addFavorite(QString name);
    void removeFavorite(QString name);
    void addBanned(QString name);
    void removeBanned(QString name);
    bool favoritesContain(QString name);
    bool bannedContain(QString name);
    void showFavorite();


private:
    QString name;
    QVector<QString> * favoriteMeal;
    QVector<QString> * bannedMeal;
};

#endif // USER_H
