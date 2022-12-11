#include "MenuUser.h"
using namespace std;

void GuestMenu::Menu(string display) 
{
    ifstream file;
    file.open(display);
    if (!file)
        cout << "Failed to find file " << display << "!\n";
    string line;
    while (getline(file, line))
        cout << line << endl;
}

void GuestMenu::getInfoMovie(MovieManager listMovies) {
    system("cls");
    Movie m;
    string id = listMovies.getId();
    if (id == "-1") {
        return;
    }
    if (id == "Menu") {
        GuestMenu::Display();
        return;
    }
    m = listMovies.getMovie(id);
    bool t = true;
    while (t == true)
    {
        system("cls");
        m.infMovie();
        cout << "\t\t1. Back to Menu.\n";
        cout << "\t\t2. Exit." << endl;
        cout << "\n\t\tEnter your selection: ";
        int c = 0;
        cin >> c;
        if (c == 1 || c == 2)
            t = false;
        switch (c)
        {
        case 1:
        {
            GuestMenu::Display();
            break;
        }
        case 2:
        {
            return;
            break;
        }
        default:
            Library::printError("Please select from the list!");
            system("pause");
            break;
        }
    }
}

void GuestMenu::Display() 
{
    system("cls");
    int c;
    MovieManager listMovies;
    listMovies.readData("Database\\Movie\\movie.txt");
    bool t = true;
    while (t == true)
    {
        cout << endl;
        GuestMenu::Menu("Database\\GuestMenu.txt");
        cout << "\t\tEnter your selection: ";
        cin >> c;
        cout << endl;
        if (cin.fail())
        {
            c = Library::fail("Enter your selection");

        }
        if (c >= 1 && c <= 3)
            t = false;
        switch (c)
        {
            case 1:
            {
                getInfoMovie(listMovies);
                break;
            }
            case 2:
            {
                string x = buyTicketsMovie();
                if (x == "Menu")
                    Display();
                if (x == "Exit")
                    return;
                break;
            }
            case 3:
            {
                cout << "\t\tGoodbye! Thanks for comming.\n ";
                return;
                break;
            }
            default:
            {
                Library::printError("\t\tSelect from 1 to 3");
                system("pause");
                system("cls");
                break;
            }
        }
    }
    system("pause");
}

string GuestMenu::buyTicketsMovie()
{
    system("cls");
    int a[20], b[20];
    ManageProduct pop;
    ManageProduct s;
    string id2;
    string id1;
    int add;
    int v = 0;
    int  adr = 0;
    int i = 0, j = 0;
    int r1, r2, r3, v1, v2, v3;
    MovieManager listMovies;
    listMovies.readData("Database\\Movie\\movie.txt");
    string tm;
    string id = listMovies.getId();
    if (id == "-1")
        return "Exit";
    if (id == "Menu") {
        return id;
    }
    Movie m = listMovies.getMovie(id);
    cout << "\nShowtime: " << m.getShowtime() << endl;
    int k = 0;
    while (true) {
        cout << "\nChoose showtime: ";
        string q;
        cin >> q;
        if (q == "8:15") {
            k = 1;
            tm = "8:15";
            break;
        }
        else if (q == "11:10") {
            k = 2;
            tm = "11:10";
            break;
        }
        else if (q == "14:15") {
            k = 3;
            tm = "14:15";
            break;
        }
        else if (q == "17:05") {
            k = 4;
            tm = "17:05";
            break;
        }
        else if (q == "19:25") {
            k = 5;
            tm = "19:25";
            break;
        }
        else if (q == "22:20") {
            k = 6;
            tm = "22:20";
            break;
        }
        else {
            Library::printError("Please select from the list! ");
        }
    }
    system("cls");
    string p = Cinema::getSeat(k, m, tm);
    if (p == "Menu" || p == "Exit") return p;
    r1 = r2 = r3 = v1 = v2 = v3 = 0;
    bool t = true;
    do
    {
        cout << "\t\tWould you like to use more popcorn or soda?" << endl;
        cout << "\t\t1.Soda" << endl;
        cout << "\t\t2.Popcorn" << endl;
        cout << "\t\t3.No, thanks.\n" << endl;
        cout << "\t\tYour choice: ";
        cin >> add;
        if (cin.fail())
        {
            add = Library::fail("\t\tEnter your selection");

        }
        cout << endl;
        while (add > 3 || add <= 0)
        {
            cout << "\t\t Please choose from 1 to 3" << endl;
            cin >> add;
            cout << endl;
        }
        switch (add)
        {
        case 1:
        {
            s.readData("Database\\Soda.txt");
            id1 = s.getId();
            if (id1 == "-1")
                break;
            cout << "\t\tPlease enter amount: ";
            int adr;
            cin >> adr;
            if (cin.fail())
            {
                adr = Library::fail("\t\tEnter your selection");

            }
            cout << endl;
            while (adr <= 0)
            {
                cout << "\t\t Please choose from 1 or more: ";
                cin >> adr;
                if (cin.fail())
                {
                    adr = Library::fail("\t\tEnter your selection");

                }
                cout << endl;
            }
            //i++; 
            //ofstream file1;
            //file1.open("Database\\Soda.txt", ios_base::out);
            //pop.WriteFile(file1);
            //file1.close();
            //pop.getProduct(id1).upSale(adr);
            ///*a[i] = s.getProduct(id1);
            //a[i].setSales(adr);
            //v += a[i].getPrice() * a[i].getSales();*/
            a[i] = adr;
            i++;
            s.updateSale("Database\\Soda.txt", id1, adr);
            break;
        }
        case 2:
        {
            pop.readData("Database\\Popcorn.txt");
            id2 = pop.getId();
            if (id2 == "-1")
                break;
            cout << "\t\tPlease enter amount: ";
            int adr;
            cin >> adr;
            cout << endl;
            while (adr <= 0)
            {
                cout << "\t\t Please choose from 1 or more: ";
                cin >> adr;
                cout << endl;
            }
            /*ofstream file;
            file.open("Database\\Soda.txt", ios_base::out);
            s.getProduct(id2).upSale(adr);
            s.WriteFile(file);
            file.close();*/
            /*j++;
            b[j].setId(pop.getProduct(id2).getId());
            b[j].setName(pop.getProduct(id2).getName());
            b[j].setPrice(pop.getProduct(id2).getPrice());
            b[j].setSales(adr);
            b[j].setPrice(pop.getProduct(id2).getPrice());
            int am = pop.getProduct(id2).getSales();
            v += b[j].getSales() * b[j].getPrice();*/
            b[j] = adr;
            j++;
            pop.updateSale("Database\\Popcorn.txt", id2, adr);
            break;
        }
        //case 1:
        //{
        //    s.readData("Database\\Soda.txt");
        //    id1 = s.getId();
        //    if (id1 == "-1")
        //        break;
        //    cout << "\t\tPlease enter amount: ";
        //    int adr;
        //    cin >> adr;
        //    if (cin.fail())
        //    {
        //        adr = Library::fail("\t\tEnter your selection");

        //    }
        //    cout << endl;
        //    while (adr <= 0)
        //    {
        //        cout << "\t\t Please choose from 1 or more: ";
        //        cin >> adr;
        //        if (cin.fail())
        //        {
        //            adr = Library::fail("\t\tEnter your selection");

        //        }
        //        cout << endl;
        //    }
        //    i++;
        //    a[i] = s.getProduct(id1);
        //    a[i].setSales(adr);
        //    v += a[i].getPrice() * a[i].getSales();
        //    s.updateSale("Database\\Soda.txt", id1, adr);
        //    break;
        //}
        //case 2:
        //{
        //    pop.readData("Database\\Popcorn.txt");
        //    id2 = pop.getId();
        //    if (id2 == "-1")
        //        break;
        //    cout << "\t\tPlease enter amount: ";
        //    int adr;
        //    cin >> adr;
        //    cout << endl;
        //    while (adr <= 0)
        //    {
        //        cout << "\t\t Please choose from 1 or more: ";// khong cho nhap so am, chu, ki tu khac,...
        //        cin >> adr;
        //        cout << endl;
        //    }
        //    j++;
        //    b[j] = pop.getProduct(id2);
        //    b[j].setSales(adr);
        //    v += b[j].getPrice() * b[j].getSales();
        //    pop.updateSale("Database\\Popcorn.txt", id2, adr);

        //    break;
        //}
        case 3:
        {
            cout << "\t\tThanks!" << endl;
            t = false;
            break;
            
        }
        default:
        {
            Library::printError("\t\tSelect from 1 to 3");
            system("pause");
            system("cls");
            break;
        }
        }
    } while (t == true);
    if (true) 
    {
        if (i == 0 && j == 0)
        {
            system("pause");
            return "Exit";
        }
        system("cls");
        ofstream filename("Database\\PrintProduct.txt");
        if (!filename.is_open())
        {
            cout << "\nCould not open the file!" << endl;
            system("pause");
            return "Menu";
        }
        int val = 0;
        cout <<     "             -----------------------------------------" << endl;
        cout <<     "                             YOUR ORDER               " << endl;
        cout <<     "             -----------------------------------------" << endl;   
        filename << "             -----------------------------------------" << endl;
        filename << "                             YOUR ORDER               " << endl;
        filename << "             -----------------------------------------" << endl;
        while (i > 0)
        {
            --i;
            s[i].Show(a[i]);
            s[i].PrintPr(filename);
            val +=a[i] * s[i].getPrice();
            /*a[i].Show();
            a[i].PrintPr(filename);
            val += a[i].getSales() * a[i].getPrice();
            i--;*/
        }
        while (j > 0)
        {
            --j;
            pop[j].Show(b[j]);
            pop[j].PrintPr(filename);
            val +=b[j] * pop[j].getPrice();
            /*b[j].Show();
            b[j].PrintPr(filename);
            val += b[j].getSales() * b[j].getPrice();
            j--;*/
        }
        cout << "             ------------------------------------------" << endl;
        cout << "             Price:\t   " <<Library::printRevenues(val, ".")<< endl;
        cout << "             ------------------------------------------" << endl;
        cout << "             Ticket:\t   " << Library::printRevenues(stoi(p), ".") << endl;
        cout << "             ------------------------------------------" << endl;
        cout << "             Total:\t   " << Library::printRevenues(stoi(p)+val, ".") << endl;
        filename << "             ------------------------------------------" << endl;
        filename << "             Total:\t   " << Library::printRevenues(stoi(p)+val, ".") << endl;
        filename.close();
        /*ofstream file1;
        ofstream file;
        file.open("Database\\Soda.txt", ios_base::out);
        s.WriteFile(file);
        file.close();
        file1.open("Database\\Popcorn.txt", ios_base::out);
        pop.WriteFile(file1);
        file1.close();*/
        cout << endl;
        system("pause");
        return "Exit";
    }
    return "Exit";
}

