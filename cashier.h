#ifndef CASHIER_H
#define CASHIER_H
#include<QString>
#include<tablecontroller.h>
#include<customer.h>

class Cashier
{
  int ID;
  QString Name;
  QString Password;
  //CashController cashcontrol;

public:
    Cashier();
    Cashier(QString Name, int i);
   // bool Login(QString id, QString password);
    bool setTable(TableController tc,Customer c);
    //Table pay(Customer tc);

};

#endif // CASHIER_H
