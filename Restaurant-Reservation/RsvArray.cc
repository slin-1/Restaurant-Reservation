#include "RsvArray.h"

RsvArray::RsvArray(int c)
{
  capacity = c;
  arrRsv = new Reservation*[c];
  size = 0;
}

RsvArray::~RsvArray()
{
  for (int i=0; i<size; i++) {
    delete arrRsv[i];
  }
  delete[] arrRsv;
}

void RsvArray::add(Reservation* r)
{
  if (size >= capacity) {
    return;
  }
  else if (size == 0) {
    arrRsv[0] = r;
    size++;
    return;
  }

  int i=0;
  for (i=0; i<size; i++) {
    if (r->lessThan(arrRsv[i])) {
      break;
    }
  }

  for (int j=size; j>i; j--) {
    arrRsv[j] = arrRsv[j-1];
  }

  arrRsv[i] = r; 
  size++;
}

int& RsvArray::getSize()
{
  return size;
}

Reservation* RsvArray::get(int index)
{
  return arrRsv[index];
}

void RsvArray::print()
{
  for (int i=0; i<size; i++) {
    arrRsv[i]->print();
  }
}