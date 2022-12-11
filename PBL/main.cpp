#include <iostream>
#include "MenuUser.h"
using namespace std;
void Menu()
{
    while (true)
    {
        system("cls");
        GuestMenu::Menu("Database\\Menu.txt");
        cout << endl;
        cout << "\t\tEnter your selection: ";
        int c = 0;
        cin >> c;
        while (cin.fail())
        {
            Library::printError("\t\tNumber please!");
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\t\tEnter your selection: ";
            cin >> c;
        }
        switch (c)
        {
        case 1:
        {
            GuestMenu::Display();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\n";
            string s = StaffMenu::logIn();
            if (s == "Menu") continue;
            if (s == "Exit") return;
            break;
        }
        case 3:
        {
            return;
            break;
        }
        default:
        {
            Library::printError("Select from 1 to 3");
            system("pause");
            break;
        }
        }
    }
}
int main() 
{

    Menu();
    system("pause");
    return 0;
}