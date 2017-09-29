#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

 * 
 */

inline bool isLeapYear(int year) {
  if (year % 4 != 0) {
    return false;
  }
  if (year % 400 == 0) {
    return true;
  }
  return year % 100 != 0;
}

int main() {
  //01/01/1900 was a Monday:
  int date = 1, month = 1, year = 1900, day = 1;
  int count;
  
  while (year <= 2000) {    
 
    day = (day == 7) ? 1 : day + 1;
    //have we fallen off the end of the month?
    if (date == 31) {
      date = 1;
    } else if ((date == 30) && ((month == 9) || (month == 4) || (month == 6) || (month == 11))) {
      date = 1;
    } else if ((date == 29) && (month == 2)) {
      date = 1;
    } else if ((date == 28) && (month == 2) && !isLeapYear(year)) {
      date = 1;
    } else {
      date++;
    }
    
    if (date == 1) {
      //we need to increment the month
      if (month == 12) {
	month = 1;
	year++;
      } else {
	month++;
      }
    }
 
    //see if this is a Sunday on the first day of the month
    if ((year >= 1901) && (date == 1) && (day == 7)) {
      count++;
    }
//    printf("%i-%i-%i (%i)\n", date, month, year, day); 
  }
  
  printf("Answer: %i\n", count);
  return 0;
}
