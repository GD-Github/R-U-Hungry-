#ifndef BANNEDWINDOW_H
#define BANNEDWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVector>
#include "meal.h"
#include "mealitem.h"
#include "user.h"
#include "utils.h"
#include "meal_window.h"

namespace Ui {
class BannedWindow;
}

class BannedWindow : public Meal_Window
{
    Q_OBJECT

public:
    explicit BannedWindow( User * currentUser = nullptr, QWidget *parent = nullptr);
    ~BannedWindow();
    void updateLists();
    void setFw(QMainWindow* fw){this->fw = fw;}

private:
    Ui::BannedWindow *ui;
    User * currentUser;
    QVBoxLayout * mealBannedList = nullptr;
    QVector<Meal*> * allMeal;
    QMainWindow* fw;

public slots:
    void homeBtnAction();
    void favoritesBtnAction();
    void exit();
    void likedAsChanged(int id) override;
    void bannedAsChanged(int id) override;

signals:
    void updateFav();

};

#endif // BANNEDWINDOW_H
