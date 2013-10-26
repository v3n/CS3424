#include "stack_list_tpt.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv) 
{
	// PART 1: stack using linked list
	cout << "TESTING LINKED LIST STACK IMPLEMENTATION" << endl;
	mystack_list<int> sl;
	
	// test push
	cout << "\nTESTING PUSH METHOD" << endl;
	sl.push(4);
	sl.push(2);
	if (sl.size() == 2)
		cout << "\tSize of list stack after pushing 2 elements == 2." << endl;
	else
		cout << "\tSize of list stack after pushing 2 elements != 2. (INCORRECT)" << endl;

	// test pop
	cout << "\nTESTING POP METHOD" << endl;
	sl.pop();
	sl.pop();
	sl.pop();
	if (sl.size() == 0)
		cout << "\tSize of list stack after popping 3 elements == 0." << endl;
	else
		cout << "\tSize of list stack after popping 3 elements != 0. (INCORRECT)" << endl;
	
	// test front
	cout << "\nTESTING TOP METHOD" << endl;
	try {
		cout << "\tThe value of the top element of the empty stack = " << sl.top() <<". (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cerr << de.what() << endl;
	}
	
	sl.push(5);
	sl.push(3);
	sl.push(10);
	sl.pop();
	try {
		if (sl.top() == 3)
			cout << "\tThe value of the top element of the stack == 3." << endl;
		else
			cout << "\tThe value of the top element of the stack != 3. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cerr << de.what() << " (INCORRECT)" << endl;
	}
	
	#ifdef __WIN32__
		system("pause");
	#endif
	return 0;
}
