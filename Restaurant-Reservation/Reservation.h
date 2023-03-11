#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Patron.h"
#include "Date.h"
#include "Time.h"

/*
  Class:    Reservation
  Purpose:  Represents a reservation for the restaurant. Contains important functions such as:
            less than comparison, matching date comparisons, and printing. A reservation is comprised
            of a table number, a patron, a date, and a time.
*/

class Reservation
{
  public:
    Reservation(int=0, Patron* =NULL, Date* =NULL, Time* =NULL);
    ~Reservation();
    bool lessThan(Reservation*);
    bool matchDate(Date*);
    void print();

  private:
    int table;
    Patron* rsvPatron;
    Date* rsvDate;
    Time* rsvTime;
};


#endif