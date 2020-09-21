/**
* Author:		Youngsup Kim
* Description:	This program profiles the complexity of sorting algorithms.
* It uses a for loop to control the size of the array. At each iteration, a
* new randomly ordered array of n numbers is created. In order to do more
* accurate timing, for each n, it do the sort as many times as needed to
* bring the total time up to 1 second (1000 ticks).

* This program uses clock(), not difftime() and time().

* The time complexity of the selection sort and quick sort is O(n^2)
* and O(n log n), respectively. This program compares the elapsed time of
* sort algorithm with the theoretical upper bound O(n^2) of the selection sort
* and O(n log n) of Quick Sort.  When it computes the elapsed time of O(n^2)
* and O(n log n), you may use Math functions as necessary. It assumes that the
* elapsed times for all three cases are exactly the same to begin with for
* STARTING_SAMPLES 500.  Once the elapsed time of the selection sort for
* STARTING_SAMPLES is got, it is set to those for O(n^2) and O(n log n).
*
* History:
* 15/09/10:		Created
* 19/02/20:		C++
*
* Compilation:	g++ insertion.cpp profiling.cpp -o profilingx
* Execution:	profiling 50000
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
#include <cassert>
#include <algorithm>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include "sort.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// a helper function
// Compute the number of digit first and return step size such as 100, 1000, 10000 etc.
// Refer to some instructions provided in pset pdf file.
int getStep(int n) {
	int digit = 1;
	int step = 1;

	// compute the number of digit first
	do {
		n = n / 10;
		if (n > 0) digit++;
	} while (n > 0);

	// compute the step
	for (int i = 0; i < (digit - 1); i++)
		step *= 10;
	return step;
}

// returns an extended random number of which the range is from 0
// to (RAND_MAX + 1)^2 - 1. // We do this since rand() returns too 
// small range [0..RAND_MAX) where RAND_MAX is usually defined as 
// 32767 in cstdlib. Refer to the following link for details
// https://stackoverflow.com/questions/9775313/extend-rand-max-range
unsigned long rand_extended(int range) {
	if (range < RAND_MAX) return rand();
	return rand() * RAND_MAX + rand();
}

void randomize(int list[], int size) {
	DPRINT(cout << "RAND_MAX = " << RAND_MAX << endl;);
	srand((unsigned)time(nullptr));	    // initialize random seed
	int size_minus_1 = size - 1;
	for (int i = 0; i < size; i++) {
		int x = rand_extended(size) % size_minus_1;
		swap(list[x], list[i]);     // swap list[i] with randomly selected list[x]
	}
}

void profiling(void (*sortFunc)(int*, int), int* list, const int n, bool random=true) {
	double duration;
	if (random)
		cout << "\tRanomized Data will be used during sorting.\n";
	else
		cout << "\tData will NOT be randomized before use.\n";

	// to save the original list into a buffer - saved
	int *saved = new (nothrow) int[n];
	assert(saved != nullptr);
	if (random) randomize(list, n); // shuffle the original list
	copy_n(list, n, saved);         // to use the same sequence during repetitions

	cout << "         N\t repetitions\t   sort(sec)\n";
	for (int i = STARTING_SAMPLES; i <= n; i += getStep(i)) {
		long repetitions = 0;
		clock_t start = clock();
		do {
			repetitions++;                    // count the repetitions for one second
			copy_n(saved, n, list);	          // get a copy of list from saved
			sortFunc(list, i);                // sort
		} while (clock() - start < CLOCKS_PER_SEC);     // run it over one sec

		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		duration /= repetitions;

		cout << fixed;
		cout << setw(10) << i << "\t"
			 << setw(12) << repetitions << "\t"
			 << setw(12) << duration << endl;
	}

	delete[] saved;
}

#if 1
int main(int argc, char *argv[]) {
	int N = 0;
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, nullptr, _IONBF, 0);

	if (argc == 1) {
		string str;
		cout << "The minimum number of entries is set to " << STARTING_SAMPLES << endl;
		cout << "Enter the number of max entries to sort: ";
		getline(cin, str);
		stringstream ss(str);
		ss >> N;
	}
	else if (argc == 2) {
		char *end;
		N = strtol(argv[1], &end, 10);
		if (N <= 0 || *end != '\0')
			std::cout << "Usage: profiling [N]\n";
	}

	if (N <= STARTING_SAMPLES) {
		cout << "Enter a number much larger than " << STARTING_SAMPLES << ".\n";
		exit(EXIT_FAILURE);
	}

	cout << "The maximum sample data size is " << N << endl;

	int *list = new (nothrow) int[N];
	assert(list != nullptr);
	for (int i = 0; i < N; i++) list[i] = i;   // unsorted data ready

	cout << "\n\tinsertionSort(): already sorted - best case." << endl;
	profiling(insertionSort, list, N, false);  // keep the data sorted

	cout << "\n\tinsertionSort(): randomized - average case." << endl;
	profiling(insertionSort, list, N);         // randomized by default

	cout << "\n\tinsertionSort(): sorted reversed - worst case." << endl;
	int j = N - 1;
	for (int i = 0; i < N; i++) list[i] = j--;	// reversed sequence
	profiling(insertionSort, list, N, false);   // keep the data sorted

	cout << "\n\tquickSort(): randomized - average case." << endl;
	profiling(quickSort, list, N);              // randomized - avg case

	delete [] list;
	return EXIT_SUCCESS;
}
#endif
