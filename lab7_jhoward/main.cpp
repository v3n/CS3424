#include <iostream>
#include <vector>
#include <string>
#include "vector_functions_tpt.h"

using namespace std;

template <typename T>
void printVec(vector<T>& v)
{
	cout << "( "; 
	for(unsigned i=0; i<v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout<<")";
}

int main(void)
{
	int errors=0;
	
	// Vector functions using RECURSION
	cout << "\nTESTING VECTOR RECURSIVE FUNCTIONS" << endl;
	vector<int> v1;
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(1);
	vector<int> v3;
	v3.push_back(11);
	v3.push_back(22);
	v3.push_back(3);
	vector<int> v4;
	v4.push_back(1);
	v4.push_back(2);
	v4.push_back(3);
	v4.push_back(1);
	v4.push_back(2);
	vector<int> v5;
	v5.push_back(3);
	v5.push_back(5);
	v5.push_back(11);
	
	// test MAX
	cout << "\nTESTING MAX FUNCTION" << endl;
	try {
		max(v1);
		++errors;
		cout << "\tMAX of empty vector does NOT throw domain error exception. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cout << "\tMAX of empty vector does throw domain error exception. (CORRECT)" << endl;
	}

	cout <<endl<< "\tThe vector v2 is "; 
	printVec(v2);
	cout<<endl;

	if (max(v2) == 3)
		cout << "\tMax of vector v2 == 3. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tMax of vector v2 is " << max(v2) << " != 3. (INCORRECT)" << endl;
	}
	
	
	// test MIN
	cout << "\nTESTING MIN FUNCTION" << endl;
	try {
		min(v1);
		++errors;
		cout << "\tMIN of empty vector does NOT throw domain error exception. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cout << "\tMIN of empty vector does throw domain error exception. (CORRECT)" << endl;
	}

	cout <<endl<< "\tThe vector v3 is "; 
	printVec(v3);
	cout<<endl;

	if (min(v3) == 3)
		cout << "\tMin of vector v3 == 3. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tMin of vector v3 is " << min(v3) << " != 3. (INCORRECT)" << endl;
	}
	
	// test SUM

	cout << "\nTESTING SUM FUNCTION" << endl;
	cout << "\tThe vector v1 is "; 
	printVec(v1);
	cout<<endl;

	if (sum(v1) == 0)
		cout << "\tSUM of empty integer vector == 0. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tSUM of empty integer vector != 0. (INCORRECT)" << endl;
	}
		
	cout <<endl<< "\tThe vector v2 is "; 
	printVec(v2);
	cout<<endl;

	if (sum(v2) == 7)
		cout << "\tSUM of vector v2 == 7. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tSUM of vector v2 is " << sum(v2) << " != 7. (INCORRECT)" << endl;
	}
		
	// test FIND

	cout << "\nTESTING FIND FUNCTION" << endl;
	cout << "\tThe vector v1 is "; 
	printVec(v1);
	cout<<endl;

	if (find(v1, 3) == -1)
		cout << "\tFIND of empty integer vector == -1. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tFIND of empty integer vector != -1. (INCORRECT)" << endl;
	}

	cout <<endl<< "\tThe vector v4 is "; 
	printVec(v4);
	cout<<endl;

	if (find(v4, 3) == 2)
		cout << "\tFIND index of value 3 in vector v4 == 2. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tFIND index of value 3 in vector v4 is " << find(v4,2) << " != 2. (INCORRECT)" << endl;
	}	
	if (find(v4, 4) == -1)
		cout << "\tFIND index of value 4 in vector v4 == -1. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tFIND index of value 4 in vector v4 is " << find(v4, 4) << " != -1. (INCORRECT)" << endl;
	}
	// test CONTAINS
	cout << "\nTESTING CONTAINS FUNCTION" << endl;
	
	cout << "\tThe vector v1 is "; 
	printVec(v1);
	cout<<endl;

	if (!contains(v1, 3))
		cout << "\tCONTAINS of empty integer vector == FALSE. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tCONTAINS of empty integer vector != FALSE. (INCORRECT)" << endl;
	}
	
	cout <<endl<< "\tThe vector v2 is "; 
	printVec(v2);
	cout<<endl;

	if (contains(v2, 3))
		cout << "\tCONTAINS value 3 in vector v2 == TRUE. (CORRECT)" << endl;
	else{
		++errors;
		cout << "\tCONTAINS value 3 in vector v2 is " << contains(v2, 3) << " != TRUE. (INCORRECT)" << endl;
	}
	if (!contains(v2, 4))
		cout << "\tCONTAINS value 4 in vector v2 == FALSE. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tCONTAINS value 4 in vector v2 is " << contains(v2, 4) << " != FALSE. (INCORRECT)" << endl;
	}
	// test VEC_UNION
	cout << "\nTESTING VEC_UNION FUNCTION" << endl;
	vector<int> v6 = vec_union(v1, v1);
	
	cout << "\tThe vector v6 is "; 
	printVec(v6);
	cout<<endl;

	if (v6.empty())
		cout << "\tUnion of 2 empty vectors is empty vector. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tUnion of 2 empty vectors is NOT empty vector. (INCORRECT)" << endl;
	}
	v6 = vec_union(v3, v5);
	if ((v6.size() == 4) && contains(v6, 3) && contains(v6, 5) && contains (v6, 11) && contains(v6, 22))
	{
		//cout <<endl<< "\tUnion of vectors v3 and v5 == {3, 5, 11, 22}. (CORRECT)" << endl;
		cout << "\tUnion of vectors v3 "; printVec(v3); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " == {3, 5, 11, 22}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tUnion of vectors v3 "; printVec(v3); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " != {3, 5, 11, 22}. (INCORRECT)" << endl;
	}
	v6 = vec_union(v3, v1);
	if ((v6.size() == 3) && contains(v6, 3) && contains (v6, 11) && contains(v6, 22))
	{
		cout << "\tUnion of vectors v3 "; printVec(v3); cout << " and v1 "; printVec(v1); cout<<" is "; printVec(v6); cout << " == {3, 11, 22}. (CORRECT)" << endl;
		//cout << "\tUnion of vectors v3 and v1 == {3, 11, 22}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tUnion of vectors v3 "; printVec(v3); cout << " and v1 "; printVec(v1); cout<<" is "; printVec(v6); cout << " != {3, 11, 22}. (INCORRECT)" << endl;
	}
	v6 = vec_union(v1, v5);
	if ((v6.size() == 3) && contains(v6, 5) && contains (v6, 11) && contains(v6, 3))
	{
		cout << "\tUnion of vectors v3 "; printVec(v3); cout << " and v1 "; printVec(v1); cout<<" is "; printVec(v6); cout << " == {3, 11, 22}. (CORRECT)" << endl;
		//cout << "\tUnion of vectors v1 and v5 == {3, 5, 11}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tUnion of vectors v1 "; printVec(v1); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " != {3, 5, 11}. (INCORRECT)" << endl;
	}
	// test INTERSECTION
	cout << "\nTESTING INTERSECTION FUNCTION" << endl;
	v6 = intersection(v1, v1);
	if (v6.empty())
		cout << "\tIntersection of 2 empty vectors is empty vector. (CORRECT)" << endl;
	else
	{
		++errors;
		cout << "\tIntersection of 2 empty vectors is "; printVec(v6); cout<< " which is NOT empty vector. (INCORRECT)" << endl;
	}
	v6 = intersection(v3, v5);
	if ((v6.size() == 2) && contains(v6, 3) && contains (v6, 11))
	{
		cout << "\tIntersection of vectors v3 "; printVec(v3); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " == {3, 11}. (CORRECT)" << endl;
		//cout <<endl<< "\tIntersection of vectors v3 and v5 == {3, 11}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tIntersection of vectors v3 "; printVec(v3); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " != {3, 11}. (INCORRECT)" << endl;
	}
	v6 = intersection(v3, v1);
	if (v6.empty())
	{
		cout << "\tIntersection of vectors v3 and v1 is "; printVec(v6); cout<< " is an empty vector. (CORRECT)" << endl;
		//cout << "\tIntersection of vectors v3 and v1 is empty vector. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tIntersection of vectors v3 and v1 is "; printVec(v6); cout<< " which is NOT empty vector. (INCORRECT)" << endl;
	}
	v6 = intersection(v1, v5);
	if (v6.empty())
	{
		cout << "\tIntersection of vectors v1 and v5 is "; printVec(v6); cout<< " is an empty vector. (CORRECT)" << endl;
		//cout << "\tIntersection of vectors v1 and v5 is empty vector. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tIntersection of vectors v1 and v5 is "; printVec(v6); cout<< " which is NOT empty vector. (INCORRECT)" << endl;
	}
	// test DIFFERENCE
	cout << "\nTESTING DIFFERENCE FUNCTION" << endl;
	v6 = difference(v1, v1);
	if (v6.empty())
	{
		cout << "\tDifference of 2 empty vectors is "; printVec(v6); cout<< " is an empty vector. (CORRECT)" << endl;
		//cout << "\tDifference of 2 empty vectors is empty vector. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tDifference of 2 empty vectors is "; printVec(v6); cout<< " which is NOT empty vector. (INCORRECT)" << endl;
	}
	v6 = difference(v3, v5);
	if ((v6.size() == 1) && contains(v6, 22))
	{
		cout << "\tDifference of vectors v3 "; printVec(v3); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " == {22}. (CORRECT)" << endl;
		//cout <<endl<< "\tDifference of vectors v3 and v5 == {22}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tDifference of vectors v3 "; printVec(v3); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " != {22}. (INCORRECT)" << endl;
	}	
	v6 = difference(v3, v1);
	if ((v6.size() == 3) && contains(v6, 3) && contains (v6, 11) && contains(v6, 22))
	{
		cout << "\tDifference of vectors v3 "; printVec(v3); cout << " and v1 "; printVec(v1); cout<<" is "; printVec(v6); cout << " == {3, 11, 22}. (CORRECT)" << endl;
		//cout << "\tDifference of vectors v3 and v1 == {3, 11, 22}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tDifference of vectors v3 "; printVec(v3); cout << " and v1 "; printVec(v1); cout<<" is "; printVec(v6); cout << " != {3, 11, 22}. (INCORRECT)" << endl;
	}
	v6 = difference(v1, v5);
	if (v6.empty())
	{
		cout << "\tDifference of vectors v1 "; printVec(v1); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " == {}. (CORRECT)" << endl;
		//cout << "\tDifference of vectors v1 and v5 == {3, 5, 11}. (CORRECT)" << endl;
	}
	else
	{
		++errors;
		cout << "\tDifference of vectors v1 "; printVec(v1); cout << " and v5 "; printVec(v5); cout<<" is "; printVec(v6); cout << " != {}. (INCORRECT)" << endl;
	}

	cout<<endl<<"Failed "<<errors<<" out of the total test cases"<<endl;
	#ifdef __WIN32__
		system("pause");
	#endif
}