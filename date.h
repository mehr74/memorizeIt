#ifndef _DATE_H
#define _DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
  public:
              // constructors
    Date();                       // construct date with default value
    Date(long days);          // construct date from absolute #
    Date(int m,int d,int y);      // construct date with specified values

              // accessor functions

    int Month()          const;     // return month corresponding to date
    int Day()            const;     // return day corresponding to date
    int Year()           const;     // return year corresponding to date
    int DaysIn()         const;     // return # of days in month
    string DayName()     const;     // "monday", "tuesday", ... or "sunday"
    string MonthName()   const;     // "january","february",... or "december"
    long Absolute()      const;     // number of days since 1 A.D. for date
    string ToString()    const;     // returns string for date in ascii

    bool Equal(const Date & rhs) const;  // for implementing <, >, etc
    bool Less(const Date & rhs) const;

    // mutator functions

    Date operator ++(int);         // add one day, postfix operator
    Date operator --(int);         // subtract one day, postfix operator
    Date& operator +=(long dx);    // add dx, e.g., jan 1 + 31 = feb 1
    Date& operator -=(long dx);    // subtract dx, e.g., jan 1 - 1 = dec 31

  private:

    int myDay;                    // day of week, 0-6
    int myMonth;                  // month, 0-11
    int myYear;                   // year in four digits, e.g., 1899

    void CheckDate(int m, int d, int y); // make sure that date is valid
};

Date operator + (const Date & d, long dx);   // add dx to date d
Date operator + (long dx, const Date & d);   // add dx to date d
Date operator - (const Date & d, long dx);   // subtract dx from date d
long operator - (const Date & lhs, const Date & rhs);

ostream & operator << (ostream & os, const Date & d);
bool operator == (const Date & lhs, const Date & rhs);
bool operator != (const Date & lhs, const Date & rhs);
bool operator <  (const Date & lhs, const Date & rhs);
bool operator >  (const Date & lhs, const Date & rhs);
bool operator <= (const Date & lhs, const Date & rhs);
bool operator >= (const Date & lhs, const Date & rhs);

#endif
