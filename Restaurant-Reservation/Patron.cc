#include "Patron.h"

int Patron::nextID = 5001;

Patron::Patron(string n)
{
  name = n;
  id = nextID++;
}

int& Patron::getId()
{
  return id;
}

string& Patron::getName()
{
  return name;
}

void Patron::print()
{
  cout << "Patron " << "#" << setfill(' ') << setw(6) << left << id << name << endl;
}