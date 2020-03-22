#ifndef BANNEDWINDOW_H
#define BANNEDWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVector>
#include "meal.h"
#include "mealitem.h"

namespace Ui {
class BannedWindow;
}

class BannedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BannedWindow( QVector<Meal*> * availableMeal, QWidget *parent = nullptr);
    ~BannedWindow();

private:
    Ui::BannedWindow *ui;
    QVector<Meal*> * availableMeal;
    QVBoxLayout * mealBannedList = nullptr;

public slots:
    void homeBtnAction();
    void favoritesBtnAction();
    void exit();
    void updateLists();
};

#endif // BANNEDWINDOW_H
