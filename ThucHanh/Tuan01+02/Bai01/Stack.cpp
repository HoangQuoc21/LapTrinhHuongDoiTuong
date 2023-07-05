#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int capacity) {
    _ptr = new int[capacity];
    _capacity = capacity;
    _currentSize = -1;
}

Stack::~Stack() {
    delete[] _ptr;
    cout << "Stack deleted.\n";
}

void Stack::push(const int& element) {
    if (_currentSize + 1 >= _capacity) {
        cout << "Stack is full!\n";
        return;
    }
    else {
        _currentSize++;
        _ptr[_currentSize] = element;
    }
}

int Stack::pop() {
    if (_currentSize >= 0) {
        int topValue = _ptr[_currentSize];
        _currentSize--;
        return topValue;
    }
    else {
        cout << "Stack is empty!\n";
        return -1;
    }
}

int Stack::getCurrentSize() {
    return _currentSize;
}