#include <iostream>
#include "myArray.h"
using namespace std;

int main() {
	int n1 = 10;
	MyIntArray a1(10);
	for (int i = 0; i < 10; i++)
		a1[i] = i;

	cout << "Test phuong thuc print()\n";
	cout << "a1: ";
	a1.print();
	cout << endl;

	MyIntArray a2(a1);
	cout << "a2: ";
	for (int i = 0; i < n1; i++)
		cout << a2[i] << " ";
	cout << endl;
	cout << endl;

	cout << "1. Test copy constructor\n";
	MyIntArray a3 = a2;
	cout << "a3: ";
	a3.print();
	cout << endl;

	int n4 = 20;
	MyIntArray a4(20);
	for (int i = 0; i < 20; i++)
		a4[i] = i;
	cout << "a4: ";
	a4.print();
	cout << endl;

	cout << "2. Test toan tu =\n";
	a4 = a3;
	cout << "a4 luc sau: ";
	a4.print();
	cout << endl;

	MyIntArray a5;
	a5 = a4;
	cout << "a5: ";
	a5.print();


	return 0;
}