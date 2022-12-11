#pragma once
#include "Ticket.h"
#include <iomanip>
Ticket::Ticket() {

}
Ticket::~Ticket() {

}

void Ticket::setCine(string cine) {
    this->Cine = cine;
}
void Ticket::setSeat(string seat) {
    this->Seat = seat;
}
void Ticket::setTime(string time)
{
    this->Time = time;
}

void Ticket::Show()
{   
    cout << "\t\t-------------------------------------------------------------" << endl;
    cout << " \t\t\t\t\tTICKET" << endl;
    cout << "\t\tId: " << Id << endl;
    cout << "\t\tLOTTE GROUP" << endl;
    cout << "\t\tAddress: 06 Nai Nam, Hai Chau, Da Nang" << endl;
    cout << "\t\t-------------------------------------------------------------\n" << endl;
    cout << "\t\tName' Film: " << Name << endl;
    cout << "\t\tSeat: " << Seat << endl;
    cout << "\t\tCinema: " << Cine;
    cout << "\t\tShow: " << Time << endl;
    cout << "\n\t\t-----------------------------------------------------------\n" << endl;
}
void Ticket::Print()
{
    ofstream filename("Database\\Ticket\\PrintTicket.txt");
    filename << "\t\t---------------------------------------------------------" << endl;
    filename << " \t\t\t\t\tTICKET" << endl;
    filename << "\t\tId: " << Id << endl;
    filename << "\t\tLOTTE GROUP" << endl;
    filename << "\t\tAddress: 06 Nai Nam, Hai Chau, Da Nang" << endl;
    filename << "\t\t----------------------------------------------------------\n" << endl;
    filename << "\t\tName's Film: " << Name << endl;
    filename << "\t\tSeat: " << Seat << endl;
    filename << "\t\tCinema: " << Cine;
    filename << "\t\tShow: " << Time << endl;
    filename << "\n\t\t--------------------------------------------------------\n" << endl;
}
void Ticket::Reset()
{
    ofstream filename("Database\\Ticket\\IdTicket.txt");
    if (!filename.is_open())
    {
        Library::printError("Not found IdTicket.txt!");
        return;
    }
    filename.close();
    return;
}