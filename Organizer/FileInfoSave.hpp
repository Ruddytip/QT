#ifndef FILEINFOSAVE_HPP
#define FILEINFOSAVE_HPP

#include <QObject>

class FileInfoSave : public QObject {
    Q_OBJECT
private:
    unsigned int TasksCountInFile;
    QString data;

public:
    explicit FileInfoSave(QObject *parent = nullptr);
    virtual ~FileInfoSave();
    Q_INVOKABLE bool addTask(QString _taskName, QString _data, QString _progress);
    Q_INVOKABLE QString getCountTasks();

signals:

};

#endif // FILEINFOSAVE_HPP
