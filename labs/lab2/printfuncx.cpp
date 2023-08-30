// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>
#include <string>

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++)
		std::cout << "Hello " << names[i] << "!" << std::endl;
}

void printfunc(std::vector<std::string> names) {
	for (auto name: names)
		std::cout << "Hello " << name << "!" << std::endl;
}
