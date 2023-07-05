#include <iostream>
#include "ComplexShape.h"
using namespace std;

int main() {
	ComplexShape cs;
	cs.input();
	system("cls");
	cout << "Complex shape inputed:\n";
	cs.print();
	cout << "Number of Cirle: " << cs.circle_Num() << endl;
	cout << "Number of Rectangle: " << cs.rectangle_Num() << endl;
	return 0;
}