#pragma once
#include<iostream>
#include "Movie.h"
using namespace std;
Movie::Movie(string id, string name, string type, string content, string time, int year, int duration, string actor, string country, string cine, string showtime, int sales, int price) {
    this->Id = id;
    this->Name = name;
    this->Type = type;
    this->Content = content;
    this->Time = time;
    this->Year = year;
    this->Duration = duration;
    this->Actor = actor;
    this->Country = country;
    this->Cine = cine;
    this->Showtime = showtime;
    this->Sales = sales;
    this->Price = price;
}
Movie::Movie() {
    /**/
    this->Id = "Unknow";
    this->Name = "Unknow";
    this->Type = "Unknow";
    this->Content = "Unknow";
    this->Time = "Unknow";
    this->Year = 0;
    this->Duration = 0;
    this->Actor = "Unknow";
    this->Country = "Unknow";
    this->Cine = "Unknow";
    this->Showtime = "Unknow";
    this->Sales = 0;
    this->Price = 0;
}
void Movie::setId(string id) {
    this->Id = id;
}
void Movie::setName(string name) {
    this->Name = name;
}
void Movie::setType(string type) {
    this->Type = type;
}
void Movie::setContent(string content) {
    this->Content = content;
}
void Movie::setTime(string time) {
    this->Time = time;
}
void Movie::setYear(int year) {
    this->Year = year;
}
void Movie::setDuration(int duration) {
    this->Duration = duration;
}
void Movie::setActor(string actor) {
    this->Actor = actor;
}
void Movie::setCountry(string country) {
    this->Country = country;
}
void Movie::setCine(string cine) {
    this->Cine = cine;
}
void Movie::setShowtime(int showtime) {
    this->Showtime = showtime;
}
void Movie::setSales(long sales) {
    this->Sales = sales;
}
void Movie::setPrice(int price) {
    this->Price = price;
}

string Movie::getId() {
    return Id;
}
string Movie::getName() {
    return Name;
}
string Movie::getType() {
    return Type;
}
string Movie::getContent() {
    return Content;
}
string Movie::getActor() {
    return Actor;
}
string Movie::getCountry() {
    return Country;
}
string Movie::getCine() {
    return Cine;
}
string Movie::getShowtime() {
    return Showtime;
}
string Movie::getTime() {
    return Time;
}
long Movie::getSales() {
    return this->Sales;
}
int Movie::getYear() {
    return Year;
}
int Movie::getDuration() {
    return Duration;
}
int Movie::getPrice() {
    return this->Price;
}

void Movie::infMovie() {
    cout << "\n                                          ";
    Library::printLineColor(this->Name + "\n", 2);
    Library::printLineColor("Type:      ", 13);
    cout << this->Type << endl;
    Library::printLineColor("Duration:  ", 13);
    cout << this->Duration << " minutes" << endl;
    Library::printLineColor("Country:   ", 13);
    cout << this->Country << endl;
    Library::printLineColor("Actor:     ", 13);
    cout << this->Actor << endl;
    Library::printLineColor("Price:     ", 13);
    cout << this->Price << " vnd" << endl;
    Library::printLineColor("Showtime:  ", 13);
    cout << this->Showtime << endl;
    Library::printLineColor("Content:   ", 13);
    cout << this->Content << endl;
    cout << endl;
}
void Movie::updateMovie() {
    ofstream file("Database\\Movie\\"+ this->Id + ".txt");
    file << this->Id << endl;
    file << this->Name << endl;
    file << this->Type << endl;
    file << to_string(this->Duration) << endl;
    file << to_string(this->Year) << endl;
    file << this->Time << endl;
    file << this->Country << endl;
    file << this->Content << endl;
    file << this->Actor << endl;
    file << this->Cine << endl;
    file << this->Showtime << endl;
    file << this->Sales << endl;
    file << this->Price << endl;
    file.close();
}
void Movie::createMovie() {
    int year, duration, price;
    string name, type, content, time, actor, country, cine, showtime, id;
    cout << "\t\tId: ";
    cin.ignore(32767, '\n');
    getline(cin, id);
    cout << "\t\tName: ";
    getline(cin, name);
    cout << "\t\tType: ";
    getline(cin, type);
    cout << "\t\tDuration: ";
    cin >> duration;
    while (cin.fail())
    {
        Library::printError("\t\tNumber please!");
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\t\tDuration: ";
        cin >> duration;
    }
    cout << "\t\tYear: ";
    cin >> year;
    while (cin.fail())
    {
        Library::printError("\t\tNumber please!");
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\t\tYear: ";
        cin >> year;
    }
    cin.ignore(32767, '\n');
    cout << "\t\tCountry: ";
    getline(cin, country);
    cout << "\t\tContent: ";
    getline(cin, content);
    cout << "\t\tTime: ";
    getline(cin, time);
    cout << "\t\tActor: ";
    getline(cin, actor);
    cout << "\t\tCinema: ";
    getline(cin, cine);
    cout << "\t\tShowtime: " << endl;
    cout << "\t\tSet 1: 8:15" << endl;
    cout << "\t\tSet 2: 11:10" << endl;
    cout << "\t\tSet 3: 14:15" << endl;
    cout << "\t\tSet 4: 17:05" << endl;
    cout << "\t\tSet 5: 19:25" << endl;
    cout << "\t\tSet 6: 22:20" << endl;
    cout << "\t\tEnter amount showtime: ";
    int sl;
    int q;
    cin >> sl;
    while ((sl <= 0 || sl > 6) || cin.fail()) {
        if (cin.fail()) {
            Library::printError("\t\tNumber please!");
            cin.clear();
        }
        cin.ignore(32767, '\n');
        cout << "\t\tPlease enter again: ";
        cin >> sl;
    }
    cout << "\t\tEnter showtime (Number): ";
    for (int i = 0; i < sl; i++) {
        cin >> q;
        while (cin.fail())
        {
            Library::printError("\t\tNumber please!");
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\t\tEnter showtime (Number): ";
            cin >> sl;
        }

        while ((q <= 0 || q > 6)) {
            cout << "\t\tPlease select from the list: ";
            cin >> q;
        }
        if (q == 1) {
            showtime += "8:15";
        }
        else if (q == 2) {
            showtime += "11:10";
        }
        else if (q == 3) {
            showtime += "14:15";
        }
        else if (q == 4) {
            showtime += "17:05";
        }
        else if (q == 5) {
            showtime += "19:25";
        }
        else if (q == 6) {
            showtime += "22:20";
        }
        else {
            cout << "\t\tPlease select from the list! " << endl;
        }
        showtime += ",";
    }
    cout << "\t\tShowtime: " << showtime << endl;
    cout << "\t\tPrice: ";
    cin >> price;
    this->Id = id;
    this->Name = name;
    this->Type = type;
    this->Content = content;
    this->Time = time;
    this->Year = year;
    this->Duration = duration;
    this->Actor = actor;
    this->Country = country;
    this->Cine = cine;
    this->Showtime = showtime;
    this->Sales = 0;
    this->Price = price;
}