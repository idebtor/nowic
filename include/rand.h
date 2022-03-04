// Note:
// Have the header guard, #ifndef, unless #pragma once
// By the way, some compilers don't support #pragma.
// This is start of the header guard. RAND_H can be any unique name.
// By convention, we use the name of the header file.
#ifndef RAND_H
#define RAND_H

/// It returns an extended random number of which the range is from 0
/// to (RAND_MAX + 1)^2 - 1. // We do this since rand() returns too
/// small range [0..RAND_MAX) where RAND_MAX is usually defined as
/// 32767 in cstdlib. Refer to the following link for details
/// https://stackoverflow.com/questions/9775313/extend-rand-max-range
/// this should work for PC/Windows and OSX as well.
unsigned long rand_extended();    

/// Fisher-Yates shuffle algorithm - modern 
/// This generates a random permutation of an array. 
/// This implements the Fisher-Yates shuffle "inside-out" algorithm described in 
/// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
/// To simultaneously initialize and shuffle an array, a bit more efficiency can 
/// be attained by doing an "inside-out" version of the shuffle. 
/// This returns new allocated array shuffled by the Fisher-Yates "inside-out" 
/// algorithm 
void randomize(int list[], int size);           // Fisher-Yates shuffle - modern 
int *randomize_insideout(int* list, int size);
void randomize_naive(int list[], int size);

#endif
