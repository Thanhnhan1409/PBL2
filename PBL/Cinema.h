#pragma once
#include<iostream>
#include"Movie.h"
#include"Library.h"

using namespace std;
class Cinema
{
private:
    string IdCine;
    string Film;
    int NumSeatAvailable;
    string Time;
    string Status;

public:
    Cinema();
    virtual ~Cinema();
    string getIdCine();
    string getFilm();
    int getNumSeatAvailable();
    string getTime();
    string getStatus();

    void setIdCine(string);
    void setFilm(string);
    void setNumSeatAvailable(int);
    void setTime(string);
    void setStatus(string);

    static string getSeat(int, Movie, string);
    static int** getposition(int, string);
    static void prArray(int**, int);
    static void writeFile(int**, int, string, int);
    static int emptySeat(int**, int);
    static void schedule();
    static void resetCine(int, string);
};