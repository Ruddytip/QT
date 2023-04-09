#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ShowInfo_triggered();
    void on_CreateNewFile_triggered();
    void on_OpenFile_triggered();
    void on_SaveHow_triggered();
    void on_Save_triggered();
    void on_OpenFileOnlyRead_triggered();
    void on_Clear_triggered();
    void on_Rus_triggered();
    void on_Eng_triggered();

private:
    Ui::MainWindow *ui;

    QString m_strName;

    void save();
    void open();

    enum class LNG{ RUS, ENG };
    void changeLangue(enum class LNG dir);

    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
