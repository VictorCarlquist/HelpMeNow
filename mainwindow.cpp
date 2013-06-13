#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logonscreen = new LogonScreen(this);
    setCentralWidget(logonscreen);
    logonscreen->resize(400, 400);
    logonscreen->show();

    connect(logonscreen, SIGNAL(connected()), logonscreen, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
