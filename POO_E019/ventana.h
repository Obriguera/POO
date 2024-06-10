<<<<<<< HEAD
#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>

namespace Ui {
class Ventana;
}

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
=======
#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>

namespace Ui {
class Ventana;
}

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
>>>>>>> c0a71fc (01 06 24 update)
