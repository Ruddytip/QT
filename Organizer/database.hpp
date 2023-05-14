#pragma once
#include <QObject>
#include <QSqlDatabase>
#include "taskviewer.h"

class DataBase : public QObject {
    Q_OBJECT

private:
    QSqlDatabase db;
    bool db_isGood;
    QString nameDB;
    int TasksCountInFile;

    bool createConnection();
    bool createTable();

public:
    explicit DataBase(QObject *parent = nullptr);
    virtual ~DataBase(){ if(db.isOpen()) db.close(); }

    Q_INVOKABLE bool add(QString name, QString date, QString progress);
    Q_INVOKABLE int getCountTasks() { return TasksCountInFile; }
    Q_INVOKABLE void openWindow();

signals:

};
