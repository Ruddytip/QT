#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setApp(QApplication* a){
        app = a;
    }

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
    void on_Light_triggered();
    void on_Dark_triggered();
    void on_Print_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_comboBox_activated(int index);
    void on_textEdit_cursorPositionChanged();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    QApplication* app;
    QString m_strName;
    QFont m_font;

    void save();
    void open();

    enum class LNG{ RUS, ENG };
    void changeLangue(enum class LNG dir);

    enum class THM{ Light, Dark };
    void changeTheme(enum class THM dir);

    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
