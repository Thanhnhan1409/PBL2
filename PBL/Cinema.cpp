#pragma once
#include "Cinema.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"
#include "Ticket.h"
#include "vector.h"
#include "MovieManager.h"
//#define seats() seats
using namespace std;

Cinema::Cinema() 
{
    IdCine = Film = Time = Status = " ";
    NumSeatAvailable = 0;
}
Cinema::~Cinema() 
{

}

void Cinema::setIdCine(string id) 
{
    this->IdCine = id;
}
void Cinema::setFilm(string film) 
{
    this->Film = film;
}
void Cinema::setTime(string time) 
{
    this->Time = time;
}
void Cinema::setStatus(string status) 
{
    this->Status = status;
}
void Cinema::setNumSeatAvailable(int i) 
{
    this->NumSeatAvailable = i;
}

string Cinema::getIdCine() 
{
    return this->IdCine;
}
string Cinema::getFilm() 
{
    return this->Film;
}
string Cinema::getStatus() 
{
    return this->Status;
}
string Cinema::getTime() 
{
    return this->Time;
}
int Cinema::getNumSeatAvailable() 
{
    return this->NumSeatAvailable;
}

int** Cinema::getposition(int n, string r) 
{
    int** mt = new int* [14];
    ifstream inp_rap("Database\\Cinema\\" + r + "\\" + to_string(n) + ".txt");

    for (int i = 0; i < 14; i++) 
        mt[i] = new int[14];
    if (!inp_rap.is_open()) 
    {
        cout << "Could not open the file" << endl;
    }
    for (int j = 0; j < 14; j++) 
    {
        for (int k = 0; k < 14; k++) 
        {
            inp_rap >> mt[j][k];
        }
    }
    return mt;
}
void Cinema::prArray(int** a, int k) 
{
    for (int h = 0; h < k + 1; h++)
    {
        cout << "\t\t";
        for (int w = 0; w < k + 1; w++)
        {
            if (h == 0) 
            {
                if (w != 14) printf("%7d",w + 1);
            }
            else if (w == 0) printf("%3c", h + 64) ;
            else 
            {
                cout << "|  ";
                if (a[h - 1][w - 1] == 1) 
                {
                    Library::printLineColor(to_string(a[h - 1][w - 1]), 2);
                }
                else 
                {
                    Library::printLineColor(to_string(a[h - 1][w - 1]), 4);
                }
                cout << "  |";
            }

        }
        cout << endl;
    }
}
void Cinema::writeFile(int** p, int k, string r, int s) 
{
    ofstream file;
    file.open("Database\\Cinema\\" + r + "\\" + to_string(s) + ".txt", ios::out);

    if (!file) 
    {
        cerr << "Error: file not opened." << endl;
        return;
    }
    for (int i = 0; i < k; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            file << to_string(p[i][j]) << " ";
        }
    }
    file.close();
}
int Cinema::emptySeat(int** a, int k)
{
    int m = 0;
    for (int h = 0; h < k; h++)
    {
        for (int w = 0; w < k; w++)
        {
            if (a[h][w] == 1) ++m;
        }
    }
    return m;
}
string Cinema::getSeat(int k, Movie m, string time) 
{
    Ticket t;
    t.setTime(time);
    t.setName(m.getName());
    t.setCine(m.getCine());
    int** p = getposition(k, m.getCine());
    cout << "\n\t\t\t\t\t\t\tMovie theater map: \n" << endl;
    prArray(p, 14);
    cout << endl;
    cout << "\t\t1: This seat is available" << endl;
    cout << "\t\t0: This seat is unavailable" << endl;
    int maxS = emptySeat(p, 14);
    if (maxS == 0) {
        cout << "\t\tSold out" << endl;
        cout << "\t\t1. Return" << endl;
        cout << "\t\t2. Exit" << endl;
        cout << "\n\t\tEnter your selection: ";
        int c;
        cin >> c;
        while ((c <= 0 || c > 2)) {
            Library::printError("\t\tPlease select from the list");
            cin >> c;
        }
        switch (c) {
        case 1: return "Menu";
        case 2: return "Exit";
        }
    }
    cout << "\n\t\tPlease select from the listThe number of tickets that can be purchased: " << maxS << " seats" << endl;
    cout << "\t\tPlease select from the listEnter the number of tickets purchased: ";
    int sl;
    cin >> sl;
    while (cin.fail())
    {
        Library::printError("\t\tNumber please!");
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\t\tNumber of tickets purchased: ";
        cin >> sl;
    }
    while (sl > maxS) 
    {
        cout << "\n\t\tSorry. Don't have enough tickets left. There 3 option: " << endl;
        cout << "\t\t1. Enter again the number of tickets purchased." << endl;
        cout << "\t\t2. Return" << endl;
        cout << "\t\t3. Exit." << endl;
        cout << "\n\t\tEnter your selection: ";
        int c;
        cin >> c;
        switch (c) 
        {
            case 1: {
                cout << "\t\tEnter the number of tickets purchased: ";
                cin >> sl;

                break;
            }
            case 2: {
                m.infMovie();
                break;
            }
            case 3: 
                return "Exit";
                break;
            default:
                break;
        }
            if (cin.fail()) {
                sl = Library::fail("\t\tEnter the number of tickets purchased: ");
            }
    }
    while (sl <= 0) {
        Library::printError("\n\t\tSorry. Please enter the number that bigger than 0. Please try again.");
        cout << "\t\tEnter the number of tickets purchased: ";
        cin >> sl;
    }
    vector<string> seats;
    for (int i = 0; i < sl; i++) {

        char c;
        int l;
        cout << "\n\t\tPlease select the seat: " << endl;
        cout << "\t\tRow: ";
        cin >> c;
        c = toupper(c);
        while (!(c >= 'A' && c <= 'N'))
        {
            Library::printError("\t\tPlease choose from A to N");
            cout << "\t\tRow: ";
            cin >> c;
            c = toupper(c);
        }
        cout << "\t\tColumn: ";
        cin >> l;
        while (cin.fail())
        {
            Library::printError("\t\tNumber please!");
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\t\tColumn: ";
            cin >> l;
        }
        int r = (int)c - 64;
        while (p[r - 1][l - 1] == 0) 
        {
            Library::printError("This seat is not available. Please select another the seat");
            cout << "\t\tRow: ";
            cin >> c;
            c = toupper(c);
            while (!(c >= 'A' && c <= 'N'))
            {
                Library::printError("\t\tPlease choose from A to N");
                cout << "\t\tRow: ";
                cin >> c;
                c = toupper(c);
            }
            cout << "\t\tColumn: ";
            cin >> l;
            while (cin.fail())
            {
                Library::printError("\t\tNumber please!");
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "\t\tColumn: ";
                cin >> l;
            }
            r = (int)c - 64;
        }
        system("cls");
        cout << "\n\t\tSuccessful seat selection: " << c << l << endl;
        seats.push_back(string(1, c) + to_string(l));
        t.setSeat(seats[i]);
        string s = "V" + m.getId() + m.getCine() + to_string(k) + seats[i] + Library::gettime();
        fstream inp_file("Database\\Ticket\\IdTicket.txt", ios::out | ios::app);
        if (!inp_file.is_open()) {
            cout << "\n\t\tCould not open the file: IdTicket.txt" << endl;
            return "Menu";
        }
        inp_file << s << endl;
        inp_file.close();
        t.setId(s);
        t.setCine(m.getCine());
        t.setSeat(seats[i]);
        t.Show();
        t.Print();
        p[r - 1][l - 1] = 0;
    }
    int sale = m.getSales() + m.getPrice() * sl;
    m.setSales(sale);
    m.updateMovie();
    writeFile(p, 14, m.getCine(), k);
    for (int h = 0; h < 14; h++)
    {
        delete[] p[h];
    }
    delete[] p;
    return to_string(sl*m.getPrice());
}
void Cinema::schedule() {
    string s[4][7];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            s[i][j] = "";
        }
    }
    ifstream inp_file("Database\\Movie\\movie.txt");
    if (!inp_file.is_open()) {
        cout << "\nCould not open the file movie.txt" << endl;
        return;
    }
    string id;
    vector< string> ls;
    while (getline(inp_file, id)) {
        ls.push_back(id);
    }
    inp_file.close();
    int length = ls.size();
    Movie* movie = new Movie[ls.size()];
    for (size_t i = 0; i < ls.size(); i++) {
        string link = "Database\\Movie\\" + ls[i] + ".txt";
        string filename(link);
        vector< string> lines;
        string line;
        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cout << "\nCould not open the file - '" + filename + "'" << endl;
            return;
        }
        while (getline(input_file, line)) {
            lines.push_back(line);
        }
        int e = (lines[9])[0] - 65;
        s[e][0] = lines[9];
        stringstream k = (stringstream)lines[10];
        while (k.good()) {
            string q;
            getline(k, q, ',');
            if (q == "") continue;
            int t = -1;
            if (q == "8:15") {
                t = 1;
            }
            if (q == "11:10") {
                t = 2;
            }
            if (q == "14:15") {
                t = 3;
            }
            if (q == "17:05") {
                t = 4;
            }
            if (q == "19:25") {
                t = 5;
            }
            if (q == "22:20") {
                t = 6;
            }
            s[e][t] = lines[1];
        }
        input_file.close();
    }
    Library::printLineColor("\n\t\t\t\t\t\tCinema's Schedule\n\n", 3);
    cout << "Cinema";
    string z[6] = { "8:15","11:10","14:15","17:05","19:25","22:20" };
    for (int i = 0; i < 6; i++) {
        if (i == 0)
        {
            cout << right << setw(8) << z[0];
        }
        else
        {
            cout << right << setw(20) << z[i];
        }
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0) {
                cout << left << setw(8) << s[i][j];
            }
            else {
                if (s[i][j] == "") s[i][j] = "FREE";
                cout << left << setw(20) << s[i][j];
            }
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
}
void Cinema::resetCine(int s, string r) {
    int** mt = new int* [14];
    for (int i = 0; i < 14; i++) {
        mt[i] = new int[14];
    }
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            mt[i][j] = 1;
            //cout << mt[i][j] << " ";
        }
        //cout << endl;
    }
    writeFile(mt, 14, r, s);
    //delete[] mt;
}