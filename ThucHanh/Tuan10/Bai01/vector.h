#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

template<typename T>
class vector {
private:
	T* ptr;
	int capacity;
	int sz;
public:
	// Constructors
	vector();
	vector(int cap);
	~vector();
	// utilities methods
	/* operator[] */
	T& operator[](int n);
	/* Expand extra memory */
	void reserve(int newalloc);
	// input, output
	void push(const T& element);
	void print();
};

#endif