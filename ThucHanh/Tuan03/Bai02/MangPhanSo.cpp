#include "MangPhanSo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

MangPhanSo::MangPhanSo() {
	_n = 0;
	_a = NULL;
}

MangPhanSo::~MangPhanSo() {
	if (_a != NULL)
		delete[] _a;
}

void MangPhanSo::nhapMang() {
	if ( _a != NULL)
		delete[]_a;

	cout << "Nhap vao so luong phan so: ";
	cin >> _n;
	_a = new PhanSo[_n];
	for (int i = 0; i < _n; i++) {
		cout << "-Phan so thu " << i + 1 << ": \n";
		cin >> _a[i];
	}
	
}

void MangPhanSo::xuatMang() {
	if (_n == 0) {
		cout << "Mang hien dang rong.\n";
		return;
	}

	for (int i = 0; i < _n; i++) {
		cout << "-Phan so thu " << i + 1 << ": " << _a[i] << endl;
	}
}

float MangPhanSo::tong() {
	float ketQua = 0;
	for (int i = 0; i < _n; i++)
		ketQua += _a[i].giaTri();

	return ketQua;
}

void MangPhanSo::sapXepTangDan() {
	for (int i = 0; i < _n - 1; i++)
		for (int j = i + 1; j < _n; j++)
			if (_a[i].giaTri() > _a[j].giaTri())
				swap(_a[i], _a[j]);
}

void MangPhanSo::ghiFile(string fileGhi) {
	ofstream fout(fileGhi);
	fout << "So luong phan so: " << _n << endl;
	for (int i = 0; i < _n; i++)
		fout << _a[i] << endl;
	fout.close();
}

void MangPhanSo::docFile(string fileDoc) {
	ifstream fin(fileDoc);
	string line,buffer;
	getline(fin, line);
	int nPhanSo = stoi(line);

	PhanSo* b = new PhanSo[_n + nPhanSo];
	for (int i = 0; i < _n; i++)
		b[i] = _a[i];
	delete[] _a;
	_a = b;

	int tu, mau;
	for (int i = _n; i < _n+nPhanSo; i++) {
		getline(fin, line);
		stringstream ss(line);

		getline(ss, buffer, ',');
		buffer.erase(0,1);
		tu = stoi(buffer);

		getline(ss, buffer, ')');
		mau = stoi(buffer);

		_a[i].setPhanSo(tu, mau);
	}
	_n = _n + nPhanSo;
	fin.close();
}