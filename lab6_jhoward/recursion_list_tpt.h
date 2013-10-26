#include <iostream>
#include <cassert>
#include <stdexcept>
using namespace std;

template<class T> class mylist;

template<class T>
ostream& operator<<(ostream& out, const mylist<T>&l);

template <typename T>
class mylist {
public:
	// single-linked list node class (structure)
	struct node {
		T data;
		node* next_ptr;
		node(const T&d, node* n):data(d),next_ptr(n){}
	};
	node* head_ptr;
	friend ostream& operator<<  <>(ostream& out, const mylist<T>&l);

	// single-linked list iterator class
	class iterator {
		node* ptr;
	public:
		// iterator constructor
		iterator(node*p):ptr(p){}
		// returns iterator pointing to next node in list
		iterator next(){return ptr->next_ptr;}
		// returns data at node currently pointed at by iterator
		T& operator*(){return ptr->data;}
		// test if 2 iterators are not equal
		bool operator!=(const iterator& other){return ptr!=other.ptr;}
		// pre-fix increment operator for iterator
		iterator operator++(){ptr=ptr->next_ptr; return *this;}
	};
	
public:	
	// returns the length of the linked list (calculated RECURSIVELY)
	unsigned length(node* n)
	{
		if(n == nullptr)
			return 0;
		return 1 + length(n->next_ptr);
	}
	
	// deletes the node pointed to by provided pointer and all nodes following
	void del_list(node* &h)
	{
		if(h == nullptr)
			return;	
		del_list(h->next_ptr);
		delete h;
		h = nullptr;
	}	
	
	// default constructor
	mylist():head_ptr(0) {}
	
	// creates iterator pointing to head of list
	iterator begin(){return iterator(head_ptr);}
	
	// creates iterator pointing to past end of list (null pointer)
	iterator end(){return iterator(nullptr);}
	
	// normal 'wrapper' method for returning length of the linked list
	// it calls the RECURSIVE version of length
	unsigned length() {return length(head_ptr);}
	
	// destructor method
	// it calls the RECURSIVE del_list method with the head pointer
	~mylist() {
		del_list(head_ptr);
	}
		
	// TO-DO: implement following methods recursively using recursive method and wrapper method:
	// AT, SUM_ALL, CONTAINS, LARGEST, SMALLEST
	
	// returns a reference to the data in the ith node in the list
	// raise an out_of_bounds exception if not enough elements
	// RECURSIVE implementation. Notice this is the wrapper function,
	// the declaration for a possible recursive one is below it
	T& at(unsigned i){
		if(i >= length(head_ptr)) throw std::out_of_range("Array out of bounds");

		return at(head_ptr, i);
	}
	
	// hint for declaration of a recursive function at
	// throw out of range exception for index bigger than length of list
	T& at(node * head, unsigned i) {
		if (i == 0) return head->data;
		return at(head->next_ptr, i-1);
	}
	
	// same as at; YOU DO NOT NEED TO IMPLEMENT THIS, ALREADY DONE FOR YOU
	T& operator[](unsigned i){
		return at(i);
	}	
	
	// returns the sum of all elements in the list. 
	// again, notice this is the wrapper
	// DO NOT THROW EXCEPTION IF EMPTY
	T sum_all(void) const {
		T sum = T();
		for(node* n = head_ptr; n != nullptr; n = n->next_ptr) {
			sum += n->data;
		}
		return sum;
	}
	
	// returns true if the element is in the list
	// DO NOT THROW EXCEPTION IF EMPTY
	bool contains(const T&elem) const {
		for(node* n = head_ptr; n != nullptr; n = n->next_ptr)
			if(n->data == elem) return true;
		return false;
	}
	
	// returns the largest element in the list
	// throw domain error exception if empty
	T largest(void) const {
		if(head_ptr == nullptr) throw std::domain_error("empty list");
		return largest(head_ptr, head_ptr->data);
	}

	T largest(node* n, T l) const {
		if(n == nullptr) return l;
		if(n->data > l) l = n->data;
		return largest(n->next_ptr, l);
	}
	
	// returns the smallest element in the list
	// throw domain error exception if empty
	T smallest(void) const {
		if(head_ptr == nullptr) throw std::domain_error("empty list");
		return smallest(head_ptr, head_ptr->data);
	}

	T smallest(node* n, T l) const {
		if(n == nullptr) return l;
		if(n->data < l) l = n->data;
		return smallest(n->next_ptr, l);
	}
	
	// END OF TO-DO

	
	// insert at beginning of list
	void push_front(const T& data) {
		head_ptr=new node(data,head_ptr);
	}
	
	// check if list is empty
	bool empty() { return head_ptr==0;}
	
	// insert at end of list
	void push_back(const T&data) {
		if(empty())
			push_front(data);
		
		node* last_ptr=head_ptr;
		while(last_ptr->next_ptr != 0)
			last_ptr=last_ptr->next_ptr;
		// pointing to last node on the list
		last_ptr->next_ptr=new node(data,0);
	}
	
	// print contents of the linked list
	void print_all(void) {
		cout << "mylist{";
		for(node*current_ptr=head_ptr;  
				current_ptr!=0; 
				current_ptr=current_ptr->next_ptr){
			cout << current_ptr->data << " ";
		}
		cout <<"}";
	}
};
