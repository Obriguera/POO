/*
CONSIGNA:
    -En un Empty qmake Project
    -En la función main crear un objeto de la clase QLabel, uno de QWidget, uno de QPushButton y uno de QLineEdit
    -Invocar al método show() de cada uno de estos 4 objetos
    -Notar que cada objeto se muestra independiente
*/


#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Etiqueta");
    QWidget widget;
    QPushButton button("Botón");
    QLineEdit lineEdit;

    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
