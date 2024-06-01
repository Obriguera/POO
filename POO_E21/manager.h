#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "login.h"
#include "admindb.h"
#include "ventana.h"

class Manager : public QObject
{
    Q_OBJECT

public:
    explicit Manager(QObject *parent = nullptr);

private slots:
    void handleLoginAttempt(const QString &username, const QString &password);
    void handleLoginSuccess();
    void handleLogout();

private:
    Login *loginWindow;
    AdminDB *adminDB;
    Ventana *mainWindow;
};

#endif // MANAGER_H
