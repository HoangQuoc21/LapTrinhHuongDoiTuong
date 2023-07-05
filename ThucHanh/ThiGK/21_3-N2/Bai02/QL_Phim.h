#pragma once
#include "Phim.h"
class QL_Phim {
private:
	int sz; // Số lượng phim
	Phim* ds_phim; // Danh sách phim
public:
	// Constructors
	QL_Phim();
	~QL_Phim();
	// Nhap/Xuat ds phim
	void nhap_dsPhim();
	void xuat_dsPhim();
	// Các phương thức xử lý

	void xepHang_caoNhat_TheLoai();
	void xoa_phim();
};

