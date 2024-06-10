#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPainter>


class Formulario : public QWidget {
public:
    Formulario(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *labelLegajo = new QLabel("Legajo:");
        QLabel *labelNombre = new QLabel("Nombre:");
        QLabel *labelApellido = new QLabel("Apellido:");
        lineEditLegajo = new QLineEdit;
        lineEditNombre = new QLineEdit;
        lineEditApellido = new QLineEdit;
        QPushButton *button = new QPushButton("Aceptar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelLegajo, 0, 0);
        layout->addWidget(lineEditLegajo, 0, 1);
        layout->addWidget(labelNombre, 1, 0);
        layout->addWidget(lineEditNombre, 1, 1);
        layout->addWidget(labelApellido, 2, 0);
        layout->addWidget(lineEditApellido, 2, 1);
        layout->addWidget(button, 3, 0, 1, 2);

        setLayout(layout);

        connect(button, &QPushButton::clicked, this, &Formulario::cerrarVentana);
    }

private:
    QLineEdit *lineEditLegajo;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditApellido;

    void cerrarVentana() {
        close();
    }
};

class Login : public QWidget {
public:
    Login(QWidget *parent = nullptr) : QWidget(parent), tempNum(new QLabel("0")), imagenFondoDownloaded(false) {
        QLabel *labelClave = new QLabel("Clave:");
        lineEditClave = new QLineEdit;
        lineEditClave->setEchoMode(QLineEdit::Password);
        QPushButton *button = new QPushButton("Ingresar");
        QLabel *labelTemp = new QLabel("Temperatura:");
        hideTemp = new QPushButton("Ocultar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelClave, 0, 0);
        layout->addWidget(lineEditClave, 0, 1);
        layout->addWidget(button, 1, 0, 1, 2);
        layout->addWidget(labelTemp, 4, 0, 2, 1);
        layout->addWidget(tempNum, 4, 1, 2, 3);
        layout->addWidget(hideTemp, 6, 1, 2, 3);
        setLayout(layout);

        connect(button, &QPushButton::clicked, this, &Login::verificarClave);
        connect(hideTemp, &QPushButton::clicked, this, &Login::toggleTempNum);
        connect(&manager, &QNetworkAccessManager::finished, this, &Login::slot_descargaFinalizada);

        obtenerTemperatura();
    }

    void setBackgroundImage(const QString &imageUrl) {
        obtenerImagenFondo(imageUrl);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        if (!imagenFondo.isNull() && imagenFondoDownloaded) {
            painter.drawImage(0, 0, imagenFondo.scaled(size())); // Escalar la imagen al tamaño del widget
        }
        // Dibujar otros elementos sobre la imagen de fondo...
    }

private:
    QLineEdit *lineEditClave;
    QLabel *tempNum;
    QPushButton *hideTemp;
    QImage imagenFondo;
    QNetworkAccessManager manager;
    bool imagenFondoDownloaded;

    void toggleTempNum() {
            if (tempNum->isVisible()) {
                tempNum->hide();
                hideTemp->setText("Mostrar");
            } else {
                tempNum->show();
                hideTemp->setText("Ocultar");
            }
        }

    void verificarClave() {
        if (lineEditClave->text() == "1111") {
            Formulario *formulario = new Formulario;
            formulario->show();
            close();
        } else {
            lineEditClave->clear();
        }
    }

    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
            verificarClave();
        } else {
            QWidget::keyPressEvent(event);
        }
    }

    void obtenerTemperatura()
    {
        manager.get(QNetworkRequest(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Cordoba&appid=7f63e534bedc6a1a5330982f6812ab10")));
    }

    void obtenerImagenFondo(const QString &imageUrl)
    {
        manager.get(QNetworkRequest(QUrl(imageUrl)));
    }

    void slot_descargaFinalizada(QNetworkReply *reply) {
            if (reply->error() == QNetworkReply::NoError) {
                if (reply->url().toString() == "http://api.openweathermap.org/data/2.5/weather?q=Cordoba&appid=7f63e534bedc6a1a5330982f6812ab10") {
                    QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
                    QJsonObject jsonObject = jsonResponse.object();
                    double temperatura = jsonObject["main"].toObject()["temp"].toDouble() - 273.15; // Convertir de Kelvin a Celsius
                    tempNum->setText(QString(" %1 °C").arg(temperatura));
                } else {
                    QByteArray imageData = reply->readAll();
                    imagenFondo.loadFromData(imageData);
                    imagenFondoDownloaded = true;
                    update();
                }
            } else {
                qDebug() << "Error al obtener la respuesta:" << reply->errorString();
            }
            reply->deleteLater();
        }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login login;
    login.setBackgroundImage("https://miielts.com/wp-content/uploads/2019/11/NZ-2-1200x800.jpg");
    login.show();

    return a.exec();
}
