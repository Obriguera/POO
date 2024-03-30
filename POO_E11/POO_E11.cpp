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
