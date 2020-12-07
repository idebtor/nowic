/// File: hashDriver.cpp
///		interactively tests hashing algorithms
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
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "nowic.h"
#include "hash2.h"
using namespace std;

string hashspecs(Hash* ht) {
	stringstream ss;
	ss << " tablesizeM:" << tablesize(ht) 
		<< " sizeN:" << nelements(ht)
		<< " max_loadfactor:" << threshold(ht)
		<< " loadfactor(N/M):" << (float)nelements(ht) / tablesize(ht); 
	return ss.str();
}

// Case Sensitive Implementation of ends_with()
// It checks if the string 'str' ends with given string 'sub'
bool ends_with(const std::string& str, const std::string& sub) {
	return str.size() >= sub.size() &&
		str.compare(str.size() - sub.size(), sub.size(), sub) == 0;
}

void show_timeit(int begin) { 	// display elapsed time
	cout << "\tcpu: " << ((double)clock() - begin) / CLOCKS_PER_SEC << " sec\n";
}

// doit() does either "insert by file" or "erase by file" operation.
// One of two function pointers is passed as a function argument along with the hash table.
void doit(bool(*func_ptr)(Hash*&, string), Hash*& ht) {
	string key, word;
	clock_t begin = 0;

	std::cout << "\n\tShell commands available(e.g. ls, dir, pwd).\n";
	while (true) {
		string str = GetLine("\tEnter a filename(q to quit): ");
		if (str.c_str()[0] == 'q') break;
		if (ends_with(str, ".txt")) {
			ifstream ifs(str);
			if (ifs) {
				begin = clock();
				while (ifs >> word) {
					if (isdigit(word.front())) continue;        // exclude the word
					if (ispunct(word.back())) word.pop_back();  // erase punct
					func_ptr(ht, word);                         // call insert() or erase()
				}
				show_timeit(begin);
				ifs.close();
			}
			else {
				cout << "\tfailed opening file: " << str << endl;
			}
			break;
		}
		else if (str.length() >= 1) {
			system(str.c_str());
		}
	}
}

int main(int argc, char* argv[]) {
	string menu = "[HashTable]";
	string key, str, word;
	stringstream ss;
	char c;
	double d;
	int size = 0;
	int show_n = 10;               // by default - a magic number 
	bool show_empty = false;       // by default
	clock_t begin = 0;
	list<wordcount> bucket;
	list<wordcount>::iterator it;
	DPRINT(cout << "\t>Joyful Coding\n";);

	Hash* ht = new Hash();
	
	do {
		std::cout << "\n\t" << menu << hashspecs(ht) << endl;
		cout << "\ti - insert\t\t";			cout << "\te - erase\n";
		cout << "\tj - insert N\t\t"; 		cout << "\tx - erase N\n";
		cout << "\tk - insert by file\t";	cout << "\tz - erase by file\n";
		cout << "\tf - find \t\t";			cout << "\th - max_loadfactor & rehash\n";
		if (show_n == 0)
			cout << "\ts - show [ALL] buckets\t";
		else
			cout << "\ts - show [" << show_n << "] buckets\t";
		cout << "\tt - tablesize & rehash\n";
		cout << "\to - show empty buckets";
		if (show_empty) cout << "[ON]"; else cout << "[OFF]";
		cout << "\tc - clear\n";

		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'i':  // insert
			key = GetString("\tEnter a key to insert: ");
			insert(ht, key);
			break;

		case 'j':	// get n keys to insert
			str = GetLine("\tEnter keys to insert: ");
			ss << str;
			begin = clock();
			while (ss >> key)
				insert(ht, key);
			show_timeit(begin);
			ss.clear();
			break;

		case 'k':  // insert
			doit(insert, ht);      // using a function poitner
			break;

		case 'e':  // erase
			key = GetString("\tEnter a key to erase: ");
			begin = clock();
			if (!erase(ht, key))
				cout << "\tErasing (" << key << ") was unsuccessful.\n";
			show_timeit(begin);
			break;

		case 'x':	// get n keys to erase
			str = GetLine("\tEnter keys to erase: ");
			ss << str;
			begin = clock();
			while (ss >> key) {
				if (!erase(ht, key))
					cout << "\tErasing (" << key << ") was unsuccessful.\n";
			}
			show_timeit(begin);
			ss.clear();
			break;

		case 'z':  // erase by file
			doit(erase, ht);      // using a function poitner
			break;

		case 'f':  // find
			key = GetString("\tEnter a key to find: ");
			bucket = find(ht, key);
			if (bucket.size() == 0)
				cout << "\tkey(" << key << ") not found \n";
			else {
				cout << "\tbucket found@: ";
				for (auto x : bucket)
					cout << x.first << ": " << x.second << " \t";
				cout << endl;
			}
			break;

		case 'h':  // set threshold & rehash()
			d = GetDouble("\tEnter a new max_loadfactor( > 0.1 ) to set: ");
			if (d < 0.1) break;
			threshold(ht, d);
			break;

		case 't':  // set tablesize & rehash()
			std::cout << "\tTablesize  current: " << tablesize(ht)
				<< ",  next: " << nextprime(tablesize(ht) + 1) << endl;
			size = GetInt("\tEnter a new tablesize( > 2 ) to set: ");
			if (size < 2) key = 2;
			rehash(ht, size);
			break;

		case 'o':  // [on/off] empty bucket 
			show_empty = show_empty ? false : true;
			break;

		case 's':  
			show_n = GetInt("\tEnter a number of buckets to show(0 for ALL): ");
			if (show_n < 0) show_n = 0;
			break;

		case 'c':	// clear hashtable, shrink it by default tablesize = 2 
			clear(ht);
			break;
		}
		show(ht, show_empty, show_n);
	} while (c != 'q');

	std::cout << "\tJoyful Coding^^\n";
	return 0;
}

