#include "customer.h"

Customer::Customer(){

}

Customer::Customer(int i, QString n)
{
    ID = i;
    Name = n;
}

void Customer::setTableID(int i){
    tableID = i;
}

int Customer::getID(){
    return ID;
}

QString Customer::getName(){
    return Name;
}
