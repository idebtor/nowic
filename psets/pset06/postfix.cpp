// postfix.cpp :
//
// The program evaluates a given postfix expression and produces
// a fully parenthesized infix expression.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
// Author: idebtor@gmail.com
// 2020.04.05	Creation
//
#include <iostream>
#include <cassert>
// 2020.04.08	for testing purpose, the basic stack with member functions added 
//
#include <iostream>
#include <cassert>
// #include <stack>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 1
/////////////////////////////////////////////////////////////////////////////////
// a basic stack functinality only provided for pedagogical purpose
// To use STL stack, just comment out this section and inclucde <stack> above.
#include <vector>
template <typename T>
struct stack {
	vector<T> item;

	bool empty() const {
		return item.empty();
	}
	auto size() const {
		return item.size();
	}
	void push(T const& data) {
		item.push_back(data);
	}
	void pop() {
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const {
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};
///////////////////////////////////////////////////////////////////////
#endif

void printStack(stack<string> orig) {
	cout << "your code here" << endl;
}

// returns an infix expression after postfix evaluation.
string evaluate(string token) {
	stack<string> s;
	DPRINT(cout << ">evaluate(): token=" << token << endl;);

	for (int i = 0; i < token.length(); i++) {
		DPRINT(cout << " token[" << i << "]=" << token[i] << endl;);
		// current token is a whitespace or an opening brace, skip it.

		cout << "your code here\n";
	}
	DPRINT(cout << "--token exhausted---\n";);
	DPRINT(cout << "--checking the stack, its size() should be 1---\n";);
	DPRINT(printStack(s); cout << endl;);
	DPRINT(cout << "--the stack is checked---\n";);

 	// change assert to check the post condition using the stack size
	cout << "your code to check the post condition\n";
	assert(true);

	cout << "your code here\n";
	string out;

	DPRINT(cout << "<evaluate() returns "  << out << endl;);
	return out;
}
