#pragma once
#include "NhanVien.h"
class NVCongNhat : public NhanVien
{
private:
	int soNgay;
public:
	NVCongNhat();
	NVCongNhat(char* m, char* ten, char* gioi, char* ns, char* dc,int ngay);
	NVCongNhat(const NVCongNhat& nv);
	
	void nhap(istream& in);
	void xuat(ostream& out);
	long tinhLuong();
	char* kieuNV();
	
	void ghiFile(ofstream& fout);
	int getSL();
};

