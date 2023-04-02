#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parseText = new Parse;

    model = new QStandardItemModel(this);
    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon("../icons/C++.png"),"C++"));
    model->appendRow(new QStandardItem(QIcon("../icons/Python.png"),"Python"));
    model->appendRow(new QStandardItem(QIcon("../icons/JavaScript.png"),"Java Script"));
    model->appendRow(new QStandardItem(QIcon("../icons/HTML5.png"),"HTML5"));
    model->appendRow(new QStandardItem(QIcon("../icons/PHP.png"),"PHP"));
    model->appendRow(new QStandardItem(QIcon("../icons/Swift.png"),"Swift"));

}

MainWindow::~MainWindow(){
    delete parseText;
    delete model;
    delete ui;
}


void MainWindow::on_plainTextEdit_textChanged(){
    QString str = ui->plainTextEdit->toPlainText(); // получаем текст виджета

    if (parseText->change(str)) // были ли примеры
    {
        ui->plainTextEdit->setPlainText(parseText->getText()); // заменяем текст примеры с результатами
    }
}

void MainWindow::on_listView_clicked(const QModelIndex &index){

}


void MainWindow::on_pushButton_clicked(){
    model->appendRow(new QStandardItem(QIcon("../icons/Default.png"),"template"));
}


void MainWindow::on_pushButton_2_clicked(){
    auto index = ui->listView->currentIndex();
    if(index.row() == -1) return;

    model->removeRows(index.row(), 1);

    //Сброс выбора строки
    QModelIndex i;
    ui->listView->setCurrentIndex(i);
}


void MainWindow::on_pushButton_3_clicked(){
    if(ui->listView->size().isEmpty()) return;

    auto index = ui->listView->currentIndex();
    if(index.row() <= 0) return;

    model->insertRow(index.row() - 1, model->takeRow(index.row()));

    //Сброс выбора строки
    QModelIndex i;
    ui->listView->setCurrentIndex(i);
}


void MainWindow::on_pushButton_4_clicked(){
    if(ui->listView->size().isEmpty()) return;

    auto index = ui->listView->currentIndex();
    if(index.row() < 0) return;
    if(index.row() >= model->rowCount() - 1) return;

    model->insertRow(index.row() + 1, model->takeRow(index.row()));

    //Сброс выбора строки
    QModelIndex i;
    ui->listView->setCurrentIndex(i);
}

