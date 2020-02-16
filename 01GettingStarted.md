# Data Structures & C++ for C Coders
Lecture Notes by idebtor@gmail.com
-------------------
# Getting Started
  __To get started__, do the first thing first:

  1. Read README.
  2. Read Syllabus.
  3. Read 'GettingStarted' - this file
  4. Follow instructions in 'GettingStarted' as soon as possible(ASAP).

  These reading materials is available at my [github.com/idebtor/nowic](https://github.com/idebtor/nowic).

### How to view markdown(.md) files in Chrome (or rendering in HTML)
  0. View them always in github website automatically and better.
  - and/or
  1. Install `Markdown Viewer` extension.
  2. Navigate to `chrome://extensions` and
      - Locate `Markdown Viewer` and click on the `DETAILS` button
      - Check the option `Allow access to file URLs`
  2. 크롬에서 `chrome://extensions` 접속 한 후,
      - `Markdown Viewer` `세부정보`에서
      - "파일 URL에 대한 액세스 허용"을 체크한다.
  3. Open local or remote .md file in Chrome.
  4. Enjoy nicely formatted HTML!

## Join Piazza.
There are two ways to join Piazza, go the www.piazza.com.
  - To join Piazza, you may need the following information and
    - School: __Handong Global University__
    - Course: __Data Structures and C++ for C Coders__
  - If you have an email address that ends with __~.hgu.edu__ or __~.handong.edu__ domain and use it everyday, go the www.piazza.com and follow the instructions in the website.

  - On your request with your email address, I may register it for you.  We'll be conducting all class-related discussion here this term. The quicker you begin asking questions on Piazza (rather than via emails), the quicker you'll benefit from the collective knowledge of your classmates and instructors. We encourage you to ask questions when you're struggling to understand a concept—you can even do so anonymously.

## Install GCC (GNU Compiler Collection) for Mac OS X
  - For mac, it is really simple.
  - Start a terminal and run the following command. Follow instructions if needed.
      ```
        $ xcode-select --install    
      ```
  - Check GCC installation with the following command. It has been installed successfully if you see some version numbers.
      ```
        $ g++ -v  
      ```
## Install GCC (GNU Compiler Collection) for Windows
  - To use g++ in Windows, we need to install two packages:
    - MSYS2    (__important note:__ install MSYS2 first)
    - MinGW-w64

### Install MSYS2 _"first"_.
  - Installing __MSYS2__ is relatively simple.
  - Connect this [website](http://www.msys2.org/) http://www.msys2.org/
  - Select this __msys2-x86_64-20190524.exe__ for 64 bit version.(the second button, usually)
  - Download and install it while accept all the default setting.
    - At the end, you will see a console opened when you accept all the default.
    - If not, open a console `MSYS2` console or run `C:\msys64\msys2.exe`.
  - At the console, run the following command to update the package database and core system packages with: (__$__ in the command line below is a console prompt: don't type it.)
  ```
    $ pacman -Syu     
  ```    
  - If you see some _failure messages_ during installation, run it __a couple of times__ until you see a very long list of downloads. Even you may need to restart a console. To restart a console, run `C:\msys64\msys2.exe`.
  - You may follow this [good installation guide](http://blog.naver.com/PostView.nhn?blogId=adapriest&logNo=220981281896&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView)

### Install MinGW-w64 (64 bit version recommended)
  - Open a console MSYS2 console and run the following command. Accept the default as they are. If some packages fail, run it again.  

  ```
    $ pacman -S mingw-w64-x86_64-gcc
  ```

### Add the following two paths to the user's (or system's) environment `PATH` variable.
  - The first one we want to add to the PATH is the path where `g++.exe` exists.
  - The second one is the path where some utility commands such as `ls`, `cat` and `cp` exist.
  - By default, the paths are:
      - `c:\msys64\mingw64\bin`  
      - `c:\msys64\usr\bin`                         
  - But it is a good idea to check and copy the folders instead of typing.

  - If you want to use it in `mintty` or `MSYS2/Mingw64` consoles, add them to your `.bash_profile` as well.
    - Follow instructions in ["UsingMintty.md" file](https://github.com/idebtor/nowic/blob/master/02UsingMintty.md) stored in this folder.

### Check GCC (MSYS2 and MinGW64-w64) installation:
  - Start a console(`cmd` or `Powershell` in Windows) or open a `mintty` console.
  - To check installation, run the following command:

  ```
  $ g++ --version
  ```
  - You may see something like below:
    ```
    $ g++ --version
    g++.exe (Rev2, Built by MSYS2 project) 9.2.0
    Copyright (C) 2019 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```
  - If you installed it in a different way, you may see .
    ```
    $ g++ --version
    g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
    Copyright (C) 2018 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```

  - If you see something different from `x86_64-posix-seh-rev0` or `Built by MSYS2 project`, you have chosen a wrong version. Go through the installation process with caution again.

#### MinGW-w64 [installation Problem](https://stackoverflow.com/questions/57894158/mingw-w64-installation-fails-with-error-res-in-windows-10): ERROR res
    - In some PC Windows, we have experienced a difficulty during MinGW-w64 installation.
    - It fails with __`ERROR res`__ during the installation. I posted [this question](https://stackoverflow.com/questions/57894158/mingw-w64-installation-fails-with-error-res-in-windows-10) in the __stackoverflow__ and got [this answer](https://stackoverflow.com/questions/30069830/how-to-install-mingw-w64-and-msys2/30071634#30071634). You may go their recommendation.
    - In summary, you install __MSYS2__ first, and then install __MinGW-w64__ as part of __MSYS2__.
      - __MSYS2__ installation is really easy and rarely fails.
      - It comes with a command-line package manager (`pacman`).
      - It offers always the newest `MinGW-w64/GCC` combo available.
      - You can also install many other packages compatible with this toolchain.
      - For details see [this answer](https://stackoverflow.com/questions/30069830/how-to-install-mingw-w64-and-msys2/30071634#30071634).
    - Don't forget adding the path `C:/mingw64/bin` to your __PATH__ environment variable.

#### This is another way to install MinGW-w64. (Not recommended)
This method fails when the user uses __KoreanUserName__. For MinGW-w64, follow this [good installation guide](https://brunch.co.kr/@mystoryg/56) available.
    - __IMPORTANT NOTE__ During the installation, select the following option:
    ```
      Architecture  x86_64
    ```
    __instead of__
    ```
      Architecture  xi686
    ```
    - After installation, don't forget the installation path to `PATH` environment variable. In my case, the installation path was:
    ```
    C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin
    ```
---------------------------------

## Using Mintty/MSYS2 console instead of cmd or PowerShell.
  - To use Mintty or MSYS2 console, follow instructions in ["UsingMintty.md" file](https://github.com/idebtor/nowic/blob/master/02UsingMintty.md) stored in this folder.

-----------------------------------
## Install Atom.
1. Atom is a text editor that most professional programmers love nowadays.
2. Start Atom.
3. Install some of essential packages recommended for C/C++ programmers listed below:

    - Platformio-ide-terminal
      - On successful installation, you will see a +sign at the bottom-left corner of the editor. Click + sign to open a console.
    - atom-file-icons
    - minimap
    - Markdown-preview
      - Open a rendered version of the Markdown in the current editor with `ctrl-shift-m`.
    - Autosave
      - It automatically saves files when the editors loses focus, are destroyed, or when the window is closed.
      - Believe or not, it is disabled by default. __You must check `enabled`__ in config setting or from the Autosave section of the Settings view.

    __Themes of my personal preference__:
      - UI Theme - Atom Dark,
      - Syntax Theme - Oceanic Next

    __Note for Multi-screen users:__ If Atom is displayed off-screen, do the following:
      1. Alt + Tab to choose the atom window
      2. Alt + Space to open the context menu
      3. Press 'm' to select move
      4. Press any arrow key once
      5. Move your mouse (The misplaced window will follow your cursor.)

    __Problem in platformio-ide-terminal:__ If the prompt does not show up in the terminal, you may look Issues #765 and #760 at github/platformio/platformio-atom-ide-terminal.
      1. #760 is a solution for Windows users.
      2. #765 includes a comment I posted. What I found is to follow the #760 solution except one item. Use apm instead of npm.

## Install "GitHub Desktop" and "Git"
- Install __git__ from [this site](https://git-scm.com/downloads) for your computer.
- Install __GitHub Desktop__

After installation of GitHub Desktop, be a member if already not.
  - Clone the GitHub `nowic` repository into your local computer:
    - https://github.com/idebtor/nowic  
  - __How to clone a repository from GitHub:__ Refer to [this site](https://help.github.com/desktop/guides/contributing-to-projects/cloning-a-repository-from-github-desktop/).
  - Click __'watch'__ and __'star'__ at the top of the web page.
  - Then, in your computer, you may have the following github/nowic folder as shown below:

    ```C:\GitHub\nowic```

  - Since this `nowic` repository can be updated anytime, keep this local repository as "read-only".  Don't code yours here!.
  - Copy them into your own repository or your own local development folders in your computer you can easily access them.  They should look like the following:
    ```
    ~/nowic/include           # include files
    ~/nowic/labs              # labs
    ~/nowic/lib               # nowic.lib, libnowic.a, libnowic_mac.a
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

      __JoyNote__: How do I force `git pull` to overwrite local files?

      - Go to the ~/nowic folder.
      - Open a console and run the following two commands.
      ```
      git fetch --all
      git reset --hard origin/master
      ```
      or
      ```
      git stash
      ```
      __Explanation:__ `git fetch` downloads the latest from remote without trying to merge or rebase anything. Then the `git reset` resets the master branch to what you just fetched. The `--hard` option changes all the files in your working tree to match the files in origin/master
      __Caution:__ If you have any local changes, they will be lost. With or without --hard option, any local commits that haven't been pushed will be lost.

      __JoyNote__: How do I keep my local files clean after trials?
      - Go to the ~/nowic folder.
      - Open a console and run the following command.
      ```
      git clean -f
      ```
      __Explanation:__ To delete all untracked files.

## Are ready for 'Hello World!' program in C++?
  - Open a console. (may use cmd or powershell)  
    - You may use cmd or powershell at this point. Sooner or later, however, we are going to use a different kind of console called mintty. You may read __UsingMinttyInMinGW.md__ for the Mintty installation at `nowic` folder.
  - Open hello.cpp file with Atom
    ```
    Atom hello.cpp
    ```
  - Build an executable. The output name depends on your OS: hello.exe, a.exe for windows; hello.out, a.out for linux and macOS. Mac users may need to add -std=c++11 option to compile as shown below:
    ```
    g++ hello.cpp -o hello            # hello.exe
    g++ -std=c++11 hello.cpp -o hello # hello.out for macOS
    g++ hello.cpp                     # a.exe or a.out
    ```
  - Run the executable.
    ```
    ./hello                           # PowerShell
    ./a                               # PowerShell
    hello                             # Cmd, Linux, OSX
    a                                 # Cmd, Linux, OSX
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
- Mac users may need to add -std=c++11 option to compile as shown below:
```
$ g++ hello.cpp              # generates a.exe, a.out
$ g++ -std=c++11 hello.cpp   # for macOS
$ ./a.exe                    # runs a.exe            for PowerShell
$ ./a                        # runs a.exe, a.out     for PowerShell and macOS
$ a                          # for Cmd Windows
```
- The line above compiles (and links) the source code and generates an executable called `a.exe` or `a.out`.
- `$` is a console prompt. (You don't need to enter it.)
- The line above compiles (and links) the source code and generates an executable called `a.exe`  
- `g++` is the name of our compiler, and `#` begins a command-line comment.  We can run the executable file, `a.exe` or `a.out`, which will run our main function. If you want to name the executable, you may provide the file name with `-.o` option as follows:

```
$ g++ hello.cpp -o hello        # generates hello.exe
$ ./hello.exe                   # runs hello.exe
$ ./hello                       # runs hello.exe, hello.out for macOS & PS
$ hello                         # for Cmd Windows
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
- Read __UsingMintty.md__ at `nowic` and install `Mintty` console.
----------------------------
_One thing I know, I was blind but now I see. John 9:25_

----------------------------
