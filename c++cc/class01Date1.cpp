#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Date {  //convention is to use initial caps for Class Names.
private:      // This data is encapsulated (accessible through member func)
  int day;
  int month;
public:       // how the private data is exposed for reading and writing
  Date();                 // the default constructor
  Date(int, int);
  void add_day( );        // no return value and takes no args
  void display( ) const;  // const because accessor, not mutator
}; // Don't forget the semicolon at the end of the class definition!

//These global arrays define the names of months and days in the month.
const int mdays[ ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string mnames[ ] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


// Define the member functions
Date::Date() { // Default constructor
  day = 1;
  month = 1;
}

Date::Date(int d, int m) {
  // assert requires the <cassert> library
  assert(m >= 1 and m <= 12 and d >= 1 and d <= mdays[m]);

  /* You can also use the <cstdlib> library's exit function as follows:
   if(m<1 or m>12) {
     cerr << "Invalid month." << endl;  // Goes to the cerr output stream
     exit(1);  // requires <cstdlib> library
   } and then do something similar for d.
  */
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
// END OF MEMBER FUNCTION DEFINITIONS

int main( ) {
  Date d1;
  Date d2(11, 30);
  d1.display();
  d2.display();
  d1.add_day();
  d1.display();
}
