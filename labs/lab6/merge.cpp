// mergesort.cpp by idebtor@gmail.com
// A typical recursive implementation of mergesort in C++.
//
// A good reference for mergesort in Korean
// https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html
//  
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 merge.cpp -o merge
// > ./merge
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG merge.cpp -o merge
// > ./merge
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c merge.cpp         # produce merge.o
// > ar r libsort.a merge.o              # insert or update merge.o in libsort.a
// > ar t libsort.a                      # show objects in libsort.a 

#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// a helper function to check two elementes sorted.
// include two elements same value as sorted 
int sorted(int *a, int i, int j) {  
    return a[i] <= a[j];                // two elements same value as sorted 
}

void merge(int *a, int *aux, int lo, int mi, int hi) {
    assert(sorted(a, lo,   mi));		// precondition: a[lo..mi]   sorted
    assert(sorted(a, mi+1, hi));		// precondition: a[mi+1..hi] sorted
    for (int k = lo; k <= hi; k++)	aux[k] = a[k];

    int i = lo;
    int j = mi + 1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mi)          a[k] = aux[j++];     // A is exhausted, take B[j]
        else if (j > hi)          a[k] = aux[i++];     // B is exhausted, take A[i]
        else if (aux[j] < aux[i]) a[k] = aux[j++];     // B[j] <  A[i], take B[j]
        else                      a[k] = aux[i++];     // A[i] <= B[j], take A[i]
    }
    assert(sorted(a, lo, hi));		// postcondition: a[lo..hi] sorted
}

void mergesort(int *a, int *aux, int lo, int hi) {
    if (hi <= lo) return;

    int mi = lo + (hi - lo) / 2;
    mergesort(a, aux, lo,     mi);
    mergesort(a, aux, mi + 1, hi);
    merge(a, aux, lo, mi, hi);
}

void mergesort(int *a, int N) {
    int *aux = new (nothrow) int[N];
    assert(aux != nullptr);

    mergesort(a, aux, 0, N - 1);
    delete[] aux;
}

#if 1

int main() {
    // char a[] = {'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'};
    // int a[] = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
	int a[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
    int N = sizeof(a) / sizeof(a[0]);

    cout << "UNSORTED: \n"; 
    for (auto x: a) cout << x << " "; 
    cout << endl << endl;;

    mergesort(a, N);
    cout << "MERGE SORTED: \n"; 
    for (auto x: a) cout << x << " "; 
    cout << endl << endl;;

    // Uncomment the next line and modify the code above to make it work. 
    // mergesort(a, N, more); 
    cout << "MERGE SORTED using more fp: \n"; 
    for (auto x: a) cout << x << " "; 
    cout << endl << endl;
    cout << "Happy Coding~~";
    return 0;
}
#endif

