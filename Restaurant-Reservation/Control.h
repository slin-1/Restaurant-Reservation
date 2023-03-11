#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
using namespace std;

#include "Restaurant.h"
#include "View.h"

/*
  Class:    Control
  Purpose:  Contains the primary control flow of the restaurant program, including the main function.
            Displays a menu in the terminal to the user.
            Initializes a restuarant w/ patrons & reservations.
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    Restaurant* restaurant;
    View* view;
    void initPatrons(Restaurant*);
    void initReservations(Restaurant*);

};

#endif
