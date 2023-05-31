/// 
/// Hashing is an important data structure which is designed to use 
/// a special function called the hash function. The function is used to 
/// map a given value with a particular key for faster access of elements. 
/// The efficiency of mapping depends of the efficiency of the hash 
/// function used.
/// author: idebtor@gmail.com

#include <iostream>
#include <list>
#include <utility>
#include <cassert>
#include <vector>
#include <algorithm>
#include "hash2.h"
using namespace std;

// Notice that ht is passed by reference only when its pointer may be changed inside.
// Passing by reference has not been used for speed-up the code.

void clear(Hash*& ht) {
    delete[] ht->hashtable;
    ht = new Hash{ 2 };                     // a magic number, using a small prime number 
}

int hashfunction(Hash* ht, int key) {       // hash function for int key
    return (key % ht->tablesize);
}

int hashfunction(Hash* ht, string key) {    // hash ft for strings
    int value = 0;
    for (auto x : key)
        value = 37 * value + x;

    value %= ht->tablesize;
    if (value < 0) value += ht->tablesize;
    return value;
}

int tablesize(Hash* ht) {
    return ht->tablesize;
}

// rehashes the table based on the new size.
// After the first rehash by the new size, if loadfactor >= max_loadfact, 
// rehashes using successive doubling and the next prime number.
void tablesize(Hash*& ht, int size) {
    if (tablesize(ht) != size) {
        rehash(ht, size);
        if (loadfactor(ht) >= threshold(ht))
            rehash(ht);
    }
}

int nelements(Hash* ht) {
    return ht->nelements;
}

double loadfactor(Hash* ht) {
    return (double)ht->nelements / ht->tablesize;
}

double threshold(Hash* ht) {
    return ht->threshold;
}

void threshold(Hash*& ht, double lf) {
    ht->threshold = lf;
    if (loadfactor(ht) >= threshold(ht)) rehash(ht);
}

// https://stackoverflow.com/questions/4475996/given-prime-number-n-compute-the-next-prime
bool isprime(int x) {
    for (int i = 3; true; i += 2) {
        int q = x / i;
        if (q < i) return true;
        if (x == q * i) return false;
    }
    return true;
}

int nextprime(int x) {

    if (x <= 2) return 2;
    if (!(x & 1)) ++x;
    for (; !isprime(x); x += 2);

    return x;
}

// rehashes it using the next prime of the doubled table size.
// it calls rehash(Hash*& ht, int new_size) with twice of its size
// until lf < max_lf repeatedly. 
void rehash(Hash*& ht) {
    DPRINT(cout << ">rehash: " << ht.tableisze << endl);

    while (loadfactor(ht) >= threshold(ht)) {
        rehash(ht, nextprime(tablesize(ht) * 2));
    }
    DPRINT(cout << "<rehash: " << ht.tableisze << endl);
}

// resets the table size by the new_size passed and rehashes once.
// there are two ways to implement this part. 
// 1. create a new table of the new_size, 
// 2. replace the old hashtable (or list) with the new list only and 
//    keep the original Hash structure.
void rehash(Hash*& ht, int new_size) {  
    DPRINT(cout << "rehash usersize: " << new_size << endl;);

    int old_size = tablesize(ht);
    if (old_size == new_size) return;

    // create a new table of the new_size.
    cout << "your code here\n";

    // rehashing 
    cout << "your code here\n";

    // free the old ht, ht becomes the new hash table
    cout << "your code here\n";

    cout << "\tREHASHED(tablesize: " << old_size << " -> " << new_size << ")\n";
}

// inserts key to the table and returns true always; 
// rehash()'s are automatically performed if loadfactor > threshold. 
bool insert(Hash*& ht, string key) {
    DPRINT(cout << ">insert: " << key << endl;);
    int index = hashfunction(ht, key);

    list<wordcount>::iterator it;
    // loop through this bucket to find the key. if found, increment it->second 

    cout << "your code here:" << index << endl;

    // if not found, make_pair(key, 1) and insert it to the table
    // rehash if necessary

    cout << "your code here\n";

    DPRINT(cout << "<insert: " << key << endl;);
	return true;
}

// erases the element itself and returns true if successful, false otherwise.
// if key is found, erase the element itself (instead of decrement the count).
bool erase(Hash*& ht, string key) {
    DPRINT(cout << ">erase: " << key << endl;);

    int index = hashfunction(ht, key);         // get the hash value for key 
    list<wordcount>::iterator it;              // find the key in (index)th list 

    // for loop through using it and return true when erased successfully.
    cout << "your code here:" << index << endl;

    DPRINT(cout << "<erase failed: " << key << endl;);
    return false;
}

// searches the container for key and returns the element if found,
list<wordcount> find(Hash* ht, string key) {
    DPRINT(cout << ">find: " << key << endl;);
    list<wordcount> empty_bucket;

    int index = hashfunction(ht, key);         // get the hash value for key 
    list<wordcount>::iterator it;              // find the key in (index)th list 
    if (ht->hashtable[index].size() > 0) {     // cannot use find() because of comp op
        // for loop through using it and returns the element if found
        cout << "your code here:" << index << endl;
    }

    DPRINT(cout << "<find: not found" << key << endl;);
    return empty_bucket;
}

// show the hash table; if show_n = 0, then print all buckets
// if show_empty is true, empty buckets are printed as well.
// Exceptionally, reference type of ht is used for speed-up.
void show_range(Hash*& ht, vector<int>& bucket_idx, size_t from, size_t to) {
    for (size_t i = from; i < to; i++) {
        cout << "\t[" << bucket_idx[i] << "]  ";
        for (auto x : ht->hashtable[bucket_idx[i]])
            cout << x.first << ": " << x.second << " \t";
        cout << endl;
    }
}

void show(Hash*& ht, bool show_empty, int show_n) {
    if (show_n <= 0 || show_n > tablesize(ht)) show_n = tablesize(ht);
    DPRINT(cout << "tablesize:" << tablesize(ht) << " show_empty:" << show_empty << " n:" << show_n << endl;);

    vector<int> bucket_idx;
    for (int i = 0; i < tablesize(ht); i++) { // get a list of bucket indices to show
        if (show_empty)
            bucket_idx.push_back(i);
        else
            if (ht->hashtable[i].size() > 0)
                bucket_idx.push_back(i);
    }

    std::size_t nlines_shown = bucket_idx.size();
    DPRINT(cout << "nlines_shown: " << nlines_shown << endl;);

    if (nlines_shown <= (size_t) show_n) {
        show_range(ht, bucket_idx, 0, nlines_shown);
    }
    else {
        int head_n = show_n / 2;                        // a num of buckets to show first
        int tail_x = int(nlines_shown - show_n / 2.0);    // starting index to show at tail

        DPRINT(cout << "head_n:" << head_n << "  tail_x:" << tail_x << endl;);
        show_range(ht, bucket_idx, 0, head_n);
        cout << "\t... ..." << endl;
        show_range(ht, bucket_idx, tail_x, nlines_shown);
    }
}

#if 0
int main() {
    // int hash_keys[] = { 1, 11, 12, 21, 14, 15 };       
    // string hash_keys[] = { "a", "called", "gracia", "sola", "fide", "z" };
    wordcount hash_keys[] = { {"a", 1}, {"called", 2}, {"gracia", 3}, 
        {"commissioned", 4}, {"sola", 5}, {"fide", 6}, {"z", 7} };

    int n = sizeof(hash_keys) / sizeof(hash_keys[0]);
    int tablesize = 7;

    Hash* ht = new Hash{ tablesize };

    for (int i = 0; i < n; i++)         //insert keys into hash table
        insert(ht, hash_keys[i].first);
    cout << "\n\tHash table created:" << endl;

    show(ht);

    erase(ht, hash_keys[4].first);  // erase two keys
    erase(ht, hash_keys[5].first);

    cout << "\n\tHash table after erase():" << endl;
    show(ht);
    return 0;
}
#endif