#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "PatronArray.h"
#include "RsvArray.h"

/*
  Class:    Restaurant
  Purpose:  Represents a restaurant. The restaurant consists of a collection of patrons and
            a collection of reservations. Patrons can be added, and reservations can be made.
            The class contains a multitude of printing functions: for reservations, a specific
            schedule(on a date), and for patrons.
*/

class Restaurant
{
  public:
    Restaurant(string="Unknown");
    ~Restaurant();
    void addPatron(Patron*);
    void reserveTable(int, int, int, int, int, int, int);
    void printReservations();
    void printSchedule(int, int, int);
    void printPatrons();

  private:
    string name;
    PatronArray patrons;
    RsvArray reservations;

};


#endif