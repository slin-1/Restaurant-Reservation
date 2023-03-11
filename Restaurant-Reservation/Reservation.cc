#include "Reservation.h"

#include <string>

Reservation::Reservation(int tab, Patron* p, Date* d, Time* t)
{
  table = tab;
  rsvPatron = p;
  rsvDate = d;
  rsvTime = t;
}

Reservation::~Reservation()
{
  delete rsvDate;
  delete rsvTime;
}

bool Reservation::lessThan(Reservation* res)
{
  if (rsvDate->lessThan(res->rsvDate)) {
    return true;
  }
  else if (rsvDate->equals(res->rsvDate) && rsvTime->lessThan(res->rsvTime)) {
    return true;
  }
  else {
    return false;
  }
}

bool Reservation::matchDate(Date* date)
{
  return (rsvDate->equals(date));
}

void Reservation::print()
{
  rsvDate->print();
  cout << " @ ";
  rsvTime->print();

  cout << " ::  Table" << setfill(' ') << setw(3) << right
  << table << "  " << left << (rsvPatron->getName()) << endl;
}