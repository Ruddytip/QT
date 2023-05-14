#include "taskviewer.h"
#include "ui_taskviewer.h"
#include <QSqlRecord>

TaskViewer::TaskViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskViewer)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Наименование задачи", "Дата выполнения", "Прогресс"});
    ui->tableWidget->setColumnWidth(0, 375);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 65);
}

TaskViewer::~TaskViewer()
{
    delete ui;
}

void TaskViewer::initTable(QSqlQuery& query){
    QSqlRecord record = query.record();

    while(query.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        auto columnName =new QTableWidgetItem(); columnName->setFlags(columnName->flags() &= ~Qt::ItemIsEditable);
        auto columnDate =new QTableWidgetItem(); columnDate->setFlags(columnDate->flags() &= ~Qt::ItemIsEditable);
        auto columnProc =new QTableWidgetItem(); columnProc->setFlags(columnProc->flags() &= ~Qt::ItemIsEditable);

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, columnName);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, columnDate);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, columnProc);

        ui->tableWidget->item(ui->tableWidget->rowCount() - 1, 0)->setText(query.value(record.indexOf("name")).toString());
        ui->tableWidget->item(ui->tableWidget->rowCount() - 1, 1)->setText(query.value(record.indexOf("date")).toString());
        ui->tableWidget->item(ui->tableWidget->rowCount() - 1, 2)->setText(query.value(record.indexOf("Progress")).toString());
    }
}
