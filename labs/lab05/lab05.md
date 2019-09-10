# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab05 - Sorting and Function pointer
## Subjects
  - selection sort
  - bubble sort
  - insertion sort
  - quick sort
  - function pointers
  - `#if 1`

## Step 1: Integrate sort programs
  - In this lab, we will get to know how to handle multiple source files,   include files, and external functions as well.
  - Eventually, we want to write a program that works like `sortx.exe`.  
  - Run `sortx.exe` provided in this lab and experience how it works.  
  - Read a skeleton code, `sort.cpp`.

## Step 2: Understand sorting algorithms
  - Each file shown below contains a specific sorting algorithm.
      - `bubble.cpp, insertion.cpp, quicksort.cpp, selection sort`
  - Build and run each file separately. Study the algorithms by your own and
    Understand how each algorithm works.
  - Compiling the source file with `-DDEBUG` option may help you trace the code.
  - The following commands show you compiling without or with `-DDEBUG` option.
    ```
    $ g++ bubble.cpp -o sort
    $ g++ bubble.cpp -o sort -DDEBUG
    ```

## Step 3: External file - printList.cpp
  - Place a copy of `printList()` into its own file and name it `printList.cpp`.
      - add a prototype for `printList()` in `sort.cpp`.
  - Include prototypes for 4 sorting functions if necessary.
  - Build `sort.cpp` along with the file `printList.cpp` together.

Sample run:
    ```
    $ g++ sort.cpp bubble.cpp insertion.cpp quicksort.cpp selection.cpp printList.cpp -o sort -DDEBUG
    $ ./sort
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit): b
    UNSORTED(10):
    3 4 1 7 0 9 6 5 2 8
    SORTED(10):
    0 1 2 3 4 5 6 7 8 9
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit): x
    ```

## Step 4: Create include/sort.h

  - In `sort.cpp`, we want to invoke sorting functions as defined in sorting files (`bubble.cpp, inserttion.cpp, quicksort.cpp, selection.cpp`), then we need to exclude `main()` and `printList()` in each sorting file. Otherwise, it causes errors because of a multiply defined functions.
  - In each sorting file, set the following macro `#if 0`. This code will exclude all codes between `#if 0` and `#endif`.
  - Create `nowic/include/sort.h` file that contains all four sorting function
    prototypes.
  - Add a line to include `sort.h` in `sort.cpp`.
  - Remove 4 sorting function prototypes in `sort.cpp`
  - Build an executable and test it.

A sample run:
  ```
  $ g++ sort.cpp bubble.cpp insertion.cpp quicksort.cpp selection.cpp printList.cpp -I../../include -o sort
  $ ./sort
  b for bubble, i for insertion, q for quick, s for selection
  Enter an algorithm to sort(x to exit): q
  UNSORTED(10):
  3 4 1 7 0 9 6 5 2 8
  SORTED(10):
  0 1 2 3 4 5 6 7 8 9
  b for bubble, i for insertion, q for quick, s for selection
  Enter an algorithm to sort(x to exit): x
  ```

## Step 5: Using a function pointer.
  - Begin with the skeleton code, `sort5.cpp`.
    Once you complete it, it should work just like `sortx.cpp`.
  - Follow the instructions in the skeleton code itself.

A sample run:
  ```
    $ g++ sortx.cpp bubble.cpp insertion.cpp quicksort.cpp selection.cpp printList.cpp -I../../include -o sort
    $ ./sort
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit): b
    UNSORTED(10):
    3 4 1 7 0 9 6 5 2 8
    SORTED(10):
    0 1 2 3 4 5 6 7 8 9
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit): i
    UNSORTED(10):
    3 4 1 7 0 9 6 5 2 8
    SORTED(10):
    0 1 2 3 4 5 6 7 8 9
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit):
  ```

  ```
  $ g++ sortx.cpp bubble.cpp selection.cpp insertion.cpp quicksort.cpp printList.cpp -I../../include -o sortx -DDEBUG
  $ ./sortx
  b for bubble, i for insertion, q for quick, s for selection
  Enter an algorithm to sort(x to exit): b
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
  SORTED(10):
  0 1 2 3 4 5 6 7 8 9
  b for bubble, i for insertion, q for quick, s for selection
  Enter an algorithm to sort(x to exit):
  ```
---------------------------------------------
# File(s) to submit for this Lab:
    - sort.cpp
    - sort5.cpp

----------------------------

_One thing I know, I was blind but now I see. John 9:25_
----------------------------
