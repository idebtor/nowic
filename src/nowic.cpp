/****************************************************************************
* nowic Library 2.0 - C++ Library for Data Structures and Algorithms
* Usage:
*    In your source file, add the following line.
*      #include "nowic.h"
*    In your command line during the build, add the following options
*    when you are in ../src folder.
*      -I../include -L../lib -lnowic
*
* To build static library, compile first to get nowic.o. 
* Then make an archive file called libnowic.a 
* > g++ -std=c++11 -c nowic.cpp 
* > ar rcs libnowic.a nowic.o 
* 
* To test the library, activate main() function at the bottom of the file first.
* Then build and run it as shown below:
* > g++ -std=c++11 nowic.cpp -o nowic.o
* > ./nowic
*
* 2020/12/01 Created by idebtor@gmail.com
*
* Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
* http://creativecommons.org/licenses/by-nc-sa/3.0/
***************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
using namespace std;

std::string ltrim(const std::string& s) {
	return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string& s) {
	return ltrim(rtrim(s));
}

/*** i prefer this code, but it does not work... use the code above
std::string trim(const std::string& s) {
	if (s.length() <= 0) return s;
	auto start = s.begin();
	while (start != s.end() && std::isspace(*start)) {
		start++;
	}
	auto end = s.end();
	do {
		end--;
	} while (std::distance(start, end) > 0 && std::isspace(*end));
	return std::string(start, end + 1);
}
***/

bool parseint(std::string& input, int& output) {
	try {
		output = std::stoi(input);
	}
	catch (std::invalid_argument& e) {
		cerr << e.what() << endl;
		return false;
	}
	return true;
}

bool parsefloat(std::string& input, float& output) {
	try {
		output = std::stof(input);
	}
	catch (std::invalid_argument& e) {
		cerr << e.what() << endl;
		return false;
	}
	return true;
}

bool parsedouble(std::string& input, double& output) {
	try {
		output = std::stod(input);
	}
	catch (std::invalid_argument& e) {
		cerr << e.what() << endl;
		return false;
	}
	return true;
}

/*
 * Reads a line of text from standard input and returns it as an int in
 * the range of [-2^31 + 1, 2^31 - 2], if possible; if text does not
 * represent such an int, user is prompted to retry. Leading and trailing
 * whitespaces are ignored.  For simplicity, overflow is not detected.
 * It provides a default parameter, but it can be overwritten.
 */
int GetInt(string prompt = "Enter an integer: ") {
	string str;
	int x;
	cout << prompt;
	getline(std::cin, str);
	while (!parseint(str, x)) {
		cout << "Retry - " << prompt;
		getline(std::cin, str);
	}
	return x;
}

/*
 * Reads a line of text from standard input and returns the equivalent
 * float as precisely as possible; if text does not represent a
 * float, user is prompted to retry.  Leading and trailing whitespaces
 * are ignored.  For simplicity, overflow and underflow are not detected.
 */
float GetFloat(string prompt = "Enter a floating point number: ") {
	string str;
	float x;
	cout << prompt;
	getline(cin, str);
	while (!parsefloat(str, x)) {
		std::cout << "Retry - " << prompt;
		getline(cin, str);
	}
	return x;
}

/*
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double, user is prompted to retry.  Leading and trailing whitespace
 * is ignored.  For simplicity, overflow and underflow are not detected.
 */
double GetDouble(string prompt = "Enter a floating point number: ") {
	string str;
	double x;
	cout << prompt;
	getline(cin, str);
	while (!parsedouble(str, x)) {
		cout << "Retry - " << prompt;
		getline(cin, str);
	}
	return x;
}

/*
 * Reads a line of text from standard input and returns the first char.
 * If text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored.
 * It provides a default parameter, but it can be overwritten.
 */
char GetChar(string prompt = "Enter a character: ") {
	string str;
	stringstream ss;
	cout << prompt;
	getline(cin, str);
	str = trim(str);
	while (str.length() == 0 || str.length() != 1) {  
		cout << "Retry - " << prompt;
		getline(cin, str);
		str = trim(str);
	}
	return str.c_str()[0];
}

/*
 * Reads a line of text from standard input and returns it, without newline character.
 * Leading and trailing whitespaces are not ignored. 
 * If user inputs only "\n", he/she will be asked to retry. 
 * No memory is allocated in heap, there is no need to free it.
 */
string GetLine(string prompt = "Enter a line: ") {
	cout << prompt;
	string str;
	getline(cin, str);
	str = trim(str);
	while (str.length() == 0) { // keep reading a new line while there is a blank line
		cout << "Retry - " << prompt;
		getline(cin, str);
		str = trim(str);
	}
	return str;
}

/*
 * Reads a line of text from standard input and returns the first string (or a word)
 * while ignoring the rest of texts.
 * Leading and trailing whitespaces are not ignored.
 * If user inputs only "\n", he/she will be asked to retry.
 */
string GetString(string prompt = "Enter a string: ") {
	string str;
	stringstream ss;
	cout << prompt;
	getline(cin, str);
	str = trim(str);
	while (str.length() == 0) { // keep reading a new line while there is a blank line 
		cout << "Retry - " << prompt;
		getline(cin, str);
		str = trim(str);
	}
	ss << str;
	ss >> str;
	return str;
}
// It is the same as GetString(), but a different prompt. 
string GetWord(string prompt = "Enter a word: ") {
	return GetString(prompt);
}

// For the sake of a simple testing 
#if 0
int main() {
	int i = GetInt();
	std::cout << "an int=" << i << std::endl;

	double x = GetDouble();
	std::cout << "a double=" << x << std::endl;

	char ch = GetChar();
	std::cout << "a char=" << ch << std::endl;

	std::string str = GetWord();
	std::cout << "a word=" << str << std::endl;

	str = GetLine();
	std::cout << "a line=" << str << std::endl;

	std::cout << "Happy Coding~~\n";
}
#endif