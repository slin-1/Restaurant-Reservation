#include "Control.h"

/*
  Author:   Steven Lin
  Purpose:  The user is able to interact with a restaurant terminal menu. The restaurant is comprised of patrons,
            and reservations (that each have a patron, table number, date, and time). The main method simply calls
            the launch() function that is responsible for user interaction.
  Usage:    The user can enter any number, but only 0, and 1 to 4 have proper functionality. The menu is repeatedly
            ouput and interactable as long as the user does not exit the program.
            At the main menu:
             (1) Print the whole reservation schedule
             (2) Prints the schedule of the user's entered date
             (3) Print the list of patrons
             (4) User can reserve a table
             (0) Exits the program
             any other integer: then the user can enter another number.
*/

int main() {
  Control controlLaunch;
  controlLaunch.launch();
  return 0;
}

Control::Control()
{
  restaurant = new Restaurant("Steven's Restaurant");
}

Control::~Control()
{
  delete restaurant;
}

void Control::launch()
{
  Control launching;
  int choice = -1;

  launching.initPatrons(restaurant);
  launching.initReservations(restaurant);
  view->showMenu(choice);
  
  while (choice != 0) {
    if (choice == 1) {
      restaurant->printReservations();
    }
    else if (choice == 2) {
      int year;
      int month;
      int day;

      view->printStr("Enter schedule date; YYYY MM DD: ");
      view->readInt(year);
      view->readInt(month);
      view->readInt(day);

      restaurant->printSchedule(year, month, day);
    }
    else if (choice == 3) {
      restaurant->printPatrons();
    }
    else if (choice == 4) {
      int patronId;
      int tableNum;
      int year;
      int month;
      int day;
      int hour;
      int minute;

      view->printStr("Please enter patron ID: ");
      view->readInt(patronId);
      view->printStr("Please enter table number: ");
      view->readInt(tableNum);
      view->printStr("Enter reservation date; YYYY MM DD: ");
      view->readInt(year);
      view->readInt(month);
      view->readInt(day);
      view->printStr("Enter reservation time; hour, minutes: ");
      view->readInt(hour);
      view->readInt(minute);

      restaurant->reserveTable(patronId, tableNum, year, month, day, hour, minute);
    }
      
    view->showMenu(choice);
  }
  
}

void Control::initReservations(Restaurant* r)
{
  r->reserveTable(100,   4, 2023,  2,  3, 14, 30);
  r->reserveTable(5002,  4, 2023, 14,  3, 14, 30);
  r->reserveTable(5002,  4, 2023,  2, 30, 14, 30);

  r->reserveTable(5001,  2, 2023, 2, 14, 17, 30);
  r->reserveTable(5005,  5, 2023, 2, 14, 19, 0);
  r->reserveTable(5002,  3, 2023, 2, 14, 19, 0);
  r->reserveTable(5003,  4, 2023, 2, 14, 19, 0);
  r->reserveTable(5004,  7, 2023, 2, 14, 19, 0);

  r->reserveTable(5006,  2, 2023, 2, 14, 19, 30);
  r->reserveTable(5006,  8, 2023, 2, 14, 18, 30);
  r->reserveTable(5006, 10, 2023, 2, 14, 18, 30);
  r->reserveTable(5001,  8, 2023, 2, 14, 20, 30);
  r->reserveTable(5004,  6, 2023, 2, 14, 20, 0);
  r->reserveTable(5002,  3, 2023, 2, 14, 21, 0);

  r->reserveTable(5004,  3, 2023, 2, 11, 20, 45);
  r->reserveTable(5003,  5, 2023, 2, 11, 19, 45);
  r->reserveTable(5006,  6, 2023, 2, 11, 18, 0);
  r->reserveTable(5004,  4, 2023, 2, 11, 20, 0);
  r->reserveTable(5004,  7, 2023, 2, 11, 20, 15);
  r->reserveTable(5003,  6, 2023, 2, 11, 20, 15);
  r->reserveTable(5004, 10, 2023, 2, 11, 21, 0);
  r->reserveTable(5001,  8, 2023, 2, 11, 20, 30);
  r->reserveTable(5001,  9, 2023, 2, 11, 19, 15);
  r->reserveTable(5006,  2, 2023, 2, 11, 19, 15);
  r->reserveTable(5001, 10, 2023, 2, 11, 19, 0);
}

void Control::initPatrons(Restaurant* r)
{
  r->addPatron(new Patron("Juliet"));
  r->addPatron(new Patron("Sayid"));
  r->addPatron(new Patron("Jack"));
  r->addPatron(new Patron("Kate"));
  r->addPatron(new Patron("James"));
  r->addPatron(new Patron("Hugo"));
}