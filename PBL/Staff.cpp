#include "Staff.h"
Staff::Staff()
{
    this->Id = "";
    this->Name = "";
    this->Password = "";
}
Staff::Staff(string id, string name, string password)
{
    this->Id = id;
    this->Name = name;
    this->Password = password;
}
Staff::~Staff() 
{

}

string Staff::getId() 
{
    return this->Id;
}
string Staff::getName() 
{
    return this->Name;
}
string Staff::getPassword() 
{
    return this->Password;
}

void Staff::setId(string id) 
{
    this->Id = id;
}
void Staff::setName(string name) 
{
    this->Name = name;
}
void Staff::setPassword(string password) 
{
    this->Password = password;
}
