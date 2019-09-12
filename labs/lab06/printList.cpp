// bubble sort by idebtor@gmail.com
// This brute force version of bubble sort that takes O(n^2).
// 2019/02/02: Created
//
// Compilation:
// g++ bubble.cpp -o sort
// g++ bubble.cpp -o sort -DDEBUG
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// To make the function included in other program, turn #if 0 off.

#include <iostream>
void printList(int *list, int n) {
	for (int i = 0; i < n; i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}
