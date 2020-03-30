#ifndef PAYWINDOW_H
#define PAYWINDOW_H

#include <QWidget>
#include "meal_window.h"

namespace Ui {
class PayWindow;
}

class PayWindow : public Meal_Window
{
    Q_OBJECT

public:
    explicit PayWindow(QWidget *parent = nullptr);
    ~PayWindow();

private:
    Ui::PayWindow *ui;

public slots:
    void likedAsChanged(int id) override;
    void bannedAsChanged(int id) override;
    void processPaiement();
};

#endif // PAYWINDOW_H
