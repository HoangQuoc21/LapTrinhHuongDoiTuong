#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class vector {
private:
	T* ptr;
	int capacity;
	int sz;
public:
	
	vector();
	vector(int cap);
	~vector();

	T& operator[](int n);
	void reserve(int newalloc);
	void push(const T& element);
	void print();
	int size();
};

#endif