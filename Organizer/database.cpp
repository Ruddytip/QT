#include "database.hpp"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <algorithm>
#include <QDebug>
#include "taskviewer.h"

DataBase::DataBase(QObject *parent)
: QObject{parent}, db_isGood(false), nameDB("Tasks"), TasksCountInFile(0) {
    if(createConnection())
        if(createTable())
            db_isGood = true;

    QSqlQuery query;
    if(!query.exec("SELECT * FROM " + nameDB + ";")){
        qDebug() << "Cannot read table";
        return;
    }
    while(query.next())
        ++TasksCountInFile;
}

bool DataBase::createConnection(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nameDB + ".db");
    if(!db.open()){
        qDebug() << "Cannot open dataBase";
        return false;
    }
    return true;
}

bool DataBase::createTable(){
    if(db.tables().count() > 0)
        for(const auto& it : db.tables())
            if(it == nameDB) return true;

    QSqlQuery query;
    QString strCreate = "CREATE TABLE Tasks ("
                        "id INTEGER PRIMARY KEY NOT NULL,"
                        "name VARCHAR(50),"
                        "date VARCHAR(10),"
                        "progress VARCHAR(5) );";

    if(!query.exec(strCreate)){
        qDebug() << "Cannot create table";
        return false;
    }
    return true;
}

bool checkData(QString& date){
    if(date.length() != 10) return false;
    if(date[2] != '.' && date[5] != '.') return false;

    int day =   std::atoi(date.mid(0, 2).toStdString().c_str());
    int month = std::atoi(date.mid(3, 2).toStdString().c_str());
    int year =  std::atoi(date.mid(6, 4).toStdString().c_str());

    if(day == 0 || month == 0 || year == 0) return false;
    if(day > 31 || month > 12 || year > 9999) return false;
    return true;
}

bool DataBase::add(QString name, QString date, QString progress){

    QMessageBox msgBox;
    QString error = "";

    if(name.isEmpty() || date.isEmpty()){
        if(name.isEmpty()) error+= "Поле \"Название задачи\" не может быть пустым.";
        if(date.isEmpty()){
            if(!error.isEmpty()) error+= "\n";
            error+= "Поле \"Дата выполнения\" не может быть пустым.";
        }
    }

    if(!checkData(date) && !date.isEmpty()){
        if(!error.isEmpty()) error+= "\n";
        error+= "Поле \"Дата выполнения\" не соответствует шаблону \"dd.mm.yyyy\".";
    }

    if(error != ""){
        msgBox.setText(error);
        msgBox.exec();
        return false;
    }

    if(!db_isGood) return false;

    QSqlQuery query;
    QString strAdd = "INSERT INTO " + nameDB + " (name, date, progress)"
                     "VALUES ('" + name + "', '" + date + "', '" + progress + "/10');";

    if(!query.exec(strAdd)){
        qDebug() << "Cannot add record";
        return false;
    }

    ++TasksCountInFile;
    return true;
}

void DataBase::openWindow(){
    TaskViewer* form = new TaskViewer;
    form->setAttribute(Qt::WA_DeleteOnClose, true);
    form->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    if(!db_isGood) return;

    QSqlQuery query;
    if(!query.exec("SELECT * FROM " + nameDB + ";")){
        qDebug() << "Cannot read table";
        return;
    }

    form->initTable(query);
    form->show();
}
