#ifndef USERLISTWINDOW_H
#define USERLISTWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

namespace Ui {
class Lista;
}

class Lista : public QMainWindow {
    Q_OBJECT

public:
    explicit Lista(QWidget *parent = nullptr);
    ~Lista();

private:
    Ui::Lista *ui;
};

#endif // USERLISTWINDOW_H
