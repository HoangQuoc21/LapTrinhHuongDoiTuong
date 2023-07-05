#include<sstream>
#include<string>
#include<fstream>
#include <iostream>
#include <vector>

using namespace std;
class NhanVien {
protected:
	string hoten;
	string ngaySinh;
	string diachi;
	float luongcoban;

public:
	virtual void nhap(){
		cout << "Ho va Ten: ";
		cin.ignore();
		getline(cin, hoten);
		cout << "Ngay Sinh: ";
		cin >> ngaySinh;
		cout << "Dia Chi: ";
		cin.ignore();
		getline(cin, diachi);
		//cin.ignore();
	}
	void Xuat()
	{
		cout << "HoTen: " << hoten << endl;
		cout << "NgaySinh: " << ngaySinh << endl;
		cout << "Dia Chi: " << diachi << endl;
	}

	virtual float tinhluong()
	{
		return 0;
	}
};

class NVsx :public NhanVien
{
private:
	int sosanpham;
public:
	void nhap()
	{
		NhanVien::nhap();
		cout << "So san Pham: ";
		cin >> sosanpham;
	}

	void Xuat()
	{
		NhanVien::Xuat();
		cout << "So San Pham: " << sosanpham << endl;
	}
	float tinhluong()
	{
		return sosanpham * 100000;
	}

};
class  NVcongnhat : public NhanVien
{
private:
	int songaycong;
public:
	void nhap()
	{
		NhanVien::nhap();
		cout << "songaycong: ";
		cin >> songaycong;
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "SoNgaycong: " << songaycong << endl;
	}
	float tinhluog()
	{
		return songaycong * 200000;
	}
};

class NVQL :public NhanVien
{
private:
	int luongcoban;
	float heso;
public:
	void nhap()
	{
		NhanVien::nhap();
		cout << "Luongcb: ";
		cin >> luongcoban;
		cout << "HS: ";
		cin >> heso;
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "Luongcb: " << luongcoban << endl;
		cout << "Heso: " << heso << endl;
	}

	float tinhluong()
	{
		return luongcoban * heso;
	}
};

//================================================================================================

class CongTy {
private:
	int n; //số lượng nhân viên trong công ty
	vector<NhanVien*> dsnv;
public:
	void nhap();
	void xuat();
	float tinhLuong();
};

void CongTy::nhap() {
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int loaiNV = 0;
		
		cout << "0. NVQL\n";
		cout << "1. NVCN\n";
		cout << "2. NVSX\n";
		cout << "Nhap loai nhan vien: \n";
		cin >> loaiNV;
		NhanVien* a = NULL;
		if (loaiNV == 0) {
			a = new NVQL;
		}
		else if (loaiNV == 1) {
			a = new NVcongnhat;
		}
		else if (loaiNV == 2) {
			a = new NVsx;
		}
		
		a->nhap();
		dsnv.push_back(a);
		cout << "-------------------------------------\n";
		
	}
}

void CongTy::xuat() {
	for (int i = 0; i < n; i++) {
		dsnv[i]->Xuat();
		cout << endl;
		cout << "-------------------------------------\n";
	}
}

float CongTy::tinhLuong() {
	float ketQua = 0;
	for (int i = 0; i < n; i++)
		ketQua += dsnv[i]->tinhluong();
	return ketQua;
}

//=======================================================================================

int main()
{
	/*NVcongnhat nvcn[100];
	NVsx nvsx[100];
	NVQL nvql[100];
	int sl_nvql = 0, sl_nvcn = 0, sl_nvsx = 0;
	float TongLuong = 0;
	for (int i = 0; i < sl_nvcn; ++i)
		TongLuong += nvcn[i].tinhluog();
	NhanVien nv;
	nv.nhap();

	nvcn[0].nhap();
	nvcn[1].nhap();*/

	CongTy ABC;
	ABC.nhap();
	cout << "=========================================\n";
	ABC.xuat();

	return 0;
}