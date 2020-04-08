// infixDriver.cpp, infix.cpp:
//
// The program evaluates and tests a given infix expression which
// is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding,
// however, the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.02	Creation
//
#include <iostream>
#include <string>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int evaluate(string token);

int main() {
	setvbuf(stdout, nullptr, _IONBF, 0);  // prevents output from buffered on console.
#if 1
	string exp;
	while (true) {
		cout << "\nExample: (1 + 3), (1 - 4), 2 * ((34 - 4) * 2)";
		cout << "\nEnter fully parenthesized infix exp.(q to quit): ";
		getline(cin, exp);
		if (exp[0] == 'q') break;
		cout << exp << " = " << evaluate(exp) << endl;
	};
#endif

#if 1
	int out;
	cout << "Step 1: Simple cases[-2, 9, 6]" << endl;
	string infix1[] = {"1 - 3", "1 - (2 * 5)", "( ( 3 - 1 ) * 5 ) - 4)"};
	for (auto exp: infix1) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}

	cout << "Step 2: Multi-digits operand[230,60]" << endl;
	string infix2[] = {"1 + ( 234 - 5 )", "( 12 - 8 ) * ( 45 / 3 )"};
	for (auto exp: infix2) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}

	cout << "Step 3: Space toleration[1000, 120]" << endl;
	string infix3[] = {"(  1 + 249 ) *4", "(1+ 23)   *5"};
	for (auto exp: infix3) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}

	cout << "Step 4: Final Testing[84, 402]" << endl;
	string infix4[] = {"2 * (( 3 - 7 ) + 46)", "(12 + (4 * 100)) - (2* 5)"};
	for (auto exp: infix4) {
		out = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << out << endl;
	}
#endif
	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}
