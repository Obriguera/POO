#include "lista.h"
#include "ui_lista.h"
#include "admindb.h"

Lista::Lista(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lista) {
    ui->setupUi(this);

    ui->twCoso->setColumnCount(3);
    ui->twCoso->setHeaderLabels({"ID", "Username", "Password"});

    QVector<QVector<QString>> users = AdminDB::getAllUsers();
    for (const auto& user : users) {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->twCoso);
        item->setText(0, user[0]);
        item->setText(1, user[1]);
        item->setText(2, user[2]);
    }
}

Lista::~Lista() {
    delete ui;
}
