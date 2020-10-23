/**
Name        : listdblDriver.cpp
Author      : Youngsup Kim, idebtor@gmail.com

04/13/16:	Created
10/20/18:	Added: O(1) options
04/10/18:	added stress test functions more completely
02/10/19:	doubly linked list with sentinel nodes
10/20/20:	randomize() - added for quicksort, swap_nodes() added

Description :
: This implements a doubly linked list with two sentinel nodes
: including interactive stress test options.

Note:
For quicksort with a large dataset with the repetition of the same
value, the algorithm requires a large stack. There are two ways to solve it.
1. Randomize the sequence before sorting. It takes O(n). Therefore it would
   hurt the complexity of sorting overall. 
2. Increase the stack size as shown below, but this is not perfect solution.
For example, if there are 50,000 of the same value repeated in the container,
I had to set the stack size to 16M (or 16777216)

For visual studio: Project Properties->Linkers->System->Stack Reserve Size
For g++/MinGW cmd windows, the following command set the stack size to 16M.
  g++ -Wl,--stack,16777216 listdblDriver.cpp listdbl.cpp .......
To check the stack size on Windows, you may use dumpbin that comes with VS
For Mac OSX
  g++ -Wl,-stack_size,0x100000 listdblDriver.cpp listdbl.cpp .......
To check the stack size on OSX
  otool -lv _exefile_name | grep stack
*/

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include "nowic.h"
#include "listdbl.h"
using namespace std;

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}

int main() {
	char c;
	int value, x, N;
	clock_t begin = 0;
	string show_menu[] = { "HEAD/TAIL", "ALL" };
	bool show_all = false;		// toggle the way of showing values
	int show_n = 10;			// a magic number to begin with 
	pList p = new List();		// create an empty list with two sentinel nodes
	
	do {
		cout << "\n\tDoubly Linked List(nodes:" << size(p)
			<< ", show:" << show_menu[show_all] << "," << show_n << ")\n";

		cout << "\tf - push front       O(1)";	 cout << "\tp - pop front   O(1)\n";
		cout << "\tb - push back        O(1)"; 	 cout << "\ty - pop back    O(1)\n";
		cout << "\ti - push             O(n)"; 	 cout << "\td - pop         O(n)\n";
		cout << "\tz - push sorted      O(n)";	 cout << "\te - pop all*    O(n)\n";
		cout << "\tB - push back N      O(n)";   cout << "\tY - pop back N  O(n)\n";
		cout << endl;
		cout << "\tu - unique*          O(n)";   cout << "\ts - sort*       O(.)\n";
		cout << "\tw - swap pairs       O(n)";   cout << "\tr - reverse     O(n)\n";
		cout << "\tx - perfect shuffle**O(n)";   cout << "\ta - randomize   O(n)\n";
		if (show_all)
			cout << "\tt - show [HEAD/TAIL]\t";
		else
			cout << "\tt - show [ALL]\t\t";
		cout << "\tn - n nodes per line\n";
		cout << "\tc - clear              \n";
		c = GetChar("\tCommand[q to quit]: ");

		switch (c) {	// execute the command
		case 'f':
		case 'b':
		case 'i':
		case 'z':
			value = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				push_front(p, value);
				break;
			case 'b':
				push_back(p, value);
				break;
			case 'i':  // push
				x = GetInt("\tChoose a position node: ");
				push(p, value, x);
				break;
			case 'z':  // push_sorted
				if (!empty(p) && !sorted(p)) {
					cout << "\t Run sort first and try it again\n";
					break;
				}
				begin = clock();
				push_sorted(p, value);
				show_timeit(begin);
				break;
			}
			break;

		case 'p':  // deletes the first node in the list
			if (empty(p)) break;
			begin = clock();
			pop_front(p);
			show_timeit(begin);
			break;
		case 'y':  // deletes the last node in the list, O(n)
			if (empty(p)) break;
			pop_back(p);
			break;
		case 'd':  // deletes one node with the value
			if (empty(p)) break;
			value = GetInt("\tEnter a number to pop: ");
			begin = clock();
			pop(p, value);
			show_timeit(begin);
			break;

		case 'e':  // deletes all the nodes with the value given
			if (empty(p)) break;
			value = GetInt("\tEnter a number to pop all: ");
			begin = clock();
			pop_all(p, value);
			show_timeit(begin);
			break;

		case 'u':  // unique
			if (empty(p)) break;
			if (!sorted(p)) {
				cout << "\n\tSort first and try it again\n";
				break;
			}
			begin = clock();
			unique(p);
			show_timeit(begin);
			break;

		case 's':  // sort
			if (empty(p)) break;

			if (sorted(p)) {
				begin = clock();
				reverse(p);
				show_timeit(begin);
			}
			else {
				char ch = GetChar("\tEnter b:bubble, i:insertion, s:selection, q:quicksort: ");
				begin = clock();
				switch (ch) {
				case 'b': bubbleSort(p); break;
				case 'i': insertionSort(p); break;
				case 's': selectionSort(p); break;
				case 'q':
					cout << "\tTo test quicksort properly, use a sequence with over 100,000 samples.\n";
					randomize(p);
					quickSort(p);
					break;
				}
				show_timeit(begin);
			}
			break;

		case 'w':  // swap_paris
			if (empty(p)) break;
			begin = clock();
			swap_pairs(p);
			show_timeit(begin);
			break;

		case 'r':  // reverse
			if (empty(p)) break;
			begin = clock();
			reverse(p);
			show_timeit(begin);
			break;

		case 'x':  // shuffle
			if (empty(p)) break;
			begin = clock();
			shuffle(p);
			show_timeit(begin);
			break;

		case 'a':  // randomize
			if (empty(p)) break;
			begin = clock();
			randomize(p);
			show_timeit(begin);
			break;


		case 't': // toggle the way of showing
			show_all ? show_all = false : show_all = true;
			break;

		case 'n': // show_n - n nodes per line
			N = GetInt("\tEnter number of nodes to show per line: ");
			if (N > 0) show_n = N;
			break;

		case 'c':
			if (empty(p)) break;
			begin = clock();
			clear(p);
			show_timeit(begin);
			break;

		case 'B':
			N = GetInt("\tEnter N nodes to push back(-N for a value)?: ");
			if (N > 0) {
				begin = clock();
				push_backN(p, N);
				show_timeit(begin);
			}
			else {
				value = GetInt("\tEnter a value to push back?: ");
				begin = clock();
				push_backN(p, -N, value);
				show_timeit(begin);
			}
			break;

		case 'Y':
			if (empty(p)) break;
			N = GetInt("\tEnter a number of nodes to pop back? :");
			begin = clock();
			pop_backN(p, N);
			show_timeit(begin);
			break;
		default:
			break;
		}

		if (c != 'q') 
			show(p, show_all, show_n);
		else {
			begin = clock();
			half(p);
			cout << "\tCongratulatios! It's half-time:";
			show_timeit(begin);
		}
	} while (c != 'q');

	clear(p);
	cout << "\n\tJoyful Coding!\n";
	return EXIT_SUCCESS;
}
