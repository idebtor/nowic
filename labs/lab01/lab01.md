# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
## Multiple source files and compilations
As our programs get more complicated, we want to store the source code into separate files.  For example, let's suppose we have `greet_func()` defined in `greet_func.cpp` and it is invoked in `greet_func()` as shown below:

```
// file: greet_func.cpp
#include <iostream>

void greet_func() {
    std::cout << "Hello World!";
}
```
To allow programs to be written in logical parts, c++ supports __separate compilation__.  It lets us split our program into several files, each of which can be compiled independently. Since `greet_func.cpp` does not have `main()`, the compiler cannot generate an executable.  But it can generates an __object__ file with `.o` extension instead of `.exe`.

```
$g++ -c greet_func.cpp     # generates greet_func.o
```

To generate an executable with the following file, `greet.cpp`, we must tell the compiler where to find all of the code we use.  
```
// file: greet.cpp
#include <iostream>
extern greet_func();   // lets the compiler know it from external sources
                       // this is called a function proto-types
                       // ~.h files consists of the function proto-types
int main() {
    greet_func();
}
```

We might compile these files as follows.  
```
$g++ greet.cpp greet_func.cpp -o greet     # generates greet.exe
$./greet                                   # runs greet.exe
```
Now we can run the `greet` program.

If we have changed only one of our source files, we want to recompile only the file that actually changed. We should be able to have a way to separately compile each file.  This process usually yeilds a file with the .o or .obj file extension, indicating that the file contains __object code__.

The compiler lets us __link__ object files together to form an executable.  On the system (Windows & gcc) we use, we would separately compile our programs as follows:

```
$g++ -c greet_func.c                   # generates greet_func.o
$g++ -c greet.c                        # generates greet.o
$g++ greet_func.c greet.c              # generates a.exe
$g++ greet_func.c greet.c -o greet     # generates greet.exe
```

## More GCC Compiler Options
There are some flags available for compiler options:
```
$g++ -std=c++11 -Wall -g file1.cpp file2.cpp -o prog   # generates prog.exe
```
  - -o : specifies the output executable filename.
  - -std=c++11 : to explicitly specify the C++ standard, c++11, c++14, c++17, c++2a
  - -Wall : enables most warning messages.
  - -g : generates additional symbolic debugging information for use with gdb debugger.

## A Good Guideline for GCC and Make
- [Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

-------------------------------------------------------

# Lab01 - Building an executable with multiple source files

## Specifications
- Get `lab01` files from `GetHub/idebtor/nowic/labs`.
- Place the source files given into an appropriate folders as necessary.  
- Open the files in `Atom` and read them.
- Build the `add` program to produce `add.exe`.
- Function prototype declarations
- Debug the program if necessary.
- Run `add.exe`.
- Use `using namespace std`

## Tips and instructions:
The following command line compiles two source files, and looks for any include file necessary in `include` folder to build an executable `add.exe`. The files required to build are `lab01.cpp, lab01driver.cpp`, and `lab01.h1`.  Therefore, you pay attention to specify where the include folder is from where you are compiling the source code.  We keep the files like in nowic, this compilation command may be as shown below.

```
  g++ lab01.cpp lab01driver.cpp -I../../include -o add
  ./add
```

When the compiler compiles the `#include "lab01.h"` line, it copies the contents of `lab01.h` into the current file at that point. Because our add.h contains a function prototype for `add()`, this prototype is now being used as a forward declaration of `add()`. Consequently, our program will compile and link correctly.

### #include:
When you `#include` a file, the entire content of the included file is inserted at the point of inclusion. This is called __preprocessing__ which happens at the beginning of compilation.

A header file only has to be written once, and it can be included in as many files as needed. This also helps with maintenance by minimizing the number of changes that need to be made if a function prototype ever changes (eg. by adding a new parameter).

Header files consist of two parts. The first part is called a `header guard`, it prevents a given header file from being #included more than once in the same file. The second part is the actual content of the `.h` file, which should be the declarations for all of the functions we want other files to be able to see. Our header files should all have a `.h` extension, so we will call our new header file `lab01.h`:

```
// This is start of the header guard.  
// LAB01_H can be any unique name.  
// By convention, we use the name of the header file.
#ifndef LAB01_H
#define LAB01_H

// declare the function prototypes for add.h
int add(int x, int y);	// don't forget the semicolon!

// This is the end of the header guard
#endif
```
Have the header guard, `#ifndef`, unless `#pragma once`. By the way, we are going to use `header guard` since some compilers don't support `#pragma`.

# Files to submit:
  - nothing^^

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
