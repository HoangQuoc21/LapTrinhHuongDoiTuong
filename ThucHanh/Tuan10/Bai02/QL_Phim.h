#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <sstream>
#include "Phim.h"
#include "vector.cpp"
using namespace std;

template<typename T>
class QL_Phim
{
private:
	vector<Phim*> ds_phim;
public:
	QL_Phim();
	~QL_Phim();
	void nhap();
	void xuat();
	void sapXepTheoNamSanXuat();
	void themPhim();
	void docFile(char* tenFile);
	void ghiFile(char* tenFile);
	void xoaPhimNXSHBO();
};
