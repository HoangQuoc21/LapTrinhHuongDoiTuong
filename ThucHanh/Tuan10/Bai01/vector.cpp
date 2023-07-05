#include "vector.h"

template<typename T>
vector<T>::vector() {
	ptr = NULL;
	capacity = sz = 0;
}

template<typename T>
vector<T>::vector(int cap) {
	capacity = cap;
	sz = 0;
	ptr = new T[capacity];
}

template<typename T>
vector<T>::~vector() {
	if (ptr != NULL) {
		delete[]ptr;
		capacity = sz = 0;
		ptr = NULL;
	}
}

template<typename T>
T& vector<T>::operator[](int n) {
	return ptr[n];
}

template<typename T>
void vector<T>::reserve(int newalloc) {
	T* b = new T[capacity + newalloc];
	for (int i = 0; i < sz; i++)
		b[i] = ptr[i];
	if (ptr != NULL)
		delete[] ptr;
	ptr = b;
	capacity += newalloc;
}

template<typename T>
void vector<T>::push(const T& element) {
	if (sz == capacity)
		reserve(capacity + 1);
	ptr[sz] = element;
	sz++;
}

template<typename T>
void vector<T>::print() {
	for (int i = 0; i < sz; i++)
		cout << ptr[i] << " ";
	cout << endl;
}