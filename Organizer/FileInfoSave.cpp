#include "FileInfoSave.hpp"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <algorithm>

FileInfoSave::FileInfoSave(QObject *parent)
    : QObject{parent}, TasksCountInFile(0), fileName(""), data("")
{
    //Q_INIT_RESOURCE(qml);
    QFile file("D:/Develop/Source/QT/Organizer/Tasks.txt");
    if(!file.open(QFile::ReadOnly)) return;

    QTextStream stream(&file);
    data = stream.readAll();
    for(const auto& it : data)
        if(it == ";") ++TasksCountInFile;

    file.close();
}

FileInfoSave::~FileInfoSave(){
    //Q_INIT_RESOURCE(qml);
    //QFile file(":/Tasks.txt");
    QFile file("D:/Develop/Source/QT/Organizer/Tasks.txt");
    if (!file.open(QFile::WriteOnly)) return;
    QTextStream stream(&file);
    stream << data;
    file.close();
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

bool FileInfoSave::addTask(QString _taskName, QString _data, QString _progress){
    QMessageBox msgBox;
    QString error = "";

    if(_taskName.isEmpty() || _data.isEmpty()){
        if(_taskName.isEmpty()) error+= "Поле \"Название задачи\" не может быть пустым.";
        if(_data.isEmpty()){
            if(!error.isEmpty()) error+= "\n";
            error+= "Поле \"Дата выполнения\" не может быть пустым.";
        }
    }

    if(!checkData(_data) && !_data.isEmpty()){
        if(!error.isEmpty()) error+= "\n";
        error+= "Поле \"Дата выполнения\" не соответствует шаблону \"dd.mm.yyyy\".";
    }

    if(error != ""){
        msgBox.setText(error);
        msgBox.exec();
        return false;
    }

    data += _taskName + ": ";
    data += _data + " -> ";
    data += _progress + "/10;\n";
    ++TasksCountInFile;
    return true;
}

QString FileInfoSave::getCountTasks(){
    return QString(std::to_string(TasksCountInFile).c_str());
}
