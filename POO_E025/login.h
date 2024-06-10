// login.h
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void on_lregistrar_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
