# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab02 - Understanding a better coding in C
  Learn about NMN, DRY, malloc(), free(), rand(), %, assert() and __a better coding__ after all.

## Specifications
There are many topics we need to pay attention. You read, run and understand `lab02.cpp` code first. Pay attention the following topics in the code.
  - Improve the following code in C first and name it as lab02a.cpp
  - Identify a magic number. (NMN)
  - Identify a repetition. (DRY)
  - rand()
  - % operator
  - #if 1

### Task I:
Replace the following line, not to use a magic number (hard-coded) 10.
```
const int N = 10;
```
### Task II:
Write a function to avoid DRY violation.

### Task III:
First of all, comment out the following two lines you coded in __Task I__.

```C++
// int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
// const int N = 10;
```

Then, set a magic number N = 50 for the time being. Use a pointer `int *list` and `malloc()` which allocates `*list` to store `N` integers to replace an array of the fixed size.   

```C++
  int *list;
  int N;
```
- Generate random numbers from `0` to `N` and add them into the list.
- Use `assert()` after `malloc()` to check whether or not `malloc()` worked.
- Use `free()` to free memory resources after use.

# Files to submit:
  - lab02a.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
