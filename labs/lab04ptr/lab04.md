# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab04 - Using new and delete operators
Write a C++ Program to store quiz score of n number of students and display it where n is the number of students entered by user.

__Sample run:__
```
Enter total number of students: 4
Enter quiz scores of students.
Student 1: 4
Student 2: 3.1
Student 3: 3.9
Student 4: 2.4
```

## Specifications
### Task I:
Do the coding using cin, cout, new and delete. Name this file as `lab04a.cpp`.
#### A possible build command line:
```
  g++ lab04a.cpp -o lab04a
```

### Task II:
  - Do the coding using `GetInt()` and `GetDouble()` defined `nowic.h`. Name this file as `lab04b.cpp`.
  - Read `include\nowic.h` and get familiar with its usage.

#### A possible build command:
This command line specifies a user-defined static library and include.  For include, you set the include folder only. For library, you set its folder as well as the name of the library to link with. `-lnowic` means to link with a library called `libnowic.a`.

```
  g++ lab04b.cpp -I../../include -L../../lib -lnowic -o lab04b
```

# Files to submit:
  - lab04a.cpp
  - lab04b.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
