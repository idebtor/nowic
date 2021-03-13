// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// sortDriver.cpp
// This code may be used to test functions in libsort.a (or libsort_mac.a).
// 
// Sample Run: (macOS)
// $ g++ sortDriver.cpp -I../../include -L../../lib -lsort_mac -o sortDriver
// $ ./sortDriver
// Sample Run: (Windows)
// $ g++ sortDriver.cpp -I../../include -L../../lib -lsort -o sortDriver
// $ ./sortDriver
// input: 3 4 1 7 0 9 6 5
// bubble sort
//         0        1        3        4        5        6        7        9
//         9        7        6        5        4        3        1        0
// insertion sort
//         0        1        3        4        5        6        7        9
//         9        7        6        5        4        3        1        0
// merge sort
//         0        1        3        4        5        6        7        9
//         9        7        6        5        4        3        1        0
// quick sort
//         0        1        3        4        5        6        7        9
//         9        7        6        5        4        3        1        0
// selection sort
//         0        1        3        4        5        6        7        9
//         9        7        6        5        4        3        1        0
// Happy Coding~~
#include <iostream>
#include "sort.h"

bool evenfirst(int x, int y) {
	// if x(2nd element) is even and y is odd, x goes first (swap needed)
	if ((x % 2 == 0) && !(y % 2 == 0)) return true;
 
	// if x(2nd element) is odd and y is even, y goes first (no swap needed)
	if (!(x % 2 == 0) && (y % 2 == 0)) return false;
 
    // otherwise sort in ascending order (x:2nd element, y:1st element)
	return less(x, y);
}

int main(int argc, char *argv[]) {
	int list[] = { 3, 4, 1, 2, 7, 0, 9, 6, 5, 8 };
	int N = sizeof(list) / sizeof(list[0]);
	
	std::cout << "input: ";
	for (int i = 0; i < N; i++) std::cout << list[i] << " "; 
	std::cout << std::endl;
	 
	std::cout << "bubble sort\n";
	bubblesort(list, N);  
	printlist(list, N);
	bubblesort(list, N, more);
	printlist(list, N);

	std::cout << "quick sort\n";
	quicksort(list, N); 
	printlist(list, N);
	quicksort(list, N, more);
	printlist(list, N);

  	std::cout << "Happy Coding~~\n";
}
