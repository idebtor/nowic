#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;
		Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr) {
			data = d; 	prev = p;	next = n;
		}
		~Node() {};
	};
	using pNode = Node*;

	int N;
	pNode head;
	pNode tail;

	void init() {
		N = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

public:
	List();
	~List();

	int size() const;
	pNode begin() const;
	pNode end() const;	// not tail->next

	// Test whether container is empty
	// Returns whether the list container is empty(i.e.whether its size is 0).
	// This function does not modify the container in any way.To clear the content 
	// of a List container, see List::clear.
	bool empty() const;

	// Clear content
	// Removes all elements from the list container(which are destroyed), 
	// and leaving the container with a size of 0.
	void clear();

	// Access first element
	// Returns a direct reference to the first element in the list container.
	// Calling this function on an empty container causes undefined behavior.
	//
	// A reference to the first element in the list container.
	// If the list object is const - qualified, the function returns a 
	// const_reference. Otherwise, it returns a reference.
	// Member types reference and const_reference are the reference types 
	// to the elements of the container(see list member types).
	const T& front() const;
	T& front();

	// Returns direct reference to the last element of the list container.
	// If empty, it causes undefined behaviour.
	const T& back() const;

	// Inserts a new element at the beginning of the list, right before its 
	// current first element.The content of val is copied(or moved) to the 
	// inserted element. This effectively increases the container size by one.
	// Parameters x: Value to be copied (or moved) to the inserted element.
	//	Member type T is the type of the elements in the container, 
	//	defined in list as an alias of its first template parameter(T).
	void push_front(const T& x);

	// Adds a new element at the end of the list container, after its current 
	// last element. The content of val is copied (or moved) to the new element.
	// This effectively increases the container size by one.
	// Value to be copied (or moved) to the new element.
	// Parameters x: Value to be copied (or moved) to the new element.
	//	Member type value_type is the type of the elements in the container, 
	//  defined in list as an alias of its first template parameter(T).
	// This effectively increases the container size by one.
	void push_back(const T& x);

	// inserts x in front of the larger or smaller one encountered firstly. 
	void push_sort(const T& x, bool ascending = true);

	// Removes the first element in the list container, effectively reducing
	// its size by one. This destroys the removed element.
	void pop_front();

	// Removes the last element in the list container, effectively reducing
	// its size by one. This destroys the removed element.
	void pop_back();

	pNode find(const T& x);

	// returns the element which is larger than x firstly encountered.
	// returns the tail if not found.
	pNode more(const T& x);

	// returns the element which is smaller than x firstly encountered
	// returns the tail if not found.
	pNode less(const T& x);

	void insert(pNode p, const T& x);

	// Erase elements
	// Removes from the list container either a single element(position) or a range of 
	// elements([first, last)). This effectively reduces the container size by the number 
	// of elements removed, which are destroyed. This is specifically designed to be 
	// efficient inserting and removing elements in any position, even in the middle 
	// of the sequence.
	void erase(pNode p);
	void erase(pNode p, pNode q);

	// Remove duplicate values
	// The version with no parameters(1), removes all but the first element 
	// from every consecutive group of equal elements in the container. 
	// Notice that an element is only removed from the list container if it 
	// compares equal to the element immediately preceding it. Thus, this 
	// function is especially useful for sorted lists.
	// The second version(2), takes as argument a specific comparison function 
	// that determine the "uniqueness" of an element.In fact, any behavior can 
	// be implemented(and not only an equality comparison), but notice that the 
	// function will call binary_pred(*i, *(i - 1)) for all pairs of elements
	// (where i is an iterator to an element, starting from the second) and 
	// remove i from the list if the predicate returns true.
	// The elements removed are destroyed.
	// For example:
	// a binary predicate implemented as a function:
	// bool same_integral_part(double first, double second) {
	// 	return (int(first) == int(second));
	// }
	// mylist.unique(same_integral_part);
	//
	// a binary predicate implemented as a class:
	// struct is_near {
	//	bool operator() (double first, double second) {
	//		return (fabs(first - second)<5.0);
	//	}
	// };
	// mylist.unique (is_near()); 
	void unique();

	// Reverses the order of the elements in the list container.
	void reverse();

	void print(bool reverse = false);
};

#endif
