# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab01
  - C and C++ coding using g++
  - a new line escape character and endl manipulator
  - `using namespace std;`
  - Understanding `int main(int argc, char *argv[])`
  - Using functions and prototype
  - Compiling multiple source files

## Instructions
  1. Use hello1.cpp provided in the `lab01` folder.
      - Add a line of code in C such that it prints "Hello World!" twice, one per line.
      - Build an executable.
      ```
      $ g++ hello1.cpp                    # generates a.exe
      $ g++ hello1.cpp -o hello           # generates hello.exe
      ```
      - Run the executable.
      ```
      $ ./a
      $ ./hello
      ```
  2. Write a C++ code such that it prints `Hello World!` twice, one per line.
      - Name the file `hello2.cpp`.
      - Use an escape character `\n` __and__ `endl` manipulator or function for a new line.
      - Build an executable and run it.

  3. Duplicate `hello2.cpp` and name it `hello3.cpp`
      - Simplify the code using `using namespace std;`
      - Build an executable and run it.

  4. Use `hello4.cpp` provided in the `lab01` folder.
      - Change the `main` function as shown below:
        ```
        int main(int argc, char *argv[])
        ```
      - Write the code such that it prints the values of `argc` and `*argv[]` just like __hello4x__ provided for you as an example.
      - Refer to the following sample run:
        ```
        $ ./hello4x
        argv[0] = C:\GitHub\nowicx\labs\lab01\hello4x.exe
        Hello World!

        $ ./hello4x john paul david
        argv[0] = C:\GitHub\nowicx\labs\lab01\hello4x.exe
        Hello john
        Hello paul
        Hello david
        ```

  5. Duplicate `hello4.cpp` and name it `hello5.cpp`
      - Define the following function below `main()` and declare the function prototype above the `main()`.
        ```
        // It prints two dimensional array of characters or an array of strings.
        // Each string is terminated by a \0 and n is the number of strings.
        void print_strs(int n, char *strs[]) {

    	   // your code here

       }
       ```
     - Modify the code such that it uses `print_strs(). But you should __not__ print `Hello` in `print_strs()`, but just arguments passed in `strs` as shown in Sample runs.

     - Sample runs:
     ```
     PS C:\GitHub\nowicx\labs\lab01hello> ./hello5 john peter
     argv[0] = C:\GitHub\nowicx\labs\lab01hello\hello5.exe
     john
     peter
     ```

     ```
     PS C:\GitHub\nowicx\labs\lab01hello> ./hello5
     argv[0] = C:\GitHub\nowicx\labs\lab01hello\hello5.exe
     Hello World!
     ```

  6. Duplicate `hello5.cpp` and name it `hello6.cpp`
      - Move `print_strs()` function into a new file called `print_strs.cpp`.
          - Don't define `print_strs()` in `hello6.cpp`, but keep the prototype.
      - Modify the code such that it uses `print_strs()` and works like `hello4x`.
      - Build an executable with two files, `hello6.cpp` and `print_strs.cpp`
        ```
        $ g++ hello6.cpp print_strs.cpp -o hello6
        $ ./hello6 john paul
        ```

      - Sample runs:
      ```
      PS C:\GitHub\nowicx\labs\lab01hello> ./hello6 john peter
      argv[0] = C:\GitHub\nowicx\labs\lab01hello\hello6.exe
      john
      peter
      ```

      ```
      PS C:\GitHub\nowicx\labs\lab01hello> ./hello6
      argv[0] = C:\GitHub\nowicx\labs\lab01hello\hello6.exe
      Hello World!
      ```
-------------------
## Multiple source files and compilations
As our programs get more complicated, we want to store the source code into separate files.  For example, let's suppose we have `print_strs()` defined in `print_strs.cpp` and it is invoked in `print_strs()` as shown below:

```
// file: print_strs.cpp
#include <iostream>

void print_strs() {
    std::cout << "my strings";
}
```
To allow programs to be written in logical parts, C++ supports __separate compilation__.  It lets us split our program into several files, each of which can be compiled independently. Since `print_strs.cpp` does not have `main()`, __the compiler cannot generate an executable.__  But it can generates an __object__ file with `.o` extension instead of `.exe`.

```
$ g++ -c print_strs.cpp     # generates print_strs.o
```

To generate an executable with the following file, `hello.cpp`, we must tell the compiler where to find all of the code we use.  

```C++
// file: greet.cpp
#include <iostream>
void print_strs();     // lets the compiler know it from external sources
                       // this is called a function proto-types
                       // ~.h files consists of the function proto-types
int main() {
    print_strs();
}
```

We might compile these files as follows.

```
$ g++ hello.cpp print_strs.cpp -o hello     # generates hello.exe
$ ./hello                                   # runs hello.exe
```
Now we can run the `hello` program.

If we have changed only one of our source files, we want to recompile only the file that actually changed. We should be able to have a way to separately compile each file.  This process usually yields a file with the .o or .obj file extension, indicating that the file contains __object code__.

The compiler lets us __link__ object files together to form an executable.  On the system (Windows & gcc) we use, we would separately compile our programs as follows:

```
$ g++ -c print_strs.cpp                   # generates print_strs.o
$ g++ -c hello.cpp                        # generates hello.o
$ g++ print_strs.cpp hello.cpp            # generates a.exe
$ g++ print_strs.cpp hello.cpp -o hello   # generates hello.exe
```

## More GCC Compiler Options
There are some flags available for compiler options:
```
$ g++ -std=c++11 -Wall -g file1.cpp file2.cpp -o prog   # generates prog.exe
```
- -o : specifies the output executable filename.
- -std=c++11 : to explicitly specify the C++ standard, c++11, c++14, c++17, c++2a
- -Wall : enables most warning messages.
- -g : generates additional symbolic debugging information for use with gdb debugger.

## A Good Guideline for GCC and Make
- [Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

----------------------------
# File(s) to submit for this Lab:
    - hello6.cpp
    - print_strs.cpp

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
