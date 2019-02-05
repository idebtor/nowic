/****************************************************************************
 * NowIC Library 1.0 - C++ Library for Data Structures and Algorithms
 *
 * Youngsup Kim <idebtor@gmail.com>
 * Compilation:
 * > g++ -c nowic.cpp -o nowic.o -I../include
 * > ar rcs libnowic.a nowic.o
 *
 * Based on Stanford Univ. - Eric Roberts' genlib.c and simpio.c.
 *          Harvard Univ. - Holloway and Malan's cs50.c
 *
 * 02/10/19 Created
 *
 * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 ***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "nowic.h"

/*
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.  If line can't be read,
 * returns CHAR_MAX.
 */
char GetChar() {
    // try to get a char from user
    while (true) {
        // get line of text, returning CHAR_MAX on failure
        cstring line = GetString();
        if (line == NULL) return CHAR_MAX;

        // return a char if only a char (possibly with
        // leading and/or trailing whitespace) was provided
        char c1, c2;
        if (sscanf(line, " %c %c", &c1, &c2) == 1) {
            free(line);
            return c1;
        }
        else {
            free(line);
            printf("Retry: ");
        }
    }
}


/*
 * Reads a line of text from standard input and returns it as an
 * int in the range of [-2^31 + 1, 2^31 - 2], if possible; if text
 * does not represent such an int, user is prompted to retry.  Leading
 * and trailing whitespace is ignored.  For simplicity, overflow is not
 * detected.  If line can't be read, returns INT_MAX.
 */
int GetInt(void) {
    // try to get an int from user
    while (true) {
        // get line of text, returning INT_MAX on failure
        cstring line = GetString();
        if (line == NULL)
            return INT_MAX;

        // return an int if only an int (possibly with
        // leading and/or trailing whitespace) was provided
        int n; char c;
		if (sscanf(line, " %d %c", &n, &c) == 1) {
            free(line);
            return n;
        }
        else {
            free(line);
            printf("Retry: ");
        }
    }
}



/*
 * Reads a line of text from standard input and returns it as a
 * cstring (char *), sans trailing newline character.  (Ergo, if
 * user inputs only "\n", returns "" not NULL.)  Returns NULL
 * upon error or no input whatsoever (i.e., just EOF).  Leading
 * and trailing whitespace is not ignored.  Stores cstring on heap
 * (via malloc); memory must be freed by caller to avoid leak.
 */
cstring GetString(void) {
    cstring buffer = NULL;			// growable buffer for chars
	unsigned int capacity = 0;		// capacity of buffer
    unsigned int n = 0;				// number of chars actually in buffer
	int c;							// character read or EOF

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF) {
        // grow buffer if necessary
        if (n + 1 > capacity) {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            cstring temp = (cstring)realloc(buffer, capacity * sizeof(char));
            if (temp == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
		buffer[n++] = c;        // append current character to buffer
    }

	if (n == 0 && c == EOF)		// return NULL if user provided no input
        return NULL;

    // minimize buffer
    cstring minimal = (cstring)malloc((n + 1) * sizeof(char));

    strncpy(minimal, buffer, n);
    free(buffer);

	minimal[n] = '\0';			// terminate cstring
    return minimal;				// return cstring
}

