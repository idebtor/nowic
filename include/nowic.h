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
* 2020/12/01 Created by idebtor@gmail.com
*
* Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
* http://creativecommons.org/licenses/by-nc-sa/3.0/
***************************************************************************/
#ifndef NOWICEE_H
#define NOWICEE_H

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
using namespace std;

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

#endif // NOWICEE_H