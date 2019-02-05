//  LinkedList.h
//  Created by idebtor@gmail.com on December 12, 2018.
//  This header file contains the LinkedList class declarations.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

// Node structs contain data and a pointer to the next node.
// In this project, it will represent a maker/brand combination.
struct node {
    string maker;
    string brand;
    node *next;
};

// LinkedList is a list of singly-linked nodes.
// In this project, it will represent a maker/brand list.
class LinkedList {
private:
    // Head of the list contains no maker data, but points to the maker/brand list.
    node *head;
    int len;

public:
    // Default Constructor creates the head node.
    LinkedList();
	
	bool append(node *newNode);

    // Setter adds a node to the list at a given position.
    // Takes a node and list position as parameters.
    // Position must be between 1 and the number of data nodes.
    // Returns true if the operation is successful.
    bool insert(node *newNode, int position);

    // Setter removes a node by its given position.
    // Returns true if the operation is successful.
    bool remove(int position);

    // Prints each node in the list in consecutive order,
    // starting at the head and ending at the tail.
    // Prints list data to the console.
    void printList();

    // Destructor de-allocates memory used by the list.
    ~LinkedList();
};
#endif
