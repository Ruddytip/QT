#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_save_clicked(){
    QString filter = "Текстовый файл(*.txt)";
    QString strFileName = QFileDialog::getSaveFileName(this, "Заголовок окна", QDir::current().path(), filter);
    if(strFileName.isEmpty()) return;

    QString strExt = QString(&(strFileName.data()[strFileName.length() - 4]));
    if(strExt != ".txt") return;

    QFile file(strFileName);
    if (file.open(QFile::WriteOnly/* | QFile::NewOnly*/)){
        QTextStream stream(&file);
        stream << ui->plainTextEdit->toPlainText();
        file.close();
    }
}


void MainWindow::on_pushButton_open_clicked(){
    QString filter = "Текстовый файл(*.txt)";
    QString strFileName = QFileDialog::getOpenFileName(this, "Заголовок окна", QDir::current().path(), filter);
    if(strFileName.isEmpty()) return;

    QString strExt = QString(&(strFileName.data()[strFileName.length() - 4]));
    if(strExt != ".txt") return;

    QFile file(strFileName);
    if (file.open(QFile::ReadOnly/* | QFile::NewOnly*/)){
        QTextStream stream(&file);
        ui->plainTextEdit->setPlainText(stream.readAll());
        file.close();
    }
}


void MainWindow::on_pushButton_info_clicked(){
    Q_INIT_RESOURCE(resource); // нужно для того, чтобы использовать ресурсы
    QFile file(":/infoFiles/info.txt");
    QString strOut;
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        strOut = stream.readAll();
        file.close();
    }
    QMessageBox::about(this, "Справочная информация", strOut);
}

