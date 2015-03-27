#ifndef RESTURANT_H
#define RESTURANT_H
#include"cashier.h"
#include"customer.h"
#include"tablecontroller.h"

class Resturant
{
    TableController tableController;
    Cashier cs;
    Customer ct;
public:
    Resturant();


};

#endif // RESTURANT_H
