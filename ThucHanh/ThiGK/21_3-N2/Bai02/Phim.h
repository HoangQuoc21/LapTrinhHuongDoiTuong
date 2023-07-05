#pragma once
#ifndef PHIM_H
#define PHIM_H
#include <iostream>
using namespace std;
class Phim {
private:
	char* maso; // Mã số, Ex. 123456
	char* tenPhim; // Tên phim: Before Sunrise, Bo Gia
	char* theLoai; // Thể loại, ex. phim hai, phim truyen
	char* nhaSX; // Nhà sản xuất, ex. Phim Sài Gòn, HBO
	int namSX; // Năm sản xuất
	float xepHang; // 6.0, 7.5, trong khoảng (1,10)
public:
	// Constructors
	Phim();
	~Phim();
	char* getTheLoai();
	char* getNhaSX();
	int getNamSX();
	// Nhap/xuat
	void Nhap();
	void Xuat();
	float getXepHang();
	// others
	Phim& operator=(const Phim& other);
};
#endif
