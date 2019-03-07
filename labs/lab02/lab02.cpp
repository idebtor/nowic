// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* lab02.cpp  & lab02a.cpp
* This brute force version of Selection Sort that takes O(n^2).
*
* Compilation:
*   g++ lab02.cpp -o lab02
*   g++ lab02a.cpp -o lab02a
*
* Lab: (1) Improve the following code in C first. Name the file as lab02a.cpp
*      (2) Then recode it in C++. Name the file as lab02b.cpp
*
*	1. Understand the following C code.
*   - #if
*		- const
*		- rand()
*		- % operator
*  2. Use dynamic allocation for the array
*		- Add assert after malloc()
*		- Add free()
*  3. NMN principle - no magic number
*     DRY principle - don't repeat yourself
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

#if 0
void printList(int *list, int N); // prototype

int main() {
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0, 10, -1 };
	const int N = sizeof(list)/sizeof(list[0]);

	printf("UNSORTED: \n");
  printList(list, N);
	selectionSort(list, N);
	printf("SORTED: \n");
  printList(list, N);

  printf("Happy Coding~~\n");
}

void printList(int *list, int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", list[i]);
	printf("\n");
}
#endif
