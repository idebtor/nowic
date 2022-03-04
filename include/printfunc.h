// This is start of the header guard.  
// PRINTFUNC_H can be any unique name.  
// By convention, we use the name of the header file.
#ifndef PRINTFUNC_H
#define PRINTFUNC_H

#include <vector>
#include <string>

// declare the function prototypes
void printfunc(int n, char *args[]);
void printfunc(std::vector<std::string> names);

// This is the end of the header guard
#endif