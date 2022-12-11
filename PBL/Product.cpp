#pragma once
#include "Product.h"
using namespace std;

Product::Product()
{
    this->Id = "";
    this->Name = "";
    this->Price = 0;
    this->Sales = 0;
}
Product::Product(string id, string name, int price, int sales) 
{
    this->Id = id;
    this->Name = name;
    this->Price = price;
    this->Sales = sales;
}
Product::~Product() 
{

}

string Product::getId() 
{
    return this->Id;
}
string Product::getName() 
{
    return this->Name;
}
int Product::getPrice() 
{
    return this->Price;
}
int Product::getSales() 
{
    return this->Sales;
}

void Product::setId(string id) 
{
    this->Id = id;
}
void Product::setName(string name) 
{
    this->Name = name;
}
void Product::setPrice(int price) 
{
    this->Price = price;
}
void Product::setSales(int sales) 
{
    this->Sales = sales;
}
void Product::upSale(int sale) 
{
    this->Sales += sale;
}

void Product::Show(int adr)
{
    cout << "             -----------------------------------------" << endl;
    cout << "                           Id: " << Id << endl;
    cout << "                           Name: " << Name << endl;
    cout << "                           Price: " << Library::printRevenues(Price,".") << endl;
    cout << "                           Sales: " << adr << endl;
    cout << endl;
}

void Product::PrintPr(ofstream& filename)
{

    filename << "             -----------------------------------------" << endl;
    filename << "                           Id: " << Id << endl;
    filename << "                           Name: " << Name << endl;
    filename << "                           Price: " << Library::printRevenues(Price, ".") << endl;
    filename << "                           Sales: " << Sales << endl;
    filename << endl;

}
istream& operator >> (istream& in, Product& x)
{
    cout << "\n\t\tId: ";
    in >> x.Id;
    cout << "\t\tName: ";
    in.ignore();
    getline(cin, x.Name);
    cout << "\t\tPrice: ";
    in >> x.Price;
    if (in.fail()) {
        Library::fail("\t\tPrice");
    }
    cout << "\t\tSales: ";
    in >> x.Sales;
    if (in.fail()) {
        Library::fail("\t\tSale");
    }
    cout << endl;
    return in;
}

