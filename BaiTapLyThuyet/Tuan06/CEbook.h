#pragma once
#include <iostream>
#include <string>
#include "CMyDate.h"
using namespace std;

class CEbook
{
private:
	string _ISBN;
	string _tenSach;
	string _tacGia;
	CMyDate _ngayXuatBan;
	string _theLoai;
	string _nhaXuatBan;
	float _gia;
public:
	CEbook();
	CEbook(string ISBN, string tenSach, string _tacGia, CMyDate ngayXuatBan, string theLoai, string nhaXuatBan, float gia);
	CEbook(const CEbook& other);

	bool operator>(const CEbook& other);
	bool operator>=(const CEbook& other);
	bool operator<(const CEbook& other);
	bool operator<=(const CEbook& other);

	string ISBN();
	float gia();
	CMyDate ngaySanXuat();
	void setBook(string ISBN, string tenSach, string _tacGia, CMyDate ngayXuatBan, string theLoai, string nhaXuatBan, float gia);

	friend istream& operator>>(istream& in,CEbook& src);
	friend ostream& operator<<(ostream& out, const CEbook& src);
};