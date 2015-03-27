#ifndef TABLE_H
#define TABLE_H
#include"customer.h"

class Table
{
    int size;
    double price;

    int TableID;
    bool isAvaliable;
public:
    Table();
    Table(int s, int id, int p, int t, bool ava);
    void setCustomer(Customer c);
    double getPrice();
    int getSize();
    int returnTableID();
    void setTableID(int i);
    bool isAva();
    void setState(bool a);
    int customerID;
};

#endif // TABLE_H
