#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
  Class:    Date
  Purpose:  Manages the dates for reservations. Allows the user to: set dates, validate dates,
            determine whether a date is less than another or equal to another, and/or print out the date object.
*/

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    void setDate(int, int, int);
    static bool validate(int, int, int);
    bool lessThan(Date*);
    bool equals(Date*);
    void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
};

#endif
