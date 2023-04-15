#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fmqw = new FirstMyQtWidget(this);
}

MainWindow::~MainWindow()
{
    delete fmqw;
    delete ui;
}

