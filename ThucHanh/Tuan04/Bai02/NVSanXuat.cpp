#include "NVSanXuat.h"
#include <iostream>
using namespace std;

NVSanXuat::NVSanXuat():NhanVien(), _soSanPham(0){}

NVSanXuat::NVSanXuat(const NVSanXuat& nv):NhanVien(nv), _soSanPham(nv.soSanPham()) {}

void NVSanXuat::nhap() {
	cout << "*Nhap NV San Xuat:\n";
	NhanVien::nhap();
	cout << "-So san pham: ";
	cin >> _soSanPham;
}

void NVSanXuat::xuat() {
	cout << "NV San Xuat:\n";
	NhanVien::xuat();
	cout << "-So san pham: " << _soSanPham << endl;
}

int NVSanXuat::soSanPham() const {
	return _soSanPham;
}

long NVSanXuat::luong() {
	return _soSanPham * 20000;
}

string NVSanXuat::kieuNV() {
	return NhanVien::kieuNV() + "SanXuat";
}

NVSanXuat& NVSanXuat::operator=(const NVSanXuat& b) {
	if (this != &b) {
		*this = b;
		this->_soSanPham = b._soSanPham;
	}
	return *this;
}