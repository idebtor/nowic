// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++)      // do not change i = 0 to i = 1.
		cout << "Hello " << names[i] << "!" << endl;
}

// Add another printfunc() for function overloading 

