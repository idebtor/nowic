// file: printList.cpp
// author: idebtor@gmail.com
// Creation: 2019/02/02
// 
// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max_print specifies the number of samples in either front 
// or rear part of the list.  The per_line determines how many 
// samples prints per line.
// 
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only. 
// For example: 
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and 
// the rear part.
// Observe the sample runs using sortx.exe provided with you. 

#include <iostream>
#include <iomanip>
#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void _printList(int *list, int start, int end, int per_line = 10) {
	int count = 1;
	for (int i = start; i < end; i++, count++) {
		std::cout << std::setw(10) << list[i];
		if (count == per_line) {
			count = 0;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void printList(int *list, int N, int max_print = 10, int per_line = 10) {
	DPRINT(std::cout << ">printList...N=" << N << " max_print=" << max_print << std::endl;);

	if (max_print >= N / 2)
		_printList(list, 0, N, per_line);
	else {
		if (max_print >= N) max_print = N / 2;
		int rear_part = N - max_print;
		_printList(list, 0, max_print, per_line);
		_printList(list, rear_part, N, per_line);
	}

	DPRINT(std::cout << "<printList\n";);
}