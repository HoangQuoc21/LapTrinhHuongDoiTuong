//#include "MyVector.h"
//
//template<typename T>
//
//MyVector<T>::MyVector() : ptr(NULL), capacity(0), sz(0) {}
//
//template<typename T>
//MyVector<T>::MyVector(int cap) : ptr(new T[cap]), capacity(cap), sz(0) {}
//
//template<typename T>
//MyVector<T>::~MyVector() {
//	if (ptr != NULL)
//		delete[] ptr;
//	ptr = NULL;
//}
//
//template<typename T>
//T& MyVector<T>::operator[](int n) {
//	return ptr[n];
//}
//
//template<typename T>
//void MyVector<T>::reserve(int newalloc) {
//	if (newalloc <= capacity) return;
//	T* newptr = new T[newalloc];
//	for (int i = 0; i < sz; i++)
//		newptr[i] = ptr[i];
//	delete[] ptr;
//	ptr = newptr;
//	capacity = newalloc;
//}
//
//template<typename T>
//void MyVector<T>::push(const T& element) {
//	if (sz == capacity)
//		reserve(capacity == 0 ? 1 : capacity * 2);
//	ptr[sz] = element;
//	sz++;
//}
//
//template<typename T>
//void MyVector<T>::print() {
//	for (int i = 0; i < sz; i++)
//		cout << ptr[i] << " ";
//	cout << endl;
//}
//
//template class MyVector<int>;