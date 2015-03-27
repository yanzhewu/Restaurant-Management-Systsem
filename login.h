#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "QtGui"
#include"resturant.h"
#include "QString"
#include "customerview.h"
#include "cashierview.h"
#include <QQueue>

namespace Ui {
    class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);   
    ~Login();
    int state;
    QString returnName();
    void setController(TableController* a);

private slots:
    void on_LoginButton_clicked();


private:
    Ui::Login *ui;
    customerView cv;
    cashierView ca;
    TableController *tmp;
    int customerNum;
    QQueue<Customer> list;



};

#endif // LOGIN_H
