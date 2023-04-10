/**
Name: driver.cpp for circular queue
Mote: allows to check the circular queue functionality interactively. 
Author: Youngsup Kim, idebtor@gmail.com

Description :
  - test an implementation of a circular queue.
Things to do: 
  - add the time comlexity checking
*/

#include <iostream>
#include <sstream>
#include <string>
#include "cqueue.h"

using namespace std;

bool valid_incr(int n) {    // returns true if n - 1, 10, 100, 1000, ... 
  int rem, sum = 0;
  while (n > 0) {    
    rem = n % 10;    
    sum += rem;    
    n = n / 10;    
  }
  return sum == 1;
}

int get_int(const string prompt) {
  int N;
  string line, tokens;
  while (1) {
    cout << prompt;
    getline(cin, line);
    if (line.size() > 0) {
      istringstream tokens(line);
      tokens >> N;
      return N;
    }
  }
}

int main() {
  int N;
	char c;
  string tokens, token, line;

  int min_qsize = 4;    // provide an initial min queue size, the max n to show
  int shown = 32;       // show "shown" number items in the queue & items
	cqueue q = newCircularQueue(min_qsize, shown);		

	do {
		cout << endl; show_setup(q); show_queue(q); show_items(q); cout << endl; 
		cout << "\te - enqueue ...      O(1)";	  cout << "\tp - profile\n";
		cout << "\tE - enqueue n        O(n)";    cout << "\tr - resize method\n";
    cout << "\td - dequeue          O(1)";    cout << "\tR - reset  queue\n";
    cout << "\tD - dequeue n        O(n)\n";   
		cout << "\tc - clear            O(n)";    cout << "\ts - show n items\n\n"; 

    while (true) {
      cout << "\tEnter a command[q to quit]: ";
      getline(cin, line);
      if (line.length() == 1) {
        c = line[0]; 
        if (c=='e' || c=='E' || c=='d' || c=='D' || c=='c' ||
            c=='p' || c=='r' || c=='s' || c=='q' || c=='R') break;
      }
    }

		switch (c) {	// execute the command
      case 'e':   // enqueue
        { // a body block necessary for compiling
          cout << "\tEnter item(s): ";
          getline(cin, line);
          istringstream tokens(line);
          while (getline(tokens, token, ' ')) {
            enqueue(q, token);
          }
        }
        break;

      case 'E':  // enqueue N
        N = get_int("\tEnter a number of items: ");

        for (int i = 0; i < N; i++) {
          token = "";
          token += 'a' + rand() % 26;           // a lowercase alphabet
          enqueue(q, token);
        }
        break;

      case 'd':  // dequeue
        dequeue(q);
        break;

      case 'D':  // dequeue n
        N = get_int("\tEnter a number of items: ");

        for (int i = 0; i < N; i++) 
          dequeue(q);
        break;

      case 'r':  
        { // a body block necessary for compiling
          if (!q->doubling) {
            q->doubling = true;
            cout << "\tQueue capacity resizes by the succssive doubling. \n";
          }
          else {
            while(1) {
              N = get_int("\tEnter an increment size [1/10/100 ... ]: ");
              if (valid_incr(N)) {
                q->incr = N;
                q->doubling = false;
                cout << "\tQueue capacity resizes by " << N << ".\n";
                break;
              }
            }
          }
        }
        break;

      case 'c':  // clear
        if (empty(q)) break;
        clear(q);
        break;

      case 'R':  // Reset        
        while(1) {
          N = get_int("\tEnter a new capacity: "); 
          if (N < min_qsize) {
            cout << "\tIt must be greater then equal to " << min_qsize << ".\n";
            continue;
          }
          break;
        }
        reset(q, N);
        break;

      case 's':
        N = get_int("\tEnter a max # of items to show: ");
        if (N > min_qsize) 
          q->shown = N;
        else
          cout << "\tToo small size to limit.\n";
        break;
        
      default:
        break;
		}
	} while (c != 'q');

	free(q);
	cout << "\n\tJoyful Coding~~\n";
	return EXIT_SUCCESS;
}
