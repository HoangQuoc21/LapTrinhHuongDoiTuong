#include <iostream>
#include "vector.h"
using namespace std;

int main() {
	cout << "Int vector: \n";
	vector<int> v;
	v.push(1);
	v.push(2);
	v.push(3);
	v.print();
	cout << "---------------------------------\n";

	cout << "Float vector:\n";
	vector<float> v1(3);
	v1.push(1.2);
	v1.push(3.4);
	v1.push(5.6);
	v1.push(7.8);
	v1.print();
	cout << "---------------------------------\n";

	cout << "String vector: \n";
	vector<string> v2;
	v2.push("Lam");
	v2.push("Hoang");
	v2.push("Quoc");
	v2.print();
	return 0;
}