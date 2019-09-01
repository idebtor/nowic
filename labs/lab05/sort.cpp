// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// sort.cpp - This brute force version of bubble Sort that takes O(n^2).
//
// Compilation:
// g++ bubble.cpp printList.cpp -o sort
// g++ bubble.cpp printList.cpp -o sort -DDEBUG
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// To make the function included in other program, turn #if 0 off.
//
// To compile all sort files
// g++ sort.cpp bubble.cpp insertion.cpp quicksort.cpp selection.cpp
//     printList.cpp -I../../include -o sort -DDEBUG

#include <iostream>
#include <cassert>
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

		// set the function pointer based on user's choice.
		cout << "your code here - one line \n";     // declare a function pointer var
		switch(algo) {
			case 'b': cout << "b: your code here\n"; 	break;
			case 'i': cout << "i: your code here\n"; 	break;
			case 'q': cout << "q: your code here\n"; 	break;
			case 's': cout << "s: your code here\n"; 	break;
			default: break;
		}

		cout << "UNSORTED(" << N << "):\n";
		printList(list, N);

		// To sort the list, invokde the function using the function pointer.
		cout << "your code here - one line \n";
		// Uncomment the next 4 line for Step 4 ///////////////////
		// bubbleSort(list, N);
		// insertionSort(list, N);
		// quickSort(list, N);
		// selectionSort(list, N);
		// Remove 4 lines above after Step 4 //////////////////////

		cout << "SORTED(" << N << "):\n";
	  printList(list, N);
	}

	delete[] list;   // free resources
  cout << "Happy Coding~~\n";
}
