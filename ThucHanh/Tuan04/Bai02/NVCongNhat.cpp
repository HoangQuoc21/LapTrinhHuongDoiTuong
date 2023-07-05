#include "NVCongNhat.h"
#include <iostream>
using namespace std;

NVCongNhat::NVCongNhat():NhanVien(),_soNgay(0) {}

NVCongNhat::NVCongNhat(const NVCongNhat& nv):NhanVien(nv),_soNgay(nv.soNgay()) {}

void NVCongNhat::nhap() {
	cout << "*Nhap NV Cong Nhat:\n";
	NhanVien::nhap();
	cout << "-So ngay: ";
	cin >> _soNgay;
}

void NVCongNhat::xuat() {
	cout << "NV Cong Nhat:\n";
	NhanVien::xuat();
	cout << "-So ngay: " << _soNgay << endl;
}

int NVCongNhat::soNgay() const {
	return _soNgay;
}

long NVCongNhat::luong() {
	return _soNgay * 300000;
}

string NVCongNhat::kieuNV() {
	return NhanVien::kieuNV() + "CongNhat";
}

NVCongNhat& NVCongNhat::operator=(const NVCongNhat& b) {
	if (this != &b) {
		*this = b;
		this->_soNgay = b._soNgay;
	}
	return *this;
}