// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 1:
//  - C and C++ coding using g++
//  - a new line escape character and endl manipulator
//  - `using namespace std;`
//  - Understanding `int main(int argc, char *argv[])`
//  - Using functions and prototype
//  - Compiling multiple source files
//
// The following command line compiles a source files and builds
// an executable a.exe or with a given name. Modify it as you need.
// 		g++ hello.cpp print_strs.cpp
//		./a john paul david
//		g++ hello.cpp print_strs.cpp -o hello
//		./hello john paul david

#include <iostream>
using namespace std;

// print argc and *argv[]
// create print_strs.cpp that has the function print_strs() defined.
// make sure that two files work together.

// your code here

int main(int argc, char *argv[]) {
	cout << "argv[0] = " << argv[0] << endl;

	if (argc == 1)
		cout << "Hello World!" << endl;
	else
		;// your code here
}
