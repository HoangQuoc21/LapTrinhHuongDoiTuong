#pragma once
#include <iostream>
using namespace std;

class Phim
{
private:
	char ma[6];
	char ten[50];
	char theLoai[50];
	char nhaXS[50];
	int namXS;
	float xepHang;
public:
	Phim();
	Phim(char* m, char* t,char* theLoai, char* NhaXS, int NamXS, float xh);
	Phim(const Phim& other);
	~Phim();
	int getNamXS();
	char* getNhaXS();
	Phim& operator=(const Phim& other);
	friend istream& operator>>(istream& in, Phim& src);
	friend ostream& operator<<(ostream& out, const Phim& src);
};