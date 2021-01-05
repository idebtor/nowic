/*
* file: hellowho.cpp
* It prints "Hello World!" or "Hello" with a given name.
* The completed code should work as shown below. “>” is a prompt of the console.
*
* To run the program without a command line argument:
*	> ./hellowho
*	> Enter a name: John Lee
*   > Hello John Lee!
*   > Enter a name: Peter Kim
*   > Hello Peter Kim!
*   > Enter a name:<Enter>
*   > Hello World!
*   >
*
* To run the program with a command line argument:
*   > ./hellowho John Peter James David Kim
*   > Hello John!
*   > Hello Peter!
*   > Hello James!
*   > Hello David!
*   > Hello Kim!
*   > Hello World!
*   >
*
* To run the program through a pipe 
* (names.txt contains a list of names as shown below:)
*   > cat names.txt | ./hellowho
*   > Enter a name: Hello john!
*   > Enter a name: Hello Dr. Lee!
*   > Enter a name: Hello Handong Global University!
*   > Enter a name: Hello Peter!
*   > Enter a name: Hello World!
*   
*	2020/02/10: Created, idebtor@gmail.com
*   2020/12/15: working in vs code
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifdef DEBUG 
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int main(int argc, char *argv[]) {
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	DPRINT(cout << "DEBUG is defined.............\n";);

	if (argc > 1) {
		for (int i = 1; i < argc; i++)
			cout << "Hello " << argv[i] << "!\n";
	}
	else {
		while (1) {
			string line;
			cout << "Enter a name: ";
			getline(cin, line);
			if (line.length() == 0) break;
			cout << "Hello " << line << "!\n";
		}
	}

	cout << "Hello World!\n";

	// Use system("pause"); to prevent the terminal from disappearing
	// as soon as the program terminates such as Visual Studio sometimes.
	// system("pause");
	return EXIT_SUCCESS;
}
