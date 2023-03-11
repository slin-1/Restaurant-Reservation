#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

bool Date::validate(int day, int month, int year)
{
  Date tempDate(day, month, year);

  if (month < 1 || month > 12) {
    return false;
  }
  if (day < 1 || day > 31) {
    return false;
  }

  if (month == 2) {
    if (tempDate.leapYear()) {
      return (day <= 29);
    }
    else {
      return (day <= 28);
    }
  }

  if (month == 4 || month == 6 || month == 9 || month == 11) {
    return (day <= 30);
  }

  return true;
}

bool Date::lessThan(Date* date)
{
  if (year < date->year) {
    return true;
  }
  else if (year == date->year && month < date->month) {
    return true;
  }
  else if (year == date->year && month == date->month && day < date->day) {
    return true;
  }
  else {
    return false;
  }
}

bool Date::equals(Date* date)
{
  if (year == date->year && month == date->month && day == date->day) {
    return true;
  }
  else {
    return false;
  }
}

void Date::print()
{
  cout<<setfill('0')<<setw(4)<<right<<year<<"-"
      <<setfill('0')<<setw(2)<<right<<month<<"-"
      <<setfill('0')<<setw(2)<<right<<day;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}