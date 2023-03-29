#pragma once
#include "PhanSo.h"
#include <string>
using namespace std;

class MangPhanSo
{
private:
	PhanSo* _a;
	int _n;
public:
	MangPhanSo();
	~MangPhanSo();

	void nhapMang();
	void xuatMang();
	float tong();
	void sapXepTangDan();
	void ghiFile(string fileDoc);
	void docFile(string fileGhi);
};

