#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QVector>
#include "rectangulo.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    QVector<Rectangulo> rectangulos;
    void cargarRectangulosDeDB();
};

#endif // PRINCIPAL_H
