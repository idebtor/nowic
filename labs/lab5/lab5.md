그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/85a7852bf0f6000fded586dadaeac02c186027a6/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.


-------------------
# Lab05 - Understanding a better coding in C/C++

## Subjects
  - NMN(No magic number)
  - DRY(Don't repeat yourself)
  - Use new and delete instead of malloc(), free()
  - Use assert() after new to check the memory allocation status
  - rand() and mod operator % 
  - Learn about __a better coding__ after all.

## Step 1: NMN and DRY - Better coding in C++
Let us convert this C code into a better C++ code.

1. Read the code provided with `selection.cpp` first. There are so many sorting algorithms available. Naming a function such as `sort()` in this file is undesirable since there are so many different sort algorithms. Replace `sort()` with an appropriate name. 

2. Replace <stdio.h> which comes from C with <iostream> and `using namespace std;`. For example, replace `printf` with `cout`. 

3. NMN: Find a magic number and replace it with a better code.

4. DRY: Replace some repeated code with `printlist()` function in `printlist.cpp` provided. Add the following function prototype before you use it in selection.cpp. 
    ```
    void printlist(int *list, int n, int show_n = 20, int per_line = 10);
    ```
5. Build and run it.

#### Sample Run:
  ```
  $ g++ selection.cpp printlist.cpp -o selection
  $ ./selection
  UNSORTED(10):
  3 4 1 7 0 9 6 5 2 8
  SORTED(10):
  0 1 2 3 4 5 6 7 8 9
  Happy Coding~~
  ```

## Step 2: Getting input n from the user and dynamic memory allocation
Instead of using a static array for sorting, we want to allocate a dynamic array and to use random numbers for sorting. For the array size, we should get an input from the user for it.

1. Comment out the following two lines you coded and add a new line with `int n = 0;`.

    ```
    // int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
    // int n = ......
    int n = 0;
    ...
    ...
    ```
2. Get an array size n from the user and set it for `n`. 
    - The `n` should be greater than 1. 
    - If `n > 1`, break the while-loop since we got the proper `n`.
    - Let the user retry if `n` is invalid. (negative, not a number...)
    - Quit the program if the user enters `q`.
    - If necessary, include <string> header file to use functions such as `getline()` and `stoi()`. 
    - Check your run with the sample solution `selectionx.exe`. 
  
    ```
    int n = 0;
    while (n <= 1) {
      cout << "Enter a number of samples to sort(q to quit): ";
      ...
      ...
    }
    ```
#### Sample Run:
  ```
  $ g++ selectionx.cpp printlist.cpp -o selectionx
  $ ./selectionx
  Enter a number of samples to sort(q to quit): abcd
  Retry -
  Enter a number of samples to sort(q to quit): -1000
  Retry -
  Enter a number of samples to sort(q to quit): q
  ```

3. Dynamic memory allocation in C++ 
  - Once you get a proper `n` from the user, use it to allocate an `int` array `list`. 
  - Instead of using `malloc()` and `free()`, use `new` and `delete` in C++.
  - Use a pointer `int *list` and `new (nothrow) int[n]`.   
  - Right after the allocation, use `assert()` to check that the allocation was successful as shown below:
    ```
    assert(list != nullptr);
    ```
  - To use `assert()`, you must include <cassert> header file. 
  - If `new` fails, it returns `nullptr`. If `list == nullptr`, then the process stops here. This is the simplest way of checking assertion in coding. 
  - 
  - Use `delete` or `delete []` to free memory resources after use.
  - If necessary, study about `new` and `delete` in C++ in your own.

4. Generate random numbers from `0` to `n` and store them in `list`. 
  - Use `rand() % n` which generates an integer between `0` and `n`. 

5. Build an executable and test it.

#### Sample Run:
```
  $ ./selectionx
  Enter a number of samples to sort(q to quit): 1000
  UNSORTED(1000):
         41      467      334      500      169      724      478      358      962      464
        ...
        676      629      650      598      309      693      686       80      116      249

  SORTED(1000):
          1        2        3        3        3        6        7        7        8        8
        ...
        990      992      993      993      994      995      996      997      998      999

  Happy Coding~~
  ```

## Step 3: Adding a default comparator function pointer
As you experienced in `bubblesort.cpp`, add an third parameter to `selectionsort()` such that it can sort in both ascending and descending order. 
1. Add a third parameter `comp` function pointer such that it may take either `more` or `less`.  Use `comp` functin pointer to compare two elements in the list.  
2. Define two comparator functions, `more() and less()`. Place it just above `main()`.
3. Define the function prototype with a default comparator for ascending order. Place it just above `main()`.
    ```
    #if 1
    // two comparator functions 
    // The value returned indicates whether the element passed as first argument
    // is considered to go before the second in the specific ordering.
    // more() and less() are equivalent to greater<int>() and less<int>() in STL. 
    bool more(int x, int y) { return x > y; }   // for descending order
    bool less(int x, int y) { return x < y; }   // for ascending order 

    // your code here - the function prototype with a default comparator argument

    int main() {
      ...
    }
    ```

4. Add the following code to sort the list in descending order in `main()`. 
    ```
      // descending order using more() fp.
      selectionsort(list, n, more);
      cout << "SORTED(" << n << "): descending using fp\n";
      printlist(list, n);

      // deallocate *list
      ...
      ...
    ```

#### Sample Run:
```
$ ./selectionx
Enter a number of samples to sort(q to quit): 100
UNSORTED(100):
       41       67       34        0       69       24       78       58       62       64
      ...
       44       39       26       23       37       38       18       82       29       41

SORTED(100):
        0        1        2        3        4        5        5        6        6        8    
      ...
       90       90       91       91       92       93       94       95       95       99

SORTED(100): descending using fp
       99       95       95       94       93       92       91       91       90       90
      ...
        8        6        6        5        5        4        3        2        1        0

Happy Coding~~
```
-------------------------------------------

# Tips and Hints

## Convert a string into an int - `stoi()` 
There are many ways to do this type of conversion. 
  - A simple trick is to use `try {} catch(...) {}` since `stoi()` throw an exception for an invalid input as shown below: 

  ```
    try {
      n = stoi(str);
      if (n > 1) break;   // we got a valid n 
    }
    catch(...) { 
    }
    // retry
  ```

## Convert a char array into an int - `strtol()`
  - The [strtol](http://www.cplusplus.com/reference/cstdlib/strtol/?kw=strtol) function parses the C-string str as an `int` of the specified base, which is returned as a `long` int value.

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
  If enough memory is not available in the heap to allocate, the `new` returns a `nullptr` pointer when `(nothrow)` is specified. it An exception error is thrown without `(nothrow)` option.  Therefore, it may be good idea to check for the pointer variable produced by new before using it program. Do not forget to include a header file called `<cassert>` to use `assert()`.

  ```
  int *r = new (nothrow) int[10];
  assert(r != nullptr);
  ```

## delete operator or free() function
  Since it is programmer’s responsibility to deallocate dynamically allocated memory, programmers are provided `delete` operator by C++ language. To free the dynamically allocated array pointed by pointer-variable, use `delete []`.

  Syntax:

  ```
  // Release memory pointed by pointer-variable
  delete pointer-variable;

  // Release block of memory pointed by pointer-variable
  delete[] pointer-variable;  
  ```
----------------------------
# File(s) to submit for this Lab:
  - selection.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
