# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
## Function Overloading
Two or more functions having same name but different argument(s) are known as overloaded functions. In C++ programming, two functions can have same name if number and/or type of arguments passed are different.

__For example__:
```
// Call-by-pointer example
void swap(int *x, int *y) {     // swap(int* x, int* y)
   int temp;
   temp = *x;   // save the value at address x
   *x = *y;     // put y into x
   *y = temp;   // put x into y
   return;      // x and y are really swapped.
}

// Call-by-reference example
void swap(int& x, int& y) {    // swap(int &x, int &y)
   int temp;
   temp = x;  // save the value at address x
   x = y;     // put y into x
   y = temp;  // put x into y
   return;    // x and y are really swapped.
}

int main() {
  int a = 1, b = 2;
  cout << "To Begin     a = " << a << ", b = " << b << endl;
  swap(a, b);
  cout << "By Reference a = " << a << ", b = " << b << endl;
  swap(&a, &b);
  cout << "By Pointer   a = " << a << ", b = " << b << endl;
}
```
__Output__:
```
To Begin     a = 1, b = 2
By Reference a = 2, b = 1
By Pointer    a = 1, b = 2
```
Here, the `swap()` function is called two times with different type of arguments.


## Yet Another Example
Consider a function `print`, which displays an int. As shown in the following example, you can overload the function print to display other types, for example, `double` and `char*`. You can have three functions with the same name, each performing a similar operation on a different data type: executed, the arguments are plugged in for the formal parameters.  

```
#include <iostream>
using namespace std;

void print(int i) {
  cout << " Here is int " << i << endl;
}
void print(double  f) {
  cout << " Here is float " << f << endl;
}

void print(char* c) {
  cout << " Here is char* " << c << endl;
}

int main() {
  print(10);
  print(10.10);
  print("ten");
}
```
The following is the output of the above example:
```
 Here is int 10
 Here is float 10.1
 Here is char* ten
```

## Default Arguments
In C++ programming, not in C, you can provide default values for function parameters.

The idea behind default argument is simple. If a function is called by passing arguments, those arguments are used by the function.

But if the arguments are not passed while invoking a function then, the default values are used. Default values are passed to arguments in the function prototype.

Following is a simple C++ example to demonstrate use of default arguments. We don’t have to write 3 sum functions, only one function works by using default values for 3rd and 4th arguments.

```c++
#include<iostream>
using namespace std;

// A function with default arguments, it can be called with  
// 2 arguments or 3 arguments or 4 arguments.
int sum(int w, int x, int y=0, int z=0) {
    return (w + x + y + z);
}

// Driver program to test above function
int main() {
    cout << sum(10, 15) << endl;
    cout << sum(10, 15, 25) << endl;
    cout << sum(10, 15, 25, 30) << endl;
    return 0;
}
```

__JoyLab__:

### Common mistakes when using Default argument
1. ```void add(int a, int b = 3, int c, int d);```

The above function will not compile. You must provide default values for each argument after `b`. In this case, `c` and `d` should also be assigned default values.
If you want a single default argument, make sure the argument is the last one.

```
void add(int a, int b, int c, int d = 4);
```

2. No matter how you use default arguments, a function should always be written so that it serves only one purpose.
If your function does more than one thing or the logic seems too complicated, you can use Function overloading to separate the logic better.

### References:
- https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr312.htm
- https://www.programiz.com/cpp-programming/default-argument
- https://www.geeksforgeeks.org/default-arguments-c/

-----------------------------
One thing I know, I was blind but now I see. John 9:25
