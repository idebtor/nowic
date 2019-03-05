// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com 
//
// Write a C++ Object-Oriented program to store quiz score of n number
// of students and display it where n is the number of students entered
// by user.
//
#include <iostream>
#include <cstring>
#include "nowic.h"
using namespace std;

class Scores {
  int		num;
  double	*ptr;

public:
  Scores() {
	cout << "...constructor...\n"
  }
  ~Scores() {
	  cout << "...destructor...\n"
    delete[] ptr;
  }

  acquire() {
	  cout << "your code here\n";
  }

  display() {
	  cout << "your code here\n";
  }
};

int main() {
  Scores quiz;
  quiz.acquire();
  quiz.display();
  return 0;
}
