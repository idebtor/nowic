// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// sort.cpp - This brute force version of bubble Sort that takes O(n^2).
//
// Compilation:
// g++ bubble.cpp -o sort
// g++ bubble.cpp -o sort -DDEBUG
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// To make the function included in other program, turn #if 0 off.

#include <iostream>
#include <cassert>
#include "sort.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void printList(int *list, int n);

int main(int argc, char *argv[]) {
	int unsorted[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	int N = sizeof(unsorted) / sizeof(unsorted[0]);

	// make a list to save the data
	int *list = new (nothrow) int[N];
	assert(list != nullptr);

	while (1) {
		// set a list to sort from unsorted.
		for (int i = 0; i < N; i++) list[i] = unsorted[i];

		// ask user to chhose a sorting algorithm
		char algo;
		cout << "b for bubble, i for insertion, q for quick, s for selection \n";
		cout << "Enter an algorithm to sort(x to exit): ";
		cin >> algo;
		if (algo == 'x') exit(0);
		if (algo != 'b' && algo != 'i' && algo != 'q' && algo != 's') {
			cout << "The sort algorithm must be one of (b, i, q, s).\n";
			exit(1);
		}

		cout << "UNSORTED(" << N << "):\n";
		printList(list, N);

		// set the function pointer based on user's choice.
		// 1. declare a function pointer
		cout << "your one-line code here"
		// 2. switch statements to set the function pointer to a function
		switch(algo) {
			case 'b':
			case 'i':
			case 'q':
			case 's': cout << "your code here";
			default: break;
		}

		// 3. invoke a sort function using the function pointer.
		cout << "your one-line code here"

		cout << "SORTED(" << N << "):\n";
	  printList(list, N);
	}

	delete[] list;   // free resources
  cout << "Happy Coding~~\n";
}
