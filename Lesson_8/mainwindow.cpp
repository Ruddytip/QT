#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QKeyEvent>
#include <QTime>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_strName = "";
    ui->comboBox->addItem("По левому краю");
    ui->comboBox->addItem("По центру");
    ui->comboBox->addItem("По правому краю");
    ui->comboBox->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::save(){
    QFile file(m_strName);
    if (!file.open(QFile::WriteOnly)) return;

    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    file.close();
}

void MainWindow::open(){
    QFile file(m_strName);
    if(!file.open(QFile::ReadOnly)) return;

    QTextStream stream(&file);
    ui->textEdit->setPlainText(stream.readAll());
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
    const int CountMenu = 22;
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
    ui->Print->setText(str[6]);
    ui->Correction->setTitle(str[7]);
    ui->Copy->setText(str[8]);
    ui->Paste->setText(str[9]);
    ui->Undo->setText(str[10]);
    ui->Clear->setText(str[11]);
    ui->View->setTitle(str[12]);
    ui->Langue->setTitle(str[13]);
    ui->Rus->setText(str[14]);
    ui->Eng->setText(str[15]);
    ui->Theme->setTitle(str[16]);
    ui->Light->setText(str[17]);
    ui->Dark->setText(str[18]);
    ui->Info->setTitle(str[19]);
    ui->ShowInfo->setText(str[20]);
    ui->Binds->setText(str[21]);
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
    ui->textEdit->clear();
    ui->textEdit->setReadOnly(false);
}

void MainWindow::on_OpenFile_triggered(){
    QString filter = "Текстовый файл(*.txt)";
    QString strFileName = QFileDialog::getOpenFileName(this, "Заголовок окна", QDir::current().path(), filter);
    if(strFileName.isEmpty()) return;

    QString strExt = QString(&(strFileName.data()[strFileName.length() - 4]));
    if(strExt != ".txt") return;

    m_strName = strFileName;
    open();
    ui->textEdit->setReadOnly(false);
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
    ui->textEdit->setReadOnly(true);
}

void MainWindow::on_Clear_triggered(){
    if(ui->textEdit->isReadOnly()) return;
    ui->textEdit->clear();
}

void MainWindow::on_Rus_triggered(){
    changeLangue(LNG::RUS);
}

void MainWindow::on_Eng_triggered(){
    changeLangue(LNG::ENG);
}

void MainWindow::changeTheme(enum class THM dir){
    QPalette CurPalette;

    switch (dir) {
    case THM::Light:

    break;
    case THM::Dark:
        CurPalette = QPalette();
        CurPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        CurPalette.setColor(QPalette::WindowText, Qt::white);
        CurPalette.setColor(QPalette::Base, QColor(35, 35, 35));
        CurPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        CurPalette.setColor(QPalette::ToolTipBase, QColor(25, 25, 25));
        CurPalette.setColor(QPalette::ToolTipText, Qt::white);
        CurPalette.setColor(QPalette::Text, Qt::white);
        CurPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        CurPalette.setColor(QPalette::ButtonText, Qt::white);
        CurPalette.setColor(QPalette::BrightText, Qt::red);
        CurPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        CurPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        CurPalette.setColor(QPalette::HighlightedText, QColor(35, 35, 35));
        CurPalette.setColor(QPalette::Active, QPalette::Button, QColor(53, 53, 53));
        CurPalette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);
        CurPalette.setColor(QPalette::Disabled, QPalette::WindowText, Qt::darkGray);
        CurPalette.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
        CurPalette.setColor(QPalette::Disabled, QPalette::Light, QColor(53, 53, 53));
    break;
    default:
        break;
    }
    app->setPalette(CurPalette);
}

void MainWindow::on_Light_triggered(){
    changeTheme(THM::Light);
}

void MainWindow::on_Dark_triggered(){
    changeTheme(THM::Dark);
}

void MainWindow::on_Print_triggered(){
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString printStr = ui->textEdit->toPlainText();
    QChar *list = printStr.data();
    QStringList strlst;

    int line = 0, cursor = 0;
    for (bool getst = true; getst ;) {
        int index = printStr.indexOf("\n", cursor); // Ищем перевод каретки
        // на новую строку
        QString s = "";
        if (index == -1) {
            getst = false;
            s.append(&list[cursor], printStr.length() - cursor);
        }
        else s.append(&list[cursor], index - cursor);
        cursor = index + 1;
        strlst << s;
    }

    QPainter painter;
    painter.begin(&printer);
    int h = painter.window().height();
    int amount = strlst.count();
    QFont font = painter.font();
    QFontMetrics fmetrics(font);

    for (int i = 0; i < amount; i++) {
        QPointF pf;
        pf.setX(10);
        pf.setY(line + 10);
        painter.drawText(pf, strlst.at(i));
        line += fmetrics.height();
        if (h - line <= fmetrics.height()) {
            printer.newPage();
            line = 0;
        }
    }

    painter.end();
}

void MainWindow::on_pushButton_clicked(){
    m_font = ui->textEdit->textCursor().charFormat().font(); // Сохраняем формат выделенного участка текста
}


void MainWindow::on_pushButton_2_clicked(){
    QTextCharFormat fmt;
    fmt.setFont(m_font);
    ui->textEdit->textCursor().setCharFormat(fmt); // Задаем формат выделенного участка текста
}

void MainWindow::on_pushButton_3_clicked(){
    QFont font = ui->textEdit->textCursor().charFormat().font(); // получаем текущий шрифт
    QFontDialog fntDlg(font,this);
    bool b[] = {true};
    font = fntDlg.getFont(b); // Запускаем диалог настройки шрифта
    if (b[0]) { // Если нажата кнопка OK, применяем новые настройки шрифта
        QTextCharFormat fmt;
        fmt.setFont(font);
        ui->textEdit->textCursor().setCharFormat(fmt);
    }
}

void MainWindow::on_comboBox_activated(int index){
    switch (index) {
        case 0: ui->textEdit->setAlignment(Qt::AlignLeft);      break;
        case 1: ui->textEdit->setAlignment(Qt::AlignCenter);    break;
        case 2: ui->textEdit->setAlignment(Qt::AlignRight);     break;
        default: break;
    }

}

void MainWindow::on_textEdit_cursorPositionChanged(){
    switch (ui->textEdit->alignment()) {
        case Qt::AlignLeft:     ui->comboBox->setCurrentIndex(0); break;
        case Qt::AlignCenter:   ui->comboBox->setCurrentIndex(1); break;
        case Qt::AlignRight:    ui->comboBox->setCurrentIndex(2); break;
        default: break;
    }
}

void MainWindow::on_pushButton_4_clicked(){
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString out = " ";
    out += QString::fromStdString(std::to_string(time.hour())) + ":";
    out += QString::fromStdString(std::to_string(time.minute())) + " ";

    out += QString::fromStdString(std::to_string(date.day())) + ".";
    out += QString::fromStdString(std::to_string(date.month())) + ".";
    out += QString::fromStdString(std::to_string(date.year())) + " ";
    ui->textEdit->textCursor().insertText(out);
}

