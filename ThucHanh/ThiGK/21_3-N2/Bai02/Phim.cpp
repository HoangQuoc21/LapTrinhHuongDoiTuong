#define _CRT_SECURE_NO_WARNINGS
#include "Phim.h"

// Constructors
Phim::Phim() {
	maso = new char[7];
	tenPhim = new char[50];
	theLoai = new char[50];
	nhaSX = new char[50];
	namSX = 0;
	xepHang = 0;
}

Phim::~Phim() {
	delete[] maso;
	delete[] tenPhim;
	delete[] theLoai;
	delete[] nhaSX;
	//cout << "deleted.\n";
}

char* Phim::getTheLoai() {
	return theLoai;
}

// Nhap/xuat
void Phim::Nhap() {
	//Nhập các dữ liệu là chuỗi
	cin.ignore();

	cout << "-Nhap ma so: ";
	cin.getline(maso, 7);

	cout << "-Nhap ten phim: ";
	cin.getline(tenPhim, 50);

	cout << "-Nhap the loai: ";
	cin.getline(theLoai, 50);

	cout << "-Nhap nha san xuat: ";
	cin.getline(nhaSX, 50);

	//Nhập các dữ liệu không phải là chuỗi
	cout << "-Nhap nam san xuat: ";
	cin >> namSX;
	cout << "-Nhap xep  hang: ";
	cin >> xepHang;

	
}
void Phim::Xuat() {
	cout << "-Ma so: " << maso << endl;
	cout << "-Ten: " << tenPhim << endl;
	cout << "-The loai: " << theLoai << endl;
	cout << "-Nha san xuat: " << nhaSX << endl;
	cout << "-Nam san xuat: " << namSX << endl;
	cout << "-Xep hang: " << xepHang << endl;
}
// others

float Phim::getXepHang() {
	return xepHang;
}

Phim& Phim::operator=(const Phim& other) {
	strcpy(this->maso, other.maso);
	strcpy(this->tenPhim, other.tenPhim);
	strcpy(this->theLoai, other.theLoai);
	strcpy(this->nhaSX, other.nhaSX);
	this->namSX = other.namSX;
	this->xepHang = other.xepHang;
	return *this;
}

char* Phim::getNhaSX() {
	return nhaSX;
}

int Phim::getNamSX() {
	return namSX;
}