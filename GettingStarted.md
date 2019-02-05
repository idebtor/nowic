# Data Structures
  Lecture Notes by idebtor@gmail.com
  --------------

  After you read syllabus or handouts in class and do the followings ASAP:

## Join Piazza.
There are two ways to join Piazza, go the www.piazza.com.
  - To join Piazza, you may need the following information and
    - School: __Handong Global University__
    - Course: __Data Structures by idebtor__
  - If you have an email address that ends with __~.hgu.edu__ or __~.handong.edu__ domain and use it everyday, go the www.piazza.com and follow the instructions in the website.

  - On your request with your email address, I may register it for you.  We'll be conducting all class-related discussion here this term. The quicker you begin asking questions on Piazza (rather than via emails), the quicker you'll benefit from the collective knowledge of your classmates and instructors. We encourage you to ask questions when you're struggling to understand a concept—you can even do so anonymously.

## Install MinGW/MSYS(32bit version recommended)
  - Follow this [good installation guide](http://holawang.blogspot.kr/2014/02/g++-installing-g++-at-windowsmingw-or.html) available.
  - After the installtion, change (add) the following two folders into user's PATH environment variable:
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
Atom is a text editor that most professional programmers love nowadays. Some essential packages recommended to install at Atom  

  - Autosave
  - File-icons
  - Mini-maps
  - Platformio-ide-terminal (On successful installation, you will see a +sign at bottom-left corner of the editor.)

## Install Desktop GitHub
From GitHub, get the following repository in your computer.

  - https://github.com/idebtor/nowic   

- Keep this repository as "read-only".   
- Copy them into your own repository or development folders in some place in your computer you can easily access them.  They should look like the following:
    ```
    ~/nowic/include
    ~/nowic/lib
    ~/nowic/src
    ~/nowic/psets/pset01/pset01.pdf, hellox.exe, names.txt
    ```

## About pset01 files provided:
These files are provided for your first homework assignment. It is called a problem set 01.

  - ~/nowic/psets/pset01/pset01.pdf            # this file
  - ~/nowic/psets/pset01/hellox.exe            # a solution to compare your work
  - ~/nowic/psets/pset01/names.txt             # a list of names used in Step 5.

## Are ready for 'Hello World!' program in C++?
  - Open a console.  (You may read __UsingMinttyInMinGW__ first.)
  - Open hello.cpp file with Atom
    ```
    Atom hello.cpp
    ```
  - Build an execuable.
    ```
    g++ hello.cpp -o hello
    ```
  - Run the execuable.
    ```
    hello
    ```
## Are ready to study more?
For further study of C or C++ basics, the following two video lectures in YouTube are recommended.  A solid background in C will do good for C++ study in this course.

  - Beginning C Programming by Bluefever
  - C++ Tutorial by Derek Banas.  

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
