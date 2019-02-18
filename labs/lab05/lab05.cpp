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
  int num;
  double *ptr;

public:
  Scores() {
    num = GetInt("Enter total number of students: ");
    ptr = new double[num]; // allocating num number of doubles

    cout << "Enter quiz scores of students." << endl;
    for (int i = 0; i < num; ++i) {
      std::stringstream prompt;
      prompt << "Student " <<  i + 1 << ": ";
      *(ptr + i) = GetDouble(prompt.str());
    }
  }
  ~Scores() {
    delete[] ptr;
  }

  display() {
    cout << "\nDisplaying scores of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student " << i + 1 << " :" << *(ptr + i) << endl;
    }
  }
};

int main() {
  Scores quiz;
  quiz.display();
  return 0;
}
