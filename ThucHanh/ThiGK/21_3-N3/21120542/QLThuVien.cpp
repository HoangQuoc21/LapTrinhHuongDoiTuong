#include "QLThuVien.h"
#include <iostream>
using namespace std;

void QLThuVien::SapXep() {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (dsdg[i] > dsdg[j])
				swap(dsdg[i], dsdg[j]);
}

//Constructors
QLThuVien::QLThuVien() {
	size = 0;
	dsdg = NULL;
}

QLThuVien::~QLThuVien() {
	if (dsdg != NULL) {
		delete[]dsdg;
		size = 0;
		dsdg = NULL;
	}
}

// Nhập danh sách độc giả
void QLThuVien::NhapDSDG() {
	cout << "Nhap so luong doc gia: ";
	cin >> size;
	cout << "-----------------------------------------------\n";
	dsdg = new DocGia[size];
	for (int i = 0; i < size; i++) {
		cout << "Nhap vao thong tin doc gia thu " << i + 1 << ":\n";
		cout << "----------------------------------\n";
		
		dsdg[i].Nhap();
		
		cout << "-----------------------------------------------\n";
	}
	SapXep();
}

// In danh sách độc giả
void QLThuVien::XuatDSDG() {
	for (int i = 0; i < size; i++) {
		cout << "Thong tin doc gia thu " << i + 1 << ":\n";
		cout << "----------------------------------\n";
		dsdg[i].Xuat();
		cout << "-----------------------------------------------\n";
	}
}

// Các hàm xử lý khác 

float QLThuVien::TongTien() {
	float tong = 0;
	for (int i = 0; i < size; i++)
		tong += dsdg[i].TinhPhi();
	return tong;
}

void QLThuVien::Them() {
	DocGia t;
	cout << "Nhap thong tin doc gia muon them: \n";
	t.Nhap();

	DocGia* dsb = new DocGia[size + 1];
	for (int i = 0; i < size; i++)
		dsb[i] = dsdg[i];

	size = size + 1;
	dsb[size-1] = t;

	delete[] dsdg;

	dsdg = dsb;
	SapXep();
}

void QLThuVien::HetHan() {
	cout << "Nhung doc gia het han truoc ngay 05/05/2023 la:\n";
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < size; i++)
		if (dsdg[i].hetHanTruoc552023()) {
			dsdg[i].Xuat();
			cout << "---------------------------\n";
		}
}