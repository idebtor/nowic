# C++ for C Coder & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Pointers reviewed
So far we have only been looking at variables and objects defined at the start of the program. Now we are going to be considering objects that are explicitly created (and destroyed) during the running of the program. When we declare an `int` we reserve a portion of memory (a few bytes) that will be used to store an item of integer data. This piece of memory has an address. We can declare an integer __pointer__, `int* p`, which can contain the address of an integer - where it is found in memory.

A pointer is always a pointer to a particular type of thing: __a pointer to an int__ `int*`, __a pointer to a double__ `double*`, __a pointer to a string__ `string*`, or whatever. The type of a pointer depends on the type of thing that it points at.

## Pointer reviewed - Example 1
When you declare a pointer its value is initially undefined, that is to say, it holds some address but you don't know what address (you don't know where it's pointing), so at some stage you should assign an address to it. You do this by assigning it an already existing address or by using the keyword new as follows:
```
int z = 25;    // declare an integer and initialize it

int* p;        // declare an integer pointer
p = &z;        // make p point to z by assigning it the address of z (&z)
```

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer1.PNG" alt="Pointer reviewed" width="50%"></p>

Note that the int value is held in memory in the space assigned to `z`. `p` does not contain an integer data value, but the address of the integer `z`.

```
int* p;         // creates an integer pointer
p = new int;    // makes p point to an uninitialized memory space for int
```
Or we can do these two things in one line:

```
int* p = new int; // creates an integer pointer and makes it point at an uninitialized
                  // piece of memory that can hold integer data

```
This code:

  - Declares an integer pointer (`int* p`)
  - Allocates enough memory to hold an integer variable (`new int`) and returns its address.
  - Initializes the pointer (`p`) with the address of that piece of memory (`=`)
The value stored in this portion of memory is as yet undefined. The only way to get at it is through the pointer, and if you lose the pointer, you can't get the memory back. More about this later.

<p align="center"> <img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer2.PNG" alt="Pointer reviewed" width="30%"> </p>

So how do we put a value in the portion of memory that p points to? We apply the __dereferencing operator *__ on `p` and then we can assign a value to it:
```
*p = 25;
```

<p align="center"> <img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer3.PNG" alt="Pointer reviewed" width="50%"> </p>

__If p is a pointer, *p is the thing it is pointing at.__

We can treat `*p` in exactly the same way as we would any other integer variable, because that is what it is!

__JoyNote__: Declaring more than one pointer in one linear
```
int* p, *q; // p and q are both integer pointers
int* p, q;  // p is an integer pointer, but q is a plain old integer
```
If it is annoying you, you can always declare pointers one per line.

## Pointer reviewed - Example 2
Consider the situation created by the following code:
```
int* p = new int;    
*p = 25;             
cout << *p << endl;  
int* q;            
q = p;             
cout << *q;          
```
Complete the data structure of the code above in memory and what is the output?

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer4.PNG" alt="Pointer reviewed" width="30%"></p>

Explanation:
```
int* p = new int;    // declare an integer pointer p,
                     // create an integer in memory and make p point to it
*p = 25;             // assign the value 25 to the integer p points to
cout << *p << endl;  // print the value in the memory that p points to (= 25)
int* q;              // declare another integer pointer q
q = p;               // make it point to the same place as p points to
cout << *q;          // print the value in the memory that q points to (= 25)
```
Answer:
```
25
25
```

- Note that `new int;` declares an integer storage space in memory, `int *p` makes create a pointer to point an integer storage and `=` makes the pointer point at an integer storage.
- The line `int* q;` only declares a pointer, assigning memory space for the address of an integer, but it doesn't point anywhere (it's uninitialized) and the statement doesn't assign any memory space for the integer data.
- It is also worth noting that `q = p`; means that `q` is pointing to the same place `p` is pointing at - it does not mean that `q` is pointing at `p`. (If we wanted `q` to be a pointer to an integer pointer we would have to declare it as type `int**`.)

## Pointer reviewed - Example 3

We can write a slightly condensed version of the above code snippet(Example 2) and add a couple of more lines as follows:
```
int* p = new int(25);  // initialize the new int when creating it
cout << *p << endl;
int* q = p;            // initialize the pointer q when defining it
cout << *q;
*q = 34;
q = new int(56);
p = new int(78);
```

What is now the effect of assigning a new value to `*q` ?
```
*q = 34;
```
Since `p` and `q` are currently pointing at the same thing, any changes to `*q` will also affect `*p`.

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer5.PNG" alt="Pointer reviewed" width="20%"></p>

But `p` and `q` do not have to point at the same thing for evermore. If there was another int, we could make q point at it, or we can create a new int for q to point at:
```
q = new int(56); // creates a new integer in memory,
                 // assigns the value 56 to it and then makes q point at it
```

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer6.PNG" alt="Pointer reviewed" width="20%"></p>

Finally, we can create another integer = 78 in memory and make `p` point at it:
```
p = new int(78);
```
<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer7.PNG" alt="Pointer reviewed" width="20%"></p>

Unfortunately by moving `p` from `34` to `78` we have no way of getting back hold of `34`. We have in effect 'let go of the balloon' which is now floating in memory, taking up space which we can't re-use. This effect is known as __memory leakage__, and the piece of memory containing the `34` is known as __garbage__. The runtime systems of some languages have garbage collection built in, but C++ doesn't and you have to be careful. If you leak too much memory, the system will run out of RAM and crash!

So what do you do when you want to make a pointer point to something else? Before you let go of the object you are pointing at, you have to `delete` it. e.g.

```
delete p;        // Release the space that p is pointing to so it can be re-used
                 // by the operating system
p = new int(78); // make p point to a new variable
```
<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class03Pointer8.PNG" alt="Pointer reviewed" width="30%"></p>

If you delete the object that is being pointed at, then, unless you immediately give the pointer a new value, it is a good idea also to set the pointer to `NULL` or `nullptr` - undefined pointers are a common source of program bugs.

```
q = NULL;
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
