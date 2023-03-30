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
	DPRINT(cout << ">infixDriver begins..." << endl;);
#if 1
	string expr;
	while (true) {
		cout << "\nEnter a fully parenthesized infix expr. w/ or w/o spaces." << endl;
		cout << "e.g.: 1 + 3, ((12/6) +3), (((123 - 3)/20)*2)  (q to quit): ";

		getline(cin, expr);
		if (expr[0] == 'q') break;
		cout << expr << " = " << evaluate(expr) << endl;
	};
#endif

#if 1
	double value;
	cout << "\nStep 1: Simple cases[-2, -9, 6]" << endl;
	string infix1[] = {"1 - 3", "1 - (2 * 5)", "( ( ( 3 - 1 ) * 5 ) - 4)"};
	for (auto expr: infix1) {
		value = evaluate(expr);
		cout << " infix: " << expr << endl;
		cout << "output: " << value << endl;
	}

	cout << "\nStep 2: Multi-digits operand[230,60]" << endl;
	string infix2[] = {"1 + ( 234 - 5 )", "( 12 - 8 ) * ( 45 / 3 )"};
	for (auto exp: infix2) {
		value = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << value << endl;
	}

	cout << "\nStep 3: Space toleration[1000, 120]" << endl;
	string infix3[] = {"(  1 + 249 ) *4", "(1+ 23)   *5"};
	for (auto exp: infix3) {
		value = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << value << endl;
	}

	cout << "\nStep 4: Final Testing[84, 409.5]" << endl;
	string infix4[] = {"2 * (( 3 - 7 ) + 46)", "(12 + (4 * 100)) - (5/ 2)"};
	for (auto exp: infix4) {
		value = evaluate(exp);
		cout << " infix: " << exp << endl;
		cout << "output: " << value << endl;
	}
#endif
	DPRINT(cout << "<infixDriver ends..." << endl;);
	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}
