#pragma once
#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class TaskViewer;
}

class TaskViewer : public QDialog
{
    Q_OBJECT

public:
    explicit TaskViewer(QWidget *parent = nullptr);
    virtual ~TaskViewer();
    void initTable(QSqlQuery& query);

private:
    Ui::TaskViewer *ui;
};
