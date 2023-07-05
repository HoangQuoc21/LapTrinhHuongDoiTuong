#include <iostream>
#include "Divide.h"
using namespace std;

int main() {
	Divide div;
	int n;
	cout << "Nhap so lan muon thuc hien phep chia: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		system("cls");
		cout << "*Lan chia thu " << i << endl;
		div.input();
		cout << "---------------------------------------\n";
		try {
			double result = div.division();
			cout << "*Ket qua phep chia la: " << result << endl;
		}
		catch (myException e) {
			cout << "*Co loi: " << e.getMessage() << endl;
		}

		system("pause");
	}
	cout << "*Ket thuc chuong trinh*";
	return 0;
}