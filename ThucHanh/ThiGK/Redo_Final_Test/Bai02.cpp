#include <iostream>
#include <string>
using namespace std;

class date {
private:
	int day, month, year;
public:
	date() {
		day = month = year = 0;
	}
	void set(int d, int m, int y) {
		day = d;
		month = m; year = y;
	}
	int ngay() {
		return day;
	}
	int thang() {
		return month;
	}
	int nam() {
		return year;
	}
	void nhap() {
		cout << "+Ngay: ";
		cin >> day;
		cout << "+Thang: ";
		cin >> month;
		cout << "+Nam: ";
		cin >> year;
	}
	void xuat() {
		cout << day << "/" << month << "/" << year;
	}
};
//=======================
class giaoDich {
private:
	string ma;
	date ngayGD;
	float gia;
	int soLuong;
public:
	giaoDich() {
		ma = "";
		ngayGD.set(0, 0, 0);
		gia = 0;
		soLuong = 0;
	}
	giaoDich(string m, date n, float g, int sl) {
		ma = m;
		ngayGD = n;
		gia = g;
		soLuong = sl;
	}
	string getMa() {
		return ma;
	}
	date getNGD() {
		return ngayGD;
	}
	float getGia() {
		return gia;
	}
	int getSL() {
		return soLuong;
	}
	virtual void nhap() {
		cout << "-Ma: ";
		cin >> ma;
		cout << "-Ngay giao dich: \n";
		ngayGD.nhap();
		cout << "-Gia: ";
		cin >> gia;
		cout << "-So luong: ";
		cin >> soLuong;
	}
	virtual void xuat() {
		cout << "-Ma: " << ma << endl;
		cout << "-Ngay giao dich: ";
		ngayGD.xuat();
		cout << endl;
		cout << "-Gia: " << gia << endl;
		cout << "-So luong: " << soLuong << endl;
	}
	virtual string loai() {
		return "";
	}
	virtual float thanhTien() {
		return (float)(gia * soLuong);
	}
};
//=======================
class GDVang :public giaoDich {
private:
	string loaiVang;
public:
	GDVang() :giaoDich::giaoDich() {
		loaiVang = "";
	}
	GDVang(string m, date n, float g, int sl, string loaiV) :giaoDich(m, n, g, sl) {
		loaiVang = loaiV;
	}
	void nhap() {
		giaoDich::nhap();
		cout << "-Loai vang: ";
		cin >> loaiVang;
	}
	void xuat() {
		giaoDich::xuat();
		cout << "-Loai vang: " << loaiVang << endl;
	}
	string loai() {
		return "GDVang";
	}
	float thanhTien() {
		return giaoDich::thanhTien();
	}
};
//=======================
class GDTien :public giaoDich {
private:
	string loaiTien;
	float tyGia;
public:
	GDTien() :giaoDich::giaoDich() {
		loaiTien = "";
		tyGia = 0;
	}
	GDTien(string m, date n, float g, int sl, string loaiT, float tg) :giaoDich(m, n, g, sl) {
		loaiTien = loaiT;
		tyGia = tg;
	}
	string getLoaiT() {
		return loaiTien;
	}
	void nhap() {
		giaoDich::nhap();
		cout << "-Loai tien(vnd, usd, Euro): ";
		cin >> loaiTien;
		cout << "-Ty gia: ";
		cin >> tyGia;
	}
	void xuat() {
		giaoDich::xuat();
		cout << "-Loai tien: " << loaiTien << endl;
		cout << "-Ty gia: " << tyGia << endl;
	}
	string loai() {
		if (loaiTien == "vnd")
			return "GDTienVND";
		else if (loaiTien == "usd")
			return "GDTienUSD";
		else
			return "GDTienEuro";
	}
	float thanhTien() {
		if (loaiTien == "vnd")
			return giaoDich::thanhTien();
		else
			return giaoDich::thanhTien() * tyGia;
	}
};
//=======================
class QLGD {
private:
	giaoDich** gd;
	int n;
public:
	QLGD() {
		gd = NULL;
		n = 0;
	}
	~QLGD() {
		if (gd != NULL) {
			for (int i = 0; i < n; i++)
				delete gd[i];
			delete[]gd;
		}
		gd = NULL;
		n = 0;
	}
	void nhap() {
		cout << "*Nhap so luong giao dich: ";
		cin >> n;
		gd = new giaoDich * [n];
		cout << "===========================================\n";
		int loaiGD;
		for (int i = 0; i < n; i++) {
			cout << "*Nhap thong tin giao dich " << i + 1 << endl;
			cout << "1. GDVang\n";
			cout << "2. GDTien\n";
			cout << "Nhap vao loai giao dich: ";
			cin >> loaiGD;
			if (loaiGD == 1)
				gd[i] = new GDVang();
			else if (loaiGD == 2)
				gd[i] = new GDTien();
			gd[i]->nhap();
			cout << "-----------------------------------------\n";
		}
	}	
	void xuat() {
		cout << "*Thong tin cac giao dich: \n";
		cout << "===========================================\n";
		for (int i = 0; i < n; i++) {
			cout << "*Thong tin giao dich " << i + 1 << endl;
			gd[i]->xuat();
			cout << "-----------------------------------------\n";
		}
	}
	void SLGD() {
		int vang = 0;
		int tien = 0;
		for (int i = 0; i < n; i++)
			if (gd[i]->loai() == "GDVang")
				vang++;
			else if (gd[i]->loai() == "GDTienVND" || gd[i]->loai() == "GDTienEuro" || gd[i]->loai() == "GDTienUSD")
				tien++;
		cout << "-So luong giao dich vang: " << vang << endl;
		cout << "-So luong giao dich tien: " << tien << endl;

	}
	void tienTeLonNhat() {
		giaoDich* vnd = NULL;
		giaoDich* usd = NULL;
		giaoDich* Euro = NULL;
		for (int i = 0; i < n; i++)
			if (gd[i]->loai() == "GDTienVND") {
				vnd = gd[i];
				break;
			}
		for (int i = 0; i < n; i++)
			if (gd[i]->loai() == "GDTienUSD") {
				usd = gd[i];
				break;
			}
		for (int i = 0; i < n; i++)
			if (gd[i]->loai() == "GDTienEuro") {
				Euro = gd[i];
				break;
			}
		if (!vnd)
			cout << "*Khong co giao dich tien vnd\n";
		else {
			for (int i = 0; i < n; i++)
				if (gd[i]->loai() == "GDTienVND" && gd[i]->thanhTien() > vnd->thanhTien())
					vnd = gd[i];
			cout << "*Giao dich tien VND lon nhat la: \n";
			vnd->xuat();
		}
		cout << "-----------------------------------------------\n";
		if (!Euro)
			cout << "*Khong co giao dich tien Euro\n";
		else {
			for (int i = 0; i < n; i++)
				if (gd[i]->loai() == "GDTienEuro" && gd[i]->thanhTien() > Euro->thanhTien())
					Euro = gd[i];
			cout << "*Giao dich tien Euro lon nhat la: \n";
			Euro->xuat();
		}
		cout << "-----------------------------------------------\n";
		if (!usd)
			cout << "*Khong co giao dich tien usd\n";
		else {
			for (int i = 0; i < n; i++)
				if (gd[i]->loai() == "GDTienUSD" && gd[i]->thanhTien() > usd->thanhTien())
					usd = gd[i];
			cout << "*Giao dich tien USD lon nhat la: \n";
			usd->xuat();
		}
		cout << "-----------------------------------------------\n";
	}
	void GD12021() {
		cout << "*Cac giao dich trong thang 1 nam 2021 la:\n";
		for (int i = 0; i < n; i++) {
			if (gd[i]->getNGD().thang() == 1)
				if (gd[i]->getNGD().nam() == 2021) {
					gd[i]->xuat();
					cout << "--------------------------------------\n";
				}
		}
	}
};
//=======================

int main() {
	QLGD ql;
	ql.nhap();
	cout << "==================================================\n";
	ql.xuat();
	cout << "==================================================\n";
	ql.GD12021();
	cout << "==================================================\n";
	ql.SLGD();
	cout << "==================================================\n";
	ql.tienTeLonNhat();
	return 0;
}

//3
//1
//1
//21
//1
//2021
//10.5
//10
//vang
//2
//2
//21
//1
//2021
//10.5
//10
//Euro
//2
//2
//3
//21
//1
//2022
//11.5
//10
//vnd
//1