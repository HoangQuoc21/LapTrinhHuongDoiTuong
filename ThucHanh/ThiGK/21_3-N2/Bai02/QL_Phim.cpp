#include "QL_Phim.h"
#include <vector>
// Constructors
QL_Phim::QL_Phim() {
	sz = 0;
	ds_phim = NULL;
}

QL_Phim::~QL_Phim() {
	if (ds_phim != NULL)
		delete[]ds_phim;
	ds_phim = NULL;
	sz = 0;
}

// Nhap/Xuat ds phim
void QL_Phim::nhap_dsPhim() {
	cout << "Nhap vao so luong danh sach phim: ";
	cin >> sz;
	cout << "------------------------------------\n";
	ds_phim = new Phim[sz];
	for (int i = 0; i < sz; i++) {
		cout << "Nhap vao thong tin phim thu " << i + 1 << ":\n";
		ds_phim[i].Nhap();
		cout << "------------------------------------\n";
	}
}

void QL_Phim::xuat_dsPhim() {
	cout << "------------------------------------\n";
	for (int i = 0; i < sz; i++) {
		cout << "Thong tin phim thu " << i + 1 << ":\n";
		ds_phim[i].Xuat();
		cout << "------------------------------------\n";
	}
}

// Các phương thức xử lý

void QL_Phim::xepHang_caoNhat_TheLoai() {
	vector<char*> theLoai;
	for (int i = 0; i < sz; i++) {
		bool tonTai = false;
		for (int j = 0; j < theLoai.size(); j++) {
			if (!strcmp(ds_phim[i].getTheLoai(), theLoai[j])) {
				tonTai = true;
				//break;
			}
		}
		if (!tonTai)
			theLoai.push_back(ds_phim[i].getTheLoai());
	}
	for (auto x : theLoai) {
		Phim xhCaoNhat;
		float xhMax = -1;
		for (int i = 0; i < sz; i++) {
			float xh = ds_phim[i].getXepHang();
			if (xh > xhMax && !strcmp(x, ds_phim[i].getTheLoai())) {
				xhMax = xh;
				xhCaoNhat = ds_phim[i];
			}
		}
		cout << "Phim thuoc the loai " << x << " co xep hang cao nhat la:\n";
		xhCaoNhat.Xuat();
		cout << "----------------------------------------------------\n";
	}
}

void QL_Phim::xoa_phim() {
	int nb = 0;
	Phim* dsb;
	for (int i = 0; i < sz; i++)
		if (ds_phim[i].getNamSX() >= 2000 || strcmp(ds_phim[i].getNhaSX(), "HBO"))
			nb++;
	dsb = new Phim[nb];
	int ib = 0;
	for (int i = 0; i < sz; i++)
		if (ds_phim[i].getNamSX() >= 2000 || strcmp(ds_phim[i].getNhaSX(), "HBO"))
			dsb[ib++] = ds_phim[i];
	delete[] ds_phim;
	ds_phim = dsb;
	sz = nb;
}