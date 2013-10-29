#ifndef _VECTOR_FUNCS_TPT_H
#define _VECTOR_FUNCS_TPT_H

#include <vector>
#include <stdexcept>
using std::vector;

// TO-DO: implement recursive versions of following functions and modify provided wrapper functions to call recursive functions:
// MAX, MIN, SUM, FIND, CONTAINS, VEC_UNION, INTERSECTION, DIFFERENCE

// Notice I'm giving you the 'normal' interfaces (i.e. the 'wrapper' functions)
// the recursive ones you write may take extra parameters (and then you make the wrappers call them)

// returns the largest element in the vector, throws a domain_error exception if vector is empty
// finds the largest element in the vector RECURSIVELY
template <typename T> T max(const vector<T>&v, unsigned i, T m){
	if((i+1) > v.size()) return m;
	return max(v, i+1, ((v[i] > m) ? v[i] : m));
}

template <typename T> T max(const vector<T>&v){
	if(v.empty())
		throw std::domain_error("Empty vector");
	return max(v, 0, T());		
}

// returns the smallest element in the vector, throws a domain_error exception if vector is empty
template <typename T> T min(const vector<T>&v, unsigned i, T m){
	if((i+1) > v.size()) return m;
	return min(v, i+1, ((v[i] > m) ? m : v[i]));
}

template <typename T> T min(const vector<T>&v) {
	if(v.empty())
		throw std::domain_error("Empty vector");
	return min(v, 0, v[0]);	
}

// returns the sum of all elements in the vector (0 if empty)
// DO NOT THROW EXCEPTION IF EMPTY 
template <typename T> T sum(const vector<T>&v, unsigned i){
	if(i+2 > v.size()) return v[i];
	return v[i] + sum(v, i+1);
}

template <typename T> T sum(const vector<T>&v){
	if(v.empty()) return T();
	return sum(v, 0);
}

// returns index of first element with that value, -1 if not found
// DO NOT THROW EXCEPTION IF EMPTY
template <typename T> int find(const vector<T>&v, T value){
	for(int i = 0; i < v.size(); i++)
		if(v[i] == value) return i;
	return -1;
}

// returns true if vector contains that element, 0 otherwise
// DO NOT THROW EXCEPTION IF EMPTY
template <typename T> bool contains(const vector<T>&v, T value) {
	for(int i = 0; i < v.size(); i++)
		if(v[i] == value) return true;
	return false;
}

// returns a new vector; every element in v1 and every element in v2 are also in this new vector
// if an element appears in both v1 and v2, it is only added once to the new vector
template <typename T> vector<T> vec_union(vector<T> &v3, vector<T> &v2, unsigned i) {
	if(i+1 > v2.size()) return v3;
	if(!contains(v3,v2[i])) v3.push_back(v2[i]);
	return vec_union(v3, v2, i+1); 
}

template <typename T> vector<T> vec_union(vector<T> &v1, vector<T> &v2)
{
	if(v1.empty() && v2.empty()) return vector<T>();
	vector<T> v3 = v1;

	return vec_union(v3, v2, 0);
}

// returns a new vector; every element that is in both v1 and v2 are also in this new vector
// there are no duplicates in v1 and v2
template <typename T> vector<T> intersection(vector<T> &v3, vector<T> &v2, unsigned i) {
	if(i+1 > v3.size()) return v3;
	intersection(v3,v2,i+1);
	if(!contains(v2,v3[i])) v3.erase(v3.begin() + i);
	return v3;
}

template <typename T> vector<T> intersection(vector<T> v1, vector<T> v2)
{
	if(v1.empty() || v2.empty()) return vector<T>();
	vector<T> v3 = v1;

	return intersection(v3, v2, 0);
}

// returns a new vector; every element that is in v1 but not v2 are also in this new vector
// there are no duplicates in v1 and v2
template <typename T> vector<T> difference(vector<T> &v3, vector<T> &v2, unsigned i) {
	if(i+1 > v3.size()) return v3;
	difference(v3,v2,i+1);
	if(contains(v2,v3[i])) v3.erase(v3.begin() + i);
	return v3;
}
 
template <typename T> vector<T> difference(vector<T> v1, vector<T> v2)
{	
	if(v1.empty() && v2.empty()) return vector<T>();
	vector<T> v3 = v1;

	return difference(v3, v2, 0);
}

// END OF TO-DO
#endif