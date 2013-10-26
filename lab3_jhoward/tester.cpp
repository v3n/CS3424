#include "stack_vec_tpt.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv) 
{
	// // PART 1: stack using linked list
	// cout << "TESTING LINKED LIST STACK IMPLEMENTATION" << endl;
	// mystack_list<int> sl;
	
	// // test push
	// cout << "\nTESTING PUSH METHOD" << endl;
	// sl.push(4);
	// sl.push(2);
	// if (sl.size() == 2)
	// 	cout << "\tSize of list stack after pushing 2 elements == 2." << endl;
	// else
	// 	cout << "\tSize of list stack after pushing 2 elements != 2. (INCORRECT)" << endl;

	// // test pop
	// cout << "\nTESTING POP METHOD" << endl;
	// sl.pop();
	// sl.pop();
	// sl.pop();
	// if (sl.size() == 0)
	// 	cout << "\tSize of list stack after popping 3 elements == 0." << endl;
	// else
	// 	cout << "\tSize of list stack after pushing 2 elements != 0. (INCORRECT)" << endl;
	
	// // test front
	// cout << "\nTESTING TOP METHOD" << endl;
	// try {
	// 	cout << "\tThe value of the top element of the empty stack = " << sl.top() <<". (INCORRECT)" << endl;
	// }
	// catch (domain_error &de) {
	// 	cerr << de.what() << endl;
	// }
	
	// sl.push(5);
	// sl.push(3);
	// sl.push(10);
	// sl.pop();
	// try {
	// 	if (sl.top() == 3)
	// 		cout << "\tThe value of the top element of the stack == 3." << endl;
	// 	else
	// 		cout << "\tThe value of the top element of the stack != 3. (INCORRECT)" << endl;
	// }
	// catch (domain_error &de) {
	// 	cerr << de.what() << " (INCORRECT)" << endl;
	// }
	
	// PART 2: stack using vector
	cout << "TESTING VECTOR STACK IMPLEMENTATION" << endl;
	mystack_vec<int> sv;
	
	// test push
	cout << "\nTESTING PUSH METHOD" << endl;
	sv.push(4);
	sv.push(2);
	if (sv.size() == 2)
		cout << "\tSize of list stack after pushing 2 elements == 2." << endl;
	else
		cout << "\tSize of list stack after pushing 2 elements != 2. (INCORRECT)" << endl;

	// test pop
	cout << "\nTESTING POP METHOD" << endl;
	sv.pop();
	sv.pop();
	sv.pop();
	if (sv.size() == 0)
		cout << "\tSize of list stack after popping 3 elements == 0." << endl;
	else
		cout << "\tSize of list stack after pushing 2 elements != 0. (INCORRECT)" << endl;
	
	// test front
	cout << "\nTESTING TOP METHOD" << endl;
	try {
		cout << "\tThe value of the top element of the empty stack = " << sv.top() <<". (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cerr << de.what() << endl;
	}
	
	sv.push(5);
	sv.push(3);
	sv.push(10);
	sv.push(20);
	sv.push(1);
	sv.push(40);
	sv.pop();
	sv.push(55);
	sv.pop();
	try {
		if (sv.top() == 1)
			cout << "\tThe value of the top element of the stack == 1." << endl;
		else
			cout << "\tThe value of the top element of the stack != 1. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cerr << de.what() << " (INCORRECT)" << endl;
	}
	
	#if __WIN23__
		system("pause");
	#endif
}
