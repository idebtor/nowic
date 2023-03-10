/**
 * @file nmn.cpp
 * @author Seongbin Kim (seongbin10209@gmail.com)
 * @brief This code is used to test good coding concepts.
 * @version 1.0
 * @date 2023-02-20
 * 
 * Note:
 * There are coding habits(required habits) that enables developers to produce/discern good code.
 * This file will touch only a few techniques so users are highly recommended to read more.
 * 
 * Links:
 * @link https://github.com/young170/Books/blob/main/Coding_Standards_101.pdf
 * @link https://github.com/young170/Books/blob/main/Clean_Code-A_Handbook_of_Agile_Software_Craftsmanship.pdf
 * 
 * Usage:
 * 	step(1). $ gcc -o "filename" nmn.cpp
 * 	- Compile the nmn.c file to produce a "filename".exe executable file.
 * 	- Run the .exe file to see how the program works.
 * 
 *  step(2). Switch #if 0 to 1
 *  - Fill in the blanks("your code here") with code applying NMN & DRY.
 * 	
 * 	step(3). Add a 11th element to the array.
 * 	- Only increase array size from 10 to 11.
 * 	- Do not change your code from the previous step.
 * 		- The program should still work.
 * 		- If it does not, rewrite your code and repeat.
 * 
 * God is good, all the time!
 * Happy Coding~~
 */
#include <stdio.h>

void printList(int *arr, int len);

#if 1

int main() {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printList(arr, 10);

	return 0;
}

#else

int main() {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printList(arr, /*your code here*/);

	return 0;
}

#endif

void printList(int *arr, int len) {
	for(int i = 0; i < len; i++) {
		printf("%d", arr[i]); printf("\n");
	}

	return;
}