#ifndef DESCARGADOR_H
#define DESCARGADOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Descargador : public QWidget
{
    Q_OBJECT
public:
    explicit Descargador(QWidget *parent = nullptr);
    ~Descargador();

private slots:
    void descargarImagen();
    void descargaFinalizada(QNetworkReply *reply);
    void actualizarProgreso(qint64 bytesRecibidos, qint64 bytesTotales);

private:
    QLineEdit *urlLineEdit;
    QPushButton *descargarButton;
    QProgressBar *progressBar;
    QImage imagen;
    QNetworkAccessManager *networkManager;
    void paintEvent(QPaintEvent *);
    void iniciarInterfaz();
};

#endif // DESCARGADOR_H
