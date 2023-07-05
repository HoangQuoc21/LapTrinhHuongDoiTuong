#include "queue.h"
#include <iostream>
using namespace std;

template<class T>
queue<T>::queue() {
	a = NULL;
	n = 0;
}

template<class T>
void queue<T>::enqueue(T x) {
	T* b = new T[n + 1];
	if (a != NULL) {
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		delete[]a;
	}
	b[n] = x;
	n++;
	a = b;
}

template<class T>
void queue<T>::dequeue() {
	if (empty())
		return;
	T* b = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
		b[i] = a[i + 1];
	delete[]a;
	n--;
	a = b;
}

template<class T>
T queue<T>::front() {
	return a[0];
}

template<class T>
bool queue<T>::empty() {
	return (n == 0);
}

template<class T>
void queue<T>::print() {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

template<class T>
queue<T>::~queue() {
	if (a != NULL) {
		delete[]a;
	}
	a = NULL;
	n = 0;
}