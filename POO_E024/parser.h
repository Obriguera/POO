#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QByteArray>
#include <QVector>
#include <QUrl>

class Parser : public QObject {
    Q_OBJECT

public:
    explicit Parser(QObject *parent = nullptr);

signals:
    void downloadFinished(bool success, const QString &filePath);

public slots:
    QVector<QUrl> parseHtmlForUrls(const QByteArray &html);

private:
    // Aquí puedes agregar cualquier método adicional que necesites para analizar el HTML
};

#endif // PARSER_H
