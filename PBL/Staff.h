#pragma once
#include <iostream>
#include "vector.h"
//#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Staff
{
protected:
    string Name;
    string Id;
    string Password;
public:
    Staff();
    Staff(string, string, string);
    ~Staff();

    string getId();
    string getName();
    string getPassword();

    void setId(string);
    void setName(string);
    void setPassword(string);
};

