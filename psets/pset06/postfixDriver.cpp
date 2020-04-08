// postfixDriver.cpp, postfix.cpp:
//
// This program evaluates and tests postfix expressions
// returns a given infix expression which is fully parenthesized.
// Author: idebtor@gmail.com
// 2020.04.05	Creation
//
#include <iostream>
#include <string>
using namespace std;

string evaluate(string tokens);

int main() {
  // prevents the output from buffered on console.
	setvbuf(stdout, nullptr, _IONBF, 0);
	string exp, out;
	while (true) {
		cout << "Example: a b +, 2 3 4 * +, ab/5+ \n";
		cout << "Enter a postfix expression(q to quit): ";
		getline(cin, exp);
		if (exp[0] == 'q') break;
		out = evaluate(exp);
		cout << "postx: " << exp << endl;
		cout << "infix: " << out << endl;
	};

	string postx[] = {"2 3 4 * +", "a b * 5 +", "1 2 + 7 *",
									 "a b c - d + / e a - * c *"};

	string infix[] = {"(2 + (3 * 4))", "((a * b) + 5)", "((1 + 2) * 7)",
										"(((a / ((b - c) + d)) * (e - a)) * c)"};
	for (auto exp : postx) {
		out = evaluate(exp);
		cout << "postx: " << exp << endl;
		cout << "infix: " << out << endl;
	}

	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}
