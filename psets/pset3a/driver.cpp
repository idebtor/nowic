//
// Description:	This program is written to run and test some recursion algorithms.
//
// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____YOUR NAME______
//
// To build this program:
//  g++ recursionDriver.cpp recursion.cpp -I../../include -L../../lib -lnowic -o recursion
//
// History:
// 2018/02/10	created by idebtor@gmail.com
// 2021/02/01	a set of test cases added for each function

#include <iostream>
#include <cassert>
#include "nowic.h"
using namespace std;
                   
long long unsigned factorial(int n);
int gcd(int x, int y);
// your function prototypes here

int main() {
	int option;
	int N;

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tRecursive Algorithms:\n"
			"\t1. Factorial\n"
			"\t2. GCD(Great Common Divisor)\n"
			"\t3. Fibonacci\n"
			"\t4. Bunny Ears\n"
			"\t5. Funny Ears\n"
			"\t6. Triangle\n"
			"\t7. Sum of digits\n"
			"\t8. Count 8\n"
			"\t9. Power N\n";

		switch (option = GetInt("\tCommand(0 to quit): ")) {
		case 0:
			break;
		case 1:
			cout << "\tFactorial Examples:\n";
			{
				int nlist1[] = {1, 2, 3, 4, 5, 8, 12, 15, 20};
				for (auto x: nlist1)
					cout << "\tfactorial(" << x << ") = " << factorial(x) << endl;
			}

			while (1) {
				N = GetInt("\tEnter a number to compute N factorial(0 to quit): ");
				if (N <= 0) break;
				cout << "\tfactorial(" << N << ") = " << factorial(N) << endl;
			}
			break;
		case 2:
			cout << "\tGCD Examples:\n";
			{
			pair<int, int> nlist2[] = {make_pair(9, 10), make_pair(27, 9), make_pair(54, 24), 
									   make_pair(48, 180), make_pair(111, 259),
									   make_pair(1701, 3768)};
			for (auto x: nlist2) 
				cout << "\tGCD(" << x.first << "," << x.second << ") = " 
								 << gcd(x.first, x.second) << endl;
			}

			while (1) {
				int x = GetInt("\tEnter 1st number to compute GCD(0 to quit): ");
				if (x == 0) break;
				int y = GetInt("\tEnter 2nd number to compute GCD(0 to quit): ");
				if (y == 0) break;
				cout << "\tgcd(" << x << ", " << y << ") = " << gcd(x, y) << endl;
			}
			break;

		case 3:
			cout << "\tFibonacci Examples:\n";
			// int nlist3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

			cout << "\tyour code here\n";
			
			break;

		case 4:
			cout << "\tBunnyEars Examples:\n";
			
			cout << "\tyour code here\n";
			// int nlist4[] = {0, 1, 2, 3, 4, 5, 9, 123};
			

			break;

		case 5:
			cout << "\tFunnyEars Examples:\n";
			
			cout << "\tyour code here\n";
			// int nlist4[] = {0, 1, 2, 3, 4, 5, 9, 123};
			
			break;

		case 6:
			cout << "\tTriangle Examples:\n";
			
			cout << "\tyour code here\n";
			// int nlist6[] = {0, 1, 2, 3, 4, 5, 9, 123};
			
			break;

		case 7:
			cout << "\tSum Digits Examples:\n";
			
			cout << "\tyour code here\n";
				// int nlist7[] = {1, 12, 126, 235, 1000, 10110, 654321};
			
			break;

		case 8:
			cout << "\tCount 8 Examples:\n";
			
			cout << "\tyour code here\n";
				// int nlist8[] = {8, 9, 123, 881238, 485810, 888586198};
			
			break;

		case 9:
			cout << "\tPower N Examples:\n";
			
			cout << "\tyour code here\n";
			cout << "\tuse pair in C++ for (2,5), (3,1), (3,3), (10,3), (4,16), (2,32)\n";

			break;

		default:
			break;
		}
	} while(option != 0);

	cout << "Happy Coding~~\n";
	return EXIT_SUCCESS;
}
