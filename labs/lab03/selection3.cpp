// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
//  selection.cpp - This brute force version of Selection Sort that takes O(n^2).
/*************************************************************
    Lab03 - Understanding a better coding in C/C++
    - NMN(No magic number)
    - DRY(Don't repeat yourself)
    - malloc(), free()
    - assert()
    - rand()
    - mod operator %
    - #if macro
    - Learn about __a better coding__ after all.
***************************************************************/
#include <iostream>
#include <cassert>
using namespace std;

void selectionSort(int *list, int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++)
      if (list[j] < list[min]) min = j;
    // Swap min found with the first one of unsorted
    temp = list[i];
    list[i] = list[min];
    list[min] = temp;
  }
}

void printList(int *list, int n) {
  for (int i = 0; i < n; i++)
    cout << list[i] << " ";
  cout << endl;
}

int main(int argc, char *argv[]) {
  // int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
  // const int N = sizeof(list) / sizeof(list[0]);

  int N;
  // get N from user; exit N <= 1.
  cout << "Enter a number of samples to sort: ";
  //

  // allocate *list to store N ints;
  // use new, N, and assert() to check the allocation
  int *list; // your code here

  // set list with random numbers; use for loop and rand()
  //

  cout << "UNSORTED(" << N << "):\n";
  printList(list, N);

  selectionSort(list, N);

  cout << "SORTED(" << N << "):\n";
  printList(list, N);

  // deallocate resources
  //

  cout << "Happy Coding~~\n";
}
