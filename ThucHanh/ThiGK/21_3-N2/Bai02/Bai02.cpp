#include <iostream>
#include "QL_Phim.h"
using namespace std;

int main() {
	QL_Phim ql;
	ql.nhap_dsPhim();
	int choice;
	while (1) {
		system("cls");
		cout << "Danh Sach Phim:\n";
		cout << "======================================================\n";
		ql.xuat_dsPhim();
		cout << "======================= MENU =========================\n";
		cout << "1. Tim cac phim co xep hang cao nhat theo the loai.\n";
		cout << "2. Xoa cac phim co NXH HBO va co nam san xuat < 2000.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "======================================================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Cac phim co xep hang cao nhat theo the loai la:\n";
			cout << "----------------------------------------------------\n";
			ql.xepHang_caoNhat_TheLoai();
		}
		else if (choice == 2) {
			ql.xoa_phim();
			cout << "Da xoa cac phim theo yeu cau.\n";
		}
		else if (choice == 0) {
			break;
		}
		else
			cout << "Lua chon khong hop le.\n";
		system("pause");
	}
	cout << "*Ket thuc chuong trinh*.\n";
	return 0;
}