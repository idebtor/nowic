# C++ for C Coder & Data Structures
Lecture Notes by idebtor@gmail.com
-------------------
# Adding nodes to a list
Let's go back to our basic Node class and create three Node* pointers head, x and y.
```
class Node  {
  public:
  int n;  
  Node* next;
};

...
Node* head, *x, *y;
```
At this point head, x and y are not pointing anywhere as they have not been initialized. Let us imagine now that we have created a linked list, where head points to the head of the list and x at the last item in the list (i.e. the one with the null pointer).

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked01.PNG" alt="Linked reviewed" width="50%"></p>

# push_front: adding at the head of the list
Let us imagine that we have created a linked list, where head points to the head of the list and x at the last item in the list (i.e. the one with the null pointer) as shown below.

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked02.PNG" alt="Linked reviewed" width="50%"></p>

Now, we want to add a node (n = 33) at the head of list.
- create a node and initialized with `n = 10`.
- let `head` point to the new node

```
y = new Node;
y->n = 33
y->next = head;
head = y;
```
This works perfectly well even if the list is empty (i.e. the head pointer is NULL).

# push_back: adding at the tail of the list
Let us imagine that we have created a linked list, where head points to the head of the list and x at the last item in the list (i.e. the one with the null pointer) as shown below.

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked03.PNG" alt="Linked reviewed" width="50%"></p>

If we have a pointer to the tail node of the list, then adding a new node at the tail end is easy:

```
y = new Node;
y->n = 33
y->next = NULL;
x->next = y;
```

However, quite often the only list pointer we have access to is the head pointer.
Now, let's add a node (n = 33) at the end of list, where only head of the list is given as shown below.

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked04.PNG" alt="Linked reviewed" width="50%"></p>

To get to the tail we have to scroll along the list until the end. We want a pointer that will stop while still pointing at the last node. Thus our termination condition is that the node's next field is NULL. Once we have a pointer to the end of the list, we can make it point to the node we want to add:

```
y = new Node;
y->n = 33
y->next = NULL;
x = head;
while (x->next != NULL)   
  x = x->next;
x->next = y;
```
# pop_front: remove the first node of the list
We want to remove the first node or move head to the next node.

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked05.PNG" alt="Linked reviewed" width="50%"></p>

When removing a node, beware of memory leak; remember to give yourself a pointer to the node that is about to be removed before you lose your pointer to it:

```
Node* zap = head;
head = head->next;
delete zap;
```
The result of the code above is shown below:

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked06.PNG" alt="Pointer reviewed" width="50%"></p>


# insert() - adding nodes in the middle of the list
The next trick is to add a node between two others. We have to make one node point to the new one, and the new node point to the next in the list. Assuming that x is pointing at the '99' node, then to add a node after 99 we use the following code:

```
y->next = x->next;   // make the new node point at the 27 node
x->next = y;         // make the 99 node point at the new node
```

To perform the same operation, but starting from the head node, we have to stop at the node before the insertion point. Remember that a singly-linked list is a one way street!

```
x = head;
while (x->n != 99)   // assumes that head is not NULL, there is a 99 in the list
x = x->next;
y->next = x->next;
x->next = y;
```
<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked07.PNG" alt="Linked reviewed" width="50%"></p>

# Remove() - removing nodes from the middle of a list
To remove a node from a list we have to do three things:

  1. use a handle pointer to keep hold of the unwanted node
  2. make the node before the unwanted node point to the node after the unwanted node
  3. delete the unwanted node

The order here is VERY important.

  - If you don't use the 'handle' pointer, the unwanted node will 'float away' when you close the gap, causing a memory leak.
  - If you delete the unwanted node before closing the gap, you will lose the pointer to the bottom end of the list.

Let's assume that we want to delete the '99' node. To make the example easier, let's assume that there is a '99' node in the list, that it is not the head node, and that there are at least two nodes in the list. (In a real program, you cannot make such assumptions, of course.) The code for removing the '99' node is as follows:
```
x = head;
while (x->next->n != 99)    // stop when you get to the
    x = x->next;            // node before 99
Node* zap = x->next;
x->next = zap->next;
delete zap;                 // avoid memory leakage
```
The above code will work, but expressions such as x->next->n are not recommended. It is hard to keep track of what exactly you are doing if you reference the node beyond the one you are pointing at. This would be better:

```
Node* x = head, *zap = head->next;	// we're assuming at least two nodes and 99 is not the head node
while(zap->n != 99) {		// we're assuming there is a 99 node
  x = zap;
	zap = zap->next;
}
// Now we've found it. zap points at it, x at the one before.
x->next = zap->next;
delete zap;
```

<p align="center"><img src="https://github.com/idebtor/nowic/blob/master/img/class05Linked08.PNG" alt="Linked reviewed" width="50%"></p>

### References:
- [C++ FAQ — Frequently Asked Questions](http://www.parashift.com/c++-faq-lite/)
- [Bjarne Stroustrup homepage](http://www2.research.att.com/~bs/)
- [Complete reference on C++ Standard Library](http://en.cppreference.com/w/cpp)
- [C++11 main features](http://en.wikipedia.org/wiki/C%2B%2B11)
- [C++ Crash Course](https://www.labri.fr/perso/nrougier/teaching/c++-crash-course/index.html)
- [Beginning C Programming by Bluefever](https://www.youtube.com/watch?v=DWWQEmyVplU)
- [C++ Programming in One Video by Derek Banas](https://www.youtube.com/watch?v=Rub-JsjMhWY)
- [C++ Tutorial Series by Derek Banas](https://www.youtube.com/watch?v=N5HgK1bTLOg)

----------------------------
_One thing I know, I was blind but now I see. John 9:25_
