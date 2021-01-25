#pragma once
/****************************************************************************
* nowic Library 2.0 - C++ Library for Data Structures and Algorithms
* Usage:
*    In your source file, add the following line.
*      #include "nowic.h"
*    In your command line during the build, add the following options
*    when you are in ../src folder.
*      -I../include -L../lib -lnowic
*
* Compilation:
* > g++ -std=c++11 nowic.cpp -o nowic.o
* > ar rcs libnowic.a nowic.o
*
* 2020/12/01 verion 2.0 created by idebtor@gmail.com
* 2020/12/20 stopwatch and timer classes added
*
* Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
* http://creativecommons.org/licenses/by-nc-sa/3.0/
***************************************************************************/
#ifndef NOWIC_H
#define NOWIC_H

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

/*
 * Reads a line of text from standard input and returns it as an int in
 * the range of [-2^31 + 1, 2^31 - 2], if possible; if text does not
 * represent such an int, user is prompted to retry. Leading and trailing
 * whitespaces are ignored.  For simplicity, overflow is not detected.
 * It provides a default parameter, but it can be overwritten.
 */
int GetInt(string prompt = "Enter an integer:");
/*
 * Reads a line of text from standard input and returns the equivalent
 * float as precisely as possible; if text does not represent a
 * float, user is prompted to retry.  Leading and trailing whitespaces
 * are ignored.  For simplicity, overflow and underflow are not detected.
 */
float GetFloat(string prompt = "Enter a floating point number: ");

/*
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double, user is prompted to retry.  Leading and trailing whitespace
 * is ignored.  For simplicity, overflow and underflow are not detected.
 */
double GetDouble(string prompt = "Enter a floating point number: ");

/*
 * Reads a line of text from standard input and returns the first char.
 * If text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.
 * It provides a default parameter, but it can be overwritten.
 */
char GetChar(string prompt = "Enter a character: ");

/*
 * Reads a line of text from standard input and returns it, without newline character.
 * Leading and trailing whitespaces are not ignored.
 * If user inputs only "\n", he/she will be asked to retry.
 * No memory is allocated in heap, there is no need to free it.
 */
string GetLine(string prompt = "Enter a line: ");

/*
 * Reads a line of text from standard input and returns the first string (or a word)
 * while ignoring the rest of texts.
 * Leading and trailing whitespaces are not ignored.
 * If user inputs only "\n", he/she will be asked to retry.
 */
string GetString(string prompt = "Enter a string: ");
// It is the same as GetString(), but a different prompt. 
string GetWord(string prompt = "Enter a word: ");

#include <ctime>
#include <chrono>
/*
 * Reliably measuring the exact running time of a given program can be difficult. 
 * Fortunately, we are usually satisified with estimates. The following two classes 
 * simply measures an elapsed time. To use a timer or stopwatch, instantiate an object 
 * right before code that you want to measure an elapsed time. Then invoke elpasedTime() 
 * method right after the code that you're timing.
 * For example:
 *    timer t;
 *    ..... your code to measure an elapsed time......
 *    cout << t.elapsedTime() << endl;
 *
 */

class stopwatch {  // measures clock in Windows, processor time on Linux
private:
	clock_t begin;
public:
	stopwatch() { begin = clock(); }
	double elapsedTime() {
		return ((double)clock() - begin) / CLOCKS_PER_SEC;
	}
	void reset() { begin = clock(); }
	void print(string prompt = "\ttime elapsed: ") {
		cout << prompt << elapsedTime() << " sec\n";
	}
};

using namespace std::chrono;;
class timer {  // measures elapsed time
private:
	high_resolution_clock::time_point begin;
public:
	timer() { begin = high_resolution_clock::now(); }
	double elapsedTime() {
		high_resolution_clock::time_point end = high_resolution_clock::now();
		return (double)duration_cast<milliseconds>(end - begin).count() / 1000;
	}
	void start() { begin = high_resolution_clock::now(); }
	void print(string prompt = "\ttime elapsed: ") {
		cout << prompt << elapsedTime() << " sec\n";
	}
};

#endif 