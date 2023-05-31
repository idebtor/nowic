/// File: hashDriver.cpp
///		interactively tests hashing algorithms
/// 
/// Hashing is an important data structure which is designed to use 
/// a special function called the hash function. The function is used to 
/// map a given value with a particular key for faster access of elements. 
/// The efficiency of mapping depends of the efficiency of the hash 
/// function used.
/// author: idebtor@gmail.com

#include <iostream>
#include <string>
#include <vector>
#include "nowic.h"
#include "hash1.h"
using namespace std;

string hashspecs(Hash* ht) {
	stringstream ss;
	ss << " tablesizeM:" << tablesize(ht) 
		<< " sizeN:" << nelements(ht)
		<< " max_loadfactor:" << threshold(ht)
		<< " loadfactor(N/M):" << (float)nelements(ht) / tablesize(ht); 
	return ss.str();
}

int main(int argc, char* argv[]) {
	string menu = "[HashTable]";
	string key, str;
	stringstream ss;
	char c;
	bool show_empty = false;			// by default
	double d;
	list<string> bucket;
	DPRINT(cout << "\t>Joyful Coding\n";);

	Hash* ht = new Hash();
	
	do {
		cout << "\n\t" << menu << hashspecs(ht) << endl;
		cout << "\ti - insert\t\t";			cout << "\te - erase\n";
		cout << "\tj - insert N\t\t"; 		cout << "\tx - erase N\n";
		cout << "\tf - find \t\t";		    cout << "\th - max_loadfactor & rehash\n";
		cout << "\to - show empty buckets";
		if (show_empty) cout << "[ON]"; else cout << "[OFF]";
		cout << "\tc - clear \n";

		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'i':  // insert
			key = GetString("\tEnter a key to insert: ");
			insert(ht, key);
			break;

		case 'j':	// get n keys to insert
			str = GetLine("\tEnter keys to insert: ");
			ss << str;
			while (ss >> key) 
				insert(ht, key);
			ss.clear();
			break;

		case 'f':  // find
			key = GetString("\tEnter a key to find: ");
			bucket = find(ht, key);
			if (bucket.size() <= 0)
				cout << "\tkey(" << key << ") not found \n";
			else {
				cout << "\tbucket found@: ";
				for (auto x : bucket) cout << x << ' ';
				cout << endl;
			}
			break;

		case 'e':  // erase
			key = GetString("\tEnter a key to erase: ");
			if (!erase(ht, key))
				cout << "\tErasing (" << key << ") was unsuccessful.\n";
			break;

		case 'x':	// get n keys to erase
			str = GetLine("\tEnter keys to erase: ");
			ss << str;
			while (ss >> key) {
				if (!erase(ht, key))
					cout << "\tErasing (" << key << ") was unsuccessful.\n";
			}
			ss.clear();
			break;

		case 'h':  // threshold
			d = GetDouble("\tEnter a new max_loadfactor to set( > 0.1 ): ");
			if (d < 0.1) break;
			threshold(ht, d);
			break;

		case 'o':  // [on/off] empty bucket 
			show_empty = show_empty ? false : true;
			break;

		case 'c': // clear hashtable, shrink it by default tablesize = 2 
			clear(ht);
			break;
		}
		show(ht, show_empty);
	} while (c != 'q');

	cout << "\tJoyful Coding^^\n";
	return 0;
}

