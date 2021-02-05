//	Lecture Note by idebtor@gmail.com
//	
//	This program is written to test the sort algorithms interactively. 
//	It takes the number of data samples to sort from the user. Then, the int 
//	array is created and filled with random numbers. The User may select one 
//	of sort functions to be used. Then execution time and its output is displayed.
//	
//	01/10/21:	Created in C++ by idebtor@gmail.com
// 
//	Subjects: 
//		- Sort algorithms: bubble, insertion, mergesort, quicksort, selection sort
//		- Shuffle/randomize algorithms
//		- Using static libraries, header files
//		- Using function pointers as a first class object
//		- Using rand(), srand(), %, new, delete, nothrow, assert()
//		- Using C++ string stream <sstream>
//		- Using STL map container
//	
//	Before Compilation, you must have some files (static library and include file) 
//	ready as shown below:
//	nowic.h, sort.h, rand.h, libnowic.a, libsort.a, librand.a 
//
//	Compilation:
//	g++ sortDriver.cpp -I../../include -L../../lib -lnowic -lsort -lrand -o sort 

#include <ctime>
#include <cassert>
#include <iostream>
#include <sstream>
#include <map>
#include "rand.h"
#include "nowic.h"
#include "sort.h"
using namespace std;

void profiling(void (*sort_fp)(int*, int, bool (*comp)(int, int)), int* list, const int n, 
               bool (*comp_fp)(int, int));

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	char choice;
	int keyin;
	clock_t begin;
	int show_n = 20;					// the total number of samples to show
	int per_line = 10;					// the number of samples per line to show
	int N = 50;							// a magic number - initial number of samples
	int *list = new (nothrow) int[N];   // create a list 
	assert(list != nullptr);
	for (int i = 0; i < N; i++) list[i] = i;

	// Declare a comparator function pointer 'comp_fp' variable and initialize 
	// it with an ascending order comparator function, '::less'.
	bool (*comp_fp)(int, int) = ::less;          	// declare a comp_fp                            

	// Declare a sort function pointer variable 'sort_fp' and initialize it 
	// with a sort function, 'bubblesort': 
	void (*sort_fp)(int *, int, bool (*comp)(int, int)) = bubblesort;   // declare sort_fp

	///////////////////////////////////////////////////////////////////////////////
	// Two STL maps are used for showing the current status of user's selections.
	// comp_map[xxx_fp] contains one of sorting-orders, "Ascending" or "Descending".
	// sort_map[xxx_fp] contains one of sorting algorithms. 
	///////////////////////////////////////////////////////////////////////////////

	// Define a STL map variable 'comp_map' to associate the comparator 
	// function pointer with a description such as "Ascending" and "Descending", 
	// respectively.
	map<bool (*)(int, int), string> comp_map;       // define comp_map

	// Insert(or populate) 'comp_map' with two keys and values pairs. 
	comp_map[::less] = "Ascending";                                 
	comp_map[  more] = "Descending";     

	// Define a STL map variable 'sort_map' to associate <key_type, value_type> pair,  
	// where key_type is sort fp and value_type is a description of the sort name.
	map<void (*)(int *, int, bool (*comp)(int, int)), string> sort_map; // define sort_map

	// Insert (or populate) 'sort_map' with key and value pairs. 
	// For example, sort_map[bubblesort] = "Bubble";
	sort_map[bubblesort] = "Bubble";
	sort_map[insertionsort] = "Insertion";
	sort_map[mergesort] = "Merge";
	sort_map[quicksort] = "Quick";
	sort_map[selectionsort] = "Selection";

	setvbuf(stdout, NULL, _IONBF, 0);  	// to prevent the output from buffered on console.

	do {
		printlist(list, N, show_n, per_line);
		stringstream ss;
		ss << "\tMENU[ sort=" << sort_map[sort_fp] << " order=" << comp_map[comp_fp];
		ss << " N=" << N << " show_n=" << show_n << " per_line=" << per_line << " ]";

		cout << ss.str() << endl;
		cout << "\tB - Bubblesort\t" 		<< "\tn - set N samples and initialize\n"; 
		cout << "\tI - Insertionsort"	 	<< "\tr - randomize(shuffle) samples\n";
		cout << "\tM - Mergesort\t"			<< "\tm - max samples to show: show_n\n";
		cout << "\tQ - Quicksort\t" 		<< "\tl - max samples to show: per_line\n";
		cout << "\tS - Selectionsort"		<< "\to - order[Ascending/Descending]\n";	
		cout << "\ts - sort()\n";
		cout << "\tp - profiling()\n";
		choice = GetChar("\tCommand(q to quit): ");

		switch (choice) {
		case 'B':
			sort_fp = bubblesort;
			break;
		case 'I':
			sort_fp = insertionsort;
			break;
		case 'M':
			sort_fp = mergesort;
			break;
		case 'Q':
			sort_fp = quicksort;
			break;
		case 'S':
			sort_fp = selectionsort;
			break;

		case 'n': 
			keyin = GetInt("\tEnter sample size N: ");
			if (keyin <= 1) {
				cout << "\tExpecting a number greater than 1\n";
				break;
			}

			// set N with the new keyin value
			// before allocating the new list, free the old list if not NULL
			// allocate memory for new data samples
			// Fill the list with numbers from 0 to n - 1.
			delete [] list;
			N = keyin;
			list = new (nothrow) int[N];
			assert(list != nullptr);
			for (int i = 0; i < N; i++) list[i] = i;
			break;

		case 'r': 
			randomize(list, N);
			break;

		case 'm': 
			keyin = GetInt("\tEnter max samples to display: ");
			if (keyin <= 1) {
				cout << "\tExpecting a number greater than 1";
				break;
			}
			show_n = keyin;
			break;

		case 'l': 
			keyin = GetInt("\tEnter max samples per line: ");
			if (keyin <= 1) {
				cout << "\tExpecting a number greater than 1";
				break;
			}
			per_line = keyin;
			break;
		
		case 'o': 
			comp_fp = (comp_fp == ::less) ? more : ::less;
			break;

		case 's': 
			begin = clock();
			sort_fp(list, N, comp_fp);  			
			show_timeit(begin);
			break;

		////////////////////// profiling only////////////////////////////////
		case 'p':
			if (N < STARTING_SAMPLES) {
				cout << "\tFor profiling, set sample size > " << STARTING_SAMPLES << endl;
				break;
			}

			profiling(sort_fp, list, N, comp_fp);
			break;
		///////////////////////////////////////////////////////////////////////////

		default:
			break;
		}
	} while (choice != 'q');

	if (list != NULL) delete[] list;
	cout << "\tHappy Coding~~";
	return EXIT_SUCCESS;
}
