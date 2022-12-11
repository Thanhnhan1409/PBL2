#pragma once
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Library
{
public:
    static void printLineColor(string line, int color_code);
    static void printError(string status);
    static void printSuccess(string status);
    static string gettime();
    static string passwdIO();
    static int fail(string);
    static string printRevenues(long long, string);
    static void Toupper(char[]);
};

