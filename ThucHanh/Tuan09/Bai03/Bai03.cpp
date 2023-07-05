#include <iostream>
#include "AgeInput.h"
using namespace std;

int main() {
	int n, lower, upper;
	cout << "*Input number of age checking: ";
	cin >> n;
	cout << "*Input lower bound: ";
	cin >> lower;
	cout << "*Input upper bound: ";
	cin >> upper;
	AgeInput ai(lower, upper);
	cout << "-----------------------------------------\n";
	for (int i = 1; i <= n; i++) {
		try {
			int age = ai.getAge();
			cout << "Input okay. Age = " << age << endl;
		}
		catch (int e) {
			if (e == -1)
				cout << "Input out of bound!" << endl;
		}
	}
	return 0;
}