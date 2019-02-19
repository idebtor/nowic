# C++ for C Coder & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------

## More on arrays
A one-dimensional array is like a one-dimensional vector; it's a row of items of the same type in which you can refer to individual items with the square-bracket notation. You could define an array of, say, seven integers as follows:
```
int foo[7];
```
The compiler would reserve enough storage for seven contiguous integers, and you could refer to these as `foo[0]`, `foo[1]` and so on up to `foo[6]` (the first element is always element zero). Note that, when you are defining an array, as above, `foo[7]` does not mean "element seven of the array foo", but rather, "I want an array of seven elements, called foo."
Given the above definition, the individual integers in `foo` would have undefined values. You could initialize the values – and this is a feature of arrays that vectors don't have – as follows:
```
int foo[7] = {42, -5, 68, 91, 3, 1002, 12};
```
Or you might want to initialize just the first few elements:
```
int foo[7] = {42, -5, 68, 91};
```
in which case the remaining elements would be initialized to zero.
If you don't do any initialization, you get undefined values, but, if you initialize any of the elements, even if it's only the first one, then all the rest get initialized to zero. So you could initialize the whole lot to zero with just:
```
int foo[7] = {0};
```
If you initialize all the values explicitly, you don't have to specify the length of the array. You could define `foo` as follows:
```
int foo[ ] = {42, -5, 68, 91, 3, 1002, 12};
```
In this case, the compiler calculates the length of array on the basis of the initialization.
Arrays are not objects in the C++ sense – there is no array class (as there is a vector class and a string class). So they don't have any functionality. We cannot say things like `foo.size()` or `foo.push_back(77)` The length of an array is fixed at compile time; you cannot grow it or shrink it during the run of the program, as you can with vectors.

# A simple Stack class
A linear list is, conceptually, just a series of items one next to another. A __stack__ is a linear list where you are limited to putting an item on the stack (known as "pushing") or taking an item off the stack (known as "popping") and where both these operations take place at the same end of the list. It's sometimes called a __LIFO__ list (Last In First Out). It is one of the fundamental data structures widely used in programming.

The following is one possible implementation of a stack, which uses an array to store the items (here integers, but, in principle, items of any type):
```
const int MAX = 10;

class Stack {
private:
  int	a[MAX+1];  // we won't be using a[0]
  int	top;       // "stack pointer"
public:
  Stack();
  void push(int);
  int pop();
};

Stack::Stack() {
  top = 0;
}

void Stack::push(int x) {
  if (top >= MAX) {
    cerr << "Stack overflow!" << endl;
		return;
	}
	top++;
	a[top] = x;
}

int Stack::pop() {
  if (top == 0) {
    cerr << "Stack underflow!" << endl;
		return 0;
	}
	int	returnval = a[top];
	top--;
	return returnval;
}
```

# A simple Queue class
The queue, another fundamental data structure, is also a linear list with restricted access, but, this time, items are added to the queue at one end but removed at the other – a __FIFO__ (First In First Out) list.

```
class Queue {
private:
  int	a[MAX+1];         // we won't be using a[0]
  int	front, rear, n;   // n = number of items in the queue
public:
  Queue();
  void add(int);
  int remove();
};

Queue::Queue() {
  n = 0;
	front = rear = 1;  // any value >= 1 and <= MAX
}

void Queue::add(int x) {
  if (n == MAX) {
    cerr << "Queue overflow!" << endl;
		return;
	}
	n++;
	rear = (rear == MAX ? 1 : rear + 1);
	a[rear] = x;
}

int Queue::remove() {
  if (n == 0) {
    cerr << "Queue underflow!" << endl;
		return 0;
	}
	n--;
	front = (front == MAX ? 1 : front + 1);
	return a[front];
}
```
This implementation of the queue is perhaps less intuitively obvious than that of the stack. When people are in a queue (for tickets, say) and someone at the front gets their ticket and leaves, the whole queue shuffles forwards. In this array implementation, however, there is no shuffling forwards, so the whole queue, in a sense, moves backwards through the array, as items are added to the rear and removed from the front. When the rear has reached `a[MAX]`, the next addition is at `a[1]` (assuming it has been vacated by items leaving the queue). The effect is that the queue, so long as it does not overflow, moves round and round the array.

## static const int
In the above, I defined the `const int` as a global. Although this will work, it seems unsatisfactory since the length of the array is a feature of the data structure used by the objects of type `Stack` or `Queue`. In other words, this `const int` ought to be private to these classes, just as the array definitions are. We can make it private to our Stack definition as follows (and we could do the same for the Queue):
```
private:
	static const int MAX = 10;
	int	a[MAX+1];  // we won't be using a[0]
	int	top;       // "stack pointer"
```
Defining it as "static" means that it belongs to the class as a whole rather than to individual objects of that class. If we had several objects of type `Stack` in our program, then each of them would have its own array and its own top variable, but they would all share a single `const int`.
You can have static variables, as well as static constants. For example, a class that dealt with currency exchange might have an `exchange_rate` variable. This would be a variable – it would change from time to time – but you would not want different objects of the class to have different values of it. You would want them all to share the same, current value, and you could ensure this by making it static. With variables, you can decide whether to make them static or not, but with constants you have no choice – they have to be `static`. (It is actually only constants of integral type that you can define within the class definition, as in the example above; you can have private, static constants of other types but defining them is more long-winded, as we'll see in a later lecture.)

# Mixing signed and unsigned values
When you compile programs containing expressions such as `int i < s.length()` or `int i < v.size()`, some compilers may give you a warning about comparing signed and unsigned values. What is it warning you about?

The compiler warning is about comparing signed and unsigned values. The first thing we need to know is that `s.length()` and `v.size()` return unsigned integers. This is reasonable since the length of a string, or the size of a vector, can never be negative.

The second thing we need to know is that, if you do arithmetic using a signed and an unsigned integer, the result is unsigned. This is probably not what you would expect. Suppose you had an expression such as `s.length() - 1` and suppose that the string was empty. Let's do it with our six-bit integers:

```
s.length()                  0  000000
- 1, which converts to   + -1  111111
=                              111111  which is -1 as a signed int, but 63 as an unsigned int
```

So, if this was part of a for loop, such as for `(int i = 0; i < s.length() - 1; i++)` and the string `s` was empty, the condition being evaluated would not be `0 < -1` (therefore false, which is what you'd expect), but `0 < 63` (therefore true).
The same applies when you are simply comparing a signed value with an unsigned one; the signed value gets converted to unsigned before the comparison takes place. Suppose you had the following:

`cout << (-1 < v.size() ? "Yes" : "No") << endl;`

You might expect this to output "Yes" whatever the size of `v`, since `-1` is obviously less than zero or any positive integer, but the reverse is the case. Because `v.size()` returns an unsigned int, the value `-1` is converted to unsigned for the comparison. Since `-1` is all ones in two's complement, this converts to a very large unsigned int.

So, the compiler warning is telling you to be careful. If all parts of the expression are always going to evaluate to zero or more, as in, for example for `(int i = 0; i < s.length(); i++)`, you will not have a problem. But, if there is any chance that any part of the expression will yield a negative value (as a signed int), which will therefore be interpreted by the computer as a very large unsigned int, you might be in trouble.

The solution to this problem is to cast the unsigned value into a signed one, with `static_cast<int>(unsigned value)`, as in this example:

`for (int i = 0; i < static_cast<int>(s.length()) - 1; i++)`

The effect of this is to type-convert the zero returned by `s.length()` from an `unsigned int` to a `signed int`, so that the evaluation of `0 - 1` yields `-1`, which is what you want.
There is an old-style form of cast, inherited from C, which looks like this:

`for (int i = 0; i < (int)s.length() - 1; i++)`

However, this is __deprecated__. That is to say, it is retained in the language in order to preserve compatibility with previous versions, but it is considered an undesirable feature and programmers are urged not to use it. The reasons for its undesirability are that ill-considered type casts are a cause of subtle bugs and they don't stand out clearly to someone reading the program. Typing out the `static_cast` rigmarole, by contrast, forces a moment of reflection, and it stands out on the page like a sore thumb.

One final point. Some students take to writing for `(unsigned int i = 0; i < s.length() - 1; i++)` and, because the compiler stops giving them a warning, they think they have dealt with the problem. But of course they haven't. The compiler stops giving its warning because now both i and `s.length() - 1` are unsigned int, so they are not mixing the types. But, if s was empty, `s.length() - 1` would still be a very large number. It's the type of `s.length()` that needs to be modified, not the type of i.


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
