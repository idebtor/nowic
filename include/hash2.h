///
/// author: idebtor@gmail.com
/// 
#ifndef HASH_H
#define HASH_H

#include <string>
#include <list>
#include <utility>
#include <unordered_map>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// std::pair is a STL container or class which a pair of public members called 
// 'first' and 'second'. The types of two members may be the same or different. 

typedef std::pair<string, int> wordcount;

struct Hash {                             
	int              tablesize;               // hash table size or bucket_count()
	list<wordcount>* hashtable;               // pointer to an array of buckets 
	int              nelements;               // number of elements in table or size()
	double           threshold;               // max_loadfactor

	Hash(int size = 2, double lf = 1.0) {     // a magic number, use a small prime 
		tablesize = size;                     // using list<wordcount> for pedagogical purpose
		hashtable = new list<wordcount>[size];// but vector<list<wordcount>> may be used
		nelements = 0;
		threshold = lf;                       // rehashes if loadfactor >= threshold
	}
	~Hash() {
		delete[] hashtable;
	}
};

// Notice that ht is passed by reference when its pointer may be changed inside 
// except erase() and show(). Passing by reference may help to run the code faster. 
int hashfunction(Hash* ht, int key);           // hash function for int key
int hashfunction(Hash* ht, string key);        // hash function for string key
void rehash(Hash*& ht);                        // doubles its tablesize and rehashes repeatedly if needed
void rehash(Hash*& ht, int usersize);          // resets the table by usersize passed and rehashes
bool insert(Hash*& ht, string key);            // inserts key & rehashes if loadfactor >= threshold
bool erase(Hash*& ht, string key);             // erases key and returns true if successful
list<wordcount> find(Hash* ht, string key);    // returns its bucket list if found
void clear(Hash*& ht);                         // clear the table

// reference type of ht is used here to speed-up purpose
void show(Hash*& ht, bool show_empty=false, int show_n=10); // show the table

int nextprime(int x);                          // returns the next prime 
int tablesize(Hash* ht);                       // returns the table size
void tablesize(Hash*& ht, int size);           // sets the tablesize and rehashes if needed
int nelements(Hash* ht);                       // returns number of elements in the table
double loadfactor(Hash* ht);                   // returns nelements/tablesize
double threshold(Hash* ht);                    // returns threshold(or max_loadfactor)
void threshold(Hash*& ht, double th);          // sets threshold and rehashes if needed

#endif