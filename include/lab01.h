#pragma once
// Note: 
// A header file only has to be written once, and it can be included 
// in as many files as needed. This also helps with maintenance by 
// minimizing the number of changes that need to be made if a 
// function prototype ever changes (eg. by adding a new parameter).
// Header files consist of two parts. The first part is called a 
// header guard, it prevents a given header file from being 
// #included more than once in the same file.
// The second part is the actual content of the.h file, which 
// should be the declarations for all of the functions we want 
// other files to be able to see. Our header files should all 
// have a .h extension, so we¡¯ll call our new header file add.h:
//
// Have the header guard, #ifndef, unless #pragma once
// By the way, some compilers don't support #pragma. 
//
// This is start of the header guard.  
// LAB01_H can be any unique name.  
// By convention, we use the name of the header file.
#ifndef LAB01_H
#define LAB01_H

// declare the function prototypes for add.h 
int add(int x, int y);	// don't forget the semicolon!

// This is the end of the header guard
#endif					
