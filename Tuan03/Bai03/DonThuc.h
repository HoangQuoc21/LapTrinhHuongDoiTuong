#pragma once
#include <iostream>
using namespace std;
class DonThuc
{
private:
	float _heSo;
	int _bac;
public:
	DonThuc();
	DonThuc(float heSo, int bac);
	DonThuc(const DonThuc &d);
	float heSo();
	float giaTri(float x);
	void setDonThuc(float heSo, int bac);
	DonThuc& operator=(const DonThuc& other);
	friend istream& operator>>(istream& in, DonThuc& src);
	friend ostream& operator<<(ostream& out, const DonThuc& src);

	//Phương thức + và - chỉ sử dụng được cho 2 đơn thức cùng bậc
	DonThuc operator+(const DonThuc& other);
	DonThuc operator-(const DonThuc& other);

	DonThuc operator*(const DonThuc& other);

	//Phương thức / chỉ sử dụng được nếu đơn thức bị chia có hệ số != 0
	DonThuc operator/(const DonThuc& other);
};

