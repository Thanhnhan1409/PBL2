#pragma once
#include <iostream>
#include <fstream>
#include "library.h"
#include <string>

using namespace std;
class Movie
{
protected:
    string Id;
    string Name;
    string Type;
    string Content;
    string Time;
    int Year;
    int Duration;
    string Actor;
    string Country;
    string Cine;
    string Showtime;
    long Sales;
    int Price;
public:
    Movie();
    Movie(string, string, string, string, string, int, int, string, string, string, string, int, int);

     string getName();
    string getId();
    string getType();
    string getContent();
    string getTime();
    int getYear();
    int getDuration();
    string getActor();
    string getCountry();
    string getCine();
    string getShowtime();
    long getSales();
    int getPrice();

    void setId(string);
    void setName(string);
    void setType(string);
    void setContent(string);
    void setTime(string);
    void setDuration(int);
    void setYear(int);
    void setActor(string);
    void setCountry(string);
    void setCine(string);
    void setShowtime(int);
    void setSales(long);
    void setPrice(int);

    void infMovie();
    void createMovie();
    void updateMovie();
};