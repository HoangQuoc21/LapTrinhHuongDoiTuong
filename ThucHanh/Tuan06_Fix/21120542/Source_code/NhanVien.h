#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

class NhanVien
{
private:
	char ma[6];
	char hoTen[50];
	char gioiTinh[4];
	char ngaySinh[11];
	char diaChi[50];
public:
	NhanVien();
	NhanVien(char* m, char* ten,char* gioi, char* ns, char* dc);
	NhanVien(const NhanVien& nv);

	char* getMa() ;
	char* getTen() ;
	char* getGioiTinh();
	char* getNgaySinh() ;
	char* getDiaChi() ;

	int tinhTuoi();

	friend istream& operator>>(istream& in, NhanVien*& nv);
	friend ostream& operator<<(ostream& out, NhanVien* nv);

	virtual int getSL() = 0;
	
	virtual void nhap(istream& in);
	virtual void xuat(ostream& out);
	virtual long tinhLuong();
	virtual char* kieuNV();

	virtual void ghiFile(ofstream& fout);
};

