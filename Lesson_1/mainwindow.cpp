#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtMath>

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


void MainWindow::on_pushButton_clicked()
{
    qint32 a = ui->lineEdit->text().toInt();
    qint32 b = ui->lineEdit_2->text().toInt();
    qint32 c = ui->lineEdit_3->text().toInt();

    qint32 d = b * b - 4 * a * c;

    if(d < 0){
        ui->lineEdit_4->setText("Нет корней");
        return;
    }else if(d == 0){
        qint32 res = -b / 2 * a;
        ui->lineEdit_4->setText("x = " + QString::number(res, 10));
        return;
    }
    qreal res1 = (-b - qSqrt(d))/ 2 * a;
    qreal res2 = (-b + qSqrt(d))/ 2 * a;
    QString out1 = QString::number(res1, 'f', 3);
    QString out2 = QString::number(res2, 'f', 3);
    ui->lineEdit_4->setText("x1 = " + out1 + ", x2 = " + out2);
}


void MainWindow::on_pushButton_2_clicked()
{
    qreal a = ui->lineEdit_6->text().toInt();
    qreal b = ui->lineEdit_5->text().toInt();
    qreal angle = ui->lineEdit_8->text().toInt();

    if(ui->radioButton->isChecked()){
        angle = angle * M_PI / 180;
    }

    qreal result = qSqrt(a*a + b*b - 2 * a * b * qCos(angle));
    QString out = QString::number(result, 'f', 3);
    ui->lineEdit_7->setText(out);
}


void MainWindow::on_pushButton_3_clicked()
{
    QStringList left = ui->plainTextEdit->toPlainText().split( "\n" );
    QStringList right = ui->plainTextEdit_2->toPlainText().split( "\n" );

    ui->plainTextEdit->clear();
    for( int i = 0; i < left.count(); i++ )
    {
        ui->plainTextEdit->appendPlainText(left.at( i ));
    }
    for( int i = 0; i < right.count(); i++ )
    {
        ui->plainTextEdit->appendPlainText(right.at( i ));
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QStringList left = ui->plainTextEdit->toPlainText().split( "\n" );

    ui->plainTextEdit_2->clear();
    for( int i = 0; i < left.count(); i++ )
    {
        ui->plainTextEdit_2->appendPlainText(left.at( i ));
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QString out = "<font color='red'>\n\tHello\n</font>";

    srand(time(0));
    if(rand()%2){
        ui->plainTextEdit->appendPlainText(out);
    }else{
        ui->plainTextEdit_2->appendPlainText(out);
    }
}

