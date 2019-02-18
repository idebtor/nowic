# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab03 - Learning C++ coding
Using C++, rewrite a good C code, `lab02a.cpp`.

- Learn about the following topics in C++.
  - `<iostream>, <cstdlib>, <cmath>, <cassert>`
  - `using namespace std`
  - `cin, cout, endl`

## Specifications:
- Copy `lab02a.cpp` into `lab03.cpp`.
- Rewrite the code, `lab03.cpp`, in C++.
- Ask the user to enter a number for N to remove the magic number N.
- Comment out the lines with `malloc()` and `free()` and Use `new int[]` and `delete[]` instead of `malloc()` and `free()`.

-------------------------------------
### cin
The `cin` object in C++ is an object of class istream. It is defined in `<iostream>` header file. It is used to accept the input from the standard input device i.e. keyboard. It is associated with the standard C input stream `stdin`.

The "c" in cin refers to "character" and 'in' means "input", hence cin means "character input".

The cin object is used along with the extraction operator (>>) in order to receive a stream of characters. The general syntax is:

```
std::cin >> varName;
```
### cout
The `cout` object in C++ is an object of class ostream. It is defined in `<iostream>` header file. It is used to display the output to the standard output device i.e. monitor. It is associated with the standard C output stream `stdout`.

The "c" in cout refers to "character" and 'out' means "output", hence cout means "character output". The cout object is used along with the insertion operator (<<) in order to display a stream of characters. The general syntax is:
```
cout << varName;
```
Or
```
cout << "Some String";
```
The extraction operator can be used more than once with a combination of variables, strings and manipulators (like `endl`):
```
cout << var1 << "Some String" << var2 << endl;
```

### Example: cin and cout with extraction operator:
```
#include <iostream>
using namespace std;

int main() {
	int x, y, z;

	// For single input
	cout << "Enter a number: ";
	cin >> x;

	// For multiple inputs
	cout << "Enter 2 numbers: ";
	cin >> y >> z;

	cout << "Sum = " << (x+y+z);
	return 0;
}
```
### new and delete operators in C++ for dynamic memory
Dynamic memory allocation in C/C++ refers to performing memory allocation manually by programmer. Dynamically allocated memory is allocated on Heap, while non-static and local variables get memory allocated on Stack.

### How is memory allocated/deallocated in C++?
C and C++ use `malloc()` and `calloc()` to allocate memory dynamically at run time and uses `free()` function to free dynamically allocated memory.  Additionally, C++ also has two operators `new` and `delete` that perform the task of allocating and freeing the memory in a better and easier way.

Syntax to use `new` operator: To allocate memory of any data type, the syntax is:
```
pointer-variable = new data-type;
```
Here, pointer-variable is the pointer of type data-type. Data-type could be any built-in data type including array or any user defined data types including structure and class.

Example:
```
// Combine declaration of pointer and their assignment
int *p = new int;       // one int memory allocated
int *q = new int(7);    // initialized with 7

int *r = new int[10];   // allocated for array of 10 integers
int *s = (int *)malloc(sizeof(int) * 10); // using malloc()

```
### Normal Array Declaration vs Using new or malloc()
There is a difference between declaring a normal array and allocating a block of memory using new. The most important difference is, normal arrays are deallocated automatically. If array is local, then deallocated when function returns or completes. However, dynamically allocated arrays always remain there until either they are deallocated by programmer or program terminates.

### What if enough memory is not available during runtime?
If enough memory is not available in the heap to allocate, the new returns a NULL pointer. Therefore, it may be good idea to check for the pointer variable produced by new before using it program.
```
int *r = new int[10];
if (!r) {
  cout << "Memory allocation failed\n";
}
```
Or
```
int *r = new int[10];
assert(r !== NULL);
```
### delete operator or free() function
Since it is programmer’s responsibility to deallocate dynamically allocated memory, programmers are provided delete operator by C++ language. To free the dynamically allocated array pointed by pointer-variable, use delete [].

Syntax:
```
// Release memory pointed by pointer-variable
delete pointer-variable;

// Using free function
free(pointer-variable);

// Release block of memory pointed by pointer-variable
delete[] pointer-variable;  
```

# Files to submit:
  - lab03.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
