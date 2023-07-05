#pragma once
#include "DocGia.h";

class QLThuVien {
private:
	int size; //số lượng độc giả
	DocGia* dsdg; //Danh sách độc giả
	void SapXep();
public:
	//Constructors
	QLThuVien();
	~QLThuVien();
	// Nhập danh sách độc giả
	void NhapDSDG();
	// In danh sách độc giả
	void XuatDSDG();
	// Các hàm xử lý khác 

	float TongTien();
	void Them();
	void HetHan();
};