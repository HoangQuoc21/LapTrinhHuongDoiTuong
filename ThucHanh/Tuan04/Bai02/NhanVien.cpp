#include "NhanVien.h"
#include <iostream>
using namespace std;

NhanVien::NhanVien() {
	_id = _hoTen = _ngaySinh = _diaChi = " ";
}

NhanVien::NhanVien(const NhanVien& nv) {
	_id = nv._id;
	_hoTen = nv._hoTen;
	_ngaySinh = nv._ngaySinh;
	_diaChi = nv._diaChi;
}

string NhanVien::id() const {
	return _id;
}

string NhanVien::ten() const {
	return _hoTen;
}

string NhanVien::ngaySinh() const {
	return _ngaySinh;
}

string NhanVien::diaChi() const {
	return _diaChi;
}

void NhanVien::nhap() {
	cout << "-Id: ";
	cin >> _id;
	cout << "-Ho Ten: ";
	cin.ignore();
	getline(cin, _hoTen);
	cout << "-Ngay Sinh (dd/mm/yyyy): ";
	cin >> _ngaySinh;
	cout << "-Dia Chi: ";
	cin.ignore();
	getline(cin, _diaChi);
}

void NhanVien::xuat() {
	cout << "-Id: " << _id << endl;
	cout << "-Ho Ten: " << _hoTen << endl;
	cout << "-NgaySinh: " << _ngaySinh << endl;
	cout << "-Dia Chi: " << _diaChi << endl;
}

long NhanVien::luong() {
	return 0;
}

string NhanVien::kieuNV() {
	return "NV";
}

NhanVien& NhanVien::operator=(const NhanVien& b) {
	if (this != &b) {
		this->_id = b._id;
		this->_hoTen = b._ngaySinh;
		this->_ngaySinh = b._ngaySinh;
		this->_diaChi = b._diaChi;
	}
	return *this;
}