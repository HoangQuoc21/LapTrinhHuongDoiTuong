#include "AgeInput.h"

AgeInput::AgeInput() {
	lowerBound = DEFAULT_LOWER_BOUND;
	upperBound = DEFAULT_UPPER_BOUND;
}

AgeInput::AgeInput(int low, int high) {
	lowerBound = low;
	upperBound = high;
}

int AgeInput::getAge(string promt) {
	int age;
	cout << promt << "Enter age: ";
	cin >> age;
	if (age < lowerBound || age > upperBound)
		throw -1;
	return age;
}