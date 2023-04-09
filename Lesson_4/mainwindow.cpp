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
    m_strName = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save(){
    QFile file(m_strName);
    if (!file.open(QFile::WriteOnly)) return;

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
}

void MainWindow::open(){
    QFile file(m_strName);
    if(!file.open(QFile::ReadOnly)) return;

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();
}

void MainWindow::changeLangue(enum class LNG dir){
    QString fileNameLNG;
    switch (dir) {
    case LNG::RUS:
        fileNameLNG = ":/Langue/Langue/RUS.txt";
        break;
    case LNG::ENG:
        fileNameLNG = ":/Langue/Langue/ENG.txt";
        break;
    default:
        return;
    }

    QFile file(fileNameLNG);
    if(!file.open(QFile::ReadOnly)) return;
    QTextStream iss(&file);
    const int CountMenu = 18;
    QString str[CountMenu];
    for(int i = 0; i < CountMenu; ++i)
        str[i] = iss.readLine(255);

    file.close();

    ui->File->setTitle(str[0]);
    ui->CreateNewFile->setText(str[1]);
    ui->OpenFile->setText(str[2]);
    ui->OpenFileOnlyRead->setText(str[3]);
    ui->Save->setText(str[4]);
    ui->SaveHow->setText(str[5]);
    ui->Correction->setTitle(str[6]);
    ui->Copy->setText(str[7]);
    ui->Paste->setText(str[8]);
    ui->Undo->setText(str[9]);
    ui->Clear->setText(str[10]);
    ui->View->setTitle(str[11]);
    ui->Langue->setTitle(str[12]);
    ui->Rus->setText(str[13]);
    ui->Eng->setText(str[14]);
    ui->Info->setTitle(str[15]);
    ui->ShowInfo->setText(str[16]);
    ui->Binds->setText(str[17]);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Q) close();
}

void MainWindow::on_ShowInfo_triggered(){
    Q_INIT_RESOURCE(resource); // нужно для того, чтобы использовать ресурсы
    QFile file(":/infoFiles/info.txt");
    QString strOut = "";
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        strOut = stream.readAll();
        file.close();
    }
    QMessageBox::about(this, "Справочная информация", strOut);
}

void MainWindow::on_CreateNewFile_triggered(){
    m_strName = "";
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setReadOnly(false);
}

void MainWindow::on_OpenFile_triggered(){
    QString filter = "Текстовый файл(*.txt)";
    QString strFileName = QFileDialog::getOpenFileName(this, "Заголовок окна", QDir::current().path(), filter);
    if(strFileName.isEmpty()) return;

    QString strExt = QString(&(strFileName.data()[strFileName.length() - 4]));
    if(strExt != ".txt") return;

    m_strName = strFileName;
    open();
    ui->plainTextEdit->setReadOnly(false);
}

void MainWindow::on_SaveHow_triggered(){
    QString filter = "Текстовый файл(*.txt)";
    QString strFileName = QFileDialog::getSaveFileName(this, "Заголовок окна", QDir::current().path(), filter);
    if(strFileName.isEmpty()) return;

    QString strExt = QString(&(strFileName.data()[strFileName.length() - 4]));
    if(strExt != ".txt") return;

    m_strName = strFileName;
    save();
}

void MainWindow::on_Save_triggered(){
    if(m_strName.isEmpty())
        on_SaveHow_triggered();
    else
        save();
}

void MainWindow::on_OpenFileOnlyRead_triggered(){
    on_OpenFile_triggered();
    ui->plainTextEdit->setReadOnly(true);
}

void MainWindow::on_Clear_triggered(){
    if(ui->plainTextEdit->isReadOnly()) return;
    ui->plainTextEdit->clear();
}

void MainWindow::on_Rus_triggered(){
    changeLangue(LNG::RUS);
}


void MainWindow::on_Eng_triggered(){
    changeLangue(LNG::ENG);
}

