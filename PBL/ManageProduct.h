#pragma once
#include "Product.h"
#include "Ticket.h"
#include "MenuUser.h"
#include "Manage.h"


class ManageProduct :public Manage
{
protected:
    Product* p;
public:
    ManageProduct();
    ManageProduct(Product*, int);
    ~ManageProduct();

    int getLength();
    void setLength(int);

    void readData(string);
    void Remove(string);
    void add();
    void show();
    void search();
    void update(string);
    string getId();

    void WriteFile(ofstream&);
    void resetSales(string);
    void updateSale(string , string, int);
    void showRevenues();
    void showProduct(string);
        

    Product getProduct(string);
    Product& operator[](const int);
};
