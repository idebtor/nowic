//  
// file: quecir.h
// Created by idebtor@gmail.com 
// This header file contains a circula queue ADT with an optional succesive doubling.
// Things to add: Template
//

#ifndef QUECIR_H
#define QUECIR_H
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

using quecir = CircularQueue *;

quecir newCircularQueue(int capa = 4, int shown=32);      // create a new queue object
void free(quecir q);                        // deallocate queue items and queue itself
bool full(quecir q);                        // returns true when the q is full
bool empty(quecir q);                       // returns false when the q is empty
int size(quecir q);                         // returns the size of q using front/back/capa
void resize(quecir q, int new_capacity);    // sucessive doubling, O(n)
void reset(quecir q, int new_capacity);     // reset queue with a new capacity & clear queue
void enqueue(quecir q, string item);        // enqueue one item
string dequeue(quecir q);                   // dequeue one item
void clear(quecir q);                       // q->items are cleared, no change in capa 
void show_setup(quecir q);                  // display the current status of the queue
void show_queue(quecir q);
void show_items(quecir q);
#endif  
