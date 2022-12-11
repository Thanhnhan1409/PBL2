#pragma once
#include <iostream>

using namespace std;
class Manage 
{
protected:
    int length;
public:
    virtual int  getLength() = 0;
    virtual void setLength(int) = 0;
    virtual void readData(string) = 0;
    virtual void Remove(string) = 0;
    virtual void update(string) = 0;
    virtual void add() = 0;
    virtual void show() = 0;
    virtual void search() = 0;
    virtual void showRevenues()=0;
    virtual string getId() = 0;
};
