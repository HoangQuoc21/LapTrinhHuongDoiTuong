#pragma once
#include "NhanVien.h"
class NVSanXuat :public NhanVien
{
private:
	int soSanPham;
public:
	NVSanXuat();
	NVSanXuat(char* m, char* ten,char* gioi, char* ns, char* dc, int sanPham);
	NVSanXuat(const NVSanXuat& nv);	
	
	void nhap(istream& in);
	void xuat(ostream& out);
	long tinhLuong();
	char* kieuNV();

	void ghiFile(ofstream& fout);
	int getSL();
};