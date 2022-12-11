#include "StaffManage.h"
using namespace std;
StaffManage::StaffManage() {
    this->p = nullptr;
    this->length = 0;
}
StaffManage::~StaffManage() {
    delete[] this->p;
}

int StaffManage::Length() {
    return this->length;
}

void StaffManage::getListStaff() 
{
    vector<string> lines;
    string line;
    string fileName = "Database\\Staff.txt";
    ifstream input_file(fileName);
    if (!input_file.is_open()) {
        cout << ("Could not open the file - '" + fileName + "'") << endl;
        return;
    }
    while (getline(input_file, line)) 
    {
        lines.push_back(line);
    }
    int k = lines.size();
    int i = 0;
    Staff* a = new Staff[k];
    for (int j = 0; j < k; j += 3) 
    {
        a[i].setId(lines[j]);
        a[i].setName(lines[j + 1]);
        a[i].setPassword(lines[j + 2]);
        i++;
    }
    input_file.close();
    delete[] p;
    this->length = i;
    this->p = a;
}
bool StaffManage::check(string id, string pass) 
{
    for (int i = 0; i < length; i++) 
    {
        if (p[i].getId() == id && p[i].getPassword() == pass) 
        {
            cout << "\t        Welcome " << p[i].getName() << " !";
            return true;
        }
    }
    return false;
}