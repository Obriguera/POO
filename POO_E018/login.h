<<<<<<< HEAD
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "ventana.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    Ventana * ventana;

private slots:
    void slot_validar();
};
#endif // LOGIN_H
=======
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "ventana.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    Ventana * ventana;

private slots:
    void slot_validar();
};
#endif // LOGIN_H
>>>>>>> c0a71fc (01 06 24 update)
