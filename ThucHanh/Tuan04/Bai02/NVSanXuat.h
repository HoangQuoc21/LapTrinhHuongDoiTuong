#pragma once
#include "NhanVien.h"
class NVSanXuat :public NhanVien{
private:
	int _soSanPham;
public:
	NVSanXuat();
	NVSanXuat(const NVSanXuat& nv);

	void nhap();
	void xuat();
	int soSanPham() const;
	long luong();
	string kieuNV();
	NVSanXuat& operator=(const NVSanXuat& b);
};

