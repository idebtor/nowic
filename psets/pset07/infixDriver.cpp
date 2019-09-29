// infixDriver.cpp, infix.cpp: 
// 
// The program evaluates and tests a given infix expression which is fully parenthesized. 
// It uses Dijkstra¡¯s two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized. 
// For example: ((3 - 1 ) * 5) + 4, 2 * ((34 - 4) * 2), 1 + (((12 * 2) / 4) - 1)
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

	string exp;
	while (true) {
		cout << "\nExample: 2 * ((34 - 4) * 2)";
		cout << "\nEnter an infix expression(fully parenthesized, q to quit): \n";
		getline(cin, exp);
		if (exp[0] == 'q') break;
		cout << exp << " = " << evaluate(exp) << endl;
	};

	cout << "Step 1: Simple cases" << endl;
	cout << "   [-2] = " << evaluate("1 - 3") << endl;
	cout << "   [-9] = " << evaluate("1 - ( 2 * 5 )") << endl;
	cout << "    [6] = " << evaluate("( ( 3 - 1 ) * 5 ) - 4") << endl;

	/***************************************************************************
	cout << "Step 2: Multi-digits operand(or value)" << endl;
	cout << "  [230] = " << evaluate("1 + ( 234 - 5 )") << endl;
	cout << "   [18] = " << evaluate("123 - ( 21 * 5 )") << endl;
	cout << "   [60] = " << evaluate("( 12 - 8 ) * ( 45 / 3 )") << endl;

	cout << "Step 3: Space toleration" << endl;
	cout << " [1000] = " << evaluate("(  1 + 249 ) *4") << endl;
	cout << "  [120] = " << evaluate("(1+23)*5") << endl;
	cout << "  [121] = " << evaluate("1 + (24 * 5)") << endl;

	cout << "Step 4: Final Testing" << endl;
	cout << "    [6] = " << evaluate("2*((21-6)/5)") << endl;
	cout << "   [84] = " << evaluate("2 * (( 3 - 7 ) + 46)") << endl;
	cout << "  [402] = " << evaluate("(12 + (4 * 100)) - (2* 5)") << endl;
	cout << "  [591] = " << evaluate("(((2 + 4) * 100) - ( 2 *5 )) + 1") << endl;
	****************************************************************************/

	cout << "Happy Coding~~";
	return EXIT_SUCCESS;
}