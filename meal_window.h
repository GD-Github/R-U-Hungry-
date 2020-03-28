#ifndef MEAL_WINDOW_H
#define MEAL_WINDOW_H

#include <QString>
#include <QMainWindow>

class Meal_Window : public QMainWindow
{
    Q_OBJECT
public:
    Meal_Window(QWidget * parent):QMainWindow(parent){}
public slots:
    virtual void likedAsChanged(int id)=0;
    virtual void bannedAsChanged(int id)=0;
    virtual void cartAsChanged(int id){}
};

#endif // MEAL_WINDOW_H
