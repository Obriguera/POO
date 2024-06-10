#include <QApplication>
#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Admin admin;
    admin.iniciar();

    return a.exec();
}
