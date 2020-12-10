/// 
/// Hashing is an important Data Structure which is designed to use 
/// a special function called the Hash function which is used to map 
/// a given value with a particular key for faster access of elements. 
/// The efficiency of mapping depends of the efficiency of the hash 
/// function used.
///
/// Thus we can say that hashing is implemented using two steps as mentioned below:
/// 1) The value is converted into a unique integer key or hash by using a hash 
/// function. It is used as an index to store the original element, which falls 
/// into the hash table.
/// 2) The element from the data array is stored in the hash table where it can 
/// be quickly retrieved using the hashed key.In the above diagram, we saw that 
/// we have stored all the elements in the hash table after computing their 
/// respective locations using a hash function. We can use the following expressions 
/// to retrieve hash values and index.
///     hash = hash_func(key)
///     index = hash % table_size
/// 
/// Hash Function
/// A hash function basically should fulfill the following requirements:
/// Easy to Compute: A hash function, should be easy to compute the unique keys.
/// Less Collision : When elements equate to the same key values, there occurs 
/// a collision.There should be minimum collisions as far as possible in the 
/// hash function that is used.As collisions are bound to occur, we have to 
/// use appropriate collision resolution techniques to take care of the collisions.
/// Uniform Distribution : Hash function should result in a uniform distribution 
/// of data across the hash tableand thereby prevent clustering
/// 
/// Hash Table
/// Hash table or a hash map is a data structure that stores pointers to the 
/// elements of the original data array.
/// Having entries in the hash table makes it easier to search for a particular 
/// element in the array. the hash table uses a hash function to compute the index 
/// into the array of buckets or slots using which the desired value can be found.
/// 
/// Collision
/// In the case of hashing, even if we have a hash table of very large size then 
/// a collision is bound to be there. This is because we find a small unique 
/// value for a large key in general, hence it is completely possible for one 
/// or more value to have the same hash code at any given time.
/// 
/// Given that a collision is inevitable in hashing, we should always look for 
/// ways to prevent or resolve the collision. There are various collision 
/// resolution techniques that we can employ to resolve the collision occurring 
/// during hashing.
/// 
/// Collision Resolution Techniques
/// 1) Separate Chaining (Open Hashing)
/// This is the most common collision resolution technique. This is also known 
/// as open hashing and is implemented using a linked list.
/// each entry in the hash table is a linked list. When the key matches the hash 
/// code, it is entered into a list corresponding to that particular hash code. 
/// Thus when two keys have the same hash code, then both the entries are entered 
/// into the linked list.
/// The worst-case for separate chaining is when all the keys equate to the same 
/// hash code and thus are inserted in one linked list only. Hence, we need to 
/// look up for all the entries in the hash table and the cost which are 
/// proportional to the number of keys in the table.
/// 
/// Linear Probing (Open Addressing/Closed Hashing)
/// all the entry records are stored in the hash table itself. When key-value maps 
/// to a hash code and the position pointed to by hash code is unoccupied, then 
/// the key value is inserted at that location. If the position is already occupied, 
/// then using a probing sequence the key value is inserted in the next position 
/// which is unoccupied in the hash table.
/// Linear probing may suffer from the problem of ¡°Primary Clustering¡± in which there 
/// is a chance that the continuous cells may get occupied and the probability of 
/// inserting a new element gets reduced.
/// 
/// The following implementation is for hashing using the linked lists 
/// as a data structure for the hash table. We also use ¡°Chaining¡± 
/// as a collision resolution technique in this implementation.
///
/// Author Youngsup Kim, idebtor@gmail.com
/// 2020/11/20	Creation

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

// it calls rehash(Hash*& ht, int n) with twice of its size
// until lf < max_lf repeatedly.
void rehash(Hash*& ht) {
    DPRINT(cout << "rehash: " << endl);

    while (loadfactor(ht) >= threshold(ht)) {
        rehash(ht, tablesize(ht) * 2);
    }
}

// sets the number of buckets in the table to n or more (use the next prime of n).
// If n is greater than the current number of buckets in tha table(tablesize or 
// bucket_count), a rehash is forced.The new bucket count can either be equal 
// or greater than n.
// If n is lower than the current number of buckets in the container(bucket_count), 
// the function may have no effect on the bucket countand may not force a rehash.
void rehash(Hash*& ht, int n) {  // n is a user specified size
    DPRINT(cout << "rehash usersize: " << n << endl;);

    int old_size = tablesize(ht);
    int new_size = nextprime(n);
    if (old_size == new_size) return;

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

    cout << "your code here\n";

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

    cout << "your code here\n";

    DPRINT(cout << "<erase failed: " << key << endl;);
    return false;
}

// searches the container for key and returns the element if found,
list<wordcount> find(Hash* ht, string key) {
    DPRINT(cout << ">find: " << key << endl;);
    list<wordcount> empty_bucket;

    int index = hashfunction(ht, key);         // get the hash value for key 
    list<wordcount>::iterator it;              // find the key in (index)th list 
    cout << "your code here\n";

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

    if (nlines_shown <= show_n) {
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