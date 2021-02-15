//  liststackDriver.cpp
//  This driver is used to test stack.cpp which implements
//  the basic linked list of nodes.
//  Author: Youngsup Kim, idebtor@gmail.com
//  2020/10/01:	Created

#include <ctime>
#include "nowic.h"
#include "liststack.h"
using namespace std;

int randint(int min, int max) {
	return std::rand() % (max + 1 - min) + min;
}

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}

int main() {
	char c;
	int val, N = 0;
	clock_t begin = 0;
	Node* stack = nullptr;
	Node* node;
	int min = 0, max = 0;
	bool show_all = true;	// toggle the way of showing values
	string show_menu[] = { "HEAD/TAIL", "ALL" };
	int show_n = 10;		// the number of items to show per line

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tStack Using List(nodes:" << size(stack) 
			 << ", show:" << show_menu[show_all] << "," << show_n << ") \n";
		cout << "\tp - push   O(1)\t";	  cout << "\tP - push N   O(n)\n";
		cout << "\to - pop    O(1)\t";    cout << "\tO - pop  N   O(n)\n";
		cout << "\tt - top    O(1)\t";    cout << "\tm - min,max  O(n)\n";
		if (show_all)
			cout << "\ts - show [HEAD/TAIL]\t";
		else
			cout << "\ts - show [ALL] items\t";
		cout << "n - n items per line\n";
		cout << "\tc - clear  O(n)\n";

		c = GetChar("\tCommand[q to quit]: ");

		// execute the command
		switch (c) {
		case 'p':
			val = GetInt("\tEnter a number to push: ");
			stack = push(stack, val);
			break;

		case 'o':  // pops(deletes) the top of the stack
			if (empty(stack)) break;
			stack = pop(stack);
			break;

		case 't':  // show the top of the stack
			if (empty(stack)) break;
			node = top(stack);
			cout << "\tTop: " << node->data << endl;
			break;

		case 'm': // find min, max in stack
			if (empty(stack)) break;
			minmax(stack, min, max);
			cout << "\tMin: " << min << "\t Max: " << max << endl;
			break;

		case 's': // toggle the way of showing
			show_all ? show_all = false : show_all = true;
			break;

		case 'n':
			val = GetInt("\tn items per line to show: ");
			if (val >= 1) show_n = val;
			break;

		case 'c':
			if (empty(stack)) break;
			stack = clear(stack);
			break;

		case 'P':
			N = GetInt("\tEnter number of nodes to push: ");
			val = GetInt("\tEnter a number to begin with: ");
			begin = clock();
			stack = push(stack, val, N);
			show_timeit(begin);
			break;

		case 'O':
			if (empty(stack)) break;
			N = GetInt("\tEnter number of nodes to pop?: ");
			begin = clock();
			stack = pop(stack, N);
			show_timeit(begin);
			break;

		default:
			break;
		}
		show(stack, show_all, show_n);
	} while (c != 'q');

	clear(stack);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}