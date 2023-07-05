#include <iostream>
#include "QL_Phim.cpp"
using namespace std;

int main() {
	QL_Phim<Phim*> ql;
	char file[] = "ds_phim.dat";
	int choice;

	ql.nhap();
	
	while (1) {
		system("cls");
		cout << "*Phim da nhap:\n";
		cout << "<Ma So|Ten|The Loai|Nha San Xuat|Nam San Xuat|Xep Hang>\n";
		cout << "==============================================================\n";
		ql.xuat();
		cout << "============================= MENU ===========================\n";
		cout << "1.Them mot phim\n";
		cout << "2.Ghi danh sach phim ra file " << file << endl;
		cout << "3.Doc danh sach  phim tu file " << file << endl;
		cout << "4.Xoa cac phim co nha san xuat \"HBO\"\n";
		cout << "0.Thoat Menu\n";
		cout << "==============================================================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 1) {
			ql.themPhim();
			cout << "*Da them phim vao danh sach.\n";
		}
		else if (choice == 2) {
			ql.ghiFile(file);
			cout << "*Da ghi danh sach phim ra file " << file << endl;
		}
		else if (choice == 3) {
			ql.docFile(file);
			cout << "*Da doc danh sach  phim tu file " << file << endl;
		}
		else if (choice == 4) {
			ql.xoaPhimNXSHBO();
			cout << "*Da xoa cac phim co nha san xuat \"HBO\"\n";
			ql.ghiFile(file);
			cout << "*Da cap nhat lai danh sach phim tren file " << file << endl;
		}
		else if (choice == 0)
			break;
		else
			cout << "*Lua chon khong hop le.\n";

		system("pause");
	}
	
	cout << "*Ket thuc chuong trinh.*\n";
	return 0;
}