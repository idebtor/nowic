# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Call-by-reference, Call-by-pointer and Call-by-value

### References
A reference is basically a short-hand for a pointer without the messiness of dereferencing or the ambiguity of ownership. Java doesn't have an analogous concept because object arguments to Java methods are passed by reference automatically. Since Java has an object class for every corresponding basic type (e.g. Integer for int), there is always a simple way to achieve pass-by-reference. In C++, the `&` character is used to indicate that a variable is a reference. For now, we'll just focus on references as parameters to functions and methods. There are some subtleties we'll get into later. The first version of `addOne()` below does not use a reference, so the variable that is passed in remains unchanged. The second version uses a reference, so the underlying variable is actually modified within the function. References can be used for basic types as well as more complex types, like classes.
```
void addOne(int i) {
 i++; // has no real effect since this is a copy of the original
}
```
``` void addOne(int& i) {
 i++; // actually changes the original variable
}
```

### Terminology: parameters and arguments
All the different terms that have to do with parameters and arguments can be confusing.  Let us make clear here.

1. The __formal parameters__ (or parameters for short) for function are list in the function declaration and are used in the body of the function definition.  A formal parameter is a kind of blank or placeholder that is filled in with something when the function is invoked.

2. An __argument__ (or actual argument) is something that is used to fill in a formal parameter.  When you write down a function call, the arguments are listed in parentheses after the function name.  When the function call is executed, the arguments are plugged in for the formal parameters.  

## Call-by-reference in C++, but not in C
There are two ways to dealing with parameters in function calls. They are __call-by-value__ and __call-by-reference__ parameters.  __Call-by-reference__ is a feature in C++, but not in c. However, the similar functionality of the call-by-reference may be achieved using a pointer in c.

With the __call-by-value__, only the _value_ of the argument is plugged in. When a parameter is passed by value, the caller and callee have two independent variables with the same value. If the callee modifies the parameter variable, the effect is not visible to the caller.

With the __call-by-pointer__, passing arguments to a function copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the passed argument.

With __call-by-reference__, the arguments is a variable and _the variable itself_ is plugged in. When a parameter is passed by reference, the caller and the callee use the same variable for the parameter. If the callee modifies the parameter variable, the effect is visible to the caller's variable. The call-by-reference parameter is indicated by appending the ampersand sign, __&__, to the parameter type.

## Call-by-value
Call-by-value parameters acts like local variables in the function while its values were initialized by the caller of the function. You can think of a call-by-value parameters as a kind of blank that is filled by the value of its corresponding argument in the function invocation.

### Call-by-value example
```
void swap(int x, int y) {
   int temp;
   temp = x;   // save the value x
   x = y;      // put y into x
   y = temp;   // put x into y
   return;     // x and y have been swapped ONLY HERE.
}
int main() {
  int a = 1, b = 2;
  swap(a, b);
  cout << "a = " << a << ", b = " << b << endl;
}
```

### Call-by-pointer example
```
void swap(int *x, int *y) {     // swap(int* x, int* y)
   int temp;
   temp = *x;   // save the value at address x
   *x = *y;     // put y into x
   *y = temp;   // put x into y
   return;      // x and y are really swapped.
}

int main() {
  int a = 1, b = 2;
  swap(&a, &b);
  cout << "a = " << a << ", b = " << b << endl;
}
```

### Call-by-reference example
```
void swap(int& x, int& y) {    // swap(int &x, int &y)
   int temp;
   temp = x;  // save the value at address x
   x = y;     // put y into x
   y = temp;  // put x into y
   return;    // x and y are really swapped.
}
int main() {
  int a = 1, b = 2;
  swap(a, b);
  cout << "a = " << a << ", b = " << b << endl;
}
```
With a call-by-reference, the _variable_ (not the value of the variable) is substituted for the formal parameter. A type followed by an ampersand is a reference type. For example, `int&` is a reference to an `int`. when passing an argument to a function that takes reference type, the object is truly passed by reference. There are no pointers involved, no copying of objects, no nothing. The name inside the function actually refers to exactly the same object that was passed in.

__JoyQuiz__: What is the output of the following program?
```
#include <iostream>
using namespace std;

void whatIsOutput(int& x, int y, int& z);

int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    whatIsOutput(a, b, c);
    cout << a << " " << b << " " << c << endl;
    return 0;
}

void whatIsOutput(int& x, int y, int& z) {
    cout << x << " " y << " " << z << endl;
    x = 1;
    y = 2;
    z = 3;
    cout << x << " " << y << " " << z << endl;
```


### References:
http://www.dcs.bbk.ac.uk/~roger/cpp/week3.htm

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
