#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>
#include<fstream>
#include <string>
#include <iomanip>
using namespace std;

class NGAY{
	int ngay;
	int thang;
	int nam;
public:
	void setNGAY(int a, int b, int c){
		ngay = a; thang = b; nam = c;
	}

	int getNgay() { return ngay; }
	int getThang() { return thang; }
	int getNam() { return nam; }
	void xuat() {
		cout << ngay << "/" << thang << "/" << nam << endl;
	}
};

class KhachHang{
	string cmnd;
	string hoten;
	NGAY ngaydk;
	float diem;
public:
	virtual void nhap();
	void xuat();
	virtual void sotienphaitra(double);
};

void KhachHang::nhap(){
	cout << "Nhap cmnd: "; cin >> cmnd;
	cin.ignore();
	cout << "Nhap ho ten: "; getline(cin, hoten);
	cout << "nhap ngay,thang,nam dang ki: "; int a, b, c;
	cin >> a >> b >> c;
	ngaydk.setNGAY(a, b, c);
	cout << "Nhap diem tich luy: "; cin >> diem;
}

void KhachHang::xuat(){
	cout << cmnd << endl;
	cout << hoten << endl;
	ngaydk.xuat();
	cout << "Diem tich luy: " << diem << endl;
}

void KhachHang::sotienphaitra(double tienhang){
	double ketqua = 0;
	if (diem > 1000 || tienhang > 5000000)
		ketqua = tienhang - tienhang * 2 / 100;
	else
		ketqua = tienhang;
	cout << "So tien phai tra la: " << fixed << ketqua;
}

class KHTT :public KhachHang{
private:
	int capdo;
public:
	void nhap(){
		KhachHang::nhap();
		cout << "Nhap cap do: ";
		cin >> capdo;
	}
	void xuat(){
		KhachHang::xuat();
		cout << "Cap do than thiet: " << capdo << endl;
	}
	void sotienphaitra(double);
};

void KHTT::sotienphaitra(double tienhang){
	double ketqua = 0;
	int discount = 0;
	switch (capdo){
		case 1:{
			discount = 5;
			break;
		}
		case 2:{
			discount = 7;
			break;
		}
		case 3:{
			discount = 10;
			break;
		}
		default:{
			discount = 0;
			break;
		}
	}
	ketqua = tienhang - (tienhang * discount) / 100;
	cout << "So tien phai tra la: " << fixed << ketqua;
}

class DSKH{
	vector<KhachHang*> DS;
public:
	void nhap(){
		cout << "1: khach hang bth" << " " << "2: KHTT" << " " << "0: thoat" << endl;
		while (1){
			cout << "Nhap loai KH: ";
			int n; cin >> n;
			KhachHang* temp = NULL;
			if (n == 1)
			{
				temp = new KhachHang();
				temp->nhap();
			}
			else if (n == 2)
			{
				temp = new KHTT();
				temp->nhap();
			}
			else
			{
				break;
			}
			DS.push_back(temp);
		}
	}
	void xuat(){
		for (auto i : DS){
			cout << "Nhap tien mua hang: ";
			double tienmua; cin >> tienmua;
			i->sotienphaitra(tienmua);
			i->xuat();
		}
	}
};

int main(){

	DSKH ds;
	ds.nhap();
	ds.xuat();
}
