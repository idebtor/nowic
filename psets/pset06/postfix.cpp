// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom. 
void printStack(stack<string> orig) {

	cout << "your code here" << endl;

}


// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {

			cout << "your code here" << endl;

		}
		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack

			cout << "your code here" << endl;
		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);

	cout << "your code here" << endl;

	DPRINT(cout << "<evaluate() returns " << "your expr" << endl;);
	return "your expr";
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens) {

	cout << "your code here" << endl;

	return true;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
\			// compute the expression and push the result

			cout << "your code here" << endl;

			st.push(0);
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack

			cout << "your code here" << endl;

			st.push(0);
		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(printStack(st););

	cout << "your code here" << endl;

	DPRINT(cout << "<evaluate() returns " << expr << endl;);
	return expr;
}
