#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class Registro;
}

class Registro : public QDialog {
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();

private slots:
    void on_registerButton_clicked();

private:
    Ui::Registro *ui;
};

#endif // REGISTERWINDOW_H
