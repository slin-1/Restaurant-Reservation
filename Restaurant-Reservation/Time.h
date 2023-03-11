#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
  Class:    Time
  Purpose:  Manages the time for the restaurant, where time can be; validated, compared 
            to one another to determine which is less, and printed.
*/

class Time
{
  public:
    Time(int=0, int=0);
    static bool validate(int, int);
    bool lessThan(Time*);
    void print();

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif
