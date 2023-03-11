#include "Time.h"

Time::Time(int h, int m)
{
  setTime(h, m);
}

void Time::setTime(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

bool Time::validate(int hrs, int mins)
{
  if ((hrs >= 0 && hrs < 24) && (mins >= 0 && mins < 60)) {
    return true;
  }
  else {
    return false;
  }
}

bool Time::lessThan(Time* time)
{
  if (hours < time->hours) {
    return true;
  }
  else if ((hours == time->hours) && (minutes < time->minutes)) {
    return true;
  }
  else {
    return false;
  }
}

int Time::convertToMins() 
{
  return (hours*60 + minutes);
}

void Time::print() 
{
  cout<<setfill('0')<<setw(2)<<right<<hours<<":"
      <<setfill('0')<<setw(2)<<right<<minutes;
}