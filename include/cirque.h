//  
// file: cirque.h
// Created by idebtor@gmail.com 
// This header file contains a circula queue ADT with maxlen option of the queue.
// Things to add: Template
//

#ifndef CIRQUE_H
#define CIRQUE_H
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

struct CircularQueue {           
  string *items;          // queue item storage
  int front, back;        // set to -1 to begin with
  int maxlen;             // maxlen: total capacity of the queue, FIFO but no overflow
  string dash;            // dash - a place holder string 
  int shown;              // the max number of items to show 

	CircularQueue(int capa=4, int nitems=20) {
		items = new string[capa]; 
    dash = "-";                       // a placeholder, empty slot available
    for (int i = 0; i < capa; i++) items[i] = dash;  // marked
    front = -1;
    back = -1;
    maxlen = capa;                   // maxlen, total capacity of the cque
    shown = nitems;                  // max number of items to show
	}
	~CircularQueue() {
    delete[] items;
    cout << "\tdestructor ends^^" << endl;
  }
};

using cirque = CircularQueue *;

bool full(cirque q);                   // returns true when the q is full
bool empty(cirque q);                  // returns false when the q is empty
int size(cirque q);                    // returns the size of q using front/back/capa
void resize(cirque q, int new_capa);   // resize the queue items[] by resetting the maxlen
void enqueue(cirque q, string item);   // enqueue one item
string dequeue(cirque q);              // dequeue one item
void clear(cirque q);                  // q->items are cleared, no change in capa or maxlen 
void show_qstat(cirque q);             // show the queue status
void show_queue(cirque q);             // show queue from 'front' to 'back'
void show_items(cirque q);             // show queue items[] as it is stored
#endif    
