/// 
/// Hashing is an important data structure which is designed to use 
/// a special function called the hash function. The function is used to 
/// map a given value with a particular key for faster access of elements. 
/// The efficiency of mapping depends of the efficiency of the hash 
/// function used.
/// Author: idebtor@gmail.com

#include <iostream>
#include <cassert>
#include <list>
#include <algorithm>
#include "hash1.h"
using namespace std;

// Notice that ht is passed by reference only whenever its pointer may be changed inside.
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
    DPRINT(cout << "next_prime: " << x;);

    if (x <= 2) return 2;
    if (!(x & 1)) ++x;
    for (; !isprime(x); x += 2);

    DPRINT(cout << " --> " << x << endl;);
    return x;
}

// rehashes the hash table using successive doubling scheme and the next prime
// The hash table doubles its size but still prime. 
void rehash(Hash*& ht) {
    DPRINT(cout << "rehash: " << endl;);

    // create new double-sized and emtpy table, use nextprime()
    int old_size = tablesize(ht);
    int new_size = 0;
    cout << "your code here\n";

    // free old ht, then set the new ht
    cout << "your code here\n";

    cout << "\tREHASHED(tablesize: " << old_size << " -> " << new_size << ")\n";
}

// inserts key to the table and returns true always; 
// rehash()'s are automatically performed if loadfactor >= threshold. 
bool insert(Hash*& ht, string key) {
    DPRINT(cout << ">insert: " << key << endl;);
    int index = hashfunction(ht, key);
    ht->hashtable[index].push_back(key);
    ht->nelements++;

    // invoke rehash() only if necessary
    cout << "your code here\n";

    DPRINT(cout << "<insert: " << key << endl;);
	return true;
}

// erases key and returns true if successful and false if unsuccessful
bool erase(Hash*& ht, string key) {
    DPRINT(cout << ">erase: " << key << endl;);

    // get the hash value for key and set the iterator variable: it 
    cout << "your code here\n";
                                        
    // for loop using it, then return true if erased successfully.
    
    cout << "your code here\n";

    DPRINT(cout << "<erase failed: " << key << endl;);
    return false;
}

// searches the container for key and returns the bucket list to it if found,
list<string> find(Hash* ht, string key) {
    DPRINT(cout << ">find: " << key << endl;);
    list<string> empty_bucket;

    int index = hashfunction(ht, key);    // get the hash value for key 
    if (ht->hashtable[index].size() > 0) {

        cout << "your code here\n";       // return the bucket list
    }

    DPRINT(cout << "<find: not found" << key << endl;);
    return empty_bucket;
}

// if show_empty is true, empty buckets are printed as well.
void show(Hash*& ht, bool show_empty) {
    cout << endl;
    for (int i = 0; i < tablesize(ht); i++) {
        if (ht->hashtable[i].size() > 0) {
            cout << "\t[" << i << "]  ";
            for (auto x : ht->hashtable[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
        else if (show_empty) {
            cout << "\t[" << i << "]  ";
            cout << endl;
        }
    }
}

#if 0
int main() {
    // int hash_keys[] = { 1, 11, 12, 21, 14, 15 };       
    string hash_keys[] = { "a", "called", "gracia", "commissioned", "sola", "fide", "z" };

    int n = sizeof(hash_keys) / sizeof(hash_keys[0]);
    int tablesize = 7;

    Hash* ht = new Hash{ tablesize };

    for (int i = 0; i < n; i++)            //insert keys into the hash table
        insert(ht, hash_keys[i]);
    cout << "Hash table created:" << endl;
    show(ht);

    erase(ht, hash_keys[4]);
    erase(ht, hash_keys[5]);

    cout << "Hash table after erase():" << endl;
    show(ht);
    return 0;
}
#endif
