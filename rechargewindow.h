#ifndef RECHARGEWINDOW_H
#define RECHARGEWINDOW_H

#include "user.h"

#include <QMainWindow>

namespace Ui {
class RechargeWindow;
}

class RechargeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RechargeWindow(User * currentUser = nullptr , QWidget *parent = nullptr);
    ~RechargeWindow();

private:
    Ui::RechargeWindow *ui;
    User * currentUser;

public slots:
    void updatePrice(int);
    void homeBtnAction();
    void favoritesBtnAction();
    void bannedBtnAction();
};

#endif // RECHARGEWINDOW_H
