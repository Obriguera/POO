#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void handleButtonClick();  // Slot para manejar el clic del botón
    void onImageDownloaded(QNetworkReply* reply);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Ventana *ui;
    QNetworkAccessManager *networkManager;
    QImage backgroundImage;
};

#endif // VENTANA_H
