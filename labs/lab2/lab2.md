그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/85a7852bf0f6000fded586dadaeac02c186027a6/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.

-------------------
# Lab2
## Subjects
  1. Learning to use `vector` class objects in C++
  2. ranged-for loop
  3. function overloading
  4. include file
  5. not using `using namespace std;`

## Instructions
### Step 1. Using vector<string> data types 
  - Study about `vector` class in your own.
    -  It is one of the most used classes in C++.
    - Refer to __Hints and Tips__ section provided in this page.
  - Use two skeleton source files provided:
    - args1.cpp 
    - printfunc.cpp
  - Follow and code the instructions in skeleton files.
    - Print the command-line arguments except the first one.
    - Copy them to a `vector<string> names` using `push_back()`.
    - To use `vector<string>`, add the `<vector>` header file.
  - Print `names` using for-loop and `names`.
    - Do not change for loop index (int i = 0).
    - Do not use `argc`, `argv` and ranged-for loop. 
    - Use `size()` method of the `vector` class to go through all elements in `names`.
  - Build an executable `args1.exe`, and run it. 

__Sample Run:__
  ```
  $ g++ -std=c++11 args1.cpp printfunc.cpp -o args1
  $ ./args1 David John Lee
  Print **argv using printfunc(**argv) except 1st one
  Hello David!
  Hello John!
  Hello Lee!
  Copy **argv using vector<string> except 1st one
  Print names using for-loop, but not argc/argv, ranged-for
  Hello David!
  Hello John!
  Hello Lee!
  ```

### Step 2: Using external functions 

  - Define a function called `printfunc()` in `printfunc.cpp`. This function takes a `vector<string>` object and prints its contents.
  ```
        printfunc(vector<string> names)
  ```      
  - Modify `printfunc(vector<string> names)` such that it uses ranged-for loop.
  - Now, we have two `printfunc()` functions in `printfunc.cpp`.
      - The name of two functions are the same, but have different arguments.
      - This kind of capability is called a __method overloading__.
  - Add the prototype of the newly added function in `args1.cpp`.
  - Build an executable and test it.
  
__Sample Run:__
  ```
  $ g++ -std=c++11 args1.cpp printfunc.cpp -o args1
  $ ./args1 David John Lee
  Print using printfunc(**argv)
  Hello David!
  Hello John!
  Hello Lee!
  Copy using vector<string>
  Print using indexing, but not ranged-for
  Hello David!
  Hello John!
  Hello Lee!
  Print names using printfunc(vector<string>)
  Hello David!
  Hello John!
  Hello Lee!
  ```

### Step 3. Using a header file and not using `namespace std`

  - Create a file called `nowic/include/printfunc.h` with the following contents;
    - Add two header files: `<vector>` and `<string>`.
    - Add two function prototypes of `printfunc()`s.
    - Do NOT USE `usng namespace std;`.

    ```
    // lab2 - printfunc.h
    #ifndef PRINTFUNC_H
    #define PRINTFUNC_H

    // your code here

    #endif 
    ```
  - Copy (Overwrite)`args1.cpp` into `args2.cpp` which is a dummy skeleton code.
  - Modify `args2.cpp` as instructed below:
    - Add the header file `printfunc.h` in `args2.cpp`.
    - Remove two `printfunc()` prototypes in `args2.cpp` since they are defined in the header file `printfunc.h`.
  - Modify `printfunc.cpp` such that it does not use `using namespace std;`.
  - Build an executable and test it.

__Sample Run:__
  ```
  $ g++ -std=c++11 args2.cpp printfunc.cpp -I../../include -o args2
  $ ./args2 David John Lee
  Print using printfunc(**argv)
  Hello David!
  Hello John!
  Hello Lee!
  Copy using vector<string>
  Print using indexing, but not ranged-for
  Hello David!
  Hello John!
  Hello Lee!
  Print names using printfunc(vector<string>)
  Hello David!
  Hello John!
  Hello Lee!
  ```

-------------------
## Hints and Tips:

### Learning `vector` class and its `push_back()` and `size()` functions

The `vector` class is a sort of a smart array type class. The data type you want to store can be specified with `<>`. The `vector` class and its functions(or methods) can be used for any data type only if you specify it using `<>` as shown below. This is called a generic programming.

  ```
      // the following code prints "HelloWorld".
      vector<string> str_arr;
      str_arr.push_back("Hello");
      str_arr.push_back("World");
      std::cout << str_arr[0] << str_arr[1] << std::endl;
  ```
- Learn how to use `vector` class [here](http://www.cplusplus.com/reference/vector/vector/) and its `push_back()` function [here](http://www.cplusplus.com/reference/vector/vector/push_back/) and `size()` function [here](http://www.cplusplus.com/reference/vector/vector/size/).

- Practice this good [example](http://www.cplusplus.com/reference/vector/vector/push_back/).


### Using `-I` Option in g++ compiler
The following command line compiles two source files, and looks for any include file necessary in `include` folder to build an executable `args.exe`. The files required to build are `args2.cpp, printfunc.cpp`, and `printfunc.h`.  Therefore, you pay attention to specify where the include folder is from where you are compiling the source code.  We keep the files like in nowic, this compilation command may be as shown below.

```
  $ g++ args2.cpp printfunc.cpp -I../../include -o args2
  $ ./args2 David John Lee
```

When the compiler compiles the `#include "printfunc.h"` line, it copies the contents of `printfunc.h` into the current file at that point. Because our `printfunc.h` contains a function prototype for `printfunc()`, this prototype is now being used as a forward declaration of `printfunc()`. Consequently, our program will compile and link correctly.

### Creating an include file and using #include:
When you `#include` a file, the entire content of the included file is inserted at the point of inclusion. This is called __preprocessing__ which happens at the beginning of compilation.

A header file only has to be written once, and it can be included in as many files as needed. This also helps with maintenance by minimizing the number of changes that need to be made if a function prototype ever changes (eg. by adding a new parameter).

Header files consist of two parts. The first part is called a `header guard`, it prevents a given header file from being #included more than once in the same file. The second part is the actual content of the `.h` file, which should be the declarations for all of the functions we want other files to be able to see. Our header files should all have a `.h` extension, so we will call our new header file `printfunc.h`:

```
// This is start of the header guard.  
// PRINTFUNC_H can be any unique name.  
// By convention, we use the name of the header file.
#ifndef PRINTFUNC_H
#define PRINTFUNC_H

// your code here

// This is the end of the header guard
#endif
```
Have the header guard, `#ifndef`, unless `#pragma once`. By the way, we are going to use `header guard` since some compilers don't support `#pragma`.

----------------------------
# File(s) to submit at Piazza lab2:
  - args1.cpp
  - args2.cpp
  - printfunc.cpp

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
