#include "Divide.h"

Divide::Divide() {
	num1 = num2 = 1;
}

Divide::~Divide() {

}

void Divide::input() {
	cout << "-Nhap so bi chia: ";
	cin >> num1;
	cout << "-Nhap so chia: ";
	cin >> num2;
}

double Divide::division() {
	if (num2 == 0)
		throw myException("Loi chia cho so 0");
	return (double)num1 / num2;
}