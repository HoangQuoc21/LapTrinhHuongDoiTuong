#define _CRT_SECURE_NO_WARNINGS
#include "CongTy.h"
#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

CongTy::CongTy() {
	nv = NULL;
	n = 0;
}
CongTy::~CongTy() {
	n = 0;
	if (nv != NULL) {
		for (int i = 0; i < n; i++)
			delete nv[i];
		delete nv;
		nv = NULL;
	}
}

void CongTy::nhap() {
	cout << "Nhap vao so luong nhan vien: ";
	cin >> n;
	nv = new NhanVien * [n];
	int choice;
	cout << "==========================================\n";
	for (int i = 0; i < n; i++) {
		cout << "--------------------------------------\n";
		cout << "1. NVSanXuat.\n";
		cout << "2. NVCongNhat.\n";
		cout << "Nhap vao kieu nhan vien: ";
		cin >> choice;
		if (choice == 1)
			nv[i] = new NVSanXuat;
		else if (choice == 2)
			nv[i] = new NVCongNhat;
		nv[i]->nhap();
	}
}

void CongTy::xuat() {
	for (int i = 0; i < n; i++) {
		cout << "-----------------------------------\n";
		cout << "*Nhan Vien " << i + 1 << ", ";
		nv[i]->xuat();
		
	}
}
long CongTy::tongLuong() {
	long tong = 0;
	for (int i = 0; i < n; i++)
		tong += nv[i]->luong();
	return tong;
}

NhanVien* CongTy::NVLuongCaoNhat() {
	long maxLuong = 0;
	NhanVien* nvMaxLuong = NULL;
	for (int i = 0; i < n; i++)
		if (nv[i]->luong() > maxLuong) {
			maxLuong = nv[i]->luong();
			nvMaxLuong = nv[i];
		}
	return nvMaxLuong;
}

float CongTy::luongTB() {
	float tbLuong = (float)this->tongLuong();
	tbLuong /= n;
	return tbLuong;
}

NhanVien* CongTy::timNVMa(string id) {
	for (int i = 0; i < n; i++)
		if (nv[i]->id() == id)
			return nv[i];
	return NULL;
}

NhanVien* CongTy::timNVTen(string hoTen) {
	for (int i = 0; i < n; i++)
		if (nv[i]->ten() == hoTen)
			return nv[i];
	return NULL;
}

int CongTy::soNVSinhThang5() {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		stringstream ss(nv[i]->ngaySinh());
		string day;
		getline(ss, day, '/');
		string month;
		getline(ss, month, '/');
		if (stoi(month) == 5)
			dem++;
	}
	return dem;
}

void CongTy::themNV() {
	NhanVien** b;
	b = new NhanVien * [n+1];
	for (int i = 0; i < n; i++)
		b[i] = nv[i];
	cout << "1. NVSanXuat.\n";
	cout << "2. NVCongNhat.\n";
	cout << "Nhap vao kieu nhan vien: ";
	int choice;
	cin >> choice;
	if (choice == 1)
		b[n] = new NVSanXuat;
	else if (choice == 2)
		b[n] = new NVCongNhat;
	b[n]->nhap();
	
	for (int i = 0; i < n; i++)
		delete nv[i];
	delete []nv;
	nv = b;
	n++;
}

void CongTy::xoaNV(string id) {
	bool coTonTai = false;
	for (int i = 0; i < n; i++)
		if (nv[i]->id() == id) {
			coTonTai = true;
			break;
		}
	if (coTonTai == true) {
		int i = 0;
		NhanVien** b = new NhanVien * [n - 1];
		for (i; i < n; i++) {
			if (nv[i]->id() == id)
				break;
			else
				b[i] = nv[i];
		}
		delete nv[i];
		for (int j = i + 1; j < n; j++)
			b[j - 1] = nv[j];
		delete nv;
		nv = b;
		n--;
		cout << "*Da xoa nhan vien co ma " << id << " khoi danh sach.\n";
	}
	else
		cout << "*Khong ton tai nhan vien co ma " << id << endl;
	
}

void CongTy::ghiNVLuongNhoHonLuongTB() {
	string outFile = "emp_LowerAvgSalary.txt";
	ofstream fout(outFile);
	float luongTBCT = this->luongTB();
	
	if (fout) {
		fout << "Luong trung binh cua cong ty: " << luongTBCT << endl;
		fout << "Cac nhan vien co luong nho hon luong trung binh cua cong ty la:\n";
		fout << "===============================================================\n";
		for (int i = 0; i < n; i++) {
			long luongNV = nv[i]->luong();
			if (luongNV < luongTBCT) {
				if (nv[i]->kieuNV() == "NVSanXuat")
					fout << "*NVSanXuat:\n";
				else if (nv[i]->kieuNV() == "NVCongNhat")
					fout << "*NVCongNhat:\n";
				fout << "-Id: " << nv[i]->id() << endl;
				fout << "-Ho Ten: " << nv[i]->ten() << endl;
				fout << "-NgaySinh: " << nv[i]->ngaySinh() << endl;
				fout << "-Dia Chi: " << nv[i]->diaChi() << endl;
				fout << "-Luong: " << luongNV << endl;
				fout << "-----------------------------------------------------\n";
			}
		}
		fout.close();
	}
}

int CongTy::soNhanVien() {
	return n;
}

CongTy& CongTy::operator=(const CongTy& cty) {
	if (this != &cty) {
		this->n = cty.n;
		this->nv = new NhanVien * [this->n];
		for (int i = 0; i < n; i++) {
			if (cty.nv[i]->kieuNV() == "NVSanXuat")
				this->nv[i] = new NVSanXuat;
			else if (cty.nv[i]->kieuNV() == "NVCongNhat")
				this->nv[i] = new NVCongNhat;
			this->nv[i] = cty.nv[i];
		}
	}
	return *this;
}