/** This brute force version of Selection Sort that takes O(n^2).
  * Instructor: Youngsup Kim
  *
  * 02/01/2019: Created
  * 02/10/2019: Compilation and DEBUG/DPRINT option added
  *
  * Compilation:
  *   g++ selection.cpp -o sort
  *   g++ selection.cpp -o sort -DDEBUG
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

void selectionSort(int *list, int n) {
	DPRINT(cout << "SELECTION SORTING...\n");
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		swap(list[i], list[min]);  // Swap min found with the first one of unsorted
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

	selectionSort(list, N);

	cout << "SELECTION SORTED: " << endl;
	printList(list, N);
	// delete[] list;
	cout << "Happy Coding~~\n";
}
#endif
