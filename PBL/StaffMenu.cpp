#pragma once
#include"MenuUser.h"
using namespace std;
void StaffMenu::Menu() {
    cout << endl;
    GuestMenu::Menu("Database\\StaffMenu.txt");
    cout << endl;
}
void StaffMenu::Display() {
    system("cls");
    int c;
    MovieManager listMovies;
    listMovies.readData("Database\\Movie\\movie.txt");
    bool tr = true;
    while (tr)
    {
    StaffMenu::Menu();
    cout << "\t\tEnter your selection: ";
    cin >> c;
    if (cin.fail())
    {   
        c = Library::fail("\t\tEnter your selection");

    }
    if (c >= 0 || c <= 7)
        tr = false;
    cout << endl;
    switch (c) 
    {
        case 1: 
        {
            system("cls");
            StaffMenu::getInfoMovie(listMovies);
            listMovies.readData("Database\\Movie\\movie.txt");
            break;
        }
        case 2: 
        {
            string x = GuestMenu::buyTicketsMovie();
            if (x == "Menu") StaffMenu::Display();
            if (x == "Exit") return;
            break;
        }
        case 3: 
        {
            bool t1 = true;
            while(t1)
            {
                system("cls");
                cout << endl;
                GuestMenu::Menu("Database\\Movie\\MovieManage.txt");
                cout << endl;
                cout << "\t\tEnter your selection: ";
                int c = 0;
                cin >> c;
                if (c >= 0 || c <= 7)
                    t1 = false;
                if (cin.fail())
                {
                    c = Library::fail("\t\tEnter your selection");

                }
                switch (c)
                {
                    case 1: 
                    {
                        Movie m = listMovies.createMovie();
                        listMovies.addMovie(m);
                        cout << endl;
                        cout << "\n\t\t1. Back to Menu.\n";
                        cout << "\t\t2. Exit.\n";
                        cout << "\t\tEnter your selection: ";
                        int c = 0;
                        cin >> c;
                        if (cin.fail())
                        {
                            c = Library::fail("\t\tEnter your selection");

                        }
                        while ((c <= 0 || c > 2)) {
                            Library::printError("Please select from the list");
                            cin >> c;
                        }
                        if (c == 1) {
                            StaffMenu::Display();
                        }
                        if (c == 2) {
                            return;
                        }
                        break;
                    }
                    case 2: 
                    {
                        system("cls");
                        Movie m;
                        int n = listMovies.getLength();
                        listMovies.show();
                        int c = 0;
                        cout << endl;
                        cout << "\t         " << n + 1 << ". Back to Menu." << endl;
                        cout << "\t         " << n + 2 << ".Exit." << endl;
                        cout << "\n\t         Enter your selection: ";
                        cin >> c;
                        if (cin.fail()) {
                            c = Library::fail("\nEnter your selection: ");
                        }
                        while ((c <= 0 || c > n + 2)) {
                            cout << "Please select from the list: ";
                            cin >> c;
                            if (cin.fail()) {
                                c = Library::fail("\nEnter your selection: ");
                            }
                        }
                        if (c == n + 1) {
                            StaffMenu::Display();
                        }
                        if (c == n + 2) {
                            return;
                        }
                        m = listMovies[c - 1];
                        listMovies.Remove(m.getId());
                        Library::printSuccess("\t\tDone!");
                        cout << endl;
                        cout << "\t         1. Back to Menu.\n";
                        cout << "\t         2. Exit.\n";
                        cout << "\t         Enter your selection: ";
                        c = 0;
                        cin >> c;
                        if (cin.fail())
                        {
                            c = Library::fail("         Enter your selection");

                        }
                        while ((c <= 0 || c > 2)) {
                            Library::printError("\t\tPlease select from the list");
                            cin >> c;
                        }
                        if (c == 1) {
                            StaffMenu::Display();
                        }
                        if (c == 2) {
                            return;
                        }
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        Movie m;
                        int n = listMovies.getLength();
                        listMovies.show();
                        int c = 0;
                        cout << endl;
                        cout << "\t         " << n + 1 << ". Back to Menu.\n";
                        cout << "\t         " << n + 2 << ".Exit.\n";
                        cout << "\n\t          Enter your selection: ";
                        cin >> c;
                        if (cin.fail()) {
                            c = Library::fail("\nEnter your selection: ");
                        }
                        while ((c <= 0 || c > n + 2)) {
                            cout << "Please select from the list: ";
                            cin >> c;
                            if (cin.fail()) {
                                c = Library::fail("\nEnter your selection: ");
                            }
                        }
                        if (c == n + 1) {
                            GuestMenu::Display();
                            return;
                        }
                        if (c == n + 2) {
                            return;
                        }
                        m = listMovies[c - 1];
                        system("cls");
                        cout << endl;
                        listMovies.update(m.getId());
                        cout << "\n\t\t    1. Back to Menu.\n";
                        cout << "\t\t    2. Exit.\n";
                        cout << "\t\t    Enter your selection: ";
                        c = 0;
                        cin >> c;
                        if (cin.fail())
                        {
                            c = Library::fail("\t\tEnter your selection");

                        }
                        while ((c <= 0 || c > 2)) {
                            Library::printError("\t\tPlease select from the list");
                            // cout << "Please select from the list: ";
                            cin >> c;
                        }
                        if (c == 1) {
                            StaffMenu::Display();
                        }
                        if (c == 2) {
                            return;
                        }
                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        MovieManager a;
                        a.search();
                        cout << "\n\t\t1. Back to Menu.\n";
                        cout << "\t\t2. Exit.\n";
                        cout << "\t\tEnter your selection: ";
                        c = 0;
                        cin >> c;
                        if (cin.fail())
                        {
                            c = Library::fail("\t\tEnter your selection");

                        }
                        while ((c <= 0 || c > 2)) {
                            Library::printError("\t\tPlease select from the list");
                            // cout << "Please select from the list: ";
                            cin >> c;
                        }
                        if (c == 1) {
                            StaffMenu::Display();
                        }
                        if (c == 2) {
                            return;
                        }
                        break;
                        break;
                    }
                    case 5: {
                        listMovies.showRevenues();
                        cout << "\n\t\t1. Back to Menu.\n";
                        cout << "\t\t2. Exit.\n";
                        cout << "\t\tEnter your selection: ";
                        int c = 0;
                        cin >> c;
                        if (cin.fail())
                        {
                            c = Library::fail("\t\tEnter your selection");

                        }
                        while ((c <= 0 || c > 2)) {
                            Library::printError("\t\tPlease select from the list");
                            //cout << "Please select from the list: ";
                            cin >> c;
                        }
                        if (c == 1) {
                            StaffMenu::Display();
                        }
                        if (c == 2) {
                            return;
                        }
                        break;
                    }

                    case 6:
                    {
                        Ticket::Reset();
                        Library::printSuccess("\t\tDone!");
                        break;
                    }
                    case 7: {
                        StaffMenu::Display();
                        break;
                    }
                    case 8:
                    {
                        cout << "\t\tGoodbye! Thanks for comming. ";
                        break;
                    }
                    default:
                    {
                        Library::printError("\t\tSelect from 1 to 7");
                        system("pause");
                        break;
                    }
                }
        }
        break;
        }
        case 4:
        {
            ManageProduct pr;
            ManageProduct sd;
            pr.readData("Database\\Popcorn.txt");
            sd.readData("Database\\Soda.txt");
            bool t2 = true;
            while (t2)
            {

            system("cls");
            cout << endl;
            GuestMenu::Menu("Database\\MenuProduct.txt");
            cout << endl;
            cout << "\t\tPlease Enter your choice: ";
            int cp;
            cin >> cp;
            if (cp >= 0 || cp <= 12)
                t2 = false;
            if (cin.fail())
            {
                cp = Library::fail("\t\tEnter your selection");

            }
            switch (cp)
            {
            case 1:
            {
                system("cls");
                string id3 = pr.getId();
                for (int i = 0; i < pr.getLength(); i++)
                {
                    if (id3 == "-1")
                        StaffMenu::Display();
                    system("cls");
                    pr.showProduct(id3);
                    system("pause");
                    break;
                }
                break;
            }
            case 2:
            {
                system("cls");
                string id3 = sd.getId();
                for (int i = 0; i < sd.getLength(); i++)
                {
                    if (id3 == "-1")
                        StaffMenu::Display();
                    system("cls");
                    sd.showProduct(id3);
                    system("pause");
                    break;
                }
                break;
            }
            case 3:
            {
                system("cls");
                pr.add();
                Library::printSuccess("\t\tDone!");
                system("pause");
                break;
            }
            case 4:
            {
                system("cls");
                sd.add();
                Library::printSuccess("\t\tDone!");
                system("pause");
                break;
            }
            case 5:
            {
                system("cls");
                string id3 = pr.getId();
                for (int i = 0; i < pr.getLength(); i++)
                {
                    if (id3 == "-1")
                        StaffMenu::Display();
                    Library::printSuccess("\t\tDone!");
                    system("pause");
                    pr.Remove(id3);
                    break;
                }
                break;
            }
            case 6:
            {
                system("cls");
                string id3 = sd.getId();
                for (int i = 0; i < sd.getLength(); i++)
                {
                    sd.Remove(id3);
                    Library::printSuccess("\t\tDone!");
                    if (id3 == "-1")
                        StaffMenu::Display();
                    break;
                }
                system("pause");
                break;
            }
            case 7:
            {
                system("cls");
                pr.search();
                system("pause");
                break;
            }
            case 8:
            {
                system("cls");
                sd.search();
                system("pause");
                break;
            }
            case 9:
            {
                system("cls");
                string id3 = pr.getId();
                for (int i = 0; i < pr.getLength(); i++)
                {
                    pr.update(id3);
                    Library::printSuccess("\t\tDone!");
                    if (id3 == "-1")
                        StaffMenu::Display();
                    break;
                }
                system("pause");
                break;
            }
            case 10:
            {
                system("cls");
                string id3 = sd.getId();
                for (int i = 0; i < sd.getLength(); i++)
                {
                    sd.update(id3);
                    Library::printSuccess("\t\tDone!");
                    if (id3 == "-1")
                        StaffMenu::Display();
                    break;
                }
                break;
                system("pause");
            }
            case 11:
            {
                system("cls");
                cout << "\t\t\t\t\     Revenues\n" << endl;
                ManageProduct a,b;
                a.readData("Database\\Popcorn.txt");
                b.readData("Database\\Soda.txt");
                a.showRevenues();
                b.showRevenues();
                cout << "\n\t\t1. Back to Menu.\n";
                cout << "\t\t2. Exit.\n";
                cout << "\t\tEnter your selection: ";
                int c = 0;
                cin >> c;
                if (cin.fail())
                {
                    c = Library::fail("\t\tEnter your selection");

                }
                while ((c <= 0 || c > 2)) {
                    Library::printError("\t\tPlease select from the list");
                    //cout << "Please select from the list: ";
                    cin >> c;
                }
                if (c == 1) {
                    StaffMenu::Display();
                }
                if (c == 2) {
                    return;
                }
                system("pause");
                break;
            }
            case 12:
            {
                StaffMenu::Display();
                break;
            } 
            default:
            {
                Library::printError("\t\tPlease choose from 1 to 13");
                system("pause");
                break;
            }
            }
            }
            ofstream file;
            ofstream file1;
            file.open("Database\\Soda.txt", ios_base::out);
            file1.open("Database\\Popcorn.txt", ios_base::out);
            sd.WriteFile(file);
            pr.WriteFile(file1);
            file.close();
            file1.close();
            int e;
            cout << "\n\t\tEnter 1 to Back to StaffMenu." << endl;
            cin >> e;
            if (e == 1)
            {
                system("cls");
                StaffMenu::Display();
            }
            else return;
            
            break;
            
        }
        case 5: 
        {
            while (true) 
            {
                vector<string> lines;
                string line;
                string fileName = "Database\\Ticket\\IdTicket.txt";
                ifstream input_file(fileName);
                if (!input_file.is_open()) 
                {
                    cout << ("\t\tCould not open the file - '" + fileName + "'") << endl;
                    return;
                }
                while (getline(input_file, line)) 
                {
                    lines.push_back(line);
                }
                int k = lines.size();
                input_file.close();
                string id;
                cout << "\t\tEnter Id you want to search:";
                cin >> id;
                if (lines.search(id)) 
                {
                    Library::printSuccess("\t\t Ticket Valid");

                }
                else {
                    Library::printError("\t\t Ticket Invalid");

                }
                cout << "\t\t1. Check again.\n";
                cout << "\t\t2. Back to Menu.\n";
                cout << "\t\t3. Exit.\n";
                cout << "\n\t\tEnter your selection: ";
                int c = 0;
                if (cin.fail())
                {
                    c = Library::fail("\t\tEnter your selection");

                }
                cin >> c;
                while ((c <= 0 || c > 3)) {
                    Library::printError("Please select from the list");
                    //cout << "Please select from the list: ";
                    cin >> c;
                }
                if (c == 1)
                {
                    continue;
                }
                if (c == 2) 
                {
                    StaffMenu::Display();
                }
                if (c == 3) 
                {
                    return;
                }
            }
            break;
        }
        case 6:
        {
            system("cls");
            Cinema::schedule();
            int e;
            cout << "\n\t\tEnter 1 to Back to StaffMenu." << endl;
            cin >> e;
            if (e == 1)
            {
                system("cls");
                StaffMenu::Display();
            }
            else return;
            break;
        }
        case 7:
        {
            break;
        }
        default:
        {
            Library::printError("\t\tPlease select from the list!");
            system("pause");
            system("cls");
            break;
        }
    }

    }
}
void StaffMenu::getInfoMovie(MovieManager listMovies) {
    Movie m;
    int n = listMovies.getLength();
    listMovies.show();
    int c = 0;
    cout << "\t         " << n + 1 << ". Back to Menu.\n";
    cout << "\t         " << n + 2 << ". Exit." << endl;
    cout << "\n\t\tEnter your selection: ";
    cin >> c;
    if (cin.fail()) {
        c = Library::fail("\nEnter your selection: ");
    }
    while ((c <= 0 || c > n + 2)) {
        cout << "Please select from the list: ";
        cin >> c;
        if (cin.fail()) {
            c = Library::fail("\nEnter your selection: ");
        }
    }
    if (c == n + 1) {
        StaffMenu::Display();
        return;
    }
    if (c == n + 2) {
        return;
    }
    m = listMovies[c - 1];
    system("cls");
    m.infMovie();
    cout << "\t\t1. Back to Menu.\n";
    cout << "\t\t2. Exit.\n";
    cout << "\t\tEnter your selection: ";
    c = 0;
    cin >> c;
    if (cin.fail())
    {
        c = Library::fail("\t\tEnter your selection");

    }
    while ((c <= 0 || c > 2)) {
        Library::printError("Please select from the list");
        cin >> c;
    }
    if (c == 1) {
        StaffMenu::Display();
    }
    if (c == 2) {
        return;
    }
}
string StaffMenu::logIn() {
    string pass, id;
    bool again = true;
    while (again) {
        cout << endl;
        cout << "                ----------------------------------  " << endl;
        cout << "                             LOG IN                 " << endl;
        cout << "                ----------------------------------  " << endl;
        cout << "                Please enter your user id: ";
        cin.ignore(32767, '\n');
        getline(cin, id);
        cout << "                Please enter your user password: ";
        pass = Library::passwdIO();
        cout << "\n\n";
        StaffManage s;
        s.getListStaff();
        if (s.check(id, pass)) {
            cout << "\n";
            Library::printSuccess("\tLogin success!\n\n\n");
            system("pause");
            Display();
            return "Exit";
        }
        else {
            Library::printError("          Invalid login attempt.");
            cout << "\t       1. Try again.\n";
            cout << "\t       2. Back to Menu.\n";
            cout << "\t       2. Exit.\n";
            cout << "\t       Enter your selection: ";
            int c = 0;
            cin >> c;
            if (cin.fail())
            {
                c = Library::fail("\t\tEnter your selection");

            }
            while ((c <= 0 || c > 3)) {
                Library::printError("       Please select from the list: ");
                cin >> c;
            }
            if (c == 1) {
                continue;
            }
            if (c == 2) {
                return "Menu";
            }
            if (c == 3)
            {
                return "Exit";

            }
        }
    }
    return "Exit";
}