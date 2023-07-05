#include <iostream>
#include "CongTy.h"
using namespace std;

int main() {
	system("cls");
	CongTy a;
	int choice;
	char id[6], ten[50];
	char file[] = "ds_NhanVien.dat";
	a.nhap();

	while (1) {
		system("cls");

		cout << "*Cong ty a:\n";
		cout << "*Danh sach nhan vien trong cong ty: \n";
		cout << "=======================================================\n";
		a.xuat();

		cout << "======================================================\n";
		if (a.soNhanVien() != 0) {
			cout << "*Tong tien luong cac nhan vien: " << a.tongTienLuong() << endl;
			cout << "*Luong trung binh cua cong ty: " << a.luongTrungBinh() << endl;
			cout << "*So luong nhan vien sinh trong thang 5: " << a.soNVSinhThang5() << endl;
			char lower[] = "emp_LowerAvgSalary.dat";
			a.ghiLuongNhoHonLTBRaFile(lower);
			cout << "*Da ghi Cac nhan vien co luong nho hon luong trung binh cua cong ty vao file.\n";
		}

		cout << "========================== MENU ======================\n";
		cout << "1. Tim nhan vien co luong cao nhat.\n";
		cout << "2. Tim nhan vien theo ma.\n";
		cout << "3. Tim nhan vien theo ten.\n";
		cout << "4. Them mot nhan vien vao cuoi danh sach.\n";
		cout << "5. Xoa mot nhan vien khoi danh sach theo ma.\n";
		cout << "6. Ghi danh sach nhan vien ra file.\n";
		cout << "7. Doc danh sach nhan vien tu file.\n";
		cout << "0. Thoat Menu.\n";
		cout << "======================================================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 1) {
			a.NVLuongCaoNhat();
		}
		else if (choice == 2) {
			cout << "*Nhap vao ma nhan vien muon tim: ";
			cin.ignore();
			cin.getline(id, 6);
			NhanVien* tim = a.timNVMa(id);
			if (!tim)
				cout << "*Khong co nhan vien nao co ma " << id << endl;
			else{
				cout << "*Thong tin cua nhan vien co ma " << id << " la:\n";
				cout << "------------------------------------------------------\n";
				cout << tim;
			}
		}
		else if (choice == 3) {
			cout << "*Nhap vao ho ten nhan vien muon tim: ";
			cin.ignore();
			cin.getline(ten, 50);
			a.timNVTen(ten);
		}
		else if (choice == 4) {
			cout << "*Nhap vao thong tin cua nhan vien muon them: \n";
			NhanVien* them;
			cout << "1. NVCongNhat.\n";
			cout << "2. NVSanXuat.\n";
			cout << "------------------------\n";
			cout << "Chon loai nhan vien: ";
			cin >> choice;
			if (choice == 1)
				them = new NVCongNhat();
			else if (choice == 2)
				them = new NVSanXuat();
			cin >> them;
			cout << "---------------------------------------------------------\n";
			a.themNV(them->kieuNV(), them->getMa(), them->getTen(), them->getGioiTinh(), them->getNgaySinh(), them->getDiaChi(), them->getSL());
			cout << "*Da them nhan vien moi vao danh sach.\n";
			a.ghiFile(file);
			cout << "*Da cap nhat lai file ds_NhanVien.\n";
			delete them;
		}
		else if (choice == 5) {
			cout << "*Nhap vao ma cua nhan vien muon xoa: ";
			cin.ignore();
			cin.getline(id, 20);
			if (a.xoaNV(id)) {
				cout << "*Da xoa nhan vien co ma " << id << endl;
				a.ghiFile(file);
				cout << "*Da cap nhat lai file ds_NhanVien.\n";
			}
			else {
				cout << "*Khong co nhan vien nao co ma " << id << endl;
			}
		}
		else if (choice == 6) {
			a.ghiFile(file);
			cout << "*Da ghi danh sach nhan vien ra file ds_NhanVien.\n";
		}
		else if (choice == 7) {
			a.docFile(file);
			cout << "*Da doc danh sach nhan tu file ds_NhanVien.\n";
		}
		else if (choice == 0) {
			break;
		}
		else
			cout << "*Lua chon khong hop le.\n";

		cout << "------------------------------------------------------\n";
		system("pause");
	}

	system("cls");
	cout << "======================== Test copy constructor =========================\n";
	CongTy b(a);
	a.~CongTy();
	cout << "*Cong ty b duoc khoi tao copy tu cong ty a co danh sach nhan vien la:\n";
	b.xuat();

	system("pause");
	system("cls");

	cout << "======================= Test assignment operator =======================\n";
	CongTy c;
	c = b;
	b.~CongTy();
	cout << "*Cong ty c duoc gan bang cong ty b co danh sach nhan vien la:\n";
	c.xuat();
	return 0;
}