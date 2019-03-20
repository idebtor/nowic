# C++ for C Coders & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Lab5 - Object-Oriented Programming
Write a C++ object-oriented program to store quiz score of n number of students and display it where n is the number of students entered by user.

__Sample run:__
```
Enter total number of students: 4
Enter quiz scores of students.
Student 1: 4
Student 2: 3.1
Student 3: 3.9
Student 4: 2.4
```
## Specification:
  - Copy lab04b.cpp and name the file `lab05.cpp`.
  - Modify the code such that it uses a class and objects. Name the class as `Scores`.  
  - This class has two member variables, `int num` and `double *ptr`, a constructor `Scores()`, a destructor `~Scores()`, one member function `display()`.  Then it should work with the following `main()`.

```
Class Scores {
  // add member variables here - private by default

  public: // add member functions here

}; // don't forget ; after Class definition

int main() {
  Scores ds_quiz;
  ds_quiz.display();
  return 0;
}
```
#### A possible build command:
```
  g++ lab05.cpp -I../../include -L../../lib -lnowic -o lab05
```
### Tips:
When the object `ds_quiz` is created, the constructor is called and allocates the memory for `num` floating-point data. When the object goes out of scope or the program ends, destructor is automatically called.  You may put a comment line to see whether or not it is called.

-----------------------------------

### Class and object
In `Scores` example shown above, `Scores` is a class and `ds_quiz` is an object. We could say we are building an `instance` of the house described by the blueprint. If we so desire, we can build several identical houses from the same blueprint.  Each house is a separate `instance` of the house described by the blueprint. For example, we can have another instances of `c_quiz` and `cpp_quiz` which have different scores of students.

# Files to submit:
  - lab05.cpp

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
----------------------------
