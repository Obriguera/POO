#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>

class Pintura : public QWidget {
    Q_OBJECT
public:
    Pintura(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(const QSize &newSize);

    bool drawing;
    QPoint lastPoint;
    QImage image;
    QColor color;
    int brushSize;
};

#endif // PINTURA_H
