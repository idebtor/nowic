# C++ for C Coder & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Pointer linked
If you create classes that contain pointers you can set their pointers to point to other objects that in turn point to other objects, creating long chains called __data structures__. For example, consider this simple `Node` class that contains a data field that can point to another `Node` object:

```
class Node {  
public:
  int   n;
  Node* next;
};
```

This is a simple form of `class`, containing only data items, and all public.  The `class` is just another name for `struct`. Only difference is that things in `class` is `private` by default, but things in `struct` is `public` by default.

In this case we are choosing not to use many features in C++ class or struct. Objects of this class are simply aggregations of data, without any functionality. Having defined a `Node class`, we can define a variable of type `Node*`:

```
int main( ) {  
  // declare a Node pointer, p, and assign space for a new  
  // Node and make p point at it
  Node* p = new Node;    

}
```
__JoyQuiz__: Draw a memory diagram for this code.

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class04Pointer1.PNG" alt="Pointer reviewed" width="30%"></p>

This notation can be simplified as shown below:

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class04Pointer2.PNG" alt="Pointer reviewed" width="30%"></p>

Now, how can we initialize the data members of the `Node *p`? The code snippet like
```
*p.n = 5;
```
looks a good bet, but unfortunately the rules of precedence mean that this is interpreted as:
```
*(p.n) = 5;
```
which makes no sense as we do not have an object called p with a pointer member called n. So we have to use brackets to force the order of evaluation:
```
(*p).n = 5;
```
In C++ this is a very common operation so there is an operator that performs the same action, `->`:
```
p->n = 5;        // sets the integer member of *p to 5
p->next = NULL;  // sets the pointer member of *p to NULL
```

In general, `ptr->mem` picks out the member `mem` of the object pointed at by `ptr`.

Now let's create a `new Node q` and make `p` point at it:
```
Node* q = new Node;
q->n = 3;
q->next = NULL;
p->next = q;        // *p's link field now points to *q
```
This is the situation in memory:

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class04Pointer3.PNG" alt="Pointer reviewed" width="30%"></p>

By stringing many of these Node objects together we can create a structure called a __singly-linked list__.

## Example (Linked01.cpp)
```
#include <iostream>
using namespace std;

class Node {  
public:
  char ch;
  Node* link;
};

int main( ) {  
  Node* p = NULL, *q = NULL;
  char ch;
  while (cin.get(ch) && ch != '\n') {  
    p = new Node;
    p->ch = ch;
    p->link = q;
    q = p;
  }
  while (p != NULL) {  
    cout.put(p->ch);
    p = p->link;
  }
  cout << endl;
}
```

Singly-linked lists are chains of nodes, each containing a pointer to the next item in the list. Assuming the input A B C D to the above program and before executing of while loop,
- what would be the data structure in memory?
- What would each p and q point to ?

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class04Pointer4.PNG" alt="Pointer reviewed" width="50%"></p>

- What would while loop output?
- What would each p and q point to after while loop?

## Heap
We have in previous weeks seen three areas of memory that a C++ program makes use of. The first, obviously, is the area where the program's executable code resides. Then there is the part of memory reserved for __static__ (as opposed to auto) variables; these are globals and local statics that remain throughout the life of the program. Then there is the system stack that holds parameters and local auto variables - the ones that are local to functions and which come into existence when a function begins and disappear when it finishes.

Dynamic data structures are supported by yet another area of memory, the __heap__. This is a large area of currently unused memory that the system can allocate to your program when you call the __new__ function. The word "heap" is chosen to indicate that there is no particular relationship between one piece of allocated memory and another - they might be next to each other in memory or they might be miles apart. It's as though there is a big heap of memory and you just get given a chunk. When you do a delete, it just gets thrown back on the heap, and could be reallocated in response to another new.

The system keeps track of which chunks have been allocated and which are still on the heap, but, if you lose all your pointers to a chunk that has been allocated to your program, it does not return to the heap. Hence the problem of __memory leak__.

(There is also a data structure called a heap, notably used in a sorting algorithm called heapsort. This is a quite different use of the word "heap".)

## JoyQuiz - Linked2.cpp
- This code extends the previous program(class01Linked1.cpp). Draw a diagram to represent the data structure in memory?
- What would the following program print?

```
#include <iostream>
using namespace std;

class Node {
public:
  char ch;
  Node* next;
};

int main( ) {
  Node* p = NULL, *q = NULL;
  char ch;
  cout << "Enter a few chars: "
  while (cin.get(ch) && ch != '\n') {
    p = new Node;
    p->ch = ch;
    p->next = q;
    q = p;
  }
  while (p != NULL) {
    cout.put(p->ch);
    p = p->next;
  }
  cout << endl;

  ////////////// new code from here ///////////////
  p = q;
  while (p->next != NULL)
      p = p->next;
  p->next = q;

  do {
    cout << p->ch;
    p = p->next;
  } while (p != NULL);
}
```

### References:
- [C++ FAQ — Frequently Asked Questions](http://www.parashift.com/c++-faq-lite/)
- [Bjarne Stroustrup homepage](http://www2.research.att.com/~bs/)
- [Complete reference on C++ Standard Library](http://en.cppreference.com/w/cpp)
- [C++11 main features](http://en.wikipedia.org/wiki/C%2B%2B11)
- [C++ Crash Course](https://www.labri.fr/perso/nrougier/teaching/c++-crash-course/index.html)
- [Beginning C Programming by Bluefever](https://www.youtube.com/watch?v=DWWQEmyVplU)
- [C++ Programming in One Video by Derek Banas](https://www.youtube.com/watch?v=Rub-JsjMhWY)
- [C++ Tutorial Series by Derek Banas](https://www.youtube.com/watch?v=N5HgK1bTLOg)

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
