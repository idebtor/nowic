// Topic: Performance Analysis - profiling
//
// Description:	This program profiles the complexity of sorting algorithms.
// It uses a for loop to control the size of the array. At each iteration,
// a new randomly ordered array of n numbers is created. In order to do more
// accurate timing, for each n, it do the sort as many times as needed to
// bring the total time up to 1 second (1000 ticks).
// This program uses clock(), not difftime() and time().
// The time complexity of the selection sort and quick sort is O(n^2)
// and O(n log n), respectively. This program compares the elapsed time of
// sort algorithm with the theoretical upper bound O(n^2) of the selection sort
// and O(n log n) of Quick Sort.  When it computes the elapsed time of O(n^2)
// and O(n log n), you may use Math functions as necessary. It assumes that the
// elapsed times for all three cases are exactly the same to begin with for
// STARTING_SAMPLES 1000.  Once the elapsed time of the selection sort for
// STARTING_SAMPLES is got, it is set to those for O(n^2) and O(n log n).
//
// History:
// 2021/01/29:	Created
// 2021/01/02:	proflie.cpp - updated for macOS and DEBUG options
//
// Compilation:	
// $ g++ profiling.cpp -I../../include -L../../lib -lsort -o profiling
// $ ./profiling 50000
//
// Compilation:	
// $ g++ profiling.cpp -I../../include -L../../lib -lsort -o profiling
// $ ./profiling 50000

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <ctime>       /* clock_t, clock, CLOCKS_PER_SEC */
#include "sort.h"
#include "rand.h"
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

void profiling(void (*sort_fp)(int*, int, bool (*comp)(int, int)), int* list, const int n, 
               bool (*comp_fp)(int, int)) {
	
	int *saved = new (nothrow) int[n];		// to save the original list into a buffer
	assert(saved != nullptr);
	copy_n(list, n, saved);         		// to use the same sequence during repetitions

	cout << "         N\t repetitions\t   sort(sec)\n";
	for (int i = STARTING_SAMPLES; i <= n; i += getStep(i)) {
		long repetitions = 0;
		clock_t start = clock();
		do {
			repetitions++;                    		// count the repetitions for one second
			copy_n(saved, n, list);	          		// get a copy of list from saved
			sort_fp(list, i, comp_fp);          	// sort
		} while (clock() - start < CLOCKS_PER_SEC); // run it over one sec

		double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
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
	setvbuf(stdout, nullptr, _IONBF, 0); // prevent the output from buffered on console.

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
		cout << "Enter a number greater than " << STARTING_SAMPLES << ".\n";
		exit(EXIT_FAILURE);
	}

	cout << "The maximum sample data size is " << N << endl;
	
	int *list = new (nothrow) int[N];
	assert(list != nullptr);

	///////////// rewrite this part for DRY and MNN ////////////////////////

	cout << "\n\tinsertionsort(): sorted" << endl;
	for (int i = 0; i < N; i++) list[i] = i;   			// sorted data ready
	profiling(insertionsort, list, N, ::less);  		

	cout << "\n\tinsertionsort(): randomized" << endl;
	randomize(list, N);
	profiling(insertionsort, list, N, ::less);         	// randomized 

	cout << "\n\tinsertionsort(): reversed" << endl;
	int j = N - 1;
	for (int i = 0; i < N; i++) list[i] = j--;			// reversed sequence
	profiling(insertionsort, list, N, ::less);   		


	cout << "\n\tmergesort(): sorted" << endl;
	for (int i = 0; i < N; i++) list[i] = i;   			// sorted data ready
	profiling(mergesort, list, N, ::less);  		

	cout << "\n\tmergesort(): randomized" << endl;
	randomize(list, N);
	profiling(mergesort, list, N, ::less);         		// randomized

	cout << "\n\tmergesort(): reversed" << endl;
	j = N - 1;
	for (int i = 0; i < N; i++) list[i] = j--;			// reversed sequence
	profiling(mergesort, list, N, ::less);   	

	cout << "\n\tquicksort(): sorted" << endl;
	for (int i = 0; i < N; i++) list[i] = i;   			// sorted data ready
	profiling(quicksort, list, N, ::less);              

	cout << "\n\tquicksort(): randomized" << endl;
	randomize(list, N);
	profiling(quicksort, list, N, ::less);              // randomized 

	cout << "\n\tquicksort(): reversed" << endl;
	j = N - 1;
	for (int i = 0; i < N; i++) list[i] = j--;			// reversed sequence
	profiling(quicksort, list, N, ::less);   

	///////////// rewrite this part for DRY and MNN ////////////////////////

	delete [] list;
	return EXIT_SUCCESS;
}
#endif
