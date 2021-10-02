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
// 2020.10.03	Use stack<double> to handle division
//
#include <iostream>
#include <string>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

double evaluate(string tokens);

int main() {
	setvbuf(stdout, nullptr, _IONBF, 0);  // prevents the output from buffered on console.
#if 1
	string expr;
	while (true) {
		cout << "\nEnter an infix expr. w/ or w/o spaces." << endl;
		cout << "e.g.: 2 *(34-4), 12/6 + 3, (123 - 3)/20*2 (q to quit): ";

		getline(cin, expr);
		if (expr[0] == 'q') break;
		cout << expr << " = " << evaluate(expr) << endl;
	};
#endif

#if 1
	double value;
	cout << "\nStep 1: Simple cases[-1, 13, 44]" << endl;
	string infix1[] = { "1 + 2 - 4", "3 + 4*5/2", "(1 + 2^ 3 )*5-1" };
	for (auto expr : infix1) {
		value = evaluate(expr);
		cout << " infix: " << expr << endl;
		cout << "output: " << value << endl;
	}

	cout << "\nStep 2: Multi-digits operand[60, 15, 120]" << endl;
	string infix2[] = { "(12 - 8) * 45/3", "1+2 * (3*4 - 5)", "(1+23)*5"};
	for (auto expr : infix2) {
		value = evaluate(expr);
		cout << " infix: " << expr << endl;
		cout << "output: " << value << endl;
	}

	cout << "\nStep 3: Final Testing[84, 409.5]" << endl;
	string infix4[] = { "2 * ((3 - 7 ) + 46)  ", "12 + 4*100 - 5/ 2" };
	for (auto expr : infix4) {
		value = evaluate(expr);
		cout << " infix: " << expr << endl;
		cout << "output: " << value << endl;
	}
#endif
	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}
