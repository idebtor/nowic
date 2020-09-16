// mergesort.cpp by idebtor@gmail.com
// A typical recursive implementation of mergesort
// using function template in C++.
// 2020.09.15  mergesort using template

#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int isSorted(int *a, int i, int j){return a[i] <= a[j];}
bool less(int a, int b) { return a - b < 0; }

void merge(int *a, int *aux, int lo, int mi, int hi) {
    cout << "your code here" << endl;

    int i = lo;
    int j = mi + 1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mi)          a[k] = aux[j++];     // A is exhausted, take B[j]
        else if (j > hi)          a[k] = aux[i++];     // B is exhausted, take A[i]
        else if (aux[j] < aux[i]) a[k] = aux[j++];     // B[j] <  A[i], take B[j]
        else                      a[k] = aux[i++];     // A[i] <= B[j], take A[i]
    }
    cout << "your code here" << endl;
}

void mergeSort(int *a, int *aux, int N, int lo, int hi) {
    cout << "your code here" << endl;
}

void mergeSort(int *a, int N) {
  cout << "your code here" << endl;
  mergeSort(a, aux, N, 0, N - 1);
}

#if 1
int main() {
    // char list[] = {'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'};
	int list[] = { 1, 4, 5, 2, 10, 3 };
    int N = sizeof(list) / sizeof(list[0]);
    cout << "UNSORTED: ";
    for (auto x: list) cout << x << " "; cout << endl;

    mergeSort(list, N);

    cout << "  SORTED: ";
    for (auto x: list) cout << x << " "; cout << endl;
}
#endif
