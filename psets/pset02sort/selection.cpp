/** This brute force version of Selection Sort that takes O(n^2).
  * Instructor: Youngsup Kim 
  *
  * 02/01/2019: Created
  * 02/10/2019: Compilation and DEBUG/DPRINT option added
  *
  * Compilation:
  * g++ selection.cpp -o sort
  * g++ -DDEBUG selection.cpp -o sort
  *
  * To use DEBUG or test it, compile with -D option and turn #if 1 on.
  * To make the function included in other program, turn #if 0 off.
  */

#include <iostream>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

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
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}

#if 0
int main() {
	/*
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);
	*/
	int N = 50;
	// int *list = (int *)malloc(N * sizeof(int));
	int* list = new int[N];

	for (int i = 0; i < N; i++)
		list[i] = rand() % 100;

	cout << "UNSORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	selectionSort(list, N);

	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;
	free(list);
	system("pause");
}
#endif