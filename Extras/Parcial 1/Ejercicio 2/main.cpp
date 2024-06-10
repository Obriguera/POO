#include "descargador.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Descargador w;
    w.show();
    return a.exec();
}
