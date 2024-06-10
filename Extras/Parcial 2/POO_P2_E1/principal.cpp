#include "principal.h"
#include "ui_principal.h"
#include "admindb.h"
#include <QPainter>
#include <QSqlQuery>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    setFixedSize(300, 300);

    cargarRectangulosDeDB();
}

Principal::~Principal()
{
    delete ui;
    AdminDB::close();
}

void Principal::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (const Rectangulo &rect : rectangulos) {
        painter.drawRect(rect.getX(), rect.getY(), rect.getAncho(), rect.getAlto());
    }
}

void Principal::cargarRectangulosDeDB()
{
    QSqlDatabase db = AdminDB::getInstance();
    QSqlQuery query(db);
    query.exec("SELECT * FROM rectangulos");
    while (query.next()) {
        int x = query.value("x").toInt();
        int y = query.value("y").toInt();
        int ancho = query.value("ancho").toInt();
        int alto = query.value("alto").toInt();
        rectangulos.append(Rectangulo(x, y, ancho, alto));
    }
}
