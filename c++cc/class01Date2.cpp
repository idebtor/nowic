// Date class program(ver.1).  Uses global arrays.
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// Global arrays
const int mdays[ ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string mnames[ ] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Date {  //convention is to use initial caps for Class Names.
private:      // This data is encapsulated (accessible through member func.)
     int daynum( ) const;   // private function
     int day;               // private data
     int month;
public:       // defines member functions
      Date(); // the default constructor (no return type with constructors)
      Date(int, int);
      void add_day( );
      void display() const;
      bool operator== (const Date&) const; // const ref parameter for passing object
      bool operator< (const Date&) const;  // final const indicates accessor function
      int operator- (const Date&) const;

};    // Don't forget the semicolon at the end of the class definition!

// Define the member functions
Date::Date()  { // Default constructor
  day = 1;
  month = 1;
}

Date::Date(int d, int m) {
  // assert requires the <cassert> library
  assert(m >= 1 && m <= 12 && d >= 1 && d <= mdays[m]);
  day = d;
  month = m;
}

void Date::add_day( ) {
  if (day == mdays[month]) { // is it last day of the month?
    day = 1;
    month = month % 12 + 1;
  }
  else day++;
}

void Date::display( ) const {
  cout << day << " " << mnames[month] << endl;
}

bool Date::operator== (const Date& dx) const {
  return month == dx.month && day == dx.day;
}

bool Date::operator< (const Date& d) const {
  return month < d.month || month == d.month && day < d.day;
}

int Date::operator- (const Date& dx) const {
  return daynum() - dx.daynum();
}

int Date::daynum( ) const {
  int num = 0;
  for (int i = 1; i < month; i++)
      num += mdays[i];
  num += day;
  return num;
}
// END OF MEMBER FUNCTION DEFINITIONS

int main( ) {
  Date d1;
  Date d2(30, 11);
  d1.display();
  d2.display();
  d2.add_day();
  d2.display();
  if (d1 == d2)
        cout << "Same date" << endl;
  else cout << "Different dates" << endl;
  cout << "Days between d1 and d2: " << d2 - d1 << endl;
  Date d3(d1);
  Date d4;
  d4 = d1;
  d3.display();
  d4.display();
  if (d3 == d4)
        cout << "Same date" << endl;
  else cout << "Different dates" << endl;
}
