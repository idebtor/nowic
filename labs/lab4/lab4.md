그런즉 너희가 먹든지 마시든지 무엇을 하든지 다 하나님의 영광을 위하여 하라 (고전10:31)

-------
<img src="https://github.com/idebtor/nowic/blob/85a7852bf0f6000fded586dadaeac02c186027a6/images/cplus_ds_title.jpg?raw=true" width=1000>

__NOTE:__ The following materials have been compiled and adapted from the numerous sources including my own. Please help me to keep this tutorial up-to-date by reporting any issues or questions. Send any comments or criticisms to `idebtor@gmail.com` Your assistances and comments will be appreciated.

-------------------
# Lab4 - Bubble sort and Function pointer
## Subjects
    - using DEBUG
    - bubble sort
    - ascending or descending sort
    - the first class function
    - defining and passing function pointer
    - default argument
    - function prototype
    - global scope resolution operator :: 

## Step 1: Understand sorting algorithms
  - A source code for the basic bubblesort algorithm is provided.
  - Study the algorithm by your own and understand how the algorithm works.
  - Build it with or without `-DDEBUG` option and run it to see the difference.
  ```
  $ g++ bubble.cpp -o sort
  $ g++ bubble.cpp -o sort -DDEBUG
  ```
#### Sample Run:
```
$ g++ -std=c++11 -Wall bubble.cpp -o bubble
$./bubble
UNSORTED: 
3  4  1  7  0  9  6  5  2  8  

[1]BUBBLE SORTED:
0  1  2  3  4  5  6  7  8  9
...
...
```
----------------------

```
$ g++ -std=c++11 -Wall bubble.cpp -o bubble -DDEBUG
$ ./bubble
UNSORTED: 
3  4  1  7  0  9  6  5  2  8  

BUBBLE SORTING...
3 1 4 0 7 6 5 2 8 9
1 3 0 4 6 5 2 7 8 9
1 0 3 4 5 2 6 7 8 9
0 1 3 4 2 5 6 7 8 9
0 1 3 2 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
[1]BUBBLE SORTED:
0  1  2  3  4  5  6  7  8  9
...
...
```

## Step 2: Sort in descending order
  - Modify only one line in `bubblesort()` function such that it sorts the list in __descending__ order.
  - Build an executable and test it.
  - You may observe the list sorted in descending order. Once you understand it, change it back. 

#### Sample Run:
```
$ g++ -std=c++11 -Wall bubble.cpp -o bubble        
$ ./bubble
UNSORTED:
3  4  1  7  0  9  6  5  2  8

[1]BUBBLE SORTED:
9  8  7  6  5  4  3  2  1  0
...
...
```

## Step 3: Use a function pointer to compare 
  - According the previous step, we now know that the comparison of two elements determines either ascending or descending order. 
  - We do not have to duplicate another bubblesort function that is different in one line that compares two elements. 
  - To solve this problem, we may just pass __a comparator function pointer__ such that the alogrithm invokes whenever it compares elements during sorting.  
  - The comparator function takes two arguments and contains logic to decide their relative order in sorted output. The idea is to provide flexibility so that `bubblesort()` can be used to obtain any desired order (increasing, decreasing or any other).   The comparator function takes two arguments and defines the order of the elements by returning true or false (in a stable and transitive manner).
  - Let us define two comparator functions above `main()` as shown below:
    ```
    #if 1
    // two comparator functions 
    // The value returned indicates whether the element passed as first argument
    // is considered to go before the second in the specific ordering.
    // more() and less() are equivalent to greater<int> and less<int> in STL. 
    bool more(int x, int y) { return x > y; }   // for descending order
    bool less(int x, int y) { return x < y; }   // for ascending order 
    ...
    ...
    int main() {
      ...
    }
    ```

  - Use one of the comparator functions. For example, `more(x, y)` returns true if `x > y`, otherwise false.
  - bubblesort() takes a third parameter that is used to specify the order in which elements are to be sorted. We can pass `more()` function to sort in descending order. This function does comparison in a way that puts greater element before.
  - By the way, `less()` is already defined in `std` namespace (Refer to [here](http://www.cplusplus.com/reference/functional/less/)). To use `less()` which we defined, we must add the global scope resolution operator(`::`) such as `::less()`. 

## Step 4: Use a function pointer
  - Observe that we may use the same code (or algorithm) to sort the list either in ascending or in descending __iff__ we could pass the function (`more` or `less`) as an argument.
  - For this purpose, fortunately, we can use a __function pointer__ or a pointer to a function.
  - Read the "Function Pointer" section at the end of this lecture note.
  - Add an function pointer variable to the function `bubblesort(int *list, int n, ???????)`.
  - Let us define the function pointer named `comp()` that accepts for either `more` or `less` which returns a `bool` type value and its parameters are two int types. This function pointer `comp()` can be defined as shown below:
    ```
    bool (*comp)(int, int)
    ```
  - Therefore, bubblesort() signature becomes as shown below:

    ```
    void bubblesort(int *list, int n, bool (*comp)(int, int)) {
      ...
      ...
    }
    ```

  - Invoke `bubblesort()` function twice, one with `more` function and the other with `::less` function as shown below:

    ```
    int main(int agrgc, char *argv[]) {
      ...
      bubblesort(list, N, more);      // descending
      ...
      bubblesort(list, N, ::less);    // ascending
      ...
    }
    ```

### Sample Run:
```
$ g++ -std=c++11 -Wall bubble.cpp -o bubble
$./bubble
UNSORTED: 
3  4  1  7  0  9  6  5  2  8

[1]BUBBLE SORTED:
0  1  2  3  4  5  6  7  8  9

[2]BUBBLE SORTED - descending using more() fp: 
9  8  7  6  5  4  3  2  1  0

[3]BUBBLE SORTED - ascending using less() fp:
0  1  2  3  4  5  6  7  8  9
```
------------------------------
### Sample Run with DEBUG:
```
$ g++ -std=c++11 -Wall bubble.cpp -o bubble -DDEBUG
$ ./bubble
UNSORTED: 
3  4  1  7  0  9  6  5  2  8

BUBBLE SORTING...
3 1 4 0 7 6 5 2 8 9
1 3 0 4 6 5 2 7 8 9
1 0 3 4 5 2 6 7 8 9
0 1 3 4 2 5 6 7 8 9 
0 1 3 2 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
[1]BUBBLE SORTED:
0  1  2  3  4  5  6  7  8  9

BUBBLE SORTING...fp
1 2 3 4 5 6 7 8 9 0
2 3 4 5 6 7 8 9 1 0
3 4 5 6 7 8 9 2 1 0
4 5 6 7 8 9 3 2 1 0
5 6 7 8 9 4 3 2 1 0
6 7 8 9 5 4 3 2 1 0
7 8 9 6 5 4 3 2 1 0 
8 9 7 6 5 4 3 2 1 0 
9 8 7 6 5 4 3 2 1 0
[2]BUBBLE SORTED - descending using more() fp:
9  8  7  6  5  4  3  2  1  0

BUBBLE SORTING...fp
8 7 6 5 4 3 2 1 0 9
7 6 5 4 3 2 1 0 8 9
6 5 4 3 2 1 0 7 8 9
5 4 3 2 1 0 6 7 8 9
4 3 2 1 0 5 6 7 8 9
3 2 1 0 4 5 6 7 8 9
2 1 0 3 4 5 6 7 8 9
1 0 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
[3]BUBBLE SORTED - ascending using less() fp:
0  1  2  3  4  5  6  7  8  9
```

Is this cool? Now, the caller can decide how the sorting will be done. Instead of using a hard-coded comparison function, we allow the caller to provide their own sorting function! This is done via a function pointer. 

We’ve given the caller the ability to control how our selection sort does its job. The caller can even define their own “strange” comparison functions:

```
bool evenfirst(int x, int y) {
  // if x(2nd element) is even and y is odd, x goes first (swap needed)
  if ((x % 2 == 0) && !(y % 2 == 0)) return true;
 
  // if x(2nd element) is odd and y is even, y goes first (no swap needed)
  if (!(x % 2 == 0) && (y % 2 == 0)) return false;
 
  // otherwise sort in ascending order (x:2nd element, y:1st element)
  return less(x, y);
}
```
The above snippet produces the following result:
```
[4]BUBBLE SORTED - even first:
0  2  4  6  8  1  3  5  7  9
```

As you can see, using a function pointer in this context provides a nice way to allow a caller to “hook” their own functionality into something you’ve previously written and tested, which helps facilitate __code reuse__! Previously, if you wanted to sort one array in descending order and another in ascending order, you’d need multiple versions of the sort routine. Now you can have one version that can sort any way the caller desires!

## Step 5: Using the function pointer as a default argument 
Finally, we just want to use the three-parameter `bubblesort()` only for all sorting operations here. 
  - __Comment out__ the two-parameter `bubblesort()` surrounding with `#if 0 ... #endif` as shown below:

  ```
  #if 0
  void bubblesort(int *list, int n) {
    DPRINT(cout << "BUBBLE SORTING...\n");
  ...
  ...
  #endif
  ```

  - Keep the three-parameter `bubblesort()` as it is. Then, however, define a three-parameter `bubblesort()` prototype with the default argument as `::less` function pointer, just above the `main()`.  
  - Since `less` is defined as a default argument in the function prototype, ::less may be omitted. Remove the `less` function pointer in `main()` as shown below:
  - Lastly, include the even number sorting first which is strange as shown in the Sample Run.

    ```
    #if 1
 
    // three-parameter bubblesort function prototype with a default function pointer here.
    void bubblesort(int *list, .....
    ...
    ...
    ...
    int main() {
      int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
      int N = sizeof(list) / sizeof(list[0]);

      cout << "UNSORTED: " << endl;
      for (auto x: list) cout << x << "  "; 
      cout << endl << endl;

      bubblesort(list, N);
      cout << "[1]BUBBLE SORTED:" << endl;
      ...
      ...
      return 0;
    }

    endif
    ```
  - Compile and run the code. We should get the same results as before.

  #### Sample Run: 
    ```
    UNSORTED:
    3  4  1  7  0  9  6  5  2  8

    [1]BUBBLE SORTED:
    0  1  2  3  4  5  6  7  8  9

    [2]BUBBLE SORTED - descending using more() fp:
    9  8  7  6  5  4  3  2  1  0

    [3]BUBBLE SORTED - ascending using less() fp:
    0  1  2  3  4  5  6  7  8  9

    [4]BUBBLE SORTED - even first:
    0  2  4  6  8  1  3  5  7  9
    ```

## Congratulations! 

------------------------------------------
# Hints and Tips
## Function pointer (or Pointer to a function)
Function Pointers provide some extremely interesting, efficient and elegant programming techniques. You can use them to replace switch/if-statements, to realize your own late-binding or to implement callbacks. Unfortunately - probably due to their complicated syntax - they are treated quite carelessly in most computer books and documentations. If at all, they are addressed quite briefly and superficially. They are less error prone than normal pointers because you will never allocate or deallocate memory with them. All you've got to do is to understand what they are and to learn their syntax. But keep in mind: Always ask yourself if you really need a function pointer.

- It's nice to realize one's own late-binding but to use the existing structures of C/C++ may make your code [more readable and clearer](http://www.newty.de/fpt/intro.html#why).

- You may watch [this lecture]( https://dojang.io/mod/page/view.php?id=592) about the function pointer in Korean.

### Definition
Function Pointer is a pointer, i.e. a variable, which points to the address of a function. You must keep in mind, that a running program gets a certain space in the main-memory. Both, the executable compiled program code and the used variables, are put inside this memory. Thus, a function in the program code is, like e.g. a character field, nothing else than an address. It is only important how you, or better your compiler/processor, interpret the memory a pointer point to.

Instead of referring to data values, a function pointer points to executable code within memory. When dereferenced, a function pointer can be used to invoke the function it points to and pass its arguments just like a normal function call.  [from Wikipedia]

Function pointers can be used to simplify code by providing a simple way to select a function to execute based on run-time values. It is so called late-binding.

A function pointer always points to a function with a specific signature! Thus all functions, you want to use with the same function pointer, must have the same parameters and return-type!

### Simple Example
Suppose that we have a very simple function to print out the sum of two numbers and returns the sum. Let us see how we can create a function pointer from there.

```
#include <iostream>
using namespace std;

int fun(int x, int y) {  		
  return x * 2 + y;
}

int foo(int x, int y) {
	return x + y * 2;
}

int add(int x, int y) {
return x + y;
}

void main() {                   // using function pointer
	int (*fp) (int, int) = fun;   // & is not needed
	cout << "fp() returns " << fp(2, 3) << endl;
	fp = foo;
	cout << "fp() returns " << fp(2, 3) << endl;		
}
```

#### Sample Run:
```
fp() returns 7
fp() returns 8
```
### Facts About Function pointers

#### Differences from normal pointers:
  - A function pointer points to code, not data. Typically, a function pointer stores the start of executable code.
  - We do not allocate nor de-allocate memory using function pointers.

#### Same as normal pointers;
  - We can have an array of function pointers.

  ```
  int main() {
     // fps is an array of function pointers
  	 int (*fps[])(int, int) = { fun, foo, add };
  	 for (int i = 0; i < 3; i++)
  		cout << "fps(" << i << ") returns " << fps[i](2, 3) << endl;;
  }
  ```
  - A function pointer can be passed as an argument and can also be returned from a function.  This feature of the function pointer is extremely useful.  In OOP, class methods are another example implemented using function pointers.
-------------------------------------
## File(s) to submit for this Lab:
  - bubble.cpp
----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
