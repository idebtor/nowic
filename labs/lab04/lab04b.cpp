// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com 
//
// Lab04 - Using new and delete operators
// Write a C++ Program to store quiz score of n number of students
// and display it where n is the number of students entered by user.
//
#include <iostream>
#include <cstring>
#include "nowic.h"
using namespace std;

int main() {
    int num = GetInt("Enter total number of students: ");
    double *ptr = new double[num];  // allocating num number of doubles

    cout << "Enter quiz scores of students." << endl;
    for (int i = 0; i < num; ++i) {
      std::stringstream prompt;
      prompt << "Student " <<  i + 1 << ": ";
      *(ptr + i) = GetDouble(prompt.str());
      /************* an alternative *************
      char prompt[64];
      sprintf(prompt, "Student %d: ", i + 1);
      *(ptr + i) = GetDouble(prompt);
      *******************************************/
    }

    cout << "\nDisplaying scores of students." << endl;
    for (int i = 0; i < num; ++i)
        cout << "Student " << i + 1 << " :" << *(ptr + i) << endl;

    delete [] ptr;   // ptr memory is released
    cout << "Happy Coding~~\n";
    return 0;
}
