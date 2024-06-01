#include "parser.h"
#include <QRegularExpression>

Parser::Parser(QObject *parent) : QObject(parent) {}

QVector<QUrl> Parser::parseHtmlForUrls(const QByteArray &html) {
    QVector<QUrl> urls;
    QString htmlString(html);

    // Expresión regular para encontrar URLs en el HTML
    QRegularExpression regex("<a\\s+(?:[^>]*?\\s+)?href\\s*=\\s*([\"\'])(.*?)\\1");

    // Coincidencias de todas las URLs encontradas en el HTML
    QRegularExpressionMatchIterator matches = regex.globalMatch(htmlString);

    // Iterar sobre todas las coincidencias y extraer las URLs
    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        if (match.hasMatch()) {
            QString urlString = match.captured(2);
            QUrl url(urlString);
            if (url.isValid()) {
                urls.append(url);
            }
        }
    }

    return urls;
}
