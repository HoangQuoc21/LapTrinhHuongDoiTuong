#pragma once
#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"

class CongTy
{
private:
	NhanVien** nv;
	int n;
public:
	CongTy();
	CongTy(const CongTy& cty);
	~CongTy();
	void nhap();
	void xuat();
	int soNhanVien();
	CongTy& operator=(const CongTy& other);

	void ghiFile(char* tenFile);
	void docFile(char* tenFile);

	long tongTienLuong();
	void NVLuongCaoNhat();
	long luongTrungBinh();
	NhanVien* timNVMa(char* ma);
	void timNVTen(char* ten);
	void themNV(char* kieu, char* m, char* ten, char* gioi, char* ns, char* dc, int sl);
	bool xoaNV(char* ma);
	void ghiLuongNhoHonLTBRaFile(char* tenFile);
	int soNVSinhThang5();
};

