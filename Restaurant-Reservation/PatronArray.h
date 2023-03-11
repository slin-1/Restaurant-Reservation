#ifndef PATRONARRAY_H
#define PATRONARRAY_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Patron.h"
#include "defs.h"

/*
  Class:    PatronArray
  Purpose:  Contains an array of patrons of a restaurant. Can be used to: add patrons, find patrons
            using their ID, and print the patrons array.
*/

class PatronArray
{
  public:
    PatronArray();
    ~PatronArray();
    void add(Patron*);
    bool find(int, Patron**);
    void print();

  private:
    Patron* arrPatrons[MAX_ARR];
    int size;
};


#endif