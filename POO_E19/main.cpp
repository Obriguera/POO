#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Pintura pintura;
    pintura.show();
    return a.exec();
}
