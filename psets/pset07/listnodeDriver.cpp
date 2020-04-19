//  nodelistDriver.cpp
//  This driver is used to test the nodelist.cpp which implements
//  the basic linked list of nodes.
//  Author: Youngsup Kim, idebtor@gmail.com
//  03/13/19:	Created

#include <iostream>
#include <string>
#include <ctime>

#include "nowic.h"
#include "listnode.h"
using namespace std;

int main() {
	char c;
	int val;
	clock_t begin = 0;
	Node *head = nullptr;
	bool show_all = false;        // toggle the way of showing values 
	int show_n = 12;              // n items shown per line  
	
	do {
		cout << "\n\tLinked List Commands(nodes:" << size(head);
		cout << ", n items shown per line:" << show_n << ")\n";

		cout << "\tf - push front     O(1)\t";   cout << "\tp - pop front        O(1)\n";
		cout << "\tb - push back      O(n)\t";   cout << "\ty - pop back         O(n)\n";
		cout << "\ti - push*          O(n)\t";   cout << "\td - pop*             O(n)\n";
		cout << "\tB - push back  N   O(n^2)";   cout << "\tY - pop back  N      O(n^2)\n";
		cout << "\tF - push front N   O(n)\t";   cout << "\tP - pop front N      O(n)\n";
		cout << "\t                       \t";   cout << "\tt - reverse in stack O(n)\n";
		cout << "\tc - clear          O(n)\t";   cout << "\tr - reverse in-place O(n)\n";
		cout << "\tn - n items per line   \t";   cout << "\to - reverse odd2**   O(n^2)\n";
		if (show_all)
			cout << "\ts - show [ALL] items\t";
		else
			cout << "\ts - show [HEAD/TAIL]\t";    
		cout << "\tz - reverse oddn***  O(n)\n";

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

		case 'y':  // deletes the last node in the list, O(n)
			if (empty(head)) break;
			head = pop_back(head);
			break;

		case 'd':  // deletes the first node with val
			if (empty(head)) break;
			val = GetInt("\tEnter a number to delete: ");
			head = pop(head, val);
			break;

		case 't':  // reverses the list using stack O(n)
			if (empty(head)) break;
			begin = clock();
			head = reverse_using_stack(head);
			break;

		case 'r':  // reverses the list in-place  O(n)
			if (empty(head)) break;
			begin = clock();
			head = reverse_in_place(head);
			break;

		case 'o':  // reverses elements in the subgroups of odd numbers O(n^2)
			if (empty(head)) break;
			begin = clock();
			head = reverse_odd2(head);
			break;

		case 'z':   // reverses elements in the subgroups of odd numbers O(n)
			if (empty(head)) break;
			begin = clock();
			head = reverse_oddn(head);
			break;

		case 'Y': ////////////// Special Note for Step 5 and after /////////////////
			if (empty(head)) break;
			val = GetInt("\tEnter number of nodes to pop back?: ");
			begin = clock();
			// use the following line for STEP 1 ~ 4, comment out one line below ///
			head = pop_backN(head, val);
			///// use the follwing line to test STEP 5 instead of one above ////////
			// head = pop_N(head, val, pop_back);
			break;

		case 'P': ////////////// Special Note for Step 5 and after /////////////////
			if (empty(head)) break;
			val = GetInt("\tEnter number of nodes to pop front?: ");
			begin = clock();
			// use the following line for STEP 1 ~ 4, comment out one line below ///
			head = pop_frontN(head, val);
			///// use the follwing line to test STEP 5 instead of one above ////////
			// head = pop_N(head, val, pop_front);
			break;

		case 'B': ////////////// Special Note for Step 5 and after /////////////////
			val = GetInt("\tEnter number of nodes to push back?: ");
			begin = clock();
			// use the following line for STEP 1 ~ 4, comment out one line below ///
			// head = push_backN(head, val); 
			///// use the follwing line to test STEP 5 instead of one above ////////
			head = push_N(head, val, push_back); 
			break;

		case 'F': ///////////// Special Note for Step 5 and after ///////////////////
			val = GetInt("\tEnter number of nodes to push front?: ");
			begin = clock();
			// use the following line for STEP 1 ~ 4, comment out one line below ///
			// head = push_frontN(head, val);   
			///// use the following line to test STEP 5 instead of one above ///////
			head = push_N(head, val, push_front);   
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
		}

		// display elapsed time
		switch (c) {  
		case 't':
		case 'r':
		case 'o':
		case 'z':
		case 'B':
		case 'F':
		case 'Y':
		case 'P':
			cout << "\tcpu: " << ((double)clock() - begin)/CLOCKS_PER_SEC << " sec\n";
		default:
			break;
		}
		show(head, show_all, show_n);
	} while (c != 'q');

	clear(head);
	cout << "\n\t--Happy Coding!--\n";
	return EXIT_SUCCESS;
}
