/// hashmap.cpp
/// 	Implement hashp using STL unordered_map container and 
///     let users test its operations interactively.        
/// 
/// Hashing is an important data structure which is designed to use 
/// a special function called the hash function. The function is used to 
/// map a given value with a particular key for faster access of elements. 
/// The efficiency of mapping depends of the efficiency of the hash 
/// function used.
/// 
/// author: idebtor@gmail.com
/// 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <unordered_map>
#include "nowic.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

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

string hashspecs(unordered_map<string, int> ht) {
	stringstream ss;
	ss << " tabelsizeM:" << ht.bucket_count() 
		<< " sizeN:" << ht.size()
		<< " max_loadfactor:" << ht.max_load_factor()
		<< " loadfactor(N/M):" << ht.load_factor(); 
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

// use find() in unordered_map to check whether or not key exists.
// if key is found, use key to increment the value of the key.
// if key is not found, invoke insert() in unordered_map. 
// there seems no clear way to check the failture of insert(). 
bool insert(unordered_map<string, int>& ht, string key) {
	DPRINT(cout << ">insert: " << key << endl;);

	cout << "your code here \n";
	ht.insert(unordered_map<string, int>::value_type(key, 1));

	return true;  // always
}

// calls unordered_map erase() and returns its return value: true or false.
bool erase(unordered_map<string, int>& ht, string key) {
	DPRINT(cout << ">erase: " << key << endl;);

	cout << "your code here  \n";

	return true; 
}

// doit() does either "insert by file" or "erase by file" operation.
// One of two function pointers is passed as a function argument along with the hash table.
void doit(bool (*func_ptr)(unordered_map<string, int>&, string), unordered_map<string, int>& ht) {
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
					if (ispunct(word.back())) word.pop_back();  // erase a punctunation
					if (word.length() == 0) continue;           // exclude if empty
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

// show the hash table; if show_n = 0, then print all buckets
// if show_empty is true, empty buckets are printed as well.
// http://www.cplusplus.com/reference/unordered_map/unordered_map/begin/
// http://www.cplusplus.com/reference/unordered_map/unordered_map/bucket_size/
void show_range(unordered_map<string, int>& ht, vector<int>& bucket_idx, size_t from, size_t to) {

	cout << "your code here\n";

}
void show(unordered_map<string, int>& ht, bool show_empty = false, size_t show_n = 10) {
	if (show_n <= 0 || show_n > ht.bucket_count()) 
		show_n = ht.bucket_count();
	DPRINT(cout << "tablesize:" << ht.bucket_count() << " show_empty:" << show_empty << " n:" << show_n << endl;);

	// get a list of bucket indices and keys to show
	vector<int> bucket_idx;

	size_t nbuckets = ht.bucket_count();
	for (size_t i = 0; i < nbuckets; i++) {
		if (show_empty) 
			bucket_idx.push_back((int)i);
		else 
			if (ht.bucket_size(i) > 0) bucket_idx.push_back((int)i);
	}

	size_t nlines_shown = bucket_idx.size();
	DPRINT(cout << "  nlines_shown: " << nlines_shown << endl;);

	if (nlines_shown <= show_n) {
		show_range(ht, bucket_idx, 0, nlines_shown);
	}
	else {
		size_t head_n = show_n / 2;                          // a num of buckets to show first
		size_t tail_x = int(nlines_shown - show_n / 2.0);    // starting index to show at tail

		DPRINT(cout << "head_n:" << head_n << "  tail_x:" << tail_x << endl;);
		show_range(ht, bucket_idx, 0, head_n);
		cout << "\t... ..." << endl;
		show_range(ht, bucket_idx, tail_x, nlines_shown);
	}
}

#if 1
int main(int argc, char* argv[]) {
	unordered_map<string, int> ht;
	string menu = "[HashTable]";
	string key, str, word;
	stringstream ss;
	char c;
	double d;
	int size;
	int show_n = 10;               // by default - a magic number 
	bool show_empty = false;       // by default
	clock_t begin = 0;

	do {
		std::cout << "\n\t" << menu << hashspecs(ht) << endl;
		cout << "\ti - insert\t\t";			cout << "\te - erase\n";
		cout << "\tj - insert N\t\t"; 		cout << "\tx - erase N\n";
		cout << "\tk - insert by file\t";	cout << "\tz - erase by file\n";
		cout << "\tf - find \t\t";			cout << "\tm - max_loadfactor & rehash\n";
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
			
			cout << "your code here \n";

			ss.clear();
			break;

		case 'k':  // insert by file
			doit(insert, ht);
			break;

		case 'f':  // find
			key = GetString("\tEnter a key to find: ");
			{
				cout << "your code here \n";
			}
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
			doit(erase, ht);
			break;

		case 'm':  // set threshold & rehash()
			d = GetDouble("\tEnter a new max_loadfactor to set( > 0.1 ): ");
			if (d < 0.1) break;
			ht.max_load_factor((float)d);
			break;

		case 't':  // set tablesize & rehash()
			std::cout << "\n\tTablesize  current: " << ht.bucket_count()
				<< ",  next: " << nextprime((int)ht.bucket_count() + 1) << endl;
			size = GetInt("\tEnter a new tablesize( >= 2 ) to set: ");
			if (size < 2) key = 2;
			ht.reserve(size);
			break;

		case 'o':  // [on/off] empty bucket 
			show_empty = show_empty ? false : true;
			break;

		case 's':
			show_n = GetInt("\tEnter a number of buckets to show(0 for ALL): ");
			if (show_n < 0) show_n = 0;
			break;

		case 'c':	// clear hashtable, shink it by default tablesize = 2 
			ht.clear();
			break;
		}
		show(ht, show_empty, show_n);
	} while (c != 'q');

	std::cout << "\tJoyful Coding^^\n";
	return 0;
}
#else
int main() {
	// int hash_keys[] = { 1, 11, 12, 21, 14, 15 };       
	// string hash_keys[] = { "a", "called", "gracia", "sola", "fide", "z" };
	unordered_map<string, int> mymap;
	mymap = { {"a", 1}, {"called", 2}, {"gracia", 3},
		{"commissioned", 4}, {"sola", 5}, {"fide", 6}, {"z", 7} };

	cout << "mymap contains:";
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
		cout << " " << it->first << ":" << it->second;
	cout << endl;

	/** without using an iterator
	for (auto x : mymap)
		cout << " " << x.first << ":" << x.second;
	cout << endl;
	*/

	cout << "mymap's buckets contain:\n";
	for (unsigned i = 0; i < mymap.bucket_count(); ++i) {
		cout << "bucket #" << i << " contains:";
		for (auto itr = mymap.begin(i); itr != mymap.end(i); ++itr)
			cout << " " << itr->first << ":" << itr->second;
		cout << endl;
	}

	return 0;
}
#endif