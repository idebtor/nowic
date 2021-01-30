// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++)
		cout << "Hello " << names[i] << "!" << endl;
}

