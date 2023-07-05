#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class DonHang {
protected:
	int soMH;
	float tienTamTinh;
	float phiGiaoHang;
public:
	DonHang() {
		soMH = tienTamTinh = phiGiaoHang = 0;
	}
	virtual void nhap() {
		cout << "-Nhap so mat hang: ";
		cin >> soMH;
		cout << "-Nhap vao tien tam tinh: ";
		cin >> tienTamTinh;
		cout << "-Nhap vao phi giao hang: ";
		cin >> phiGiaoHang;
	}
	virtual void xuat() {
		cout << kieu()<< "|" << soMH << "|" << fixed << setprecision(0) << tienTamTinh << "|" << fixed << setprecision(0) << phiGiaoHang << "|" << fixed << setprecision(0) << thanhTien() << endl;
	}
	float virtual thanhTien() = 0;
	virtual string kieu() {
		return "DonHang";
	}
};

//==========================================================

class DHBinhTuong :public DonHang {
public:
	void nhap() {
		DonHang::nhap();
		while (soMH >= 50) {
			cout << "*So mat hang khong hop le. Hay nhap lai: ";
			cin >> soMH;
		}
		while (tienTamTinh >= 10000000) {
			cout << "*So tien tam tinh khong hop le. Hay nhap lai: ";
			cin >> tienTamTinh;
		}
	}
	float thanhTien() {
		return tienTamTinh + phiGiaoHang;
	}
	string kieu() {
		return "DonHangBinhThuong";
	}
};

//==========================================================

class DHGiamGia :public DonHang {
public:
	void nhap() {
		DonHang::nhap();
		while (soMH < 50) {
			cout << "*So mat hang khong hop le. Hay nhap lai: ";
			cin >> soMH;
		}
		while (tienTamTinh >= 10000000) {
			cout << "*So tien tam tinh khong hop le. Hay nhap lai: ";
			cin >> tienTamTinh;
		}
	}
	float thanhTien() {
		return tienTamTinh*0.8 + phiGiaoHang;
	}
	string kieu() {
		return "DonHangGiamGia";
	}
};

//==========================================================

class DHMienPhiGH :public DonHang {
public:
	void nhap() {
		DonHang::nhap();
		while (soMH >= 50) {
			cout << "*So mat hang khong hop le. Hay nhap lai: ";
			cin >> soMH;
		}
		while (tienTamTinh < 10000000) {
			cout << "*So tien tam tinh khong hop le. Hay nhap lai: ";
			cin >> tienTamTinh;
		}
	}
	float thanhTien() {
		return tienTamTinh;
	}
	string kieu() {
		return "DonHangMienPhiGiaoHang";
	}
};

//==========================================================
class CongTy {
private:
	vector<DonHang*> dh;
public:
	CongTy() {

	}
	~CongTy() {
		if (dh.size() != 0) {
			for (auto& x : dh)
				delete x;
			dh.clear();
		}
	}
	void nhap() {
		int n;
		cout << "*Nhap vao so don hang: ";
		cin >> n;
		cout << "=====================================\n";
		for (int i = 0; i < n; i++) {
			int loai;
			cout << "1.Don hang binh thuong.\n";
			cout << "2.Don hang giam gia.\n";
			cout << "3.Don hang mien phi giao hang.\n";
			cout << "Nhap vao kieu don hang: ";
			cin >> loai;
			cout << "-----------------------------------\n";
			DonHang* h = NULL;
			if (loai == 1)
				h = new DHBinhTuong;
			else if (loai == 2)
				h = new DHGiamGia;
			else if (loai == 3)
				h = new DHMienPhiGH;
			h->nhap();
			dh.push_back(h);
		}
	}
	void xuat() {
		for (auto x : dh)
			x->xuat();
	}
	float tongTien() {
		float tong = 0;
		for (auto x : dh)
			tong += x->thanhTien();
		return tong;
	}
};

int main() {
	
	CongTy a;
	a.nhap();
	cout << "=======================================================\n";
	a.xuat();
	cout << "=======================================================\n";
	cout << "*Tong Tien: " << a.tongTien() << endl;
	return 0;
}

//3
//1
//3
//100000
//3000
//2
//51
//500000
//5000
//3
//40
//11000000
//69000