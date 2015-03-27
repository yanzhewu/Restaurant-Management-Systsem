#include "table.h"
#include<QtGui>

Table::Table()
{
}
Table::Table(int s, int id, int p, int t, bool ava){
   size = s;
   price = p;
   TableID = id;
   customerID = t;
   isAvaliable =ava;
}

double Table::getPrice(){
    return price;
}

int Table::getSize(){
    return size;
}

void Table::setCustomer(Customer c){
    customerID = c.getID();
    c.setTableID(TableID);
}

int Table::returnTableID(){
    return TableID;
}

void Table::setTableID(int i){
    TableID=i;
}

bool Table::isAva(){
    return isAvaliable;
}

void Table::setState(bool a){
    isAvaliable = a;
}
