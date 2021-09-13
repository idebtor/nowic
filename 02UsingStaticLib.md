그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/c4d8ad9a5a51d14744e3e5b66da376c8bef15292/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.
Lecture notes by idebtor@gmail.com

-----
# About Static Library

A library is a collection of pre-compiled object files that can be linked into your programs via the linker. Examples are the system functions such as printf() and sqrt(). There are two types of external libraries: static library and shared library.

  - A static library has file extension of `.a` (archive file) in Unixes or `.lib` (library) in Windows.
  - A shared library has file extension of `.so` (shared objects) in Unixes or `.dll` (dynamic link library) in Windows. Because of the advantage of dynamic linking, g++, by default, links to the shared library if it is available. You can list the contents of a library via `nm filename`.

## How to build a static library
Let's suppose that you have a source file (`nowic.cpp`) to turn it into a static library (`libnowic.a`). Assume that you keep `lib/nowic.cpp` and `~/include/nowic.h`.

```
g++ -c nowic.cpp -I../include    // produces nowic.o
ar rcs libnowic.a nowic.o        // produces libnowic.a that includes nowic.o
ar                               // list all the options available
ar t libnowic.a                  // list ~.o files archived
ar x libnowic.a                  // extract ~.o files archived
nm nowic.o                       // list the actual function names in .o file
```
#### ar flags:
  - -c: Create an archive file		
  - -r: Insert the files member... into archive (with replacement).
  - -s: Write an object-file index into the archive, change is made to the archive 		
  - -t: display contents of archive
			(show the list of .o files, use nm ~.o to see functions in ~.o)

#### NOTE
It is important that you recognize that the g++ compiler requires that you prefix your static library with the keyword `lib` and suffix `.a`, like `libnowic.a`. The `lib` prefix is required by the linker to find the static library in Linux and OSX. Without a prefix, it uses `nowic.lib` in Windows.

## How to reference a static library
Assuming that you are in `~/src` folder and already have `../lib/libnowic.a`  

```
g++ selection.cpp sortDriver.cpp -o sort –I../include –L../lib –lnowic
```

#### g++ flags: 	
  - -L: Indicates the location of the library you want to reference
  - -l: Specifies the specific library you want to attach

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
