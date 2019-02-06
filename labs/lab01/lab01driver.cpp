//
// Lab 1: Building an executable with multiple source files
//
// The following command line compiles two source files,
// looks for any include file necessary in `include` folder
// to build an executable add.exe.
//
// Build command
// 		g++ lab01.cpp lab01driver.cpp -I../../include -o add
// 		./add
//

#include <iostream>
#include "lab01.h"

// forward declaration using function prototype

int main() {
	std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
	return 0;
}
