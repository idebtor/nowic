# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab03 - Understanding a better coding in C/C++
## Subjects
  - NMN(No magic number)
  - DRY(Don't repeat yourself)
  - malloc(), free()
  - assert()
  - rand()
  - mod operator %
  - #if macro
  - strtol()
  - Learn about __a better coding__ after all.

## Task I: NMN & DRY
  - Using a better function name
  - NMN
  - DRY

1. Read the code provided with `selection.cpp` first.
    - Build an executable and test it.

2. Duplicate `selection.cpp` and name it `selection1.cpp`.
    - There are so many sorting algorithms available. Naming a function such as `sort()` is undesirable.
    - Replace sort() with an appropriate name in `selection1.cpp`.
    - Build an executable and test it.

3. Find a magic number and replace it with a better code in `selection1.cpp`.
    - Replace the following line, not to use a magic number (hard-coded) 10.
      ```
      const int N = 10;
      ```
4. Find some repeated code blocks and replace them with a better code.
    - Consider making a function called `void printList(int *list, int n)`.

## Task II: Using malloc()

  - Using malloc(), free()
  - assert()
  - rand()
  - %

1. Duplicate `selection1.cpp` and name it `selection2.cpp`.
    - First of all, comment out the following two lines you coded in __Task I__.

      ```
      // int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
      // const int N = 10;
      ```

    - Instead of sorting data a fixed size of an array, we want to implement data in a dynamically allocated array.
    - First, set a magic number N = 20 for the time being.
    - Use a pointer `int *list` and `malloc()`.   
    - Use malloc() and allocate `*list` to store `N` integers.

      ```
      const int N = 20;
      int *list;           // your code here
      ```
2. Generate random numbers from `0` to `N` and store them in `list`.
    - Use `assert()` after `malloc()` to check whether or not `malloc()` worked.
    - Use `free()` to free memory resources after use.
    - Build an executable and test it.
    - A sample run:

## Task III: Coding in C++
    - Convert C code into C++
    - Using new and delete
    - Getting user's input
        - Display a message if user's input is less than 2.

1. Duplicate `selection2.cpp` and name it `selection3.cpp`.

    - Replace `printf()` with `cout <<`
    - Instead of using the following `include`:
      ```
      #include <stdio.h>
      #include <stdlib.h>
      #include <assert.h>
      ```
      Use the following `include`:
      ```
      #include <iostream>
      #include <cassert>
      using namespace std;
      ```
    - Build an executable and test it.

2. Study about `new` and `delete` in C++ in your own.
    - Get user's input for `N`
        - `N` is not a `const` variable anymore since it is set by user's input.
        - Use `cout` for prompt and use `cin` to get `N`.
        - No error checking necessary in this case for now. If `N` is less than 2, just exit the program.
    - Rewrite `malloc()` and `free()` to use `new` and `delete`.
    - Build an executable and test it.

3. Replace some code in selectionSort() using swap() in C++.

4. Sample runs:

    ```
    $ g++ selection3.cpp -o sort

    $ ./sort
    Enter a number of samples to sort: -5
    The number must be greater than 1.
    ```

    ```
    $ ./sort
    Enter a number of samples to sort: 5
    UNSORTED(5):
    1 2 4 0 4
    SORTED(5):
    0 1 2 4 4
    Happy Coding~~
    ```

## Task IV: Interaction with users
    - `strtol()` vs. `atoi()`
    - Good interaction with users
    - Good use of `Usage:`

1. Duplicate `selection3.cpp` and name it `selection4.cpp`.
    - In `selection4.cpp`, read user's input from the command line argument if any.
    - Use it if user enters a number as a command line argument
        - Use `strtol()` instead of `atoi()` to convert `argv[1]` to an int.
          For more information about `strtol()`, refer to __Hints and Tips__ section in this page.
        - Do a bit of error checking as shown below in sample runs.
    - Ask user to enter a number if nothing is passed through the command line.
        - Keep on asking until the user enters a proper number which is greater than 1.

2. Sample runs:
  ```
    $ g++ selection4.cpp -o sort
    $ ./sort
    Enter a number of samples: -30
    Retry...
    Enter a number of samples: 5
    UNSORTED(5):
    1 2 4 0 4
    SORTED(5):
    0 1 2 4 4
    Happy Coding~~
  ```

  ```
    $ ./sort 10
    UNSORTED(10):
    1 7 4 0 9 4 8 8 2 4
    SORTED(10):
    0 1 2 4 4 4 7 8 8 9
    Happy Coding~~
  ```

  ```
  $ ./sort -30
  Usage: selection [N]
  $./sort xxx
  Usage: selection [N]
  ```
-----------------------------------
# File(s) to submit for this Lab:
  - selection4.cpp

-------------------------------------------

# Tips and Hints

## cin
  The `cin` object in C++ is an object of class `istream`. It is defined in `<iostream>` header file. It is used to accept the input from the standard input device i.e. keyboard. It is associated with the standard C input stream `stdin`.

  The "c" in cin refers to "character" and 'in' means "input", hence `cin` means "character input".

  The cin object is used along with the extraction operator (>>) in order to receive a stream of characters. The general syntax is:

  ```
  std::cin >> varName;
  ```
  ### cout
  The `cout` object in C++ is an object of class ostream. It is defined in `<iostream>` header file. It is used to display the output to the standard output device i.e. monitor. It is associated with the standard C output stream `stdout`.

  The "c" in cout refers to "character" and 'out' means "output", hence `cout` means "character output". The `cout` object is used along with the insertion operator (<<) in order to display a stream of characters. The general syntax is:
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

## Convert a char array into an int - `strtol()`
  The [strtol](http://www.cplusplus.com/reference/cstdlib/strtol/?kw=strtol) function parses the C-string str as an `int` of the specified base, which is returned as a `long` int value.

  Example:
  ```
  char* p;
  N = strtol(argv[1], &p, 10);
  if (*p != '\0' || N <= 1)
     // this is an error.

  // N is greater than 1 and it is an int.
  ```
## `new` and `delete` operators in C++
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
  int *s = (int *) malloc(sizeof(int) * 10);
  ```

#### Using new or malloc() vs normal array declaration

  There is a difference between declaring a normal array and allocating a block of memory using `new`. The most important difference is, normal arrays are deallocated automatically. If array is local, then deallocated when function returns or completes. However, dynamically allocated arrays always remain there until either they are deallocated by programmer or program terminates.

#### What if enough memory is not available during runtime?
  If enough memory is not available in the heap to allocate, the `new` returns a `nullptr` pointer when `(nothrow)` is specified. it An exception error is thrown without `(nothrow)` option.  Therefore, it may be good idea to check for the pointer variable produced by new before using it program.

  ```
  int *r = new (nothrow) int[10];
  assert(r !== nullptr);
  ```

## delete operator or free() function
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
----------------------------
# File(s) to submit for this Lab:
  - selection4.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
