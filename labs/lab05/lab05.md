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
  - For testing purpose, build a skeleton code, `sort.cpp` along with the file `printList.cpp` together.
  - Sample run:
    ```
    $ g++ sort.cpp printList.cpp -o sort -DDEBUG
    $ ./sort
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit): b
    your code here - one line
    b: your code here
    UNSORTED(10):
    3 4 1 7 0 9 6 5 2 8
    your code here - one line
    SORTED(10):
    3 4 1 7 0 9 6 5 2 8
    b for bubble, i for insertion, q for quick, s for selection
    Enter an algorithm to sort(x to exit): x
    ```

## Step 4: Create include/sort.h

  - In `sort.cpp`, we want to invoke sorting functions as defined in sorting files (`bubble.cpp, inserttion.cpp, quicksort.cpp, selection.cpp`), then we need to exclude `main()` and `printList()` in sorting files. Otherwise, it causes errors because of a multiply defined functions.
  - In every sorting files, set the following macro `#if 0`. This code will exclude all codes between `#if 0` and `#endif`.
  - Create `nowic/include/sort.h` file that contains all four sorting function
    prototypes. Notice that your lab folder is located at `nowic/labs/lab05`.
  - Add a line to include `sort.h` in `sort.cpp`.
  - For this step, uncomment the following 4 lines of code only in `sort.cpp`.

  ```
  // Uncomment the next 4 line for Step 4 ///////////////////
  // bubbleSort(list, N);
  // insertionSort(list, N);
  // quickSort(list, N);
  // selectionSort(list, N);
  // Remove 4 lines above after Step 4 //////////////////////
  ```
  - Build an executable and test it.
  - A sample run:

  ```
  $ g++ sort.cpp bubble.cpp insertion.cpp quicksort.cpp selection.cpp printList.cpp -I../../include -o sort
  $ ./sort
  b for bubble, i for insertion, q for quick, s for selection
  Enter an algorithm to sort(x to exit): q
  your code here - one line
  q: your code here
  UNSORTED(10):
  3 4 1 7 0 9 6 5 2 8
  your code here - one line
  SORTED(10):
  0 1 2 3 4 5 6 7 8 9
  b for bubble, i for insertion, q for quick, s for selection
  Enter an algorithm to sort(x to exit): x
  ```

## Step 5: Complete sort.cpp

  - Remove the following lines of code in `sort.cpp`.
  ```
    // Uncomment the next 4 line for Step 4 ///////////////////
    bubbleSort(list, N);
    insertionSort(list, N);
    quickSort(list, N);
    selectionSort(list, N);
    // Remove 4 lines above after Step 4 //////////////////////
  ```
  - Make `sort.cpp` work just like `sortx.cpp`.
  - A sample run:
  ```
    $ g++ sortx.cpp bubble.cpp insertion.cpp quicksort.cpp selection.cpp printList.cpp
      -I../../include -o sort
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
---------------------------------------------
# File(s) to submit for this Lab:
    - sort.cpp


----------------------------

_One thing I know, I was blind but now I see. John 9:25_
----------------------------
