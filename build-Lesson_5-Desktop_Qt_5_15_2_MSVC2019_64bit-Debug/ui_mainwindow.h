/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *CreateNewFile;
    QAction *OpenFile;
    QAction *OpenFileOnlyRead;
    QAction *Save;
    QAction *SaveHow;
    QAction *Copy;
    QAction *Paste;
    QAction *Undo;
    QAction *Clear;
    QAction *ShowInfo;
    QAction *Binds;
    QAction *Rus;
    QAction *Eng;
    QAction *Light;
    QAction *Dark;
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *File;
    QMenu *Correction;
    QMenu *View;
    QMenu *Langue;
    QMenu *Theme;
    QMenu *Info;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        CreateNewFile = new QAction(MainWindow);
        CreateNewFile->setObjectName(QString::fromUtf8("CreateNewFile"));
        OpenFile = new QAction(MainWindow);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        OpenFileOnlyRead = new QAction(MainWindow);
        OpenFileOnlyRead->setObjectName(QString::fromUtf8("OpenFileOnlyRead"));
        Save = new QAction(MainWindow);
        Save->setObjectName(QString::fromUtf8("Save"));
        SaveHow = new QAction(MainWindow);
        SaveHow->setObjectName(QString::fromUtf8("SaveHow"));
        Copy = new QAction(MainWindow);
        Copy->setObjectName(QString::fromUtf8("Copy"));
        Paste = new QAction(MainWindow);
        Paste->setObjectName(QString::fromUtf8("Paste"));
        Undo = new QAction(MainWindow);
        Undo->setObjectName(QString::fromUtf8("Undo"));
        Clear = new QAction(MainWindow);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        ShowInfo = new QAction(MainWindow);
        ShowInfo->setObjectName(QString::fromUtf8("ShowInfo"));
        Binds = new QAction(MainWindow);
        Binds->setObjectName(QString::fromUtf8("Binds"));
        Rus = new QAction(MainWindow);
        Rus->setObjectName(QString::fromUtf8("Rus"));
        Eng = new QAction(MainWindow);
        Eng->setObjectName(QString::fromUtf8("Eng"));
        Light = new QAction(MainWindow);
        Light->setObjectName(QString::fromUtf8("Light"));
        Dark = new QAction(MainWindow);
        Dark->setObjectName(QString::fromUtf8("Dark"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 801, 551));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        File = new QMenu(menubar);
        File->setObjectName(QString::fromUtf8("File"));
        Correction = new QMenu(menubar);
        Correction->setObjectName(QString::fromUtf8("Correction"));
        View = new QMenu(menubar);
        View->setObjectName(QString::fromUtf8("View"));
        Langue = new QMenu(View);
        Langue->setObjectName(QString::fromUtf8("Langue"));
        Theme = new QMenu(View);
        Theme->setObjectName(QString::fromUtf8("Theme"));
        Info = new QMenu(menubar);
        Info->setObjectName(QString::fromUtf8("Info"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(File->menuAction());
        menubar->addAction(Correction->menuAction());
        menubar->addAction(View->menuAction());
        menubar->addAction(Info->menuAction());
        File->addAction(CreateNewFile);
        File->addAction(OpenFile);
        File->addAction(OpenFileOnlyRead);
        File->addAction(Save);
        File->addAction(SaveHow);
        Correction->addAction(Copy);
        Correction->addAction(Paste);
        Correction->addAction(Undo);
        Correction->addAction(Clear);
        View->addAction(Langue->menuAction());
        View->addAction(Theme->menuAction());
        Langue->addAction(Rus);
        Langue->addAction(Eng);
        Theme->addAction(Light);
        Theme->addAction(Dark);
        Info->addAction(ShowInfo);
        Info->addAction(Binds);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CreateNewFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(shortcut)
        CreateNewFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        OpenFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(shortcut)
        OpenFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        OpenFileOnlyRead->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\202\320\276\320\273\321\214\320\272\320\276 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
#if QT_CONFIG(shortcut)
        OpenFileOnlyRead->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        Save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        SaveHow->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
#if QT_CONFIG(shortcut)
        SaveHow->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        Copy->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        Copy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        Paste->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        Paste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        Undo->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        Undo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        Clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        Clear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        ShowInfo->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\276\321\207\320\275\321\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", nullptr));
#if QT_CONFIG(shortcut)
        ShowInfo->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        Binds->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\207\320\265\321\202\320\260\320\275\320\270\321\217 \320\272\320\273\320\260\320\262\320\270\321\210", nullptr));
#if QT_CONFIG(shortcut)
        Binds->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        Rus->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        Eng->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\270\320\271", nullptr));
        Light->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217", nullptr));
        Dark->setText(QCoreApplication::translate("MainWindow", "\320\242\321\221\320\274\320\275\320\260\321\217", nullptr));
        File->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        Correction->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        View->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264", nullptr));
        Langue->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\217\320\267\321\213\320\272", nullptr));
        Theme->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\274\320\260", nullptr));
        Info->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
