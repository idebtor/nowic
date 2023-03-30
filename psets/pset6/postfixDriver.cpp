// postfixDriver.cpp, postfix.cpp:
//
// This program evaluates and tests postfix expressions
// returns a given infix expression which is fully parenthesized.
// The postfix can be evaluated if it is expressed numerically.
//
// Author: idebtor@gmail.com
//
#include <iostream>
#include <string>
using namespace std;

string evaluate(string tokens);
double evaluate_numeric(string tokens);
bool is_numeric(string tokens);

int main() {
	setvbuf(stdout, nullptr, _IONBF, 0); // prevents the output from buffered on console.
	string expr;
	while (true) {
		cout << "\nEnter a postfix expression w/ or w/o spaces."  << endl;
		cout << "e.g.:  a b +, 2 3 4 * +, ab/5+ (q to quit): ";
		getline(cin, expr);
		if (expr[0] == 'q') break;

		cout << "postfix expr: " << expr << endl;
		cout << "  infix expr: " << evaluate(expr) << endl;
		if (is_numeric(expr))
			cout << "   evaluated: " << evaluate_numeric(expr) << endl;
	};

	string postx[] = {"2 3 4 * +", "a b * 5 +", "1 2 + 7 *", "a b c - d + / e a - * c *"};
	string infix[] = {"(2 + (3 * 4))", "((a * b) + 5)", "((1 + 2) * 7)",
	                  "(((a / ((b - c) + d)) * (e - a)) * c)"};
	for (auto expr : postx) {
		cout << "postfix expr: " << expr << endl;
		cout << "  infix expr: " << evaluate(expr) << endl;
		if (is_numeric(expr)) 
			cout << "   evaluated: " << evaluate_numeric(expr) << endl;
	}

	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}
