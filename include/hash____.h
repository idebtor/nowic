/// Author Youngsup Kim, idebtor@gmail.com
/// 2020/11/20	Creation
#ifndef HASH_H
#define HASH_H

#include <string>
#include <list>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Hash {                              // vector<list<int>> hashtable may be used
	int         tablesize;                 // hash table size
	list<int>*  hashtable;                 // pointer to an array of buckets 
	int         nelements;                 // number of elements in table
	double      threshold;                 // max_loadfactor 

	Hash(int size = 2, double lf = 1.0) {  // a magic number, use a small prime 
		tablesize = size;                  // using list<int> for a pedagogical purpose
		hashtable = new list<int>[size];   // but vector<list<int>> may be used
		nelements = 0;
		threshold = lf;                    // rehashes if loadfactor >= threshold
	}
	~Hash() {
		delete[] hashtable;
	}
};

// Notice that ht is passed by reference when its pointer may be changed inside.
// Passing by reference has not been used for speed-up the code.
int hashfunction(Hash* ht, int key);        	// hash function for int key
int hashfunction(Hash* ht, string key);     	// hash function for string key
void rehash(Hash*& ht);							// rehashes - doubles its tablesize
list<int> insert(Hash*& ht, int key);			// inserts key & rehashes if loadfactor>threshold
list<int> find(Hash*& ht, int key);	            // returns its list if found
int erase(Hash* ht, int key);					// erases key, return 1 if successful
void clear(Hash*& ht);							// clear the table

void show(Hash* ht, bool show_empty=true);		// show the table

int nextprime(int x);							// returns the next prime 
int tablesize(Hash* ht);						// returns the table size
int nelements(Hash* ht);						// returns number of elements in table
double loadfactor(Hash* ht);					// returns nelements/tablesize
double threshold(Hash* ht);						// returns threshold(or max_loadfactor)
void threshold(Hash* &ht, double th);			// sets threshold and rehash() if needed
#endif