#include <iostream>
#include "vector.cpp"
using namespace std;

int main() {
	vector<int> a(10);
	for (int i = 0; i < 10; i++)
		a.push(i);
	a.print();
	cout << "-----------------------------------------------\n";

	a.reserve(10);
	for (int i = 10; i < 15; i++)
		a.push(i);
	a.print();
	cout << "-----------------------------------------------\n";
	cout << "a[0] = " << a[0] << endl;
	return 0;
}