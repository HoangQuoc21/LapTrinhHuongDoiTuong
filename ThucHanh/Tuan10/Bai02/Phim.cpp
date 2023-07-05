#define _CRT_SECURE_NO_WARNINGS
#include "Phim.h"

Phim::Phim() {
	strcpy(ma, "");
	strcpy(ten, "");
	strcpy(theLoai, "");
	strcpy(nhaXS, "");
	namXS = 0;
	xepHang = 0;
}

Phim::Phim(char* m, char* t,char* tl, char* NhaXS, int NamXS, float xh) {
	strcpy(ma, m);
	strcpy(ten, t);
	strcpy(theLoai, tl);
	strcpy(nhaXS, NhaXS);
	namXS = NamXS;
	xepHang = xh;
}

Phim::Phim(const Phim& other) {
	strcpy(ma, other.ma);
	strcpy(ten, other.ten);
	strcpy(theLoai, other.theLoai);
	strcpy(nhaXS, other.nhaXS);
	namXS = other.namXS;
	xepHang = other.xepHang;
}

Phim::~Phim() {}

int Phim::getNamXS() {
	return namXS;
}

char* Phim::getNhaXS() {
	char nxs[50];
	strcpy(nxs, nhaXS);
	return nxs;
}

Phim& Phim::operator=(const Phim& other) {
	strcpy(this->ma, other.ma);
	strcpy(this->ten, other.ten);
	strcpy(this->nhaXS, other.nhaXS);
	strcpy(this->theLoai, other.theLoai);
	this->namXS = other.namXS;
	this->xepHang = other.xepHang;
	return *this;
}

istream& operator>>(istream& in, Phim& src) {
	cin.ignore();
	cout << "-Nhap ma: ";
	in.getline(src.ma, 6);

	cout << "-Nhap ten: ";
	in.getline(src.ten, 50);

	cout << "-Nhap the loai: ";
	in.getline(src.theLoai, 50);

	cout << "-Nhap nha san xuat: ";
	in.getline(src.nhaXS, 50);

	cout << "-Nhap nam san xuat: ";
	in >> src.namXS;

	cout << "-Nhap xep hang: ";
	in >> src.xepHang;

	return in;
}

ostream& operator<<(ostream& out,const Phim& src) {
	out << src.ma << "|" << src.ten << "|" << src.theLoai << "|" << src.nhaXS << "|" << src.namXS << "|" << src.xepHang;
	return out;
}