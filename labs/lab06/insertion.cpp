/** This brute force version of Selection Sort that takes O(n^2).
* Instructor: Youngsup Kim
*
* 12/10/2016: Created
* 12/10/2016: Compilation and DEBUG/DPRINT option added
*
* Compilation:
*	  g++ insertion.cpp -o sort
*   g++ insertion.cpp -o sort -DDEBUG
* To use DEBUG or test it, compile with -D option and turn #if 1 on.
* To make the function included in other program, turn #if 0 off.
*/

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void insertionSort(int *list, int n) {
	DPRINT(cout << "INSERTION SORTING...\n");
	for (int i = 1; i < n; i++) {
		int key = list[i];
		int j = i - 1;
		// move elements of list[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && key < list[j]) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
		DPRINT(for(int x = 0; x < n; x++) cout << list[x] << " "; cout << endl);
	}
}

#if 0
void printList(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main() {
	int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	int N = sizeof(list) / sizeof(list[0]);
	// int N = 50;
	// int* list = new int[N];
	// for (int i = 0; i < N; i++) list[i] = rand() % N;

	cout << "UNSORTED: " << endl;
	printList(list, N);

	insertionSort(list, N);

	cout << "INSERTION SORTED: " << endl;
	printList(list, N);
	// delete[] list;
	cout << "Happy Coding~~\n";
}
#endif
