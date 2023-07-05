#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int soNgauNhien(int min, int max) {
	return rand() % (max - min + 1) + min;
}


int main() {
	srand(time(NULL));

	while (1) {
		system("cls");



		system("pause");
	}
	return 0;
}