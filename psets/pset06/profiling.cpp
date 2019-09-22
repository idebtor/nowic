/**
* Author:		Youngsup Kim
* Description:	This program profiles the complexity of sorting algorithms.
* It uses a for loop to control the size of the array. At each iteration, a
* new randomly ordered array of n numbers is created. In order to do more
* accurate timing, for each n, it do the sort as many times as needed to
* bring the total time up to 1 second (1000 ticks).

* This program uses clock(), not difftime() and time().

* The time complexity of the selection sort and quick sort is O(n^^2)
* and O(n log n), respectively. This program compares the elapsed time of
* sort algorithm with the theoretical upper bound O(n^^2) of the selection sort
* and O(n log n) of Quick Sort.  When it computes the elapsed time of O(n^^2)
* and O(n log n), you may use Math functions as necessary. It assumes that the
* elapsed times for all three cases are exactly the same to begin with for
* STARTING_SAMPLES 100.  Once the elapsed time of the selection sort for
* STARTING_SAMPLES is got, it is set to those for O(n^^2) and O(n log n).
*
* History:
* 15/09/10:		Created
* 19/02/20:		C++
*
* Compilation:	g++ selection.cpp profiling.cpp -o profiling
* Execution:	profiling 30000
*
* See Also:
* There is a profiling tool provided by gcc compiler. To obtain a profie
* report, compile the program with -pg option as shown below:
* > g++ -pg -o program program.cpp
*
* Then run the program. Running the program creates the file gmon.out,
* which can be viewed as follows:
* > gprof your_program
*
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include "sort.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// a helper function
// Compute the number of digit first.
// For example, 1 for [0..9], 2 for [10..99], 3 for [100..999] and so on.
// Then compute the step: 1 for 1, 10 for 2, 100 for 3 and so on.
int getStep(int n) {
	int digit = 1;
	int step = 1;

	// your code here
	step = 100;

	return step;
}

// NOTICE: There is a discrepancy between Mac and PC/Windows code
//
// rand() returns a random number between 0 and RAND_MAX which is defined in stdlib.h
// RAND_MAX is surprisingly small(32767, not 1M nor 1B) and also depends
// on the machine since RAND_MAX is defined as 0x7FFF (or 32767 = 2 ^ 15 - 1)
// The following program will work for random values in the
// range[0, (RAND_MAX + 1)*(RAND_MAX + 1)), providing there's no overflow.
// returns an array filled with random numbers [0..size)
void randomize(int list[], int size) {
	DPRINT(cout << "RAND_MAX = " << RAND_MAX << endl;);
	srand((unsigned)time(nullptr));	    // initialize random seed
	for (int i = 0; i < size; i++) {
		int x = (rand() * (RAND_MAX + 1) + rand()) % size;     // for PC
		// int x = rand() % size;                              // for mac
		swap(list[x], list[i]);     // swap list[i] with randomly selected list[x]
	}
}

//////////////// Step 4: your code here ////////////////////////////////
void profiling(void (*sortFunc)(int*, int), int* list, int n, bool random=true) {
	double duration;
	if (random)
		cout << "\tRandomized Data will be used during sorting.\n";
	else
		cout << "\tData will NOT be randomized before use.\n";

  // to save the original list into a buffer - saved
	int *saved = new (nothrow) int[n];
	assert(saved != nullptr);
	if (random) randomize(list, n); // shuffle the original list
	copy_n(list, n, saved);         // to use the same sequence during repetitions

	cout << "         n\t repetitions\t   sort(sec)\n";
	for (int i = STARTING_SAMPLES; i <= n; i += getStep(i)) {
		long repetitions = 0;
		clock_t start = clock();

		cout << "your code here for the followings inside do loop \n";
		do {
			                   // count the repetitions for one second
				                 // get a copy of list from saved
			                   // sort
		} while (clock() - start < 1000);		// run it over one sec

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;

		cout << fixed;
		cout << setw(10) << i << "\t"
			 << setw(12) << repetitions << "\t"
			 << setw(12) << duration << endl;
	}
}

////////////////////////////////////////////////////////////////////////
////// Step 4: Turn off this main() and use one in sortDriver3.cpp ////
///////////////////////////////////////////////////////////////////////
#if 1
int main(int argc, char *argv[]) {
	int N = 0;
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	if (argc == 1) {
		string str;
		cout << "The minimum number of entries is set to " << STARTING_SAMPLES << endl;
		cout << "Enter the number of max entries to sort: ";
		getline(cin, str);
		stringstream ss(str);
		ss >> N;
	}
	else if (argc == 2) {
		cout << "your code here\n";
	}

	cout << "your code here\n";

	cout << "The maximum sample data size is " << N << endl;

  // replace the following line for dynamic memory allocation by N
  int list[100];                            // Use new & N here
	for (int i = 0; i < N; i++) list[i] = i;	// unsorted data ready

	cout << "\n\tinsertionSort(): already sorted - best case." << endl;
	profiling(insertionSort, list, N, false);  // keep the data sorted

	cout << "\n\tinsertionSort(): randomized - average case." << endl;
	profiling(insertionSort, list, N);      // randomized by default

	cout << "\n\tinsertionSort(): sorted reversed - worst case." << endl;
	int j = N - 1;
	for (int i = 0; i < N; i++) list[i] = j--;	// reversed sequence
	profiling(insertionSort, list, N, false);  // keep the data sorted

	cout << "\n\tquickSort(): randomized - average case." << endl;
	cout << "your code here\n";

	// For the worst-case quicksort() testing
	cout << "\n\tquickSort(): already sorted - worst case." << endl;
	cout << "your code here\n";

	// deallocate resources

	return EXIT_SUCCESS;
}
#endif
