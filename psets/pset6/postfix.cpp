// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
//
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

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

		// current token is a operator, 
		// pop two operands and evaluate them and push the result to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {

			cout << "your code here" << endl;

		}
		else {  // push the operand
			// convert token(char type) to a string type and push it to the stack

			cout << "your code here" << endl;
		}
	}

	// cout << "token exhausted: \n"
	// printStack(st);
	// stack size() should be 1.

	cout << "your code here" << endl;

	// cout << "<evaluate() returns " << "your expr" << endl;
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
		//cout << "token: " << token << endl;

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
			// compute the expression and push the result

			cout << "your code here" << endl;

			st.push(0);
		}
		else { // push the operand (digit) in a value to the stack
			   // convert token to a numeric data type and push it the stack

			cout << "your code here" << endl;

			st.push(0);
		}
	}

	//cout << "token exhausted: check the stack, its size() should be 1.\n";
	//printStack(st);

	cout << "your code here" << endl;
	double expr = 0;

	//cout << "<evaluate() returns " << expr << endl;
	return expr;
}
