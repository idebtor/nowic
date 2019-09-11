/* 
 * Lecture Notes on Recursion by Youngsup Kim
 * Recursive algorithm is expressed in terms of 
 * 1. base case(s) for which the solution can be stated non‐recursively,
 * 2. recursive case(s) for which the solution can be expressed in terms 
 *    of a smaller version of itself. 
 *
 * @author: idebtor@gmail.com 
 * 2018/03/08	Creation
 * 2019/02/02	C++ Conversion
 *
 */

#include <iostream>

/* 
 * Example 1: factorial 
 * input : integer n such that n >= 0
 * output: [n ×(n - 1) ×(n - 2) × … × 1]
 *         if n is 0, return 1
 *         otherwise, return[n × factorial(n - 1)]
 * end factorial
*/

long long factorial(int n) {
	if (n == 1) return n;
	return n * factorial(n - 1);
}


/*
 * Example 2: GCD(Great Common Divisor)
 * Recurrence relation for greatest common divisor, 
 * where x%y  expresses the remainder of x/y:
 *		gcd⁡(x, y) = gcd⁡(y, x % y)    if y !=0
 *		          = gcd⁡(x, 0) = x    if y = 0
 */
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}


/*
 * Example 3: fibonacci
 * The sequence f(n) of Fibonacci numbers is defined 
 * by the recurrence relation:
 *		f(n) = f(n-1) + f(n-2)
 *		f(0) = 0, f(1) = 1
 * 0, 1, 2, 2, 3, 5, 8, 13, 21, 34, ....
 */

long long fibonacci(int n) {
	if (n == 0 || n == 1) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}


/*
 * Example 4: Bunny ears
 * We have a number of bunnies and each bunny has two big floppy ears. 
 * We want to compute the total number of ears across all the bunnies 
 * recursively (without loops or multiplication).
 *	bunnyEars(0) → 0
 *	bunnyEars(1) → 2
 *	bunnyEars(2) → 4
 *	bunnyEars(3) → 6
 *	bunnyEars(234) → 468 
 */
int bunnyEars(int bunnies) {
	if (bunnies == 0) return 0;

	// Recursive case: otherwise, make a recursive call with bunnies-1
	// (towards the base case), and fix up what it returns.
	return 2 + bunnyEars(bunnies - 1);
}


/* 
 * Example 5: Funny ears
 * We have bunnies and funnies standing in a line, 
 * numbered 1, 2, ... The odd bunnies (1, 3, ..) have the normal 2 ears. 
 * The even funnies (2, 4, ..) we'll say have 3 ears, because they each
 * have a raised foot. Recursively return the number of "ears" in the 
 * bunny and funny line 1, 2, ... n (without loops or multiplication).
 * 
 funnyEars(0) → 0
 funnyEars(1) → 2
 funnyEars(2) → 5
 funnyEars(3) → 7
 funnyEars(4) → 10
 funnyEars(9) → 22
 *
 */
int funnyEars(int funnies) {
	std::cout << "your code here\n";
	return 2;
}

/* 
 * Example 6: Triangle
 * We have triangle made of blocks. The topmost row has 1 block, 
 * the next row down has 2 blocks, the next row has 3 blocks, 
 * and so on. Compute recursively (no loops or multiplication) 
 * the total number of blocks in such a triangle with the given 
 * number of rows.
 * triangle(0) → 0
 * triangle(1) → 1
 * triangle(2) → 3
 * triangle(3) → 6
 * triangle(4) → 10
 * triangle(7) → 28
 * 
 */

int triangle(int rows) {
	std::cout << "your code here\n";
	return rows;
}


/*
 * Example 7: Sum of digits
 * Given a non - negative int n, return the sum of its digits recursively(no loops).Note that mod(%) by 10 yields the rightmost digit(126 % 10 is 6), while divide(/ ) by 10 removes the rightmost digit(126 / 10 is 12).
 * sumDigits(126) → 9
 * sumDigits(49) → 13
 * sumDigits(12) → 3
 * sumDigits(1) → 1
 * sumDigits(0) → 0
 * sumDigits(10110) → 3
 * sumDigits(235) → 10
 */
int sumDigits(int n) {
	std::cout << "your code here\n";
	return n;
}

/* 
 * Example 8: Count 8
 * Given a non-negative int n, return the count of the occurrences 
 * of 8 as a digit, so for example 818 yields 2. (no loops). 
 * Note that mod (%) by 10 yields the rightmost digit 
 * (126 % 10 is 6), while divide (/) by 10 removes the rightmost 
 * digit (126 / 10 is 12).

 * count8(818) → 2
 * count8(8) → 1
 * count8(123) → 0
 * count8(881238) → 3
 * count8(48581) → 2
 * count8(888586198) → 5
 * count8(99899) → 1
 */

int count8(int n) {
	std::cout << "your code here\n";
	return n;
}

/* 
 * Example 9: Power N
 * Given base and n that are both 1 or more, compute recursively(no loops) 
 * the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
 * powerN(2, 5) → 32
 * powerN(3, 1) → 3
 * powerN(3, 2) → 9
 * powerN(3, 3) → 27
 * powerN(10, 2) → 100
 * powerN(10, 3) → 1000
 */

long long powerN(int base, int n) {
	std::cout << "your code here\n";
	return n;
}


