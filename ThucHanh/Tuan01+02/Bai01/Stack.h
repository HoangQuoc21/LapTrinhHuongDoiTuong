#pragma once
class Stack
{
private:
    int* _ptr;
    int _capacity;
    int _currentSize;
public:
    // Constructor
    Stack(int capacity);
    // destructor
    ~Stack();
    // Thêm phần tử vào stack, them vào cuối
    void push(const int& element);
    // Lấy phần tử khỏi stack, Lấy ra ở cuối theo LIFO
    int pop();

    int getCurrentSize();
};

