#include "Restaurant.h"

Restaurant::Restaurant(string n)
{
  name = n;
}

Restaurant::~Restaurant() {}

void Restaurant::addPatron(Patron* p)
{
  patrons.add(p);
}

void Restaurant::reserveTable(int patronId, int tableNum, int year, int month, int day, int hour, int minute)
{
  Patron* rsvPatron;
  if ((patrons.find(patronId, &rsvPatron)) && (Date::validate(day, month, year)) && (Time::validate(hour, minute))) {
    Date* date = new Date(day, month, year);
    Time* time = new Time(hour, minute);
    Reservation* reservation = new Reservation(tableNum, rsvPatron, date, time);
    reservations.add(reservation);
  }
  else if (!(patrons.find(patronId, &rsvPatron))){
    cout << "Error: Patron " << patronId << " was not found!" << endl;
  }
  else if (!(Date::validate(day, month, year))){
    cout << "Error: Reservation date "
    << setfill('0') << setw(4) << right << year << "-"
    << setfill('0') << setw(2) << right << month << "-"
    << setfill('0') << setw(2) << right << day
    << " is invalid" << endl;
  }
  else if (!(Time::validate(hour, minute))){
    cout << "Error: Reservation time "
    << setfill('0') << setw(2) << right << hour << ":"
    << setfill('0') << setw(2) << right << minute;
  }
}

void Restaurant::printReservations()
{
  cout << endl << "All Reservations at " << name << ":" << endl;
  reservations.print();
}

void Restaurant::printSchedule(int year, int month, int day)
{
  if (Date::validate(day, month, year)) {
    Date date(day, month, year);
    cout << "Reservations for: ";
    date.print();
    cout << " at " << name << endl << endl;

    for (int i=0; i<reservations.getSize(); i++) {
      if (reservations.get(i)->matchDate(&date)) {
        reservations.get(i)->print();
      }
    }
  }
}

void Restaurant::printPatrons()
{
  patrons.print();
}