#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void credentialsEntered(const QString &username, const QString &password);

private slots:
    void on_loginButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
