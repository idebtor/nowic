# C++ for C Coder & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------

# Classes

Suppose a code begins like this:

int     i;
string  s;
Car     c;

This defines three variables. The first i is just an item of data. You can do things to it, but it has no functions of its own; you can't say i.odd() It might be useful if you could test whether it was an odd number with i.odd(), but you can't. Because, it's not an object in the C++ sense; it does not have member functions.
The other two, however, are objects. One is defined as an object of the class string, which is one of the standard C++ classes. The other is an object of the class Car, defined by a coder like you. Each of these has a repertoire of member functions, which we call with the dot notation, as for example in s.length() and c.speed()

If we want objects of our own design, we have to define a class. A class definition is a complete specification of what an object of that class contains (its data members) and what it can do (its member functions, sometimes called "methods").

# A basic `Date` class
Suppose that we want to handle dates in our program. Each date will consist simply of a day and a month. We won't bother about leap years.

At the most basic level we could simply use two int variables to represent the day and the month, but, so far as the compiler was concerned, there would be no more connection between them than between any other two variables. It would be up to the programmer to remember that some changes to the day variable (such as adding a day to Jan 31) would need to be accompanied by changes to the month variable, and so on. Any linkage between the two variables would be in the code; the variables would just be separate variables.

We want the two numbers to be treated as a single unit - a date. We want to have objects in our program of type Date so that we could do things like this:

```
int main( ) {  
  Date d1;          // create a Date object and call d1
  Date d2(1, 18);   // create a Date object and set it to Jan 18.
  d1.display();     // disply them
  d2.display();
  d1.add_day();     // add a day to d1
  d1.display();     // display it
}
```

To get there we first need to define a class. We use the `class` keyword and a name. By convention, class names begin with a capital letter. The class definition follows inside curly braces, and ends with a semicolon after the closing brace (easy to forget). The definition specifies the interface and the data that the class will hold. It defines the access (read, write or none) you want the outside world to have to an object's data and methods. The public part comprises the methods (and occasionally data) you want to expose to the outside world; this is known as the interface. The private part comprises the data (and often also) methods you want to encapsulate or hide from the outside world. Encapsulated data and methods are not accessible from outside the objects.

Before we define the class, we must decide what we want to store in it and how we want to access the data:

It should hold integers representing the month and the day of the month
  - We want to be able to create an object and specify the date it represents
  - We want to be able to increment the date by one day
  - We want to be able to print the date, as for example "Dec 25"

The class definition looks like this:
```
class Date {  
private:
  int day;
  int month;
public:
  Date();
  Date(int, int);
  void add_day( );
  void display( ) const;
};
```

### The private part
Next we turn to the private part of the class declaration. Here we declare the data fields and methods we want to encapsulate. We only have two data items, `day` and `month`, both integers.

### The public part (Interface)
The first thing we usually declare for any class is its __constructor__. It's the constructor that initializes the data members. Often a class has a __default constructor__, which creates a default instance of the class, initializing its data to some default values. In this case the declaration takes the form `Date();`This is the method that will be called by code such as `Date today;` the date represented by the object it creates will be the default.

Next we define a constructor that allows us to create a Date object and specify the date it represents: `Date(int, int);` This is the method called by an initialization such as `Date d(12, 25);` or an assignment such as `today = Date(12, 25);`

The `add_day()` method will be used to add one day to the date. It takes no arguments and returns nothing. This procedure will change the data and is known as a __mutator__.

The last method declared, `display()`, also takes no arguments and returns nothing. It will be used to print the date. Since the method doesn't modify but only accesses data, it is known as an __accessor__ function. We add the keyword `const` to the declaration so the compiler knows the function should not change the data fields.

# Defining the class's methods
We now have to define these functions. Since different classes might have member functions with the same name (you can see that each of several classes might have its own `display` procedure, for example), we have to explicitly identify the class whose member function we are defining. To do this, use the __scope operator ::__. We can write the member function definitions in any order. Here we begin by defining the default constructor.

```
Date::Date() {  
  day = 1;   // we decide what the default is going to be
  month = 1;
}
```

A constructor always has the same name as the class, and it returns nothing, not even `void`.

Note that a member function has access to all the data (and functions) in the class. We just refer to day, for example, as if it were a global variable. Next we define the `add_day` function

```
void Date::add_day( ) {  
  if (is it the last day of the month?) {  
    day = 1;
    month = month % 12 + 1;
  }
  else
    day++;
}
```
This code is incomplete because we have no way yet of knowing whether it is the last day of the month. What we need is a list of integers representing days of the month – 31, 28, 31 etc (remember that we are ignoring leap years). A vector of integers would do, but it is tedious to initialise the individual elements of a vector one by one. Fortunately there is an alternative structure, called an array that is very like a vector but which can be initialised with a list of differing values all at one go. I'll say more about arrays in a later lecture. For now, all we need to know is that we can define and initialize an array of 13 constant integers, each element containing the number of days in a month, as follows:

```
const int mdays[ ] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

Why 13 elements rather than 12? As with vectors, the first element of an array is element zero, not element one. Since I want to consider January as month 1 rather than month 0, I've just put a dummy value (0) into the first element. `mdays[1]` now holds the number of days in January, `mdays[2]` February and so on to `mdays[12]`. We use the square-bracket notation, as with vectors, to refer to individual elements of an array.

Similarly we can define an array of constant strings to hold the names of the months (again putting a dummy value – this time the empty string – into element zero):

```
const string mnames[ ] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
```
For now, we'll declare these two arrays as global. We'll see in a later lecture how to improve on this.

We are now in a position to test for the last day of the month and can amend the `add_day()` function as follows:

```
void Date::add_day( ) {  
  if (day == mdays[month]) // is it last day of the month {  
    day = 1;
    month = month % 12 + 1;
  }
  else day++;
}
```
The `display()` procedure is easily defined:
```
void Date::display( ) const {  
  cout << day << " " << mnames[month] << endl;
}
```
Finally we come to the second constructor that allows us to specify the date. It could be as simple as this:
```
Date::Date(int d, int m) {
  day = d;
	month = m;
}
```
However, it's possible that the parameters might be given impossible values, such as the 50th day of the 13th month, so we might decide to test the validity of the arguments supplied. We can do so either by including the `<cassert>` library and an `assert` statement or by writing some output to the `cerr` output stream and calling the `exit` function (requires the `<cstdlib>` library)

```
Date::Date(int d, int m) {  
  assert(m >= 1 and m <= 12 and d >= 1 and d <= mdays[m]);
  // assert requires the <cassert> library
  /* alternatively we can use the exit function as follows:
  if(m < 1 or m > 12) {  
    cerr << "Invalid month: " << m << endl;      // Goes to the cerr output stream
    exit(1);                                     // Requires <cstdlib> library
  }
  if(d < 1 or d > mdays[m]) {  
    cerr << "Invalid day: " << d << endl;
    exit(1);
  }
  */
   day = d;
   month = m;
}
```

Note that `exit` is very different from `return`. Whereas `return` terminates the procedure or function and returns control to the place where it was called from, `exit` terminates the whole program.

The class and all its member functions have now been defined. We now have everything in place to compile and run our `main()` function:

```
int main( ) {  
  Date d1;
  Date d2(1, 18);
  d1.display();
  d2.display();
  d1.add_day();
  d1.display();
}
```

__Encapsulation__
The code shown below in `main()` would not be possible because of the effect of encapsulation.
```
	d1.day = 31;		// Can't be done.
                  // From outside the class there is no access to the day data-item.
```
Click [here](https://github.com/idebtor/nowicx/blob/master/c%2B%2Bcc/class01Date.cpp) to see what our class now looks like.

## Copying objects
With simple classes (where the objects do not contain explicit pointers - a topic we deal with later in the course), there are two operations that are provided and which we therefore do not have to define.

We can use a __copy constructor__. That is, we can create a new object and initialize it with an object of the same class as follows:

```
Date d1(10, 20);
Date d2(d1);        // Create d2 as a copy of d1 using copy constructor
```
And we can use assignment – we can assign one object to have the value of another:
```
Date d3;
d3 = d1;           // Give d3 the same value as d1
d2 = Date(6, 15);  // Create d2 with the value of Jun 15
```

## Overloading operators
We now have a basic Date class that works, but say we wanted to use an expression of the form `if (thisdate == thatdate) ...` If we tried this with the current `Date` class the compiler would complain: the operator `==` is not defined for the `Date` class. One way round such as in `Java` this would be to define a public member function `equals()` as follows:

```
bool equals (Date) const; // prototype in the public part of the class definition, const because accessor
...
bool Date::equals (Date dx) const {
  return month == dx.month and day == dx.day;
}  

...
if (thisdate.equals(thatdate)) ...
```

This works fine. There are a couple of things to note about this code:

- You need to use the dot operator to access the members of those objects passed as parameters (the __explicit__ parameters) but not for the members of the object whose member function is being called (the __implicit__ parameter). That is to say, if we just use the word month in this function, it refers to the `month` variable of the Date `thisdate` - the one on the left of the dot in `if (thisdate.equals(thatdate))` - whereas if we want to refer to the month variable of the explicit parameter dx (which corresponds to `thatdate` in the call) we have to say `dx.month`. If you prefer, you can make it obvious when you are referring to the implicit parameter by writing `this->month` and `this->day` instead of just month and day, so you would write return `this->month == dx.month` and `this->day == dx.day;` This is not necessary, but some people feel it makes it clearer. We will see in a later lecture what this `"this->"` actually is.
- It looks at first sight as though the references to `dx.month` and `dx.day` are breaking the rules about encapsulation. Effectively, `thisdate` is directly accessing the private data of `thatdate`. In fact it's OK because the parameter `dx` happens also to be a `Date`. Encapsulation is enforced at the level of the class, rather than at the level of the object. It's as if the compiler says, "Are we at a place in the program that has access to the private section of `Date`?" Since we are inside a member function definition belonging to the `Date` class, the answer is obviously "Yes".
However, we can go one step better than this; we can overload the `==` operator in the `public` interface so that it will give us the functionality of the `equals()` method.

However, we can go one step better than this; we can overload the `==` operator in the public interface so that it will give us the functionality of the `equals()` method.

```
bool operator== (Date) const;
...
// Now, use the ordinary == operator to define a special == for Dates
bool Date::operator== (Date dx) const {
  return month == dx.month and day == dx.day;
}
```

We have now overloaded the `==` operator for `Date`s, i.e. given it a special meaning in the context of `Date`s, so we can go ahead and say:
```
if (thisdate == thatdate) ...
```
An overloaded operator is a function that we are allowed to call like an operator. But it is still a function and, if we wanted, we could call it in the more familiar way - `if (thisdate.operator==(thatdate)) ...`

In the same way we can overload the `<` operator and use it to test whether one date is earlier than another. Here we are passing the explicit parameter as a const ref parameter; this is customary with objects since objects are likely to be large structures, for which call-by-value would be inefficient.
```
bool operator< (const Date&) const; //public declaration
...

bool Date::operator< (const Date& dx) const {  
  return month < dx.month or (month == dx.month and day < dx.day);
}
```

We need to have const twice because they state different things. In `if (thisdate < thatdate)`, the `const` inside the parameter list `(const Date& dx)` promises that this function will not change `thatdate` while the `const` at the end of the function header promises that this function will not change `thisdate`.

Note that it is only existing operators that we can overload; we cannot take any old character and turn it into an operator. Nor can we change the number of arguments that it takes or its place in the precedence table.

[Code of Date class](https://github.com/idebtor/nowicx/blob/master/c%2B%2Bcc/class01Date2.cpp)

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
