# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Getting Started
  __To get started__, do the first thing first:

  1. Read README.
  2. Read Syllabus.
  3. Read 'GettingStarted' - this file 
  4. Follow instructions in 'GettingStarted' as soon as possible(ASAP).

  These reading materials is available at my [github.com/idebtor/nowic](https://github.com/idebtor/nowic).

## Join Piazza.
There are two ways to join Piazza, go the www.piazza.com.
  - To join Piazza, you may need the following information and
    - School: __Handong Global University__
    - Course: __Data Structures and C++ for C Coders__
  - If you have an email address that ends with __~.hgu.edu__ or __~.handong.edu__ domain and use it everyday, go the www.piazza.com and follow the instructions in the website.

  - On your request with your email address, I may register it for you.  We'll be conducting all class-related discussion here this term. The quicker you begin asking questions on Piazza (rather than via emails), the quicker you'll benefit from the collective knowledge of your classmates and instructors. We encourage you to ask questions when you're struggling to understand a concept—you can even do so anonymously.

## Install MinGW/MSYS(32bit version recommended)
  - Follow this [good installation guide](http://holawang.blogspot.com/2014/02/gcc-installing-gcc-at-windowsmingw-or.html) available.  For mac, [good installation guide](https://thdev.net/132)
  - After the installation, change (add) the following two folder names into user's PATH environment variable:
      ```
      C:\MinGW\bin
      C:\MinGW\msys\1.0\bin
      ```
  - To check your installation, do the following in cmd windows or in PowerShell;
      ```
      g++ --version
      ```
  - If you encounter the following error message during the first compilation of your program such as 'HelloWorld.cpp', Refer to [this site](
http://stackoverflow.com/questions/39185248/eclipse-mingw-c-cannot-find-lpthread).

    ```
    c:/mingw/bin/../lib/g++/mingw3 ........ mingw32/bin/ld.exe: cannot find -lpthread
    ```

## Install Atom.
1. Atom is a text editor that most professional programmers love nowadays.
2. Start Atom.
3. Install some of essential packages recommended for C/C++ programmers listed below:
    - Autosave
      - Autosaves editor when they lose focus, are destroyed, or when the window is closed. This package is disabled by default and can be enabled via the autosave.enabled config setting or from the Autosave section of the Settings view.
    - Platformio-ide-terminal
      - On successful installation, you will see a +sign at bottom-left corner of the editor. Click + sign to open a console.
    - File-icons
    - Mini-maps
    - Markdown-preview
      - Open a rendered version of the Markdown in the current editor with `ctrl-shift-m`.
    - language-c
       - Adds syntax highlighting and snippets to C/C++ files
    - gpp-compiler
      - Allows you to compile and run C++ and C within the editor.
      - To compile C or C++, press F5 or right click the file in tree view and click Compile and Run.
      - To compile C or C++ and attach the GNU Debugger, press F6 or right click the file in tree view and click Compile and Debug.

    __Note for Multi-screen users:__ If Atom is displayed off-screen, do the following:
    1. Alt + Tab to choose the atom window
    2. Alt + Space to open the context menu
    3. Press 'm' to select move
    4. Press any arrow key once
    5. Move your mouse (The misplaced window will follow your cursor.)

## Install GitHub Desktop
After installation of Desktop-GitHub, be a member if already not.

  - Clone the GitHub `nowic` repository into your local computer:
    - https://github.com/idebtor/nowic  
  - __How to clone a repository from GitHub:__ Refer to [this site](https://help.github.com/desktop/guides/contributing-to-projects/cloning-a-repository-from-github-desktop/).
  - Click __'watch'__ and __'star'__ at the top of the web page.
  - Then, in your computer, you may have the following github/nowic folder as shown below:
    - ```C:\Users\user\Documents\GitHub\nowic```
  - Since this `nowic` repository can be updated anytime, keep this local repository as "read-only".  Don't code yours here!.
  - Copy them into your own repository or your own local development folders in your computer you can easily access them.  They should look like the following:
    ```
    ~/nowic/c++cc             # c++ for c coders
    ~/nowic/include           # include files
    ~/nowic/labs              # labs
    ~/nowic/lib               # nowic.lib, libnowic.a
    ~/nowic/src               # all source files except labs
    ~/nowic/psets             # problem sets - homework
    ```

    - __For example:__ The pset01(problem set 01) folder provides you with a few files for your first homework assignment.
    ```
    ~/pset01/pset01.pdf       # this file
    ~/pset01/hellox.exe       # a solution to compare your work
    ~/pset01/names.txt        # a list of names used in Step 5.
    ```
      __Note for Multi-screen users:__ Remove the following file if GitHub Desktop is displayed off-screen. Restart Desktop GitHub. (`user` below may be different in your system.)
      ```
      C:\Users\user\AppData\Roaming\GitHub Desktop\window-state.json
      ```

## Are ready for 'Hello World!' program in C++?
  - Open a console. (may use cmd or powershell)  
    - You may use cmd or powershell at this point. Sooner or later, however, we are going to use a different kind of console called mintty. You may read __UsingMinttyInMinGW.md__ for the Mintty installation at `nowic` folder.
  - Open hello.cpp file with Atom
    ```
    Atom hello.cpp
    ```
  - Build an executable. The output name depends on your OS: hello.exe, a.exe for windows; hello.out, a.out for linux
    ```
    g++ hello.cpp -o hello
    g++ hello.cpp
    ```
  - Run the executable.
    ```
    ./hello
    ./a
    hello
    a
    ```

## Write `Hello World!` program
It is a tradition to write a `Hello World!` program when you learn a new programming language.  The following program prints `Hello World!` on a console.  Create a file with the following contents.  Its file name is `hello.cpp`

```
// file: hello.cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!";
}
```

- `//` The line begins with two slashes is not a part of source code.  This line will be excluded when the program runs.
- `#include ` The line begins with `#` is called a `preprocessor directive`.  The preprocessor reads your program before it is compiled and only executes those lines beginning with a # symbol.  When you send the file to the compiler, the preprocessor substitutes the `#include` with the contents of the specified file.
- `<iostream>` The `iostream` file must be included since this program uses `cout` to display console output. This kind of file is called a header file. In this way you can create and use __modules__ that define functions that you only add to your code when you need them. There are lots of different header files available for many different purposes.
- `using namespace std;`  C++ uses namespaces to organize the names of program entities.  This line declares that the program will be accessing entities whose names are part of the namespace called `std`. Every name created by the `iostream` file is part of `std` namespace.  In order for a program to use the entities such as `cout` in `iostream`, it must have access to the `std` namespace.  You may rewrite hello.cpp as shown below:

```
// file: hello.cpp
#include <iostream>

int main() {
    std::cout << "Hello World!";
}
```
Observe two versions `Hello World!` program to see the difference. The difference is whether you are using the namespace or not.

## Run hello.cpp program
To run the program, you must make an executable from the source code file, `hello.cpp`. We use the compiler to generate an __executable__ (or runnable) file from the code in the source file.  The executable file ends with `.exe` or `.out` extension as our source file ends with `.cpp` extension. We might compile the file as follows:

- On the console, type the following line (without $) and press `Enter` key.
```
$ g++ hello.cpp         # generates a.exe, a.out
$ ./a.exe               # runs a.exe
$ ./a                   # runs a.exe, a.out
```
- The line above compiles (and links) the source code and generates an executable called `a.exe` or `a.out`.
- `$` is a console prompt. (You don't need to enter it.)
- The line above compiles (and links) the source code and generates an executable called `a.exe`  
- `g++` is the name of our compiler, and `#` begins a command-line comment.  We can run the executable file, `a.exe` or `a.out`, which will run our main function. If you want to name the executable, you may provide the file name with `-.o` option as follows:

```
$ g++ hello.cpp -o hello        # generates hello.exe
$ ./hello.exe                   # runs hello.exe
$ ./hello                       # runs hello.exe, hello.out
```

  __JoyNote:__
  - Run `hello.exe` or `hello.out` without `./` in front, when you run it at Linux, OSX and mintty console^^.

## Are ready to study more?
For further study of C or C++ basics, the following two video lectures in YouTube are recommended.  A solid background in C will do good for C++ study in this course.

  - [Beginning C Programming by Bluefever](https://www.youtube.com/watch?v=DWWQEmyVplU&list=PLZ1QII7yudbdFfKY1eKV3x_bag04AMPJq)
  - [C++ Programming in One Video by Derek Banas](https://www.youtube.com/watch?v=Rub-JsjMhWY)
  - [C++ Tutorial by Derek Banas](https://www.youtube.com/watch?v=DamuE8TM3xo&list=PLGLfVvz_LVvQ9S8YSV0iDsuEU8v11yP9M)

## What's Next?
- Watch [Derek's lecture](https://www.youtube.com/watch?v=Rub-JsjMhWY) or more.
- Read __ArgcArgv.md__. It may help you do the first problem set(pset).
- Read __UsingMinttyInMinGW.md__ at `nowic` and install `Mintty` console.
----------------------------
_One thing I know, I was blind but now I see. John 9:25_

----------------------------
