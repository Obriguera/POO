#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>

class Formulario : public QWidget {
public:
    Formulario(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *labelLegajo = new QLabel("Legajo:");
        QLabel *labelNombre = new QLabel("Nombre:");
        QLabel *labelApellido = new QLabel("Apellido:");

        lineEditLegajo = new QLineEdit;
        lineEditNombre = new QLineEdit;
        lineEditApellido = new QLineEdit;

        QPushButton *button = new QPushButton("Aceptar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelLegajo, 0, 0);
        layout->addWidget(lineEditLegajo, 0, 1);
        layout->addWidget(labelNombre, 1, 0);
        layout->addWidget(lineEditNombre, 1, 1);
        layout->addWidget(labelApellido, 2, 0);
        layout->addWidget(lineEditApellido, 2, 1);
        layout->addWidget(button, 3, 0, 1, 2);

        setLayout(layout);

        connect(button, &QPushButton::clicked, this, &Formulario::cerrarVentana);
    }

private:
    QLineEdit *lineEditLegajo;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditApellido;

    void cerrarVentana() {
        close();
    }
};

class Login : public QWidget {
public:
    Login(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *labelClave = new QLabel("Clave:");
        lineEditClave = new QLineEdit;
        lineEditClave->setEchoMode(QLineEdit::Password);
        QPushButton *button = new QPushButton("Ingresar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelClave, 0, 0);
        layout->addWidget(lineEditClave, 0, 1);
        layout->addWidget(button, 1, 0, 1, 2);

        setLayout(layout);

        connect(button, &QPushButton::clicked, this, &Login::verificarClave);
    }

private:
    QLineEdit *lineEditClave;

    void verificarClave() {
        if (lineEditClave->text() == "1111") {
            Formulario *formulario = new Formulario;
            formulario->show();
            close();
        } else {
            lineEditClave->clear();
        }
    }

    // Capturar el evento de tecla presionada para detectar Enter
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
            verificarClave();
        } else {
            QWidget::keyPressEvent(event);
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login login;
    login.show();

    return a.exec();
}
