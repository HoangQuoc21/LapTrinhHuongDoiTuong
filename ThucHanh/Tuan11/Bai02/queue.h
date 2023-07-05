#pragma once

template<class T>
class queue
{
private:
	T* a;
	int n;
public:
	queue();
	void enqueue(T x);
	void dequeue();
	T front();
	bool empty();
	void print();
	~queue();
};