#include <iostream>
#include "QLThuVien.h"
using namespace std;



int main() {
	QLThuVien ql;
	int choice;
	ql.NhapDSDG();
	while (1) {
		system("cls");
		cout << "DS DOC GIA:\n";
		cout << "===================================================\n";
		ql.XuatDSDG();
		cout << "======================== MENU =====================\n";
		cout << "1. Tinh tong tien phi DSDG.\n";
		cout << "2. Them doc gia.\n";
		cout << "3. Liet ke doc gia het han truoc 05/05/2023.\n";
		cout << "===================================================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 1)
			cout << "Tong tien phi la : " << ql.TongTien() << endl;
		else if (choice == 2)
			ql.Them();
		else if (choice == 3)
			ql.HetHan();
		else if (choice == 0)
			break;
		else
			cout << "Lua chon khong hop le.\n";
		system("pause");
	}
	cout << "*Ket thuc chuong trinh*.\n";
}