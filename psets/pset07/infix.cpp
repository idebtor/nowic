// infix.cpp : 
//
// The program evaluates a given infix expression which is fully parenthesized. 
// It uses Dijkstra¡¯s two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized. 
// For example: ((3 - 1 ) * 5) + 4, 2 * ((34 - 4) * 2), 1 + (((12 * 2) / 4) - 1)
// 
// Author: idebtor@gmail.com
// 2019.09.20	Creation
// 
#include <iostream>
#include <stack>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// Stay tuned since we are going to use C++ Template to make them into 
// one or a generic function.
// prints stack items from botton to top recursively.
void printStack(stack<int> s) {
	cout << "stack<int>: your code here\n";
}

void printStack(stack<char> s) {
	cout << "stack<char>: your code here\n";
}

// performs arithmetic operations. 
int apply_op(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

int compute(stack<int>& va_stack, stack<char>& op_stack) {
	int rigt = va_stack.top(); va_stack.pop();     // right operand first
	int left = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	int ans = apply_op(left, rigt, op);
	DPRINT(cout << " va/op_stack.pop: " << left << op << rigt << " = " << ans << endl;);
	return ans;
}

// returns value of expression after evaluation. 
int evaluate(string tokens) {
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<int>  va_stack;                 // stack to store operands or values
	stack<char> op_stack;                 // stack to store operators. 

	for (int i = 0; i < tokens.length(); i++) {
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a whitespace or an opening brace, skip it. 
		if (tokens[i] == ' ') continue;
		if (tokens[i] == '(') continue;

		// current token is a value(or operand), push it to va_stack. 
		if (isdigit(tokens[i])) { 
			int va = 0;
			// add the code to handle multi-digits value(operand) 
			va = tokens[i] - '0';
			va_stack.push(va);
			DPRINT(cout << " va_stack.push: " << va << endl;);
		} // closing brace encountered; compute it and push the result to va_stack. 
		else if (tokens[i] == ')') {  
			int answer = compute(va_stack, op_stack);
			va_stack.push(answer);
			DPRINT(cout << " va_stack.push: " << answer << endl;);
		}
		else { // current token is an operator; push it to op_stack. 
			op_stack.push(tokens[i]);
			DPRINT(cout << " op_stack.push: " << tokens[i] << endl;);
		}
	}

	printStack(va_stack);
	printStack(op_stack);

	DPRINT(cout << " Parsing finished...clear va_stack and op_stack if any." << endl;);
	// The whole expression has been parsed at this point, 
	// apply remaining op_stack to remaining va_stack. 
	while (!op_stack.empty()) {
		int answer = compute(va_stack, op_stack);
		va_stack.push(answer);
		DPRINT(cout << " va_stack.push: " << answer << endl;);
	}

	DPRINT(cout << "<evaluate" << endl;);
	// va_stack top contains the result, return it. 
	return va_stack.top();
}

