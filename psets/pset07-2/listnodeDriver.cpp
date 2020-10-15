//  nodelistDriver.cpp
//
//  This driver is used to test the nodelist.cpp which implements
//  the basic linked list of nodes.
//
// 03/13/19:	Created by idebtor@gmail.com
// 10/01/20:	show_timeit, inserrion sort, keep second half, zap duplicate

#include <iostream>
#include <string>
#include <ctime>

#include "nowic.h"
#include "listnode.h"
using namespace std;

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}

int main() {
	char c;
	int val, min = 0, max = 0;
	clock_t begin = 0;
	Node *head = nullptr;
	bool show_all = false;        // toggle the way of showing values 
	string show_menu[] = { "HEAD/TAIL", "ALL" };
	int show_n = 12;              // n items shown per line  
	
	do {
		cout << "\n\tLinked List(nodes:" << size(head);
		cout << ", min,max:" << min << "," << max; 
		cout << ", show:" << show_menu[show_all] << "," << show_n << ")\n";

		cout << "\tf - push front     O(1)\t";   cout << "\tp - pop front        O(1)\n";
		cout << "\tb - push back      O(n)\t";   cout << "\ty - pop back         O(n)\n";
		cout << "\ti - push               \t";   cout << "\td - pop                  \n";
		cout << "\tB - push back  N       \t";   cout << "\tY - pop back  N          \n";
		cout << "\tF - push front N       \t";   cout << "\tP - pop front N          \n";
		cout << "\to - push sorted*       \t";   cout << "\tt - reverse using stack  \n";
		cout << "\tx - insertion sort*    \t";   cout << "\tr - reverse in-place     \n";
		cout << "\tk - keep second half*  \t";   cout << "\tz - zap duplicates*      \n";
		cout << "\tc - clear              \n";   
		if (show_all)
			cout << "\ts - show [HEAD/TAIL]\t";
		else
			cout << "\ts - show [ALL] items\t";
		cout << "\tn - n items per line   \n";

		c = GetChar("\tCommand[q to quit]: ");

		// execute the command
		switch (c) {
		case 'f':
		case 'b':
		case 'i':
			val = GetInt("\tEnter a number to push: ");
			switch (c) {
			case 'f':
				head = push_front(head, val);
				break;
			case 'b':
				head = push_back(head, val);
				break;
			case 'i':
				int x = GetInt("\tChoose a position node: ");
				head = push(head, val, x);
			}
			break;

		case 'p':  // deletes the first node in the list
			if (empty(head)) break;
			head = pop_front(head);
			break;

		case 'y':  // deletes the last node in the list.
			if (empty(head)) break;
			head = pop_back(head);
			break;

		case 'd':  // deletes the first node with val
			if (empty(head)) break;
			val = GetInt("\tEnter a number to delete: ");
			head = pop(head, val);
			break;

		case 't':  // reverses the list using stack.
			if (empty(head)) break;
			begin = clock();
			head = reverse_using_stack(head);
			show_timeit(begin);
			break;

		case 'r':  // reverses the list in-place.
			if (empty(head)) break;
			begin = clock();
			head = reverse_in_place(head);
			show_timeit(begin);
			break;

		case 'o':
			val = GetInt("\tEnter a number to push sorted: ");
			begin = clock();
			head = push_sorted(head, val);
			show_timeit(begin);
			break;

		case 'x':
			begin = clock();
			head = insertion_sort(head);
			show_timeit(begin);
			break;

		case 'Y': 
			if (empty(head)) break;
			val = GetInt("\tEnter number of nodes to pop back?: ");
			begin = clock();
			head = pop_N(head, val, pop_back);
			show_timeit(begin);
			break;

		case 'P': 
			if (empty(head)) break;
			val = GetInt("\tEnter number of nodes to pop front?: ");
			begin = clock();
			head = pop_N(head, val, pop_front);
			show_timeit(begin);
			break;

		case 'B': 
			val = GetInt("\tEnter number of nodes to push back?: ");
			begin = clock();
			head = push_N(head, val, push_back); 
			show_timeit(begin);
			break;

		case 'F': 
			val = GetInt("\tEnter number of nodes to push front?: ");
			begin = clock();

			head = push_N(head, val, push_front);   
			show_timeit(begin);
			break;

		case 's': // toggle the way of showing
			show_all ? show_all = false : show_all = true;
			break;

		case 'n':
			val = GetInt("\tEnter the max items to show per line: ");
			if (val >= 1) show_n = val;   
			break;

		case 'c':
			if (empty(head)) break;
			head = clear(head);
			break;

		case 'k':
			if (empty(head)) break;
			head = keep_second_half(head);
			break;

		case 'z':
			begin = clock();
			head = zap_duplicates(head);
			show_timeit(begin);
			break;
		
		default:
			break;
		}
		show(head, show_all, show_n);
		minmax(head, min, max);
	} while (c != 'q');

	clear(head);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}
