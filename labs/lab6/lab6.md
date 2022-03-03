그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/85a7852bf0f6000fded586dadaeac02c186027a6/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.

-------------------
# Lab6 - Be prepared to build a static library

## Subjects
  - Recall - using a comparator function pointer as a default argument 
  - make, makefile, make clean, make bubble

## Getting Started
  - files provided
    - makefile
    - bubble.cpp, selection.cpp - fully coded source files
    - insertion.cpp, merge.cpp, quick.cpp - partial coded source files (skeleton code)
  - We want to complete the code of three more sorting algorithms in the following files:
    - insertion.cpp
    - merge.cpp
    - quick.cpp

## Step 1: Reviewing `bubblesort()` and `selectionsort()`

1. Two complete programs, `bubble.cpp` and `selection.cpp` and `makefile`, are provided for your references. 
2. Build and test it as shown below:

__Sample Run:__
  ```
  $ make bubble
  g++ -Wall -std=c++11  -c bubble.cpp
  g++ -Wall -std=c++11  -o bubble bubble.o     
  $ ./bubble
  UNSORTED: 
  3  4  1  7  0  9  6  5  2  8

  BUBBLE SORTED:
  0  1  2  3  4  5  6  7  8  9

  BUBBLE SORTED using more fp:
  9  8  7  6  5  4  3  2  1  0

  Happy Coding~~
  ```

## Step 2. Add a comparator function pointer as a default argument
  - As you have experienced in `bubblesort.cpp` and `selectionsort()`, add add the third parameter to the rest of sort functions such as `insertionsort()`, `mergesort()` and `quicksort()`. 
  - After you add the comparator function pointer as an argument in sort functions, the ACTUAL `comp` function (not pointer) is used in one line only (i.e. as a default argument in the proto-type). When you invoke `mergesort()` several times, in this lab example, you may omit or insert an actual `comp` function as an argument as needed.  
  - Given skeleton code in `insertion.cpp`, `merge.cpp` and `quick.cpp`, you may find some comments in each file as shown below: 
  - As it said, uncomment the next line and modify the code above to make it work in all three files. 
  - I recommend that you do `insertionsort()` first and `quicksort()` next since the `comp` is actually used one place. Do `merge.cpp` at last since it is more challenging than others. 

  ```
  ...
  ...
    // Uncomment the next line and modify the code above to make it work. 
    // quicksort(list, N, more);
    cout << "QUICK SORTED using more fp): " << endl;
    for (auto x: list) cout << x << "  "; 
    cout << endl << endl;

    cout << "Happy Coding~~";
    return 0;
  }
  #endif
  ```

__Sample Run:__
```
  $ make quick
  g++ -g -Wall -std=c++11  -c quick.cpp
  g++ -g -Wall -std=c++11  -o quick quick.o
  $ ./quick
  UNSORTED:
  54  26  93  17  77  31  44  55  20

  QUICK SORTED:
  17  20  26  31  44  54  55  77  93

  QUICK SORTED using more fp):
  93  77  55  54  44  31  26  20  17

  Happy Coding~~
```

## Step 3. Working on merge.cpp 
 - In fact, `comp()` comparator is actully used only once in `mergesort()` if we exclude the calls of `sorted()`. For example, `assert(sorted(a, lo, mi));`.	
 - These `assert` lines are being used only for error checking. It does not affect the actual sorting. First, comment out these lines for the time being, and make sure that sorting are working correctly. Then you have only one line to apply for `comp()` comparator. 
 - After you observe the sorting working fine, think about how you going to apply `comp()` in the following code.
    ```
    // a helper function to check two elementes sorted.
    // include two elements same value as sorted 
    int sorted(int *a, int i, int j) {  
        return a[i] <= a[j];  
    }
    ```
  - In the following code, `comp` alone cannot resolve `=` case. You must `add the code` to take care of `=` case since the same value of two elements must be considered as __sorted__. 
    ```
    // a helper function to check two elementes sorted.
    // include two elements same value as sorted 
    int sorted(int *a, int i, int j,  bool (*comp)(int, int)) {  
        return a[i] <= a[j];  
    }
    ```
  - Test mergesort() with some equal elements. 

__Sample Run:__
  ```
  $ ./merge
  UNSORTED:
  3 4 1 7 0 9 6 5 2 8

  MERGE SORTED:
  0 1 2 3 4 5 6 7 8 9

  MERGE SORTED using more fp:
  9 8 7 6 5 4 3 2 1 0

  Happy Coding~~
  ```
----------------------------
## File(s) to submit for this Lab:
  - insertion.cpp  
  - merge.cpp  
  - quick.cpp  
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
