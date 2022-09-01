// file: printlist.cpp
// author: idebtor@gmail.com
// Creation: 2019/02/02
// 
// When we have a long list, we want to print some in the front part of the list 
// and some in the rear part of the list.  
// The show_n/2 specifies the number of samples in either front or rear part of 
// the list. The per_line determines how many samples prints per line.

#include <iostream>
#include <iomanip>

// a helper function
void print(int *list, int start, int end, int per_line) {
	int count = 1;
	for (int i = start; i < end; i++, count++) {
		std::cout << std::setw(9) << list[i];
		if (count == per_line) {
			count = 0;
			std::cout << std::endl;
		}
		else if (i + 1 == end) {
			std::cout << std::endl;
		}
	}
	//if (count % per_line != 0) std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// the following printlist() prototype is included in sort.h 
// void printlist(int *list, int n, int show_n = 20, int per_line = 10);
///////////////////////////////////////////////////////////////////////////////
// prints all the values in the list if the list size N is less than show_n. 
// If the list size is greater than show_n, then it shows only show_n/2
// values from the beginning part and the end part in the list, respectively.
void printlist(int *list, int N, int show_n, int per_line) {
	if (N <= show_n)
		print(list, 0, N, per_line);
	else {
		int rear_part = N - show_n / 2;
		print(list, 0, show_n / 2, per_line);
		std::cout << "\t...\n";
		print(list, rear_part, N, per_line);
	}
}

