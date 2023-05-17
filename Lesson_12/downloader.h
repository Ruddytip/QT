#pragma once
#include <QObject>
#include <QNetworkAccessManager>

class Downloader : public QObject {
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = nullptr);
    virtual ~Downloader() {}
    void download(const QUrl&);

signals:
    void downloadProgress(qint64, qint64);
    void done(const QUrl&, const QByteArray&);
    void error();

private slots:
    void slotFinished(QNetworkReply*);

private:
    QNetworkAccessManager* pnam;

};
