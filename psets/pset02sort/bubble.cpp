// bubble sort by idebtor@gmail.com
// This brute force version of bubble sort that takes O(n^2).
// 2019/02/02: Created
//
// Compilation:
// g++ bubble.c -o sort
// g++ -DDEBUG bubble.c -o sort
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// To make the function included in other program, turn #if 0 off.

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void bubbleSort(int *list, int n) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		// last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}

#if 0
int main() {
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	bubbleSort(list, N);

	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	system("pause");
}
#endif
