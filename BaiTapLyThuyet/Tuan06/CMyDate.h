#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CMyDate
{
private:
	int _ngay, _thang, _nam;
public:
	CMyDate();
	void setDate(string date);

	bool operator>(const CMyDate& other);
	CMyDate& operator=(const CMyDate& other);

	friend istream& operator>>(istream& in, CMyDate& src);
	friend ostream& operator<<(ostream &out, const CMyDate& src);
};

