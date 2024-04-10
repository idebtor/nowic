/**
Name: driver.cpp for circular queue with maxlen
Mote: allows to check the circular queue with maxlen interactively. 
Author: Youngsup Kim, idebtor@gmail.com

Description :
  - test an implementation of a circular queue with maxlen option
Things to do: 
  - add the time comlexity checking
*/

#include <iostream>
#include <sstream>
#include <string>
#include "cirque.h"

using namespace std;

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
  int min_qsize = 2;       // provide a minimum queue size

	cirque q = new CircularQueue(min_qsize);		

	do {
		cout << endl; show_qstat(q); show_items(q); show_queue(q); cout << endl; 
		cout << "\te - enqueue(s)    O(1)";     cout << "\t\tr - resize queue/maxlen\n";
		cout << "\tE - enqueue n     O(n)";     cout << "\t\tc - clear queue\n";
    cout << "\td - dequeue       O(1)";     cout << "\t\ts - show n items\n"; 
    cout << "\tD - dequeue n     O(n)\n\n";     
    
    while (true) {
      cout << "\tEnter a command[q to quit]: ";
      getline(cin, line);
      if (line.length() == 1) {
        c = line[0]; 
        if (c=='e' || c=='E' || c=='d' || c=='D' || c=='c' || 
            c=='p' || c=='r' || c=='s' || c=='q') break;
      }
    }

		switch (c) {	// execute the command
      case 'e':   // enqueue
        { // a body block necessary for compiling
          cout << "\tEnter item(s): ";
          getline(cin, line);
          istringstream tokens(line);
          while (getline(tokens, token, ' ')) {
            if (token.size()) enqueue(q, token);
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

      case 'D':  // dequeue N
        N = get_int("\tEnter a number of items: ");

        for (int i = 0; i < N; i++) 
          dequeue(q);
        break;

      case 'r':  // resize the queue items by resetting the maxlen
        while(1) {
          N = get_int("\tEnter the new maxlen of the queue: ");
          if (N < min_qsize) {
            cout << "\tThe new maxlen provided is too small: " << N << ".\n";
            continue;
          }
          if (N == q->maxlen) 
            cout << "\tThe no change in queue has bene made: " << N << ".\n";
          else 
            resize(q, N);
          break;
        }
      
        break;

      case 'c':  // simply clear the queue contents 
        if (empty(q)) break;
        clear(q);
        break;

      case 's':
        N = get_int("\tEnter the max number of items to show: ");
        if (N > min_qsize) 
          q->shown = N;
        else
          cout << "\tToo small size to limit.\n";
        break;
        
      default:
        break;
		}
	} while (c != 'q');

	delete q;

	cout << "\n\tJoyful Coding~~\n";
	return EXIT_SUCCESS;
}
