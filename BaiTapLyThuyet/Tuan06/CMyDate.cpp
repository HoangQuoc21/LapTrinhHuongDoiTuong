#include "CMyDate.h"

CMyDate::CMyDate() {
	_ngay = _thang = _nam = 0;
}

void CMyDate::setDate(string date) {
	stringstream ss(date);
	string buffer;
	getline(ss, buffer, '/');
	_ngay = stoi(buffer);
	getline(ss, buffer, '/');
	_thang = stoi(buffer);
	getline(ss, buffer);
	_nam = stoi(buffer);
}

bool CMyDate::operator>(const CMyDate& other) {
	if (this->_nam > other._nam)
		return true;
	else if (this->_nam == other._nam) {
		if (this->_thang > other._thang)
			return true;
		else if (this->_thang == other._thang) {
			if (this->_ngay > other._ngay)
				return  true;
			else
				//this->_ngay <= other.ngay
				return false;
		}
		else
			//this->_thang < other._thang
			return false;
	}
	else 
		//this->_nam < other._nam
		return false;
}

CMyDate& CMyDate::operator=(const CMyDate& other) {
	if (this != &other) {
		this->_ngay = other._ngay;
		this->_thang = other._thang;
		this->_nam = other._nam;
	}
	return *this;
}

istream& operator>>(istream& in, CMyDate& src) {
	cout << "-Ngay: ";
	in >> src._ngay;
	cout << "-Thang: ";
	in >> src._thang;
	cout << "-Nam: ";
	in >> src._nam;
	return in;
}

ostream& operator<<(ostream& out, const CMyDate& src) {
	out << src._ngay << "/" << src._thang << "/" << src._nam;
	return out;
}