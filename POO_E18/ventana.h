<<<<<<< HEAD
#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QtDebug>
#include <QtNetwork>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;

private slots:
    void slot_mostrar_html();
};

#endif // VENTANA_H
=======
#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QtDebug>
#include <QtNetwork>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;

private slots:
    void slot_mostrar_html();
};

#endif // VENTANA_H
>>>>>>> c0a71fc (01 06 24 update)
