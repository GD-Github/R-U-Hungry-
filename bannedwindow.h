#ifndef BANNEDWINDOW_H
#define BANNEDWINDOW_H

#include <QMainWindow>

namespace Ui {
class BannedWindow;
}

class BannedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BannedWindow(QWidget *parent = nullptr);
    ~BannedWindow();

private:
    Ui::BannedWindow *ui;

public slots:
    void homeBtnAction();
    void favoritesBtnAction();
    void exit();
};

#endif // BANNEDWINDOW_H
