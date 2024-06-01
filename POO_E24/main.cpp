/*
Consigna:
    -Crear un parser que pueda analizar cualquier html en busca de todas las URLs que encuentre
    -Crear una GUI que permita al usuario ingresar un sitio web en un QLineEdit
    -Que descargue en archivos todos los recursos de dicho sitio web
    -Es decir, que busque en el html las imágenes, los css, los javascript y los descargue en archivos
    -Que le permita al usuario indicar en qué directorio descargar los archivos
    -También agregar un botón que upermita elegir un archivo de imagen del disco con QFileDialog y que la dibuje en pantalla con paintEvent.
*/

#include <QApplication>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>
#include "main.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    urlLineEdit = new QLineEdit(this);
    urlLineEdit->setPlaceholderText("Cargue una URL del sitio");

    downloadButton = new QPushButton("Desgargar recursos", this);
    chooseDirectoryButton = new QPushButton("Elija un directorio de descarga", this);
    chooseImageButton = new QPushButton("Elija una imagen para mostrar", this);
    logTextEdit = new QTextEdit(this);
    logTextEdit->setReadOnly(true);

    layout->addWidget(urlLineEdit);
    layout->addWidget(downloadButton);
    layout->addWidget(chooseDirectoryButton);
    layout->addWidget(chooseImageButton);
    layout->addWidget(logTextEdit);

    setLayout(layout);

    parser = new Parser(this);
    networkManager = new QNetworkAccessManager(this);

    connect(downloadButton, &QPushButton::clicked, this, &MainWindow::onDownloadButtonClicked);
    connect(chooseDirectoryButton, &QPushButton::clicked, this, &MainWindow::onChooseDirectoryButtonClicked);
    connect(chooseImageButton, &QPushButton::clicked, this, &MainWindow::onChooseImageButtonClicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onNetworkReplyFinished); // Corregido aquí
    connect(parser, &Parser::downloadFinished, this, &MainWindow::onDownloadFinished);
}

void MainWindow::onDownloadButtonClicked() {
    QString urlString = urlLineEdit->text();
    if (urlString.isEmpty()) {
        logTextEdit->append("La URL no puede estar vacía.");
        return;
    }
    if (downloadDirectory.isEmpty()) {
        logTextEdit->append("Debe elegir un directorio de descarga primero.");
        return;
    }

    QUrl url(urlString);
    if (!url.isValid()) {
        logTextEdit->append("URL inválida.");
        return;
    }

    QNetworkRequest request(url);
    htmlReply = networkManager->get(request);
    if (htmlReply) {
        connect(htmlReply, &QNetworkReply::downloadProgress, this, &MainWindow::onDownloadProgress);
        logTextEdit->append("Descargando recursos...");
    }
}

void MainWindow::onNetworkReplyFinished(QNetworkReply *reply) {
    if (reply == htmlReply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray htmlContent = reply->readAll();
            QVector<QUrl> urls = parser->parseHtmlForUrls(htmlContent);
            for (const QUrl &url : urls) {
                QNetworkRequest request(url);
                QNetworkReply *resourceReply = networkManager->get(request);
                resourceReplies.append(resourceReply);
            }
        } else {
            logTextEdit->append("No se pudo descargar el contenido de la página: " + reply->errorString());
        }
        reply->deleteLater();
        htmlReply = nullptr;
    } else if (resourceReplies.contains(reply)) {
        if (reply->error() == QNetworkReply::NoError) {
            QString filePath = downloadDirectory + "/" + QFileInfo(reply->url().path()).fileName();
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(reply->readAll());
                file.close();
                emit downloadFinished(true, filePath);
                logTextEdit->append("Descargando recurso: " + filePath);
            } else {
                emit downloadFinished(false, filePath);
                logTextEdit->append("Error al guardar el archivo: " + filePath);
            }
        } else {
            logTextEdit->append("Error al descargar el recurso: " + reply->errorString());
            emit downloadFinished(false, "");
        }
        reply->deleteLater();
        resourceReplies.removeOne(reply);
    }
}

void MainWindow::onChooseDirectoryButtonClicked() {
    QString directory = QFileDialog::getExistingDirectory(this, "Elija un directorio");
    if (!directory.isEmpty()) {
        downloadDirectory = directory;
        logTextEdit->append("Directorio de descarga establecido a: " + downloadDirectory);
    }
}

void MainWindow::onChooseImageButtonClicked() {
    QString file = QFileDialog::getOpenFileName(this, "Elegir imagen", QString(), "Images (*.png *.xpm *.jpg)");
    if (!file.isEmpty()) {
        imagePath = file;
        logTextEdit->append("Imagen elegida: " + imagePath);
        update();
    }
}

void MainWindow::onDownloadFinished(bool success, const QString &filePath) {
    if (success) {
        logTextEdit->append("Descargado: " + filePath);
    } else {
        logTextEdit->append("Error al descargar: " + filePath);
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (!imagePath.isEmpty()) {
        QImage image(imagePath);
        painter.drawImage(rect(), image);
    }
}

void MainWindow::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal) {
    if (bytesTotal > 0) {
        int percent = static_cast<int>((bytesReceived * 100) / bytesTotal);
        logTextEdit->append("Descargando: " + QString::number(percent) + "%");
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
