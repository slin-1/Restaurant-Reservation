#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
  Class:    Patron
  Purpose:  Represents a patron of a restaurant, where there are the data members:
            'name', 'id', and 'nextID'.
*/

class Patron
{
  public:
    Patron(string="Unknown");
    int& getId();
    string& getName();
    void print();

  private:
    string name;
    int id;
    static int nextID;
};

#endif