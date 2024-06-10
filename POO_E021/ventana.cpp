#include "ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    pbVolver = new QPushButton("Volver", this);
    connect(pbVolver, &QPushButton::clicked, this, &Ventana::on_pbVolver_clicked);
}

void Ventana::on_pbVolver_clicked()
{
    emit pbVolverClicked();
}
