#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "parser.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:
    void downloadFinished(bool success, const QString &filePath);

private slots:
    void onDownloadButtonClicked();
    void onChooseDirectoryButtonClicked();
    void onChooseImageButtonClicked();
    void onDownloadFinished(bool success, const QString &filePath);
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onNetworkReplyFinished(QNetworkReply *reply);
    void paintEvent(QPaintEvent *event);

private:
    QLineEdit *urlLineEdit;
    QPushButton *downloadButton;
    QPushButton *chooseDirectoryButton;
    QPushButton *chooseImageButton;
    QTextEdit *logTextEdit;
    Parser *parser;
    QNetworkAccessManager *networkManager;
    QNetworkReply *htmlReply;
    QList<QNetworkReply*> resourceReplies;
    QString downloadDirectory;
    QString imagePath;
};

#endif // MAINWINDOW_H
