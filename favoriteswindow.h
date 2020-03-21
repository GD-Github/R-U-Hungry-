#ifndef FAVORITESWINDOW_H
#define FAVORITESWINDOW_H

#include <QMainWindow>

namespace Ui {
class FavoritesWindow;
}

class FavoritesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FavoritesWindow(QWidget *parent = nullptr);
    ~FavoritesWindow();

private:
    Ui::FavoritesWindow *ui;

public slots:
    void homeBtnAction();
    void bannedBtnAction();
    void exit();
};

#endif // FAVORITESWINDOW_H
