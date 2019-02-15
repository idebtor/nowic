/****************************************************************************
* Nowic Library 1.0 - C++ Library for Data Structures and Algorithms
* Youngsup Kim <idebtor@gmail.com>
* Usage:
*    In your source file, add the following line.
*      #include "nowic.h"
*    In your command line during the build, add the following options
*    when you are in ../src folder.
*      -I../include -L../lib -lnowic
*
* Compilation:
* > g++ -c nowic.cpp -o nowic.o
* > ar rcs libnowic.a nowic.o
*
* 2019/02/05 Created
*
* Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
* http://creativecommons.org/licenses/by-nc-sa/3.0/
***************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

/*
 * Reads a line of text from standard input and returns it as an int in
 * the range of [-2^31 + 1, 2^31 - 2], if possible; if text does not
 * represent such an int, user is prompted to retry. Leading and trailing
 * whitespace is ignored.  For simplicity, overflow is not detected.
 * It provides a default parameter, but it can be overwritten.
 */
 int GetInt(std::string prompt = "Enter an integer: ") {
   int keyin;
   std::string line;
   std::cout << prompt;                   // display a prompt
   while (true) {
     if (std::getline(std::cin, line)) {  // get an input
       std::stringstream sstr(line);      // make sstream obj
       if (sstr >> keyin) break;          // scan for int
     }
     std::cout << "Retry: ";              // not an int, retry
   }
   return keyin;
 }

/*
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double, user is prompted to retry.  Leading and trailing whitespace
 * is ignored.  For simplicity, overflow and underflow are not detected.
 */

double GetDouble(std::string prompt = "Enter a floating point number: ") {
  double x;
  std::string line;
  std::cout << prompt;                   // display a prompt
  while (true) {
    if (std::getline(std::cin, line)) {  // get an input
      std::stringstream sstr(line);      // make sstream obj
      if (sstr >> x) break;          // scan for double
    }
    std::cout << "Retry: ";              // not an int, retry
  }
  return x;
}

/*
 * Reads a line of text from standard input and returns the first char.
 * If text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.
 * It provides a default parameter, but it can be overwritten.
 */
char GetChar(std::string prompt = "Enter a character: ") {
  char ch;
  std::string line;
  std::cout << prompt;                  // diplay prompt
  while (true) {
    if (getline(std::cin, line)) {      // get a line
      std::stringstream sstr(line);     // create a sstream obj
      if (sstr >> ch) break;            // get the first char
    }
    std::cout << "Retry: ";             // not a char, retry
  }
  return ch;
}

/*
 * Reads a line of text from standard input and returns it as a
 * string in C++, without trailing newline character.
 * If user inputs only "\n", he/she will be asked to retry. Leading
 * and trailing whitespace is not ignored.
 * No memory is allocated in heap, there is no need to free it.
 */
std::string GetString(std::string prompt = "Enter a string: ") {
  std::string line, str;
  std::cout << prompt;                 // display prompt
  while (true) {
    if (getline(std::cin, line)) {     // get a line
      std::stringstream ssobj(line);   // make string stream obj
      if (ssobj >> str) break;         // scan for a string
    }
    std::cout << "Retry: ";            // if not, retry
  }
  return str;                          // C++ string object
}

 /*
  * Reads a line of text from standard input and returns it as a
  * c char array or char *, without trailing newline character.
  * If user inputs only "\n", he/she will be asked to retry. Leading
  * and trailing whitespace is not ignored.  It stores c char array
  * on heap via malloc and returns the pointer. The memory must be
  * freed by caller to avoid leak. Use free() or delete [] to free it.
  */
 char* GetCString(std::string prompt = "Enter a string: ") {
   std::string line, str;
   std::cout << prompt;                 // display prompt
   while (true) {
     if (getline(std::cin, line)) {     // get a line
       std::stringstream ssobj(line);   // make string stream obj
       if (ssobj >> str) break;         // scan for a string
     }
     std::cout << "Retry: ";            // if not, retry
   }
   char *cstr = new char [str.length()+1]; // malloc for c char array
   strcpy (cstr, str.c_str());          // copy the contents
   return cstr;                         // C string - char array
 }

// For the sake of a simple testing
#if 0
int main() {
  int i = GetInt();
  std::cout << "i=" << i << "==" << std::endl;

  double x = GetDouble();
  std::cout << "x=" << x << "==" << std::endl;

  char ch = GetChar();
  std::cout << "ch=" << ch << "==" << std::endl;

  char *cstr = GetCString();
  std::cout << "str=" << cstr << "==" << std::endl;
  delete cstr;

  std::string str = GetString();
  std::cout << "str=" << str << "==" << std::endl;

  std::cout << "Happy Coding~~\n";
}
#endif
