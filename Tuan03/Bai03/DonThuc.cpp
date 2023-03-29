#include "DonThuc.h"
#include <iostream>
#include <cmath>
using namespace std;

DonThuc::DonThuc() {
	_heSo = 0;
	_bac = 0;
}

DonThuc::DonThuc(float heSo, int bac):_heSo(heSo), _bac(bac) {}

DonThuc::DonThuc(const DonThuc& d) {
	_heSo = d._heSo;
	_bac = d._bac;
}

float DonThuc::heSo() {
	return _heSo;
}

float DonThuc::giaTri(float x) {
	return _heSo * pow(x, _bac);
}

void DonThuc::setDonThuc(float heSo, int bac) {
	_heSo = heSo;
	_bac = bac;
}

DonThuc& DonThuc::operator=(const DonThuc& other) {
	if (this != &other) {
		this->_heSo = other._heSo;
		this->_bac = other._bac;
	}
	return *this;
}

istream& operator>>(istream& in, DonThuc& src) {
	cout << "Nhap vao he so: ";
	in >> src._heSo;
	cout << "Nhap vao bac: ";
	in >> src._bac;
	return in;
}

ostream& operator<<(ostream& out, const DonThuc& src) {
	if (src._bac == 0)
		out << src._heSo;
	else {
		if (src._heSo == 0) {
			out << "0";
			return out;
		}
		else if (src._heSo == -1)
			out << "-";
		else if (src._heSo != 1)
			out << src._heSo;
		out << "x";
		if (src._bac != 1)
			out << "^" << src._bac;
	}
	return out;
}

DonThuc DonThuc::operator+(const DonThuc& other) {
	if (_bac != other._bac) {
		cerr << "Khong the cong 2 don thuc co bac khac nhau!\n";
		exit(1);
	}
	return DonThuc(_heSo + other._heSo, _bac);
}

DonThuc DonThuc::operator-(const DonThuc& other) {
	if (_bac != other._bac) {
		cerr << "Khong the tru 2 don thuc co bac khac nhau!\n";
		exit(1);
	}
	return DonThuc(_heSo - other._heSo, _bac);
}

DonThuc DonThuc::operator*(const DonThuc& other) {
	return DonThuc(_heSo * other._heSo, _bac + other._bac);
}

DonThuc DonThuc::operator/(const DonThuc& other) {
	if (other._heSo == 0) {
		cerr << "Khong the chia cho don thuc 0!\n";
		exit(1);
	}
	return DonThuc(_heSo / other._heSo, _bac - other._bac);
}