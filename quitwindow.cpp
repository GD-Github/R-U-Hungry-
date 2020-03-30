#include "quitwindow.h"
#include "ui_quitwindow.h"

QuitWindow::QuitWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuitWindow)
{
    ui->setupUi(this);
}

QuitWindow::~QuitWindow()
{
    delete ui;
}
