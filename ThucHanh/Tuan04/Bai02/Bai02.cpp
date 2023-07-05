#include <iostream>
#include "CongTy.h"
using namespace std;

int main() {
	system("cls");
	CongTy a;
	string choice, id, ten;
	a.nhap();
	while (1) {
		system("cls");
		cout << "*Cong ty a:\n";
		cout << "*Danh sach nhan vien trong cong ty: \n";
		a.xuat();
		cout << "======================================================\n";
		if (a.soNhanVien() != 0) {
			cout << "*Tong tien luong cac nhan vien: " << a.tongLuong() << endl;
			cout << "*Luong trung binh cua cong ty: " << a.luongTB() << endl;
			cout << "*So luong nhan vien sinh trong thang 5: " << a.soNVSinhThang5() << endl;
			a.ghiNVLuongNhoHonLuongTB();
			cout << "*Da ghi Cac nhan vien co luong nho hon luong trung binh cua cong ty vao file.\n";
		}
		
		cout << "========================== MENU ======================\n";
		cout << "1. Tim nhan vien co luong cao nhat.\n";
		cout << "2. Tim nhan vien theo ma.\n";
		cout << "3. Tim nhan vien theo ten.\n";
		cout << "4. Them mot nhan vien vao cuoi danh sach.\n";
		cout << "5. Xoa mot nhan vien khoi danh sach theo ma.\n";
		cout << "0. Thoat Menu.\n";
		cout << "======================================================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == "1") {
			cout << "*Thong tin nhan vien co luong cao nhat la:\n";
			NhanVien* maxLuong = a.NVLuongCaoNhat();
			maxLuong->xuat();
			cout << "-Luong: " << maxLuong->luong() << endl;
		}
		else if (choice == "2") {
			cout << "*Nhap vao ma nhan vien muon tim: ";
			cin >> id;
			NhanVien* tim = a.timNVMa(id);
			if (tim) {
				cout << "*Thong tin cua nhan vien co ma " << id << " la : \n";
				tim->xuat();
			}
			else {
				cout << "*Khong tim duoc nhan vien co ma " << id << endl;
			}
		}
		else if (choice == "3") {
			cout << "*Nhap vao ten nhan vien muon tim: ";
			cin >> ten;
			NhanVien* tim = a.timNVTen(ten);
			if (tim) {
				cout << "*Thong tin cua nhan vien co ten " << ten << " la : \n";
				tim->xuat();
			}
			else {
				cout << "*Khong tim duoc nhan vien co ten " << ten << endl;
			}
		}
		else if (choice == "4") {
			cout << "*Nhap vao thong tin cua nhan vien muon them: \n";
			a.themNV();
			cout << "*Da them nhan vien moi vao danh sach.\n";
		}
		else if (choice == "5") {
			cout << "*Nhap vao ma cua nhan vien muon xoa: ";
			cin >> id;
			a.xoaNV(id);
			
		}
		else if (choice == "0") {
			break;
		}
		else
			cout << "Lua chon khong hop le.\n";
		system("pause");
	}

	system("cls");
	cout << "======================= Test assignment operator =======================\n";
	CongTy b;
	b = a;
	a.~CongTy();
	cout << "*Cong ty b duoc gan bang cong ty a co danh sach nhan vien la:\n";
	b.xuat();
	return 0;
}