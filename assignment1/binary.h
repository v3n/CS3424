/* Assignment 1
 * Jonathan Howard
 * CS3424
 */
#ifndef _BINARY_H_
#define _BINARY_H_

#include <iostream>
#include <sstream>
#include <stdexcept>      // std::invalid_argument
#include <cmath>
 #include <algorithm>

//Int to string cast macro courtesy DevSolar of StackOverflow
//Because for some reason, to_string isn't in scope. APPLE?!
// ***
//130903 – This is a Clang-GCC aliasing issue on OS X,
//while less efficient than sprintf, keeping here to maintain
//portability between Linux (GCC) and OS X (Clang) operating systems
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()

class Binary {
private:
	struct BinaryNode {
		int degree;
		BinaryNode* next;
		BinaryNode(int d, BinaryNode* n): degree(d),next(n) {}
	};
	BinaryNode *firstTerm;
	
//	//Recursive method to free all nodes
//	void r_freeNode(BinaryNode *node) {
//		while(node->next) {
//			r_freeNode(node->next);
//		}
//		// delete node;
//	}
    
	//recursive method to convert int to base2 string
	std::string binaryConvert(int x) const {
		if(x <= 1)
			return std::to_string(x);
		return binaryConvert(x >> 1).append(std::to_string(x % 2));
	}
    
public:
	// default constructor
	Binary() {firstTerm = nullptr;}
	
	// constructor
	// takes a value representing a decimal number and creates
	// the binary linked list representation of it.
	Binary(int x) {
		firstTerm = nullptr;
        
		std::string s = binaryConvert(x);
		for (auto rit= s.crbegin(); rit != s.crend(); ++rit) {
			// std::cout<< (rit - s.crbegin()) << '\t' << (*rit - '0') << std::endl;
	    	set_bit((*rit - '0'), (rit - s.crbegin()));
		}
	}
	
	// sets the term with degree d and bit b
	// notice a node is created if bit is 1 AND a node
	// for that degree doesn't exist, or the node is removed
	// if the bit is 0 AND the node with that degree already exists
	void set_bit(int b, int d) {
		//we make the assumption that the list is sorted
		//and make every attempt to keep it so.
		BinaryNode* current; //the currently iterated node
		BinaryNode* nextNext; //this holds the next node during insertion
        
		current = firstTerm;
		if(b == 0) { //remove node
			while (nullptr != current) { //quit on nullptr (end of L.L.)
				if(current->next == nullptr) { //end of list
					return;
				} else if(current->next->degree == d) { //lookahead
					nextNext = current->next->next;
					delete current->next; //remove middle term
					current->next = nextNext;
					return;
				}
				current = current->next;
			}
		} else if(b == 1) { //add node
			if(current == nullptr) { //first node in list
				firstTerm = new BinaryNode(d, nullptr);
				return;
			}
			if(d < current->degree) { //new first node
				firstTerm = new BinaryNode(d, firstTerm->next);
				return;
			}
			while (current != nullptr) {//every other
				if(current->next == nullptr) {
					current->next = new BinaryNode(d,nullptr);
					return;
				} else if(d == current->degree) {
					return;
				} else if(d == current->next->degree) {
					current->next->degree = d;
					return;
				} else if(d > current->degree && d < current->next->degree) {
					current->next = new BinaryNode(d, current->next);
				}
                current = current->next;
			}
        } else {
//            throw std::invalid_argument("set_bit: Argument is not modulus of 2");
		}
	}
	
	// returns one if a term with degree d exists, zero otherwise
	int get_bit(int d) const {
		try{
		BinaryNode *current = firstTerm;
		while(current != nullptr) {
			if (current->degree == d)
				return 1;
			current = current->next;
		}
		return 0;}
		catch(void *e) {
			std::cout << e;
		}
	}
	
	// returns the decimal integer representation of the binary number.
	int convert() const {
		int result = 0;
		BinaryNode *current = firstTerm;
		while(nullptr != current) {
			result += pow(2, current->degree);
			current = current->next;
		}
		return result;
	}
    
	// returns the highest degree of any term in the binary number
	// returns -1 if the the list is empty.
	int get_degree() const {
		if (firstTerm == nullptr) return -1;
        
		//Seek to end
		BinaryNode *currentNode = firstTerm;
		while(nullptr != currentNode->next) currentNode = currentNode->next;
		
		return currentNode->degree; //return last degree
	}
	
	// destructor
	// make sure that all memory is returned (freed up) correctly
	~Binary() {
		BinaryNode *t =NULL;
		while (t)
		{
			t = firstTerm->next;
			delete firstTerm;
			firstTerm = t; 
		}
	}
    
	// copy constructor
	// creates a new linked list where the contents are a deep copy of the provided list
	Binary(const Binary &b) {
		firstTerm = nullptr;
        
		for (BinaryNode *current = b.firstTerm; current != nullptr; current = current->next)
			this->set_bit(1, current->degree);
	}
	
	// assignment operator
	// sets the current link list to be a deep copy of the provided list.
	// make sure to check if assigning to itself, and make sure to free old memory
	// before making the copy.
	Binary& operator=(const Binary &other) {
		if (this == &other) return *this;
        
		Binary b = Binary(other);
        
		this->firstTerm = b.firstTerm;
		return *this;
	}	
	
	// prints the binary number to the output stream o
	// please use like:		10001101
	// terms must be printed in descending order of degree
	friend std::ostream& operator<<(std::ostream &o, const Binary &b);
	
	// returns a new binary number representing the addition of 2 provided binary numbers.
	// do NOT simply convert the numbers to decimal using convert(),add them,
	// then convert back to binary.
	friend Binary operator+(const Binary &b1, const Binary &b2);
	
	// returns a new binary number representing the subtraction
	// of 2 provided binary numbers. can assume b1 will always be
	// larger than b2.
	// do NOT simply convert the numbers to decimal using convert(),subtract them,
	// then convert back to binary.
	friend Binary operator-(const Binary &b1, const Binary &b2);
	
	// returns a new binary number representing the multiplication
	// of 2 provided binary numbers.
	// do NOT simply convert the numbers to decimal using convert(),multiply them,
	// then convert back to binary.
	friend Binary operator*(const Binary &b1, const Binary &b2);
	
};

std::ostream& operator<<(std::ostream &o, const Binary &b) {
	o << b.binaryConvert(b.convert());
	return o;
}

Binary operator+(const Binary &b1, const Binary &b2) {
	Binary b = Binary();
	int mx = std::max(b1.get_degree(), b2.get_degree());
	int remain = 0;
	Binary::BinaryNode* c1 = b1.firstTerm;
	Binary::BinaryNode* c2 = b2.firstTerm;
    
	for(int i = 0; i <= mx; i++) { //std::max+1 allows for remainder on MSB
		while(c1 != nullptr && c1->degree < i)
			c1 = c1->next;
		while(c2 != nullptr && c2->degree < i)
			c2 = c2->next;
        
		int bit = ((c1 != nullptr && c1->degree == i) ? 1 : 0) +
	        ((c2 != nullptr && c2->degree == i) ? 1 : 0) + remain;
		remain = bit >> 1;
        
		b.set_bit(bit % 2, i);
	}
	b.set_bit(remain, mx+1);
	return b;

}

//subtraction via two's complement
Binary operator-(const Binary &b1, const Binary &b2) {
    Binary r = Binary();
    Binary twos = Binary(b2);

    int mx = std::max(b1.get_degree(), b2.get_degree());
    for(int i = 0; i < mx; i++)
    	twos.set_bit(~b2.get_bit(i), i);

    twos = twos + Binary(1);
    r = b1 + twos;

    // r.set_bit(0, mx+1);
   
   return r;
}

Binary operator*(const Binary &b1, const Binary &b2) {
	Binary t = Binary();
	Binary b;
    
	for(Binary::BinaryNode *s = b2.firstTerm;s != nullptr; s = s->next) {
		b = Binary();
		for(Binary::BinaryNode *c = b1.firstTerm;c != nullptr; c = c->next) {
			b.set_bit(1,(c->degree + s->degree)); // bit shift
		}
		std::cout << std::endl;
		t = t + b;
	}
	// std::cout << t << std::endl;
	return t;
}

#endif
