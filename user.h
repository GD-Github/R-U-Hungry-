#ifndef USER_H
#define USER_H

#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>
#include <QFile>
#include<iostream>

class User
{
public:
    User(QString name);
    void addFavorite(int id);
    void removeFavorite(int id);
    void addBanned(int id);
    void removeBanned(int id);
    bool favoritesContain(int id);
    bool bannedContain(int id);
    void showFavorite();
    void addSolde(int n){solde += n;}
    void removeSolde(double d){solde -= d;}
    double getSolde(){return solde;}
    QString getName(){return name;}


private:
    QString name;
    QVector<int> * favoriteMeal;
    QVector<int> * bannedMeal;
    double solde;


};

#endif // USER_H
