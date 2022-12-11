#pragma once
#include "Staff.h"
#include <iostream>
#include "vector.h"
//#include <vector>
#include <fstream>
#include <string>
class StaffManage
{
private:
    Staff* p;
    int length;
public:
    int Length();

    StaffManage();
    ~StaffManage();

    void getListStaff();
    bool check(string, string);
};

