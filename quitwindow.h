#ifndef QUITWINDOW_H
#define QUITWINDOW_H

#include <QWidget>

namespace Ui {
class QuitWindow;
}

class QuitWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QuitWindow(QWidget *parent = nullptr);
    ~QuitWindow();

private:
    Ui::QuitWindow *ui;
};

#endif // QUITWINDOW_H
