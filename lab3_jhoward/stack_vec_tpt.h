#ifndef _STACK_VEC_TPT_H_
#define _STACK_VEC_TPT_H_
#include <stdexcept>
#include <iostream>

using namespace std;

// abstract stack class implemented using vector
template<class T>
class abs_stack_vec {
public:
	// pushes an element onto the top of the stack. 
	// grows the vector if needed.
	virtual void push(const T& elem)=0;
	
	// pops an element from the top of the stack.
	// does nothing if the stack is empty.
	virtual void pop()=0;
	
	// returns the value of the top element on the stack.
	// throws domain_error if the stack is empty.
	virtual const T& top() const=0;
	
	// returns the number of elements currently on the stack.
	virtual unsigned size() const=0;
};

// the following class inherits from the abstract stack class
// using its own implementation of a vector
// you must implement the abstract methods push, pop, and top.
template<class T>
class mystack_vec: public abs_stack_vec<T> {
public:
	unsigned size() const {return _size;}
	
	// method used for growing vector when size equals capacity
	// and need to add more elements
	void grow() {
		T* temp = new T[_size * 2];
		for(unsigned i = 0; i < _size; ++i) {
			temp[i] = _values[i];
		}
		delete[] _values;
		_values = temp;
		_capacity = _size * 2;
	}
	
	// default constructor
	mystack_vec() {
		_capacity = 5;
		_size = 0;
		_values = new T[_capacity];
	}
	
	//destructor
	~mystack_vec() {
		delete[] _values;
	}
	
	// TO-DO: YOU MUST IMPLEMENT THE FOLLOWING METHODS:
	// PUSH, POP, TOP
	
	void pop() {
		if (_size == 0) return;
		_size--;
		// return _values[_size];
	}

	const T& top() const {
		//This should really be type-checking and returning a null value
		if (_size == 0) throw domain_error("Out of range, value is null.");
		return _values[_size-1];
	}

	void push(const T& elem) {
		_size++;
		if(_size == _capacity) grow();
		_values[_size-1] = elem;
	}

	
	// END OF TO-DO
private:
	T *_values; // array !!
	unsigned _size, _capacity;
};
#endif