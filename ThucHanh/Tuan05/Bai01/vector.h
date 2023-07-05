#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;

/* vector class template */
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

template<typename T>
vector<T>::vector() :ptr(NULL), capacity(0), sz(0) {}

template<typename T>
vector<T>::vector(int cap) : ptr(new T[cap]), capacity(cap), sz(0) {}

template<typename T>
vector<T>::~vector() {
	if (ptr != NULL)
		delete[] ptr;
	ptr = NULL;
}

template<typename T>
T& vector<T>::operator[](int n) {
	return ptr[n];
}

template<typename T>
void vector<T>::reserve(int newalloc) {
	if (newalloc <= capacity)
		return;
	T* newptr = new T[newalloc];
	for (int i = 0; i < sz; i++)
		newptr[i] = ptr[i];
	if (ptr != NULL)
		delete[] ptr;
	ptr = newptr;
	capacity = newalloc;
}

template<typename T>
void vector<T>::push(const T& element) {
	if (sz == capacity)
		reserve(capacity == 0 ? 1 : capacity + 1);
	ptr[sz] = element;
	sz++;
}

template<typename T>
void vector<T>::print() {
	for (int i = 0; i < sz; i++)
		cout << ptr[i] << " ";
	cout << endl;
}

#endif