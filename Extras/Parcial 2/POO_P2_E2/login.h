#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admindb.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(AdminDB *adminDB, QWidget *parent = nullptr);
    ~Login();

signals:
    void signal_usuarioValidado();

private slots:
    void on_pbLogin_clicked();

private:
    Ui::Login *ui;
    AdminDB *adminDB;
};

#endif // LOGIN_H
