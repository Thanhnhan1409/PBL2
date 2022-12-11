#pragma once

#include "Product.h"
#include "Cinema.h"
#include "vector.h"


using namespace std;
class Ticket : public Product
{
protected:
    string Seat;
    string Cine;
    string Time;
public:
    Ticket();
    ~Ticket();

    void setSeat(string);
    void setCine(string);
    void setTime(string);

    void Show();
    void Print();
    static void Reset();
};