#pragma once
#include "NhanVien.h"
class NVCongNhat :public NhanVien{
private:
	int _soNgay;
public:
	NVCongNhat();
	NVCongNhat(const NVCongNhat& nv);

	void nhap();
	void xuat();
	int soNgay() const;
	long luong();
	string kieuNV();
	NVCongNhat& operator=(const NVCongNhat& b);
};

