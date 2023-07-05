#pragma once
#include <iostream>
#include "DonThuc.h"
using namespace std;

class DaThuc
{
private:
	DonThuc* _d;
	int _n;
public:
	DaThuc();
	DaThuc(int n);
	DaThuc(const DaThuc& other);
	~DaThuc();

	int bacCaoNhat();
	float giaTri(float x);

	DaThuc& operator=(const DaThuc& other);

	DaThuc operator+(DaThuc other);
	DaThuc operator-(DaThuc other);
	DaThuc operator*(DaThuc other);

	//Phép chia 2 đa thức chỉ thực hiện được nếu bậc cao nhất của đa thức bị chia lớn hơn bậc cao nhất của đa thức chia
	//Phép chia không thực hiện nếu chia một đa thức bất kỳ cho 0
	DaThuc operator/(DaThuc other);


	friend istream& operator>>(istream& in, DaThuc& src);
	friend ostream& operator<<(ostream& out, const DaThuc& src);
};

