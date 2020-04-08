// infixallDriver.cpp, infixall.cpp :
//
// The program evaluates and tests a given infix expression using
// Dijkstra's two-stack algorithm.
// For example:
//   (3 - 1 ) * 5 + 4
//   2 * (34 - 4) * 2
//   1 + (12 * 2) / 4 - 1
//
// Author: idebtor@gmail.com
// 2019.09.20	Creation
//
#include <iostream>
#include <string>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int evaluate(string tokens);

int main() {
	setvbuf(stdout, nullptr, _IONBF, 0);  // prevents the output from buffered on console.
#if 1
	string exp;
	while (true) {
		cout << "\nExample: 2 * ((34 - 4) * 2), (3 - 1) * 5 - 4";
		cout << "\nEnter an infix expression(q to quit): ";
		getline(cin, exp);
		if (exp[0] == 'q') break;
		cout << exp << " = " << evaluate(exp) << endl;
	};
#endif

#if 1
	int out;
	cout << "Step 1: Simple cases[-1, 13, 41]" << endl;
	string infix1[] = { "1 + 2 - 4", "3 + 4*5/2", "(1 + 2^ 3 ) * 5 - 4" };
	for (auto exp : infix1) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}

	cout << "Step 2: Multi-digits operand[60, 15, 120]" << endl;
	string infix2[] = { "(12 - 8) * 45/3", "1 + 2 * (3 * 4 - 5)", "(1 + 23)*5"};
	for (auto exp : infix2) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}

	cout << "Step 3: Final Testing[84, 402]" << endl;
	string infix4[] = { "2 * ((   3 - 7 ) + 46)  ", "(12 + (4*100)) - (2* 5)" };
	for (auto exp : infix4) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}
#endif
	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}
