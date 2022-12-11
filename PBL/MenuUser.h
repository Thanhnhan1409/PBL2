#pragma once
#include <iostream>
#include <string>
#include "MenuUser.h"
#include "MovieManager.h"
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "Ticket.h"
#include "vector.h"
#include "Cinema.h"
#include "ManageProduct.h"
#include "StaffManage.h"
#include "Ticket.h"
class MovieManager;

class GuestMenu
{
public:
    static void Menu(string);
    static void Display();
    static void getInfoMovie(MovieManager);
    static string buyTicketsMovie();
};
class StaffMenu : public GuestMenu
{
public:
    static string logIn();
    static void Menu();
    static void getInfoMovie(MovieManager);
    static void Display();
};
