// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* This brute force version of Selection Sort that takes O(n^2).
*
*  Lab - Using C++, rewrite lab02a.cpp and name the file as lab03.cpp.
*		- <iostream>, <cstdlib>, <cmath>, <cassert>
*		- using namespace std
*		- cin, cout, endl
*		- use new and delete operators instead of malloc() and free()
*/
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

void selectionSort(int *list, int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

#if 1
int main() {
	/*
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	const int N = sizeof(list) / sizeof(list[0]);
	*/

	int N;
	cout << "Enter a number of samples to sort: ";
	cin >> N;

	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new int[N];
	assert(list != NULL);

	for (int i = 0; i < N; i++)
		list[i] = rand() % N;

	cout << "UNSORTED: " << endl;
	print_list(list, N);

	selectionSort(list, N);

	cout << "SORTED: " << endl;
	print_list(list, N);

	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif
