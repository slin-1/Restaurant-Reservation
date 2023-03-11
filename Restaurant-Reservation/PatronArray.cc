#include "PatronArray.h"

PatronArray::PatronArray()
{
  size = 0;
}

PatronArray::~PatronArray()
{
  for (int i=0; i<size; i++) {
    delete(arrPatrons[i]);
  }
}

void PatronArray::add(Patron* p)
{
  if (size >= MAX_ARR) {
    return;
  }

  arrPatrons[size] = p;
  size++;
}

bool PatronArray::find(int id, Patron** p)
{
  for (int i=0; i<size; i++) {
    if (id == arrPatrons[i]->getId()) {
      *p = arrPatrons[i];
      return true;
    }
  }
  
  p = NULL;
  return false;
}

void PatronArray::print()
{
  cout << endl << "Patrons: " << endl;
  for (int i=0; i<size; i++) {
    arrPatrons[i]->print();
  }
}