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
#include <ctime>
#include "nowic.h"
using namespace std;

long long unsigned factorial(int N);
long long unsigned fibonacci(int N);
int gcd(int a, int b);
int bunnyEars(int a);
int funnyEars(int a);
int triangle(int a);
int sumDigits(int n);
int count8(int n);
long long unsigned powerN(int base, int n);
int array10x(int *list, int a, int b);

int main() {
	int option;
	int N;
	setvbuf(stdout, NULL, _IONBF, 0); // prevent the output from buffered on console.

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
			{
				int nlist3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
				for (auto x: nlist3) 
					cout << "\tfibonacci(" << x << ") = " << fibonacci(x) << endl;
			}

			while (1) {
				N = GetInt("\tEnter a number to compute N fibonacci(0 to quit): ");
				if (N <= 0) break;
				cout << "\tfibonacci(" << N << ") = " << fibonacci(N) << endl;
			}
			break;

		case 4:
			cout << "\tBunnyEars Examples:\n";
			{
				int nlist4[] = {0, 1, 2, 3, 4, 5, 9, 123};
				for (auto x: nlist4) 
					cout << "\tbunnyEars(" << x << ") = " << bunnyEars(x) << endl;
			}
			while (1) {
				N = GetInt("\tEnter a number of Bunnies(0 to quit): ");
				if (N <= 0) break;
				cout << "\tbunnyEars(" << N << ") = " << bunnyEars(N) << endl;
			}
			break;

		case 5:
			cout << "\tFunnyEars Examples:\n";
			{
				int nlist5[] = {0, 1, 2, 3, 4, 5, 9, 123};
				for (auto x: nlist5) 
					cout << "\tfunnyEars(" << x << ") = " << funnyEars(x) << endl;
			}
			while (1) {
				N = GetInt("\tEnter a number of Funnies(0 to quit): ");
				if (N <= 0) break;
				cout << "\tfunnyEars(" << N << ") = " << funnyEars(N) << endl;
			}
			break;

		case 6:
			cout << "\tTriangle Examples:\n";
			{
				int nlist6[] = {0, 1, 2, 3, 4, 5, 9, 123};
				for (auto x: nlist6) 
					cout << "\ttrianle(" << x << ") = " << triangle(x) << endl;
			}
			while (1) {
				N = GetInt("\tEnter a row number for Triangle(0 to quit): ");
				if (N <= 0) break;
				cout << "\ttriangle(" << N << ") = " << triangle(N) << endl;
			}
			break;

		case 7:
			cout << "\tSum Digits Examples:\n";
			{
				int nlist7[] = {1, 12, 126, 235, 1000, 10110, 654321};
				for (auto x: nlist7) 
					cout << "\tsumDigits(" << x << ") = " << sumDigits(x) << endl;
			}
			while (1) {
				N = GetInt("\tEnter a number to sum digits(0 to quit): ");
				if (N <= 0) break;
				cout << "\tsumDigits(" << N << ") = " << sumDigits(N) << endl;
			}
			break;

		case 8:
			cout << "\tCount 8 Examples:\n";
			{
				int nlist8[] = {8, 9, 123, 881238, 485810, 888586198};
				for (auto x: nlist8) 
					cout << "\tcount8(" << x << ") = " << count8(x) << endl;
			}
			while (1) {
				N = GetInt("\tEnter a number to count 8(0 to quit): ");
				if (N <= 0) break;
				cout << "\tcount8(" << N << ") = " << count8(N) << endl;
			}
			break;

		case 9:
			cout << "\tPower N Examples:\n";
			{
			pair<int, int> nlist9[] = {make_pair(2, 5), make_pair(3, 1), make_pair(3, 3), 
									   make_pair(10, 3), make_pair(4, 16), make_pair(2, 32)};
			for (auto x: nlist9) 
				cout << "\tpowerN(" << x.first << "," << x.second << ") = " 
									<< powerN(x.first, x.second) << endl;
			}
			while (1) {
				int a = GetInt("\tEnter a base number(0 to quit): ");
				if (a <= 0) break;
				int b = GetInt("\tEnter a power number(0 to quit): ");
				if (b <= 0) break;
				cout << "\tpowerN(" << a << "," << b << ") = " << powerN(a, b) << endl;
			}
			break;
			
		default:
			break;
		}
	} while(option != 0);

	cout << "Happy Coding~~\n";
	return EXIT_SUCCESS;
}
