#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

namespace Ui {
class ventana;
}

class ventana : public QWidget
{
    Q_OBJECT

public:
    explicit ventana(QWidget *parent = nullptr);
    ~ventana();
    bool es_admin;


private:
    Ui::ventana *ui;

private slots:
    void slot_bienvenido();
};

#endif // VENTANA_H
