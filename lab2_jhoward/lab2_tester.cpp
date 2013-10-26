#include <iostream>
#include <string>
using namespace std;

#include "lab2_class.h"
#include "lab2_func.h"

int main(void)
{	
	string s1, s2;
	int int1, int2;
	
	cout << "Please enter a string: ";
	cin >> s1;
	cout << "Please enter a second string: ";
	cin >> s2;
	
	StringLengthCalc slc(s1, s2);
	
	cout << "The addition of the 2 string lengths is " << slc.add() << endl;
	cout << "The subtraction of the 2 string lengths is " << slc.subtract() << endl;
	cout << "The multiplication of the 2 string lengths is " << slc.multiply() << endl;
	cout << "The division of the 2 string lengths is " << slc.divide() << endl;
	
	cout << "Please enter an integer: ";
	cin >> int1;
	cout << "Please enter a second integer: ";
	cin >> int2;
		
	cout << "The addition of the 2 integers is " << add(int1, int2) << endl;
	cout << "The subtraction of the 2 integers is " << subtract(int1, int2) << endl;
	cout << "The multiplication of the 2 integers is " << multiply(int1, int2) << endl;
	cout << "The division of the 2 integers is " << divide(int1, int2) << endl;
	
	#ifdef __WIND32__
		system("pause");
	#endif
}