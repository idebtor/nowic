#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#define BANG "!"

int main() {
  cout << "Hello World " << BANG << endl;
}
