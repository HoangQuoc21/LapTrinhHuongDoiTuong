#define _CRT_SECURE_NO_WARNINGS
#include "DocGia.h"
#include <iostream>
#include <sstream>
using namespace std;

//Constructors
DocGia::DocGia() {
	MaDG = new char[6];
	HoTen = new char[50];
	NgayExpire = new char[50];
	SachMuon = -1;
	LoaiDG = new char[50];
}

DocGia::DocGia(char* ma, char* ten, char* hethan, int muon, char* loai) {
	MaDG = new char[10];
	HoTen = new char[50];
	NgayExpire = new char[50];
	SachMuon = -1;
	LoaiDG = new char[50];
	strcpy(MaDG, ma);
	strcpy(HoTen, ten);
	strcpy(NgayExpire, hethan);
	SachMuon = muon;
	strcpy(LoaiDG, loai);
}

DocGia::DocGia(const DocGia& d) {
	MaDG = new char[6];
	HoTen = new char[50];
	NgayExpire = new char[50];
	SachMuon = -1;
	LoaiDG = new char[50];
	strcpy(MaDG, d.MaDG);
	strcpy(HoTen, d.HoTen);
	strcpy(NgayExpire, d.NgayExpire);
	SachMuon = d.SachMuon;
	strcpy(LoaiDG, d.LoaiDG);
}

DocGia::~DocGia() {
	delete[] MaDG;
	delete[] HoTen;
	delete[] NgayExpire;
	delete[] LoaiDG;
}

//Nhập thông tin độc giả
void DocGia::Nhap() {
	//Nhập các thuộc tính là chuỗi
	cin.ignore();

	cout << "-Nhap ma doc gia: ";
	cin.getline(MaDG, 10);
	
	cout << "-Nhap ho ten: ";
	cin.getline(HoTen, 50);
	
	cout << "-Nhap ngay het han: ";
	cin.getline(NgayExpire, 50);
	
	cout << "-Nhap loai doc gia: ";
	cin.getline(LoaiDG, 50);

	//Nhập các thuộc tính không là chuỗi
	cout << "-Nhap so sach muon: ";
	cin >> SachMuon;
}

//Xuất thông tin độc giả
void DocGia::Xuat() {
	cout << "-Ma doc gia: " << MaDG << endl;
	cout << "-Ho ten: " << HoTen << endl;
	cout << "-Ngay het han: " << NgayExpire << endl;
	cout << "-So sach muon: " << SachMuon << endl;
	cout << "-Loai doc gia: " << LoaiDG << endl;
}

//Hàm tính phí
float DocGia::TinhPhi() {
	if (!strcmp(LoaiDG, "Thuong"))
		return SachMuon * 5000;
	else if (!strcmp(LoaiDG, "VIP"))
		return 100000;
}

DocGia& DocGia::operator=(const DocGia& other) {
	strcpy(this->MaDG, other.MaDG);
	strcpy(this->HoTen, other.HoTen);
	strcpy(this->NgayExpire, other.NgayExpire);
	this->SachMuon = other.SachMuon;
	strcpy(this->LoaiDG, other.LoaiDG);
	return *this;
}

bool DocGia::operator>(const DocGia& other) {
	int a = atoi(this->MaDG);
	int b = atoi(other.MaDG);
	return (a > b);
}

bool DocGia::hetHanTruoc552023() {
	char buffer[50];
	stringstream ss(NgayExpire);
	int ngay, thang, nam;
	ss.getline(buffer,50, '/');
	ngay = atoi(buffer);
	ss.getline(buffer, 50, '/');
	thang = atoi(buffer);
	ss.getline(buffer, 50);
	nam = atoi(buffer);

	if (nam < 2023)
		return true;
	else if (nam == 2023) {
		if (thang < 5)
			return true;
		else if (thang > 5)
			return false;
		else {
			if (ngay <= 5)
				return true;
			else
				return false;
		}
	}
	else
		return false;
}