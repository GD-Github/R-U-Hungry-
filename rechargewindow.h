#ifndef RECHARGEWINDOW_H
#define RECHARGEWINDOW_H

#include "user.h"
#include <QMainWindow>
#include<QMessageBox>
#include <QPushButton>

namespace Ui {
class RechargeWindow;
}

class RechargeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RechargeWindow(User * currentUser = nullptr , QWidget *parent = nullptr);
    ~RechargeWindow();
    void setBw(QMainWindow* bw){this->bw = bw;}
    void setFw(QMainWindow* fw){this->fw = fw;}

private:
    QMessageBox* confirmationBox;
    Ui::RechargeWindow *ui;
    User * currentUser;
    QMainWindow * bw;
    QMainWindow * fw;

public slots:
    void updatePrice(int);
    void homeBtnAction();
    void favoritesBtnAction();
    void bannedBtnAction();
    void pay();

signals:
void soldeChanged(double);
};

#endif // RECHARGEWINDOW_H