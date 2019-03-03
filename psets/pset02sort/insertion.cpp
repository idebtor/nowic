/** This brute force version of Selection Sort that takes O(n^2).
* Instructor: Youngsup Kim
*
* 12/10/2016: Created
* 12/10/2016: Compilation and DEBUG/DPRINT option added
*
* Compilation:
*	g++ insertion.cpp -o sort
*   g++ -DDEBUG insertion.cpp -o sort
*
* To use DEBUG or test it, compile with -D option and turn #if 1 on.
* To make the function included in other program, turn #if 0 off.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void insertionSort(int *list, int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i];
		j = i - 1;
		// move elements of list[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
		DPRINT(for (int x = 0; x < n; x++) printf("%d ", list[x]); printf("\n");)
	}
}

#if 0
int main() {
	int list[] = { 7, 3, 4, 1, 9, 6, 5, 2, 8, 0};
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	insertionSort(list, N);

	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	system("pause");
}
#endif
