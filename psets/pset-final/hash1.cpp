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
/// 

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

    cout << "\tREHASHED(tablesize: " << old_size << " -> " << new_size << ")\n";
}

// inserts key to the table and returns true always; 
// rehash()'s are automatically performed if loadfactor >= threshold. 
bool insert(Hash*& ht, string key) {
    DPRINT(cout << ">insert: " << key << endl;);
    int index = hashfunction(ht, key);
    ht->hashtable[index].push_back(key);
    ht->nelements++;

    // rehash if necessary
    cout << "your code here\n";

    DPRINT(cout << "<insert: " << key << endl;);
	return true;
}

// erases key and returns true if successful and false if unsuccessful
bool erase(Hash*& ht, string key) {
    DPRINT(cout << ">erase: " << key << endl;);

    cout << "your code here\n";

    DPRINT(cout << "<erase failed: " << key << endl;);
    return false;
}

// searches the container for key and returns the bucket list to it if found,
list<string> find(Hash* ht, string key) {
    DPRINT(cout << ">find: " << key << endl;);
    list<string> empty_bucket;

    cout << "your code here\n";

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
