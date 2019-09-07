# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab04 - Bubble sort and Function pointer
## Subjects
    - bubble sort
    - ascending or descending sort
    - the first class function
    - function pointer
    - DEBUG

## Step 1: Understand sorting algorithms
  - A source code for bubble-sort algorithm is provided.
  - Study the algorithms by your own and Understand how each algorithm works.
  - Build it with or without `-DDEBUG` option and run it to see the difference.
  - Building it with -D may help you follow the code.
    ```
    $ g++ bubble.cpp -o sort
    $ g++ bubble.cpp -o sort -DDEBUG
    ```

## Step 2: Sort in descending order
  - Duplicate `bubble.cpp` and name it `bubble2.cpp`.
  - Modify one line in `bubbleSort()` function such that it sorts the list in __descending__ order.
  - Build an executable and test it.

### Sample runs:
```
  $ g++ bubble2x.cpp -o sort
  $ ./sort
  UNSORTED(10):
  3 4 1 7 0 9 6 5 2 8
  BUBBLE SORTED(10):
  9 8 7 6 5 4 3 2 1 0
  Happy Coding~~

  $ g++ bubble2.cpp -o sort -DDEBUG
  $ ./sort
  UNSORTED(10):
  3 4 1 7 0 9 6 5 2 8
  BUBBLE SORTING...
  4 3 7 1 9 6 5 2 8 0
  4 7 3 9 6 5 2 8 1 0
  7 4 9 6 5 3 8 2 1 0
  7 9 6 5 4 8 3 2 1 0
  9 7 6 5 8 4 3 2 1 0
  9 7 6 8 5 4 3 2 1 0
  9 7 8 6 5 4 3 2 1 0
  9 8 7 6 5 4 3 2 1 0
  9 8 7 6 5 4 3 2 1 0
  BUBBLE SORTED(10):
  9 8 7 6 5 4 3 2 1 0
  Happy Coding~~
```

## Step 3: Use a function to compare
  - In this step, we want to sort the list using one of two comparison functions such as `less()` or `more()`.
      - Later, this will help us easily to sort the list either __descending__ or __ascending order__.
  - Duplicate `bubble.cpp` which has a bubble-sort algorithm and name it `bubble3.cpp`.
  - The line you modified in Step 2 compares two items using a comparison operator. Modify the line such that it uses a function to compare two items instead of a comparison operator.
  - Use one of the following functions. For example, `less(x, y)` returns `true` if `x < y`, `false` otherwise.

  ```
    bool less(int x, int y) {   return x < y;   }   // use this for ascending
    bool more(int x, int y) {   return x > y;   }   // use this for descending
  ```

  - By the way, `less()` is already defined in `std` namespace. To use `less()` which we defined in this file `bubble3.cpp`, we must add the global scope resolution operator(`::`) such as `::less()`.

  ```
  if (::less(list[j + 1], list[j]))
    swap(list[j], list[j + 1]);
  ```
  - Build an executable and test it.

### Sample Run:

```
$ g++ bubble3x.cpp -o sort -DDEBUG
$ ./sort
UNSORTED(10):
3 4 1 7 0 9 6 5 2 8
BUBBLE SORTING...
3 1 4 0 7 6 5 2 8 9
1 3 0 4 6 5 2 7 8 9
1 0 3 4 5 2 6 7 8 9
0 1 3 4 2 5 6 7 8 9
0 1 3 2 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
BUBBLE SORTED(10):
9 8 7 6 5 4 3 2 1 0
Happy Coding~~
```

## Step 4: Use a function pointer
  - Observe that we may use the same code (or algorithm) to sort the list either in ascending or in descending __iff__ we could pass the function (`less` or `more`) as an argument.
  - For this purpose, fortunately, we can use a __function pointer__ or a pointer to a function.
  - Read the "Function Pointer" section at the end of this lecture note.
  - Duplicate `bubble3.cpp` which has a bubble-sort algorithm and name it `bubble4.cpp`.
  - Add an function pointer variable to the function `bubbleSort(int *list, int n, ???)`.
  - Let us define the function pointer named `comp()` that accepts for either `more()` or `less()` which returns a `bool` type value and its parameters are two int types.
      - This function pointer `comp()` can be defined as shown below:
      ```
      bool (*comp)(int, int)
      ```
  - Therefore, bubbleSort() signature and its code become as shown below:

  ```
  void bubbleSort(int *list, int n, bool (*comp)(int, int)) {
    ...
    ...
  }

  - Invoke `bubbleSort()` function twice, one with `less` function and the other with `more` function as shown below:

  int main(int agrgc, char *argv[]) {
    ...
    bubbleSort(list, N, ::less);    // ascending
    ...
    bubbleSort(list, N, more);      // descending
    ...
  }

  ```
  - Build an executable and test it.

### Sample Run:

```
    $ g++ bubble4x.cpp -o sort -DDEBUG
    $ ./sort
    BUBBLE SORTING...
    3 1 4 0 7 6 5 2 8 9
    1 3 0 4 6 5 2 7 8 9
    1 0 3 4 5 2 6 7 8 9
    0 1 3 4 2 5 6 7 8 9
    0 1 3 2 4 5 6 7 8 9
    0 1 2 3 4 5 6 7 8 9
    0 1 2 3 4 5 6 7 8 9
    0 1 2 3 4 5 6 7 8 9
    0 1 2 3 4 5 6 7 8 9
    BUBBLE SORTED(10):
    0 1 2 3 4 5 6 7 8 9
    BUBBLE SORTING...
    1 2 3 4 5 6 7 8 9 0
    2 3 4 5 6 7 8 9 1 0
    3 4 5 6 7 8 9 2 1 0
    4 5 6 7 8 9 3 2 1 0
    5 6 7 8 9 4 3 2 1 0
    6 7 8 9 5 4 3 2 1 0
    7 8 9 6 5 4 3 2 1 0
    8 9 7 6 5 4 3 2 1 0
    9 8 7 6 5 4 3 2 1 0
    BUBBLE SORTED(10):
    9 8 7 6 5 4 3 2 1 0
    Happy Coding~~
```

------------------------------------------
# Hints and Tips
## Function pointer (or Pointer to a function)
Function Pointers provide some extremely interesting, efficient and elegant programming techniques. You can use them to replace switch/if-statements, to realize your own late-binding or to implement callbacks. Unfortunately - probably due to their complicated syntax - they are treated quite carelessly in most computer books and documentations. If at all, they are addressed quite briefly and superficially. They are less error prone than normal pointers because you will never allocate or deallocate memory with them. All you've got to do is to understand what they are and to learn their syntax. But keep in mind: Always ask yourself if you really need a function pointer.

- It's nice to realize one's own late-binding but to use the existing structures of C/C++ may make your code [more readable and clearer](http://www.newty.de/fpt/intro.html#why).

- You may watch [this lecture]( https://dojang.io/mod/page/view.php?id=592) about the function pointer in Korean.

### Definition
Function Pointer is a pointer, i.e. a variable, which points to the address of a function. You must keep in mind, that a running program gets a certain space in the main-memory. Both, the executable compiled program code and the used variables, are put inside this memory. Thus, a function in the program code is, like e.g. a character field, nothing else than an address. It is only important how you, or better your compiler/processor, interpret the memory a pointer point to.

Instead of referring to data values, a function pointer points to executable code within memory. When dereferenced, a function pointer can be used to invoke the function it points to and pass its arguments just like a normal function call.  [from Wikipedia]

Function pointers can be used to simplify code by providing a simple way to select a function to execute based on run-time values. It is so called late-binding.

A function pointer always points to a function with a specific signature! Thus all functions, you want to use with the same function pointer, must have the same parameters and return-type!

### Simple Example
Suppose that we have a very simple function to print out the sum of two numbers and returns the sum. Let us see how we can create a function pointer from there.

```
#include <iostream>
using namespace std;

int fun(int x, int y) {  		
  return x * 2 + y;
}

int foo(int x, int y) {
	return x + y * 2;
}

int add(int x, int y) {
return x + y;
}

void main() {                   // using function pointer
	int (*fp) (int, int) = fun;   // & is not needed
	cout << "fp() returns " << fp(2, 3) << endl;
	fp = foo;
	cout << "fp() returns " << fp(2, 3) << endl;		
}
```

### Sample run:
```
fp() returns 7
fp() returns 8
```
### Facts About Function pointers

#### Differences from normal pointers:
  - A function pointer points to code, not data. Typically, a function pointer stores the start of executable code.
  - We do not allocate nor de-allocate memory using function pointers.

#### Same as normal pointers;
  - We can have an array of function pointers.

  ```
  int main() {
     // fp is an array of function pointers
  	 int (*fp[])(int, int) = { fun, foo, add };
  	 for (int i = 0; i < 3; i++)
  		cout << "fp(" << i << ") returns " << fp[i](2, 3) << endl;;
  }
  ```
  - A function pointer can be passed as an argument and can also be returned from a function.  This feature of the function pointer is extremely useful.  In OOP, class methods are another example implemented using function pointers.
-------------------------------------
# File(s) to submit for this Lab:
  - bubble4.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
