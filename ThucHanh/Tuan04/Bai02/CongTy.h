#pragma once
#include "NhanVien.h"


class CongTy{
private:
	NhanVien** nv;
	int n;
public:
	CongTy();
	~CongTy();
	

	void nhap();
	void xuat();
	long tongLuong();
	NhanVien* NVLuongCaoNhat();
	float luongTB();
	NhanVien* timNVMa(string id);
	NhanVien* timNVTen(string hoTen);
	int soNVSinhThang5();
	void themNV();
	void xoaNV(string id);
	void ghiNVLuongNhoHonLuongTB();
	int soNhanVien();

	CongTy& operator=(const CongTy& cty);
};

