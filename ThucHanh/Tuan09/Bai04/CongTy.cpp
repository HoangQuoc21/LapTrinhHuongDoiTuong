#include "CongTy.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

CongTy::CongTy() {
	nv = NULL;
	n = 0;
}

CongTy::CongTy(const CongTy& cty) {
	n = cty.n;
	nv = new NhanVien * [n];
	for (int i = 0; i < n; i++) {
		char kieu[20];
		strcpy(kieu, cty.nv[i]->kieuNV());
		if (!strcmp(kieu,"NVCongNhat")) {
			nv[i] = new NVCongNhat(cty.nv[i]->getMa(), cty.nv[i]->getTen(), cty.nv[i]->getGioiTinh(), cty.nv[i]->getNgaySinh(), cty.nv[i]->getDiaChi(), cty.nv[i]->getSL());
		}
		else if (!strcmp(kieu, "NVSanXuat")) {
			nv[i] = new NVSanXuat(cty.nv[i]->getMa(), cty.nv[i]->getTen(), cty.nv[i]->getGioiTinh(), cty.nv[i]->getNgaySinh(), cty.nv[i]->getDiaChi(), cty.nv[i]->getSL());
		}
	}
}

CongTy::~CongTy() {
	if (nv != NULL) {
		for (int i = 0; i < n; i++)
			delete nv[i];
		delete []nv;
		nv = NULL;
		n = 0;
		//cout << "Da xoa cong ty.\n";
	}
}

void CongTy::nhap() {
	if (nv == NULL) {
		cout << "Nhap vao so luong nhan vien: ";
		cin >> n;
		nv = new NhanVien * [n];
		cout << "=======================================================\n";
	}
	int choice;
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao thong tin nhan vien thu " << i + 1 << endl;
		cout << "1. NVCongNhat.\n";
		cout << "2. NVSanXuat.\n";
		cout << "------------------------\n";
		cout << "Chon loai nhan vien: ";
		cin >> choice;
		if (choice == 1)
			nv[i] = new NVCongNhat();
		else if (choice == 2)
			nv[i] = new NVSanXuat();
		cin >> nv[i];
		cout << "---------------------------------------------------------\n";
	}
}

void CongTy::xuat() {
	for (int i = 0; i < n; i++) {
		cout << "Thong tin nhan vien thu " << i + 1 << endl;
		cout << "-------------------------\n";
		char kieu[20];
		strcpy(kieu, nv[i]->kieuNV());
		cout << "-Kieu nhan vien: " << kieu << endl;
		cout << nv[i];
		cout << "---------------------------------------------------------\n";
	}
}

int CongTy::soNhanVien() {
	return n;
}

CongTy& CongTy::operator=(const CongTy& cty) {
	if (this->nv == NULL) {
		this->n = cty.n;
		this->nv = new NhanVien * [n];
	}
	for (int i = 0; i < n; i++) {
		char kieu[20];
		strcpy(kieu, cty.nv[i]->kieuNV());
		if (!strcmp(kieu, "NVCongNhat")) {
			this->nv[i] = new NVCongNhat(cty.nv[i]->getMa(), cty.nv[i]->getTen(), cty.nv[i]->getGioiTinh(), cty.nv[i]->getNgaySinh(), cty.nv[i]->getDiaChi(), cty.nv[i]->getSL());
		}
		else if (!strcmp(kieu, "NVSanXuat")) {
			this->nv[i] = new NVSanXuat(cty.nv[i]->getMa(), cty.nv[i]->getTen(), cty.nv[i]->getGioiTinh(), cty.nv[i]->getNgaySinh(), cty.nv[i]->getDiaChi(), cty.nv[i]->getSL());
		}
	}
	return *this;
}

void CongTy::ghiFile(char* tenFile) {
	ofstream fout(tenFile);
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		nv[i]->ghiFile(fout);
	}
	fout.close();
}

void CongTy::docFile(char* tenFile) {
	ifstream fin(tenFile);
	char line[200];
	fin.getline(line, 200,'\n');
	
	int n2 = atoi(line);
	
	for (int i = 0; i < n2; i++) {
		fin.getline(line, 200, '\n');
		stringstream ss(line);
		char kieu[20];
		char ma[10];
		char hoTen[50];
		char gioi[4];
		char ngaySinh[20];
		char diaChi[50];
		char sl[5];
		ss.getline(kieu, 20, '|');
		ss.getline(ma, 10, '|');
		ss.getline(hoTen, 50, '|');
		ss.getline(gioi, 4, '|');
		ss.getline(ngaySinh, 20, '|');
		ss.getline(diaChi, 50, '|');
		ss.getline(sl, 5, '\n');
		themNV(kieu,ma, hoTen,gioi, ngaySinh, diaChi, atoi(sl));
	}
	
	fin.close();
}

long CongTy::tongTienLuong() {
	long tong = 0;
	for (int i = 0; i < n; i++)
		tong += nv[i]->tinhLuong();
	return tong;
}

void CongTy::NVLuongCaoNhat() {
	long luongMax = INT_MIN;
	for (int i = 0; i < n; i++)
		if (nv[i]->tinhLuong() > luongMax)
			luongMax = nv[i]->tinhLuong();
	cout << "Cac nhan vien co luong cao nhat (" << luongMax << ") la:\n";
	cout << "======================================================\n";
	for (int i = 0; i < n; i++) {
		if (nv[i]->tinhLuong() == luongMax) {
			char kieu[20];
			strcpy(kieu, nv[i]->kieuNV());
			cout << "-Kieu nhan vien: " << kieu << endl;
			cout << nv[i];
			cout << "------------------------------------------------------\n";
		}
	}
}

long CongTy::luongTrungBinh() {
	long trungBinh = tongTienLuong();
	trungBinh /= n;
	return trungBinh;
}

NhanVien* CongTy::timNVMa(char* ma) {
	for (int i = 0 ; i < n; i++)
		if (!strcmp(nv[i]->getMa(), ma)) {
			return nv[i];
		}
	return NULL;
}

void CongTy::timNVTen(char* ten) {
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (!strcmp(nv[i]->getTen(), ten))
			dem++;
	if (dem == 0) {
		cout << "*Khong co nhan vien nao co ten la " << ten << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		if (!strcmp(nv[i]->getTen(), ten)) {
			cout << "*Thong tin cua nhung nhan vien co ho ten " << ten << " la:\n";
			cout << nv[i];
			cout << "-------------------------------------------------------\n";
		}
}

void CongTy::themNV(char* k, char* m, char* ten,char* gioi, char* ns, char* dc, int sl) {
	NhanVien** b = new NhanVien * [n + 1];
	for (int i = 0; i < n; i++) {
		char kieu[20];
		strcpy(kieu, nv[i]->kieuNV());
		if (!strcmp(kieu, "NVCongNhat")) 
			b[i] = new NVCongNhat(nv[i]->getMa(), nv[i]->getTen(), nv[i]->getGioiTinh(), nv[i]->getNgaySinh(), nv[i]->getDiaChi(), nv[i]->getSL());
		else if (!strcmp(kieu, "NVSanXuat"))
			b[i] = new NVSanXuat(nv[i]->getMa(), nv[i]->getTen(), nv[i]->getGioiTinh(), nv[i]->getNgaySinh(), nv[i]->getDiaChi(), nv[i]->getSL());
	}
	if (!strcmp(k, "NVCongNhat"))
		b[n] = new NVCongNhat(m, ten, gioi, ns, dc, sl);
	else if (!strcmp(k, "NVSanXuat"))
		b[n] = new NVSanXuat(m, ten, gioi, ns, dc, sl);

	
	for (int i = 0; i < n; i++)
		delete nv[i];
	delete[]nv;

	n++;
	nv = b;
}

bool CongTy::xoaNV(char* ma) {
	if (n <= 0 || !timNVMa(ma))
		return false;
	NhanVien** b = new NhanVien * [n - 1];
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(ma, nv[i]->getMa())) {
			char kieu[20];
			strcpy(kieu, nv[i]->kieuNV());
			if (!strcmp(kieu, "NVCongNhat"))
				b[temp] = new NVCongNhat(nv[i]->getMa(), nv[i]->getTen(), nv[i]->getGioiTinh(), nv[i]->getNgaySinh(), nv[i]->getDiaChi(), nv[i]->getSL());
			else if (!strcmp(kieu, "NVSanXuat"))
				b[temp] = new NVSanXuat(nv[i]->getMa(), nv[i]->getTen(), nv[i]->getGioiTinh(), nv[i]->getNgaySinh(), nv[i]->getDiaChi(), nv[i]->getSL());
			temp++;
		}
	}
	for (int i = 0; i < n; i++)
		delete nv[i];
	delete[]nv;

	n = temp;
	nv = b;
	return true;
}

void CongTy::ghiLuongNhoHonLTBRaFile(char* tenFile) {
	long ltb = luongTrungBinh();
	ofstream fout(tenFile);
	fout << "Danh Sach Nhan Vien Co Luong Nho Hon LTB Cong Ty (" << ltb << ") la:\n";
	fout << "=============================================================\n";
	for (int i = 0; i < n; i++) {
		if (nv[i]->tinhLuong() < ltb)
			nv[i]->ghiFile(fout);
	}
	fout.close();
}

int CongTy::soNVSinhThang5() {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		stringstream ss(nv[i]->getNgaySinh());
		string day;
		getline(ss, day, '/');
		string month;
		getline(ss, month, '/');
		if (stoi(month) == 5)
			dem++;
	}
	return dem;
}