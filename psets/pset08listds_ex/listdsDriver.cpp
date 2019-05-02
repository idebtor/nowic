/**
Name        : listdsDriver.cpp
Author      : Youngsup Kim, idebtor@gmail.com

04/13/16:	Created
10/20/18:	Added: O(1) options
04/10/18:	added stress test functions more completely
02/10/19:	doubly linked list with sentinel nodes

Description :
: This implements a doubly linked list with two sentinel nodes
: including interactive stress test options.

Note: For quicksort with a large dataset with the repetition of the same
value, the algorithm requires a large stack.
For example, if there are 50,000 of the same value repeated in the container,
I had to set the stack size to 16M (or 16777216)

For visual studio: Project Properties->Linkers->System->Stack Reserve Size

For g++/MinGW cmd windows, the following command set the stack size to 16M.
  g++ -Wl,--stack,16777216 listdsDriver.cpp listdsx.cpp .......
To check the stack size on Windows, you may use dumpbin that comes with VS

For Mac OSX
  g++ -Wl,-stack_size,0x1000000 listdsDriver.cpp listdsx.cpp .......
To check the stack size on OSX
  otool -lv _exefile_name | grep stack
*/

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include "nowic.h"
#include "listds.h"
using namespace std;

int main(int argc, char **argv) {
	char c;
	int val, x, N;
	clock_t start = 0;
	bool show_all = false;  // toggle the way of showing values 
	pList p = new List;		// create an empty list with two sentinel nodes

	do {
		cout << "\n\tDoubly Linked List(N=" << size(p) << ")\n";
		cout << "\tf - push front   O(1)\t";		cout << "\tp - pop front   O(1)\n";		
		cout << "\tb - push back    O(1)\t"; 		cout << "\ty - pop back    O(1)\n";		
		cout << "\ti - push         O(n)\t"; 		cout << "\td - pop         O(n)\n";
		cout << "\tz - push sorted* O(n)\t";		cout << "\te - pop vals*   O(n)\n";
		cout << "\n";
		cout << "\ts - sort*        O(n^2)\t";		cout << "\tu - unique*     O(n)\n";
		cout << "\tr - reverse**    O(n)\t"; 		cout << "\tx - shuffle***  O(n)\n";
		cout << "\tc - clear        O(n)\t";
		if (show_all)
			cout << "\tt - show [ALL]\n";
		else
			cout << "\tt - show [HEAD/TAIL]\n";
		cout << endl;
		cout << "\tB - push backN   O(n)\t";  		cout << "\tS - push sortedN O(n^2)\n";
		cout << "\tY - pop  backN   O(n)\t";		cout << "\tZ - push sortedN O(n log n)***\n";
		c = GetChar("\tCommand[q to quit]: ");
		
		switch (c) {	// execute the command
		case 'f':
		case 'b':
		case 'i':
		case 'z':
			val = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				push_front(p, val);
				break;
			case 'b':
				push_back(p, val);
				break;
			case 'i':  // push
				x = GetInt("\tChoose a position node: ");
				push(p, val, x);
				break;
			case 'z':  // push_sorted
				if (!empty(p) && !sorted(p)) {
					cout << "\t Run sort first and try it again\n";
					break;
				}
				start = clock();
				push_sorted(p, val);
				break;
			}
			break;

		case 'p':  // deletes the first node in the list
			if (empty(p)) break;
			start = clock();
			pop_front(p);
			break;
		case 'y':  // deletes the last node in the list, O(n)
			if (empty(p)) break;
			pop_back(p);
			break;
		case 'd':  // deletes one node with the value
			if (empty(p)) break;
			val = GetInt("\tEnter a number to pop: ");
			start = clock();
			pop(p, val);
			break;
		case 'e':  // deletes all the nodes with the value given
			if (empty(p)) break;
			val = GetInt("\tEnter a number to pop all: ");
			start = clock();
			pop_all(p, val);
			break;
		case 's':  // sort
			if (empty(p)) break;

			if (sorted(p)) {
				start = clock();
				reverse(p);
			}
			else {
				char ch = GetChar("\tEnter b for bubble, q for quick, s for selection sort: ");
				start = clock();
				switch(ch) {
				case 'b': bubbleSort(p); break;
				case 'q': quickSort(p); break;
				case 's': selectionSort(p); break;
				}
			}
			break;
		case 'u':  // unique
			if (empty(p)) break;
			if (!sorted(p)) {
				cout << "\n\tsort first and try it again\n";
				break;
			}
			start = clock();
			unique(p);
			break;

		case 'r':  // reverse
			if (empty(p)) break;
			start = clock();
			reverse(p);
			break;

		case 'x':  // shuffle
			if (empty(p)) break;
			start = clock();
			shuffle(p);
			break;

		case 't': // toggle the way of showing
			show_all ? show_all = false : show_all = true;
			break;		
		
		case 'c':
			if (empty(p)) break;
			start = clock();
			clear(p);
			break;

		case 'S': // push_sortedN  O(n^2)
			if (!empty(p) && !sorted(p)) {
				cout << "\n\tsort first and try it again\n";
				break;
			}
			N = GetInt("\tEnter number of nodes to push sorted?: ");
			start = clock();
			push_sortedN(p, N);
			break;

		case 'Z': // push_sortedNlog  O(n log n)
			if (!empty(p) && !sorted(p)) {
				cout << "\n\tsort first and try it again\n";
				break;
			}
			N = GetInt("\tEnter number of nodes to push sorted?: ");
			start = clock();
			push_sortedNlog(p, N);
			break;

		case 'B':
			N = GetInt("\tEnter number of nodes to push back?: ");
			val = GetInt("\tEnter a value to push back?(0 for random): ");
			start = clock();
			push_backN(p, N, val);
			break;
		case 'Y':
			if (empty(p)) break;
			N = GetInt("\tEnter number of nodes to pop back?: ");
			start = clock();
			pop_backN(p, N);
			break;
		}

		switch (c) {
		case 'c':
		case 'd':
		case 'e':
		case 'p':
		case 'r':
		case 's':
		case 'u':
		case 'x':
		case 'z':
		case 'B':
		case 'Y':
		case 'S':
		case 'Z':
			cout << "\tcpu: "
				 << ((clock_t) clock() - start) / (double) CLOCKS_PER_SEC << " sec\n";
		default:
			break;
		}
		show(p, show_all);
	} while (c != 'q');

	clear(p);
	cout << "\n\tJoyful Coding!\n";
	return EXIT_SUCCESS;
}
