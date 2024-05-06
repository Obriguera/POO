#include "pintura.h"

Pintura::Pintura(QWidget *parent) : QWidget(parent), color(Qt::black), brushSize(2) {
    image = QImage(400, 400, QImage::Format_RGB32);
    image.fill(Qt::white);
}

void Pintura::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        drawing = true;
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        drawLineTo(event->pos());
    }
}

void Pintura::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawLineTo(event->pos());
        drawing = false;
    }
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_R) {
        color = Qt::red;
    } else if (event->key() == Qt::Key_G) {
        color = Qt::green;
    } else if (event->key() == Qt::Key_B) {
        color = Qt::blue;
    } else if (event->key() == Qt::Key_Escape) {
        image.fill(Qt::white);
        update();
    }
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(0, 0, image);
}

void Pintura::wheelEvent(QWheelEvent *event) {
    int delta = event->angleDelta().y();
    if (delta > 0) {
        // Ampliar el tamaño del trazo
        brushSize++;
    } else {
        // Disminuir el tamaño del trazo
        if (brushSize > 1) {
            brushSize--;
        }
    }
}

void Pintura::drawLineTo(const QPoint &endPoint) {
    QPainter painter(&image);
    painter.setPen(QPen(color, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    update();
}

void Pintura::resizeEvent(QResizeEvent *event) {
    if (event->size().width() > image.width() || event->size().height() > image.height()) {
        QSize newSize(qMax(event->size().width(), image.width()), qMax(event->size().height(), image.height()));
        resizeImage(newSize);
        update();
    }
    QWidget::resizeEvent(event);
}

void Pintura::resizeImage(const QSize &newSize) {
    if (image.size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), image);
    image = newImage;
}
