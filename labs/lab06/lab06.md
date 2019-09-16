# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab06 - Build a static lib on your machine
## Subjects
  - Compile and link separately
  - Compile and link Multiple Source Files
  - Utilities for Examining the Compiled Files
  - Build a static library or archive file

### Step 1: Compile and link separately
```
$ g++ hello.cpp -o hello
```
  The above command compile the source file into object file and link with other object files and system libraries into executable in one step.

```
// Compile-only with -c option
$ g++ -c hello.cpp
// Link object file(s) into an executable
$ g++ hello.o -o hello
```
The options are:
  - `-c`: Compile into object file "hello.o". By default, the object file has the same name as the source file with extension of `.o` (there is no need to specify `-o` option). No linking with other object files or libraries.

  - Linking is performed when the input file are object files `.o` (instead of source file `.cpp`). GCC uses a separate linker program (called `ld.exe`) to perform the linking.

### Step 2: Compile and Link Multiple Source Files

Suppose that your program has two source files: `bubble.cpp, sortDriver.cpp`. You could compile all of them in a single command:

```
$ g++ bubble.cpp, sortDriver.cpp -I../include -L../lib -lnowic -o sort
```
However, we usually compile each of the source files separately into object file, and link them together in the later stage. In this case, changes in one file does not require re-compilation of the other files.

```
$ g++ -c bubble.cpp
$ g++ -c sortDriver.cpp
$ g++ bubble.o sortDriver.o -I../include -L../lib -lnowic -o sort
```

### Step 3: Headers (.h), Static Libraries (.lib, .a) and Shared Library (.dll, .so)
  - A library is a collection of pre-compiled object files that can be linked into your programs via the linker. Examples are the system functions such as `printf()` and `sqrt()`.

  - There are two types of external libraries:
      - static library
      - shared library
  - A __static__ library has file extension of `.a` (archive file) in Unixes or `.lib`(library) in Windows. When your program is linked against a static library, the machine code of external functions used in your program is copied into the executable. A static library can be created via the archive program `ar.exe`.
  - A __shared__ library has file extension of `.so` (shared objects) in Unixes or `.dll`(dynamic link library) in Windows. When your program is linked against a shared library, only a small table is created in the executable. Before the executable starts running, the operating system loads the machine code needed for the external functions - a process known as dynamic linking. Dynamic linking makes executable files smaller and saves disk space, because one copy of a library can be shared between multiple programs. Furthermore, most operating systems allows one copy of a shared library in memory to be used by all running programs, thus, saving memory. The shared library codes can be upgraded without the need to recompile your program.
  - Because of the advantage of dynamic linking, GCC, by default, links to the shared library if it is available.
  - You can list the contents of a library via `nm filename`.

### Step 4: Searching for Header Files and Libraries (-I, -L and -l)

  - When compiling the program, the compiler needs the header files to compile the source codes; the linker needs the libraries to resolve external references from other object files or libraries. The compiler and linker will not find the headers/libraries unless you set the appropriate options, which is not obvious for first-time user.

  - For each of the headers used in your source (via #include directives), the compiler searches the so-called include-paths for these headers. The include-paths are specified via `-Idir` option (or environment variable CPATH). Since the header's filename is known (e.g., `iostream.h`, `stdio.h`), the compiler only needs the directories.

  - The linker searches the so-called library-paths for libraries needed to link the program into an executable. The library-path is specified via `-Ldir` option (uppercase `L` followed by the directory path). In addition, you also have to specify the library name. In Unixes, the library `libxxx.a` is specified via `-lxxx` option (lowercase letter `l`, without the prefix `lib` and `.a` extension). In Windows, provide the full name such as `-lxxx.lib`. The linker needs to know both the directories as well as the library names. Hence, two options need to be specified.


### Step 5: Default Include-paths, Library-paths and Libraries
Try list the default include-paths in your system used by the "GNU C Preprocessor" via `g++ -v`:
```
$ g++ -v
```

Try running the compilation in verbose mode (`-v`) to study the library-paths (`-L`) and libraries (`-l`) used in your system:

```
$ g++ -v hello.cpp -o hello
```

### Step 6: Utilities for Examining the Compiled Files
For all the GNU utilities, you can use `command --help` to list the help menu;

  - `file` - list file type

    The utility "file" can be used to display the type of object files and executable files. For example,
  ```
    $ file hello.cpp
    hello.cpp: C++ source, ASCII text, with CRLF line terminators
  ```
  ```
    $ file hello.exe
    hello.exe: PE32+ executable (console) x86-64, for MS Windows
  ```

  - `ldd` - list dynamic link libraries

    It examines an executable and displays a list of the shared libraries that it needs. For example,

    ```
    $ ldd hello.exe
    USER32.dll => /c/WINDOWS/System32/USER32.dll (0x7ff995c20000)
    win32u.dll => /c/WINDOWS/System32/win32u.dll (0x7ff993870000)
    ...
    libgcc_s_seh-1.dll => /c/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/libgcc_s_seh-1.dll (0x61440000)
    libwinpthread-1.dll => /c/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/libwinpthread-1.dll (0x64940000)
    ```

  - `nm` - List Symbol Table of Object Files

    The utility "nm" lists symbol table of object files. Since it lists so many symbols, we often use it with pipe(`|`) and  `grep` command as shown below:

    ```
    $ nm hello.exe | grep main
    0000000000402b98 T __getmainargs
    00000000004082e0 I __imp___getmainargs
    0000000000407960 B __mingw_winmain_lpCmdLine
    0000000000403000 D __mingw_winmain_nShowCmd

    0000000000403024 D __native_dllmain_reason
    0000000000401180 t __tmainCRTStartup
    00000000004015f0 t _GLOBAL__sub_I_main
    0000000000401550 T main
    00000000004014e0 T mainCRTStartup
    ```
    It also is commonly-used to check if a particular function is defined in an object file. A `T` in the second column indicates a function that is defined, while a `U` indicates a function which is undefined and should be resolved by the linker.

### Step 7: Make your own `libnowic.a` and `libsort.a` for your machine.
  - To build an archive file, refer to [UsingStaticLib.pdf](https://github.com/idebtor/nowic/blob/master/03UsingStaticLib.md) provided.
  - To create or update .o's in an archive file, use `ar rcs archive_name.a my_obj.o`
  - To list .o's in an archive file, use `ar t archive_name.a` command.

### Step 8: Test your own `libnowic.a` and `libsort.a` for your machine.
  - To test your `libnowic.a`, build `nowicx.cpp` and run it. The build script would be something like below:
  ```
  $ g++ nowic_test.cpp -I../../include -L./ -lnowic -o nowicx
  ./nowicx        # cmd/PowerShell
  ./nowicx.exe    # mintty
  ```

  - To test your `libsort.a`, build `sortx.cpp` and run it. The build script would be something like below:

  ```
  $ g++ sortx.cpp printList.cpp -I../../include -L./ -lsort -o sortx
  ./sortx        # cmd/PowerShell
  ./sortx.exe    # mintty
  ```

### Step 9: Understanding compiling and linking process
The build process mainly consists of compiling and linking. Compiling produces ~.o's from source files and linking produces ~.exe from ~.o's. For example:

#### compiling
```
$ g++ -c sortx.cpp -I../../include
$ g++ -c printList.cpp
```
#### linking
```
$ g++ sortx.o printList.o -L./lib -lsort -o sortx
```

#### building: compiling and linking all together
```
$ g++ sortx.cpp printList.cpp -I../../include -L./lib -lsort -o sortx
```

### Last step:
You may copy or move `libnowic.a` and `libsort.a` in ../../lib folder _if you wish_.

---------------------------------
# File(s) to submit for this Lab:
  - libnowic.a
  - libsort.a

----------------------------

_One thing I know, I was blind but now I see. John 9:25_
----------------------------
