#pragma once
#include <string>
using namespace std;

class NhanVien
{
private:
	string _id;
	string _hoTen;
	string _ngaySinh;
	string _diaChi;
public:
	NhanVien();
	NhanVien(const NhanVien& nv);
	
	string id() const;
	string ten() const;
	string ngaySinh() const;
	string diaChi() const;

	virtual void nhap();
	virtual void xuat();
	virtual long luong();
	virtual string kieuNV();
	NhanVien& operator=(const NhanVien& b);
};

