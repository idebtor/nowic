 /*
 * This program implements a recurisve binary_search():
 *
 * The binary search algorithm is a method of searching a sorted array for a single
 * element by cutting the array in half with each recursive pass.The trick is to
 * pick a midpoint near the center of the array, compare the data at that point
 * with the data being searched and then responding to one of three possible
 * conditions : the data is found at the midpoint, the data at the midpoint is
 * greater than the data being searched for, or the data at the midpoint is less
 * than the data being searched for.
 * Recursion is used in this algorithm because with each pass a new array is
 * created by cutting the old one in half.The binary search procedure is then
 * called recursively, this time on the new (and smaller) array.
 * Typically, the array's size is adjusted by manipulating a beginning and
 * ending index. The algorithm exhibits a logarithmic order of growth because
 * it essentially divides the problem domain in half with each pass.
 *
 * In this example, you need an extra function at user's convenience since a
 * user may want to simply call the function with three parameters such as
 * binary_search(data, key, size).  Once you get the user's initial call,
 * then you call binary_search(data, key, low, high) recursively.
 *
 * @author: idebtor@gmail.com
 * 2018/03/08	Creation
 * 2020/03/01	Using cpp
 * 2020/09/01 Using template
 *
 * int binary_search(int *list, int key, int lo, int hi)
 * implements a recursive binary search algorithm.
 * INPUT:
 *		*list is a array of integers SORTED in ASCENDING order,
 *		key is the integer to search for, lo is the minimum
 *      array index, hi is the maximum array index
 * OUTPUT:
 *		returns the array index of `key` in the list' if found.
 *		otherwise returns a modified index where it could be found.
 * NOTE:
 * If the key is not found, lo is the insertion point where a key would be
 * inserted to maintain the order of the list.  It is more useful to return
 * the insertion point than -1.  The method must return a negative value to
 * indicate that the key is not in the list. Can it simply return -lo? No.
 * If key is less than list[0], lo would be 0. -0 is 0. This would indicate
 * that key matches list[0]. A good choice is to let the method return -lo-1
 * if the key is not in the list. Returning -lo-1 indicate not only that key
 * is not in the list, but also where the key would be inserted.
 */

#include <iostream>
#include <iomanip>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int binary_search(int *data, int key, int lo, int hi) {
	DPRINT(cout << "key=" << key << " lo=" << lo << " hi=" << hi << endl;);

	cout << "your code here \n";

	return 0;
}

// randomly generate a key to search between list[0] and list[size-1].
int get_a_key(int *list, int size) {
  int key = rand() % (list[size - 1] + 1 - list[0]) + list[0];
	return key;
}

// calls binary_search(data, key, lo, hi) "size" number of times
// while generating a new random key at every call of the function.
// and also displays the results. If the key is found in the list,
// it displays its index in the list. If the key is not found, it
// displays where it is supposed to be appeared if there is one.
void binary_search(int *list, int size) {
	DPRINT(cout << ">binary_search: size=" << size << endl;)
	int key = get_a_key(list, size);
	int idx = binary_search(list, key, 0, size);

	cout << "your code here \n";

	DPRINT(cout << "<binary_search\n";)
}

//////// The following code is the same in binsearchDriver.cpp //////////
//////// This is given at your convenience. /////////////////////////////
#if 1
int main(int argc, char *argv[]) {
	// char list[] = { 'a', 'b', 'e', 'g' };
	// char list[] = { 'c', 'e', 'f', 'h', 'i', 'k' };
	int list[] = { 0, 1, 4, 6 };
	// int list[] = { 3, 5, 6, 8, 9, 11 };

	int size = sizeof(list) / sizeof(list[0]);
	srand((unsigned)time(nullptr));    // turn off this line during debugging

	cout << "  list: ";
	for (auto x: list) cout << x << " "; 	cout << endl;
	for (auto x: list) binary_search(list, size);
}
#endif
