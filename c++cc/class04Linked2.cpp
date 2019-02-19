
#include <iostream>
using namespace std;

class Node {
public:
  char ch;
  Node* next;
};

int main( ) {
  Node* p = NULL, *q = NULL;
  char ch;
  cout << "Enter a few chars: "
  while (cin.get(ch) && ch != '\n') {
    p = new Node;
    p->ch = ch;
    p->next = q;
    q = p;
  }
  while (p != NULL) {
    cout.put(p->ch);
    p = p->next;
  }
  cout << endl;

  p = q;
  while (p->next != NULL)
      p = p->next;
  p->next = q;

  do {
    cout << p->ch;
    p = p->next;
  } while (p != NULL);
}
