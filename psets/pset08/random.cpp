/// 
/// randomze.cpp
/// 2020/10/18:	Created idebtor@gmail.com
/// 2020/10/20:	The Fisher?Yates shuffle "inside-out" and modern algorithms added
/// 
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

/// <summary>
/// It returns an extended random number of which the range is from 0
/// to (RAND_MAX + 1)^2 - 1. // We do this since rand() returns too
/// small range [0..RAND_MAX) where RAND_MAX is usually defined as
/// 32767 in cstdlib. Refer to the following link for details
/// https://stackoverflow.com/questions/9775313/extend-rand-max-range
// this should work for PC/Windows and OSX as well.
/// </summary>
/// <param name="max_range"></param>
/// <returns></returns>
unsigned long rand_extended(int max_range) {
	if (max_range < RAND_MAX) return rand();
	return rand() * RAND_MAX + rand();
}

/// <summary>
/// This generates a random permutation of an array. 
/// 
/// This implements the Fisher-Yates shuffle "inside-out" algorithm described in 
/// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
/// To simultaneously initialize and shuffle an array, a bit more efficiency can 
/// be attained by doing an "inside-out" version of the shuffle. 
/// </summary>
/// <param name="list"> input array </param>
/// <param name="size"> input array size </param>
/// <returns> new allocated array shuffled by the Fisher-Yates "inside-out" algorithm </returns>
int *randomize_insideout(int* list, int size) {
	srand((unsigned)time(nullptr));	    // initialize random seed
	int* aux = new (std::nothrow) int[size];
	assert(aux != nullptr);

	int j = 0;
	for (int i = 0; i < size; i++) {
		if (i != 0) j = rand_extended(size) % i;
		if (i != j) aux[i] = aux[j];
		aux[j] = list[i];
	}
	return aux;
}

/// <summary>
/// This implements the modern version of the Fisher?Yates shuffle to 
/// generate a random permutation of an array. 
/// Reference: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
/// 
/// Start from the last element and swap one by one. 
/// We don't need to run for the last element. 
/// </summary>
/// <param name="list"> input array </param>
/// <param name="size"> input array size </param>
void randomize(int list[], int size) {
	srand((unsigned)time(nullptr));	    // initialize random seed
	for (int i = 0; i < size - 1; i++) {
		int lock = size - 1 - i;
		int roll = rand_extended(lock) % lock;
		swap(list[lock], list[roll]);
	}
}

/// <summary>
/// The na?ve method of swapping each element with another element chosen 
/// randomly from all elements is biased and fundamentally broken.
/// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
/// This is an example of what not to do -- use Fisher-Yates instead.
/// </summary>
/// <param name="list"> input array </param>
/// <param name="size"> input array size </param>
void randomize_naive(int list[], int size) {
	srand((unsigned)time(nullptr));	    // initialize random seed
	for (int i = 0; i < size; i++) {
		int x = rand_extended(size) % size;
		std::swap(list[x], list[i]);     // swap list[i] with randomly selected list[x]
	}
}


#if 0
int main() {
	int source[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(source) / sizeof(source[0]);

	int* aux = randomize_insideout(source, size);
	for (int x: source)
		cout << x << "  ";
	cout << endl;

	for (int i = 0; i < size; i++) 
		cout << aux[i] << "  ";
	cout << endl;

	delete[] aux;

	randomize(source, size);  
	for (int i = 0; i < size; i++)
		cout << source[i] << "  ";
	cout << endl;
}
#endif 
