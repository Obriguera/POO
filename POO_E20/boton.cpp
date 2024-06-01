#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) : QWidget(parent), m_color(Qt::red) {}

void Boton::colorear(Color color) {
    switch (color) {
        case Rojo:
            m_color = Qt::red;
            break;
        case Azul:
            m_color = Qt::blue;
            break;
        case Verde:
            m_color = Qt::green;
            break;
    }
    update(); // Fuerza la actualización del widget
}

void Boton::setText(const QString &text) {
    m_text = text;
    update();  // Fuerza la actualización del widget para mostrar el nuevo texto
}

QString Boton::text() const {
    return m_text;
}

void Boton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(), m_color);
    painter.drawText(rect(), Qt::AlignCenter, m_text);  // Dibuja el texto en el centro del botón
}

void Boton::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    // Cambiar de color al hacer clic, alternando entre rojo, azul y verde.
    if (m_color == Qt::red) {
        colorear(Azul);
    } else if (m_color == Qt::blue) {
        colorear(Verde);
    } else {
        colorear(Rojo);
    }
    emit signal_clic();  // Emitir la señal cuando se hace clic
}
