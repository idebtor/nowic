// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. Using vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`

#include<iostream>
using namespace std;

void printfunc(int n, char *args[]);

int main(int argc, char *argv[]) {

	// pass one less of argc and argv. Do not change printfunc()."
	cout << "Invoke printfunc() to print *argv[] except 1st one \n";
	cout << "your code here\n";

	cout << "Copy *argv[] except 1st one into vector<string> names \n";
	// use push_back() method in the vector class
	cout << "your code here\n";

	// print names only using for-loop and names
	// do not use argc/argv and ranged-for loop
	cout << "Print names using for-loop, but not argc/argv, ranged-for\n";
	cout << "your code here\n";

	// print names using printfunc(vector<string>)
	// use ranged-for loop in printfunc(vector<string>)
	// do not use `using namespace std;` in printfunc.cpp 
	// cout << "Print names using printfunc(vector<string>)\n";
	// printfunc(names);

	return 0;
}
