#include "manager.h"
#include <QDebug>

Manager::Manager(QObject *parent) : QObject(parent)
{
    loginWindow = new Login();
    adminDB = new AdminDB();
    mainWindow = new Ventana();

    connect(loginWindow, &Login::credentialsEntered, this, &Manager::handleLoginAttempt);
    connect(mainWindow, &Ventana::pbVolverClicked, this, &Manager::handleLogout);

    // Conectar la base de datos
    if (!adminDB->conectar("C:/Qt/db/db.sqlite")) {
        qDebug() << "No se pudo conectar a la base de datos";
    }

    loginWindow->show();
}

void Manager::handleLoginAttempt(const QString &username, const QString &password)
{
    if (adminDB->validarUsuario("usuarios", username, password)) {
        handleLoginSuccess();
    } else {
        qDebug() << "Usuario Inválido";
        loginWindow->show(); // Mostrar de nuevo la ventana de login si las credenciales son inválidas
    }
}

void Manager::handleLoginSuccess()
{
    loginWindow->close();
    mainWindow->show();
}

void Manager::handleLogout()
{
    mainWindow->close();
    loginWindow->show();
}
