//  
// file: cqueue.h
// Created by idebtor@gmail.com 
// This header file contains a circula queue ADT with an optional succesive doubling.
// Things to add: Template
//

#ifndef CQUEUE_H
#define CQUEUE_H
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

struct CircularQueue {
  string *items;
  int front, back;
  int capa;           // total capacity of the queue
  string dash;        // dash - a place holder string 
  bool doubling;      // if true, increase capacity by 2x, otherwise by 10
  int incr;           // if doubling is false, increase capacity by incr
  int shown;          // the max number of items to show 
};

using cqueue = CircularQueue *;

cqueue newCircularQueue(int capa = 4, int shown=32);      // create a new queue object
void free(cqueue q);                        // deallocate queue items and queue itself
bool full(cqueue q);                        // returns true when the q is full
bool empty(cqueue q);                       // returns false when the q is empty
int size(cqueue q);                         // returns the size of q using front/back/capa
void resize(cqueue q, int new_capacity);    // sucessive doubling, O(n)
void reset(cqueue q, int new_capacity);     // reset queue with a new capacity & clear queue
void enqueue(cqueue q, string item);        // enqueue one item
string dequeue(cqueue q);                   // dequeue one item
void clear(cqueue q);                       // q->items are cleared, no change in capa 
void show_setup(cqueue q);                  // display the current status of the queue
void show_queue(cqueue q);
void show_items(cqueue q);
#endif  
