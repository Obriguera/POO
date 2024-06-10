#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>
#include <ventana.h>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class Acceso; }
QT_END_NAMESPACE

//Clase que hereda de QWidget
class Acceso : public QWidget
{
    Q_OBJECT

public:
    Acceso(QWidget *parent = nullptr);
    ~Acceso();

private:
    Ui::Acceso *ui;
    ventana * ventana;

private slots:
    void slot_validar();
    void slot_descargaFinalizada( QNetworkReply * reply );
protected:
    void paintEvent( QPaintEvent * );
    QImage im;
    QNetworkAccessManager * manager;

};
#endif // ACCESO_H
