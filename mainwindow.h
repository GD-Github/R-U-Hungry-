#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QVector>
#include "meal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<Meal> * availableMeal;

public slots:
    void rechargeBtnAction();
    void favoritesBtnAction();
    void bannedBtnAction();
    void exit();
};
#endif // MAINWINDOW_H
