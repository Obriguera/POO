<<<<<<< HEAD
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
=======
/*
CONSIGNA:
    -Diseñar un login con QGridLayout.
    -Usar asteriscos para la clave.
    -Detectar enter para simular la pulsación del botón.
    -Definir la clase Formulario que será un QWidget
    -Formulario tendrá QLabels y QLineEdits para Legajo, Nombre y Apellido, y un QPushButton
    -Si la clave ingresada es admin:1111, se cierra Login y se muestra Formulario
    -Si se ingresa otra clave se borrará el texto del QLineEdit de la clave.
*/

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
>>>>>>> c0a71fc (01 06 24 update)
