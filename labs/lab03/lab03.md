# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab03 - Understanding a better coding in C/C++

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
    - Consider making a function called `void print_list(int *list, int n)`.

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
    - First, set a magic number N = 50 for the time being.
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

## Task III: Conding in C++
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

3. Sample runs:

    ```
    $ g++ selection3.cpp -o selection
    $ ./selection
    Enter a number of samples to sort: -5
    The number must be greater than 1.
    ```

    ```
    $ ./selection
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
        - Do a bit of error checking as shown below in sample runs.
    - Ask user to enter a number if nothing is passed through the command line.
        - Keep on asking until the user enters a proper number which is greater than 1.

2. Sample runs:
  ```
    $ g++ selection4.cpp -o selection
    $ ./selection
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
    $ ./selection 10
    UNSORTED(10):
    1 7 4 0 9 4 8 8 2 4
    SORTED(10):
    0 1 2 4 4 4 7 8 8 9
    Happy Coding~~
  ```

  ```
  $ ./selection -30
  Usage: selection [N]
  $./selection xxx
  Usage: selection [N]
  ```
# Files to submit:
  - selection4.cpp

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
