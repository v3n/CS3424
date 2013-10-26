#ifndef _LAB2_CLASS_H_
#define _LAB2_CLASS_H_

#include <string>
using namespace std;

// simple class to add, subtract, multiply, and divide the lengths of 2 strings
class StringLengthCalc {
	public:
		// constructor method to set private attributes based on provided arguments
		StringLengthCalc (string s1, string s2) {
			// string1 = new string;
			// string2 = new string;

			string1 = s1;
			string2 = s2;
		}
		
		// add the length of the private attribute strings
		int add (void) {
			return (string1.length() + string2.length());
		}
		
		// subtract the length of the private attribute strings
		int subtract (void) {
			return (string1.length() - string2.length());

		}
		
		// multiply the length of the private attribute strings
		int multiply (void) {
			return (string1.length() * string2.length());

		}
		
		// divide the length of the private attribute strings
		int divide (void){
			return (string1.length() / string2.length());
		}
		
	private:
		string string1, string2;
};

#endif