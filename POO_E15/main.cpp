#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QMessageBox>

class Formulario : public QWidget {
public:
    Formulario(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *labelLegajo = new QLabel("Legajo:");
        QLabel *labelNombre = new QLabel("Nombre:");
        QLabel *labelApellido = new QLabel("Apellido:");
        QLabel *labelCaptcha = new QLabel("Captcha:");

        lineEditLegajo = new QLineEdit;
        lineEditNombre = new QLineEdit;
        lineEditApellido = new QLineEdit;
        lineEditCaptcha = new QLineEdit;
        QPushButton *buttonAceptar = new QPushButton("Aceptar");

        // Generar el número aleatorio para el captcha
        captcha = QRandomGenerator::global()->bounded(1000, 9999);
        QString captchaText = QString::number(captcha);
        QLabel *labelCaptchaValue = new QLabel(captchaText);

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelLegajo, 0, 0);
        layout->addWidget(lineEditLegajo, 0, 1);
        layout->addWidget(labelNombre, 1, 0);
        layout->addWidget(lineEditNombre, 1, 1);
        layout->addWidget(labelApellido, 2, 0);
        layout->addWidget(lineEditApellido, 2, 1);
        layout->addWidget(labelCaptcha, 3, 0);
        layout->addWidget(labelCaptchaValue, 3, 1);
        layout->addWidget(lineEditCaptcha, 4, 1);
        layout->addWidget(buttonAceptar, 5, 0, 1, 2);

        setLayout(layout);

        connect(buttonAceptar, &QPushButton::clicked, this, &Formulario::verificarFormulario);
    }

private:
    QLineEdit *lineEditLegajo;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditApellido;
    QLineEdit *lineEditCaptcha;
    int captcha;

    void verificarFormulario() {
        // Verificar si el captcha es correcto
        if (lineEditCaptcha->text().toInt() != captcha) {
            QMessageBox::critical(this, "Error", "Captcha incorrecto");
            return;
        }

        // Verificar si los campos del formulario están completos
        if (lineEditLegajo->text().isEmpty() || lineEditNombre->text().isEmpty() || lineEditApellido->text().isEmpty()) {
            QMessageBox::critical(this, "Error", "Por favor complete todos los campos");
            return;
        }

        // Si todo está correcto, cerrar la aplicación
        close();
    }
};

class Login : public QWidget {
public:
    Login(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *labelClave = new QLabel("Clave:");
        lineEditClave = new QLineEdit;
        lineEditClave->setEchoMode(QLineEdit::Password);
        QPushButton *buttonIngresar = new QPushButton("Ingresar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelClave, 0, 0);
        layout->addWidget(lineEditClave, 0, 1);
        layout->addWidget(buttonIngresar, 1, 0, 1, 2);

        setLayout(layout);

        connect(buttonIngresar, &QPushButton::clicked, this, &Login::verificarClave);
    }

private:
    QLineEdit *lineEditClave;

    void verificarClave() {
        if (lineEditClave->text() == "1111") {
            Formulario *formulario = new Formulario;
            formulario->show();
            close(); // Cerramos la ventana de login
        } else {
            QMessageBox::critical(this, "Error", "Clave incorrecta");
        }
    }

    // Capturar el evento de tecla presionada para simular el clic del botón "Ingresar"
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
