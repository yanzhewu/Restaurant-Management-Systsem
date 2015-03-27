#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<QString>


class Customer
{
    int ID;
    QString Name;

public:
    Customer();
    Customer(int i, QString n);
    //QString checkDeskBySize(TableController tc, int size);
    void Register();
    //QString checkDeskByID(TableController tc, QString id);
    int getID();
    void setTableID(int i);
    QString getName();
    int tableID;


};

#endif // CUSTOMER_H
