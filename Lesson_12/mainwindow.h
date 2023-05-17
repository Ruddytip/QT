#pragma once
#include <QMainWindow>
#include "downloader.h"
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Downloader* downloader;
    QProgressBar* ppb;
    QLineEdit* txt;
    QPushButton* button;

    void showPic(const QString&);

private slots:
  void slotGo();
  void slotError();
  void slotDownloadProgress(qint64, qint64);
  void slotDone(const QUrl&, const QByteArray&);

};
