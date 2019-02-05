/****************************************************************************
* nowic Library 1.0 - C Library for Data Structures and Algorithms
* Youngsup Kim <idebtor@gmail.com>
*
* Based on Stanford Univ. - Eric Roberts' genlib.c and simpio.c.
*          Harvard Univ. - Holloway and Malan's cs50.c
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

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>

// Our own data type for string variables.
typedef char *cstring;   // a pointer to a char or an array of chars

/*
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.  If line can't be read,
 * returns CHAR_MAX.
 */
char GetChar(void);


/*
 * Reads a line of text from standard input and returns it as an
 * int in the range of [-2^31 + 1, 2^31 - 2], if possible; if text
 * does not represent such an int, user is prompted to retry.  Leading
 * and trailing whitespace is ignored.  For simplicity, overflow is not
 * detected.  If line can't be read, returns INT_MAX.
 */
int GetInt(void);

/*
* Reads a line of text from standard input and returns it as a
* cstring (char *), sans trailing newline character.  (Ergo, if
* user inputs only "\n", returns "" not NULL.)  Returns NULL
* upon error or no input whatsoever (i.e., just EOF).  Leading
* and trailing whitespace is not ignored.  Stores c string on heap
* (via malloc); memory must be freed by caller to avoid leak.
*/
cstring GetString(void);

#endif
