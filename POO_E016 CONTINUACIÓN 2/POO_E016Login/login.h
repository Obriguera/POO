#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void onReplyFinished(QNetworkReply* reply);

private:
    Ui::Login *ui;
    QNetworkAccessManager *networkManager;
};

#endif // LOGIN_H
