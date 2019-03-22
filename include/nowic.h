/****************************************************************************
* nowic Library 1.0 - C Library for Data Structures and Algorithms
* Youngsup Kim <idebtor@gmail.com>
*
* Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
* http://creativecommons.org/licenses/by-nc-sa/3.0/
***************************************************************************/

#ifndef NOWIC_H
#define NOWIC_H

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

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
int GetInt(std::string prompt = "Enter an integer: ");


/*
* Reads a line of text from standard input and returns the equivalent
* double as precisely as possible; if text does not represent a
* double, user is prompted to retry.  Leading and trailing whitespace
* is ignored.  For simplicity, overflow and underflow are not detected.
*/
double GetDouble(std::string prompt = "Enter a floating point number: ");

/*
 * Reads a line of text from standard input and returns the first char.
 * If text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.
 * It provides a default parameter, but it can be overwritten.
 */
char GetChar(std::string prompt = "Enter a character: ");


/*
 * Reads a line of text from standard input and returns it as a
 * c string (char *), without trailing newline character.
 * If user inputs only "\n", he/she will be asked to retry.
 * Leading and trailing whitespace is not ignored.  Stores c string
 * on heap via malloc and returns the pointer.  The memory must be
 * freed by caller to avoid leak. Use free(), or delete [] to free it.
 */
std::string GetString(std::string prompt = "Enter a string: ");

#endif
