#ifndef RSVARRAY_H
#define RSVARRAY_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Reservation.h"
#include "defs.h"

/*
  Class:    RsvArray
  Purpose:  Manages a collection of reservations for the restaurant. Can add to the collection
            by using a reservation pointer, and obtain a reservation pointer by using an index integer.
            The reservation array itself is a dynamically allocated array of pointers.
*/

class RsvArray
{
  public:
    RsvArray(int=MAX_ARR);
    ~RsvArray();
    void add(Reservation*);
    int& getSize();
    Reservation* get(int);
    void print();
    
  private:
    Reservation** arrRsv;
    int capacity;
    int size;

};


#endif