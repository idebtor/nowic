# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab02
  1. Using vector class objects in C++
  2. ranged-for loop
  3. function overloading
  4. include file

## Instructions
  1. Duplicate `lab01/print_strs.cpp` and name it `lab02/print_strs2.cpp`
      - Study about vector class in your own. It is one of the most used classes in C++.
      - Use the file `args1.cpp` provided and code copying the contents of `*argv[]` to a `vector<string>` object;
          - Use `push_back()` method (or member function) in the vector class.
      - Once you have a `vector<string>` object, you may access the contents
        just like an array as well.
      - Print contents stored in the `vector<string>` object.
      - Build and run an executable.
      - A sample run:

      ```
      $ g++ args1x.cpp print_strs2.cpp -I../../include -o args
      $ ./args hello world
      Using char arrays
      hello
      world
      Copy *argv[] using vector<string>
      Print argv using indexing
      hello
      world
      ```

  2.  Duplicate `args1.cpp` and name it `args2.cpp`.
      - Make the printing code you coded in `args1.cpp` into a function called `print_strs()` that takes a `vector<string>` object and prints its contents.
      - Now, we have two `print_strs()` functions in `print_strs2.cpp`.
          - The name of two functions are the same, but different arguments.
          - This kind of capability is called a __method overloading__.
      - Add a prototype of the newly added function in `args2.cpp`.
      - Build an executable and test it.
        ```
        $ g++ args2.cpp print_strs2.cpp -o args           # generates args.exe
        $ ./args hello world
        Using char arrays
        hello
        world
        Copy *argv[] using vector<string>
        Print argv using print_strs()
        hello
        world
        ```
  3. Create a file called `include/print_strs.h` with the following contents;
        ```
        // lab02 - print_strs.h
        #ifndef PRINT_STRS_H
        #define PRINT_STRS_H

        using namespace std;
        void print_strs(int n, char *strs[]);
        void print_strs(vector<string> strs);

        #endif
        ```
      - Duplicate `args2.cpp` and name it `args3.cpp`.
          - Add a `#include "print_strs.h"`.
          - Remove two `print_strs()` prototypes.
      - Build an executable and test it.

      ```
      $ g++ args3.cpp print_strs2.cpp -I../../include -o args
      $ ./args hello world
      ```

  4. Duplicate `arg3.cpp` and name it `arg4.cpp`.
      - Add __ranged-for__ loop to print the `vector<string>` object.
      - Build an executable and test it.
      - A sample run:
        ```
        $ g++ args4.cpp print_strs2.cpp -I../../include -o args
        $ ./args hello world
        Using char arrays
        hello
        world
        Copy *argv[] using vector<string>
        Print argv using print_strs()
        hello
        world
        Print argv using ranged-for
        hello
        world
        ```
-------------------
## Tips and instructions:
The following command line compiles two source files, and looks for any include file necessary in `include` folder to build an executable `args.exe`. The files required to build are `args3.cpp, print_strs2.cpp`, and `print_strs.h`.  Therefore, you pay attention to specify where the include folder is from where you are compiling the source code.  We keep the files like in nowic, this compilation command may be as shown below.

```
  $ g++ args3.cpp print_strs2.cpp -I../../include -o args
  $ ./args hello world
```

When the compiler compiles the `#include "print_strs.h"` line, it copies the contents of `print_strs.h` into the current file at that point. Because our `print_strs.h` contains a function prototype for `print_strs()`, this prototype is now being used as a forward declaration of `print_strs()`. Consequently, our program will compile and link correctly.

### #include:
When you `#include` a file, the entire content of the included file is inserted at the point of inclusion. This is called __preprocessing__ which happens at the beginning of compilation.

A header file only has to be written once, and it can be included in as many files as needed. This also helps with maintenance by minimizing the number of changes that need to be made if a function prototype ever changes (eg. by adding a new parameter).

Header files consist of two parts. The first part is called a `header guard`, it prevents a given header file from being #included more than once in the same file. The second part is the actual content of the `.h` file, which should be the declarations for all of the functions we want other files to be able to see. Our header files should all have a `.h` extension, so we will call our new header file `print_strs.h`:

```C++
// This is start of the header guard.  
// PRINT_STRS_H can be any unique name.  
// By convention, we use the name of the header file.
#ifndef PRINT_STRS_H
#define PRINT_STRS_H

// declare the function prototypes for print_strs.h


// This is the end of the header guard
#endif
```
Have the header guard, `#ifndef`, unless `#pragma once`. By the way, we are going to use `header guard` since some compilers don't support `#pragma`.

----------------------------
# File(s) to submit for this Lab:
  - args4.cpp
  - print_strs2.cpp

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
