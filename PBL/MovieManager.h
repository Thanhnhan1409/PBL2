#pragma once
#include "Movie.h"
#include <fstream>
#include <cstdio>
#include "vector.h"
#include "MenuUser.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Manage.h"

class MovieManager : public Manage
{
protected:
    Movie* movie;
public:
    int getLength();
    void setLength(int);

    MovieManager();
    ~MovieManager();

    void readData(string);
    void show();
    void add();
    void search();
    void addMovie(Movie); //add film to database
    void update(string);
    string getId();
    void Remove(string); //remove film from database
    Movie getMovie(string); //get film from database
    Movie createMovie();//insert inf of film
    bool isDuplicateId(Movie);
    void showRevenues();
    void RevenueSort(int, int, bool(*CompFunc)(int, int));
    Movie& operator[](const int);
};