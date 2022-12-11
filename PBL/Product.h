
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"

using namespace std;
class Product
{
protected:
    string Id;
    string Name;
    int Price;
    int Sales;

public:
    Product();
    Product(string, string, int, int);
    ~Product();
    string getId();
    string getName();
    int getPrice();
    int getSales();
    

    void setId(string);
    void setName(string);
    void setPrice(int);
    void setSales(int);
    void upSale(int);
    friend istream& operator >> (istream&, Product&);

    void Show(int );
    void PrintPr(ofstream&);
};
