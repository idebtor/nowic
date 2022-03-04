// Note:
// A header file only has to be written once, and it can be included
// in as many files as needed. This also helps with maintenance by
// minimizing the number of changes that need to be made if a
// function prototype ever changes (eg. by adding a new parameter).
// Header files consist of two parts. The first part is called a
// header guard, it prevents a given header file from being
// #included more than once in the same file.
// The second part is the actual content of the.h file, which
// should be the declarations for all of the functions we want
// other files to be able to see. Our header files should all
// have a .h extension, so we will call our new header file sort.h:
//
// Have the header guard, #ifndef, unless #pragma once
// By the way, some compilers don't support #pragma.
//
// This is start of the header guard. SORT_H can be any unique name.
// By convention, we use the name of the header file.
#ifndef SORT_H
#define SORT_H

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// two comparator function prototypes
// The value returned indicates whether the element passed as first argument
// is considered to go before the second in the specific ordering.
// more() and less() are equivalent to greater<int>() and less<int>() in STL. 
bool more(int x, int y);   // for descending order
bool less(int x, int y);   // for ascending order 

// declare the sort function prototypes 
void bubblesort(int *list, int n, bool (*comp)(int, int) = ::less);
void insertionsort(int *list, int n, bool (*comp)(int, int) = ::less);
void mergesort(int *a, int N, bool (*comp)(int, int) = ::less);
void quicksort(int *a, int n, bool (*comp)(int, int) = ::less);
void selectionsort(int *list, int n, bool (*comp)(int, int) = ::less);

// prints all the values in the list if the list size N is less than show_n.
// If the list size is greater than show_n, then it shows only show_n/2
// values from the beginning part and the end part in the list, respectively.
void printlist(int *list, int n, int show_n = 20, int per_line = 10);

// for initial samples 
const int STARTING_SAMPLES = 1000;
#endif
