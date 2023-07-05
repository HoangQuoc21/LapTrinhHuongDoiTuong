#include "CEbook.h"

CEbook::CEbook() {
	_ISBN = _tenSach = _tacGia = _theLoai = _nhaXuatBan = "";
	_ngayXuatBan.setDate("0,0,0");
	_gia = 0;
}

CEbook::CEbook(string ISBN, string tenSach, string tacGia, CMyDate ngayXuatBan, string theLoai, string nhaXuatBan, float gia) {
	_ISBN = ISBN;
	_tenSach = tenSach;
	_tacGia = tacGia;
	_theLoai = theLoai;
	_ngayXuatBan = ngayXuatBan;
	_nhaXuatBan = nhaXuatBan;
	_gia = gia;
}

CEbook::CEbook(const CEbook& other) {
	_ISBN = other._ISBN;
	_tenSach = other._tenSach;
	_tacGia = other._tacGia;
	_theLoai = other._theLoai;
	_ngayXuatBan = other._ngayXuatBan;
	_nhaXuatBan = other._nhaXuatBan;
	_gia = other._gia;
}

bool CEbook::operator>(const CEbook& other) {
	return (this->_gia > other._gia);
}

bool CEbook::operator>=(const CEbook& other) {
	return (this->_gia >= other._gia);
}

bool CEbook::operator<(const CEbook& other) {
	return (this->_gia < other._gia);
}

bool CEbook::operator<=(const CEbook& other) {
	return (this->_gia <= other._gia);
}

string CEbook::ISBN() {
	return _ISBN;
}

float CEbook::gia() {
	return _gia;
}

CMyDate CEbook::ngaySanXuat() {
	return _ngayXuatBan;
}

void CEbook::setBook(string ISBN, string tenSach, string tacGia, CMyDate ngayXuatBan, string theLoai, string nhaXuatBan, float gia) {
	_ISBN = ISBN;
	_tenSach = tenSach;
	_tacGia = tacGia;
	_theLoai = theLoai;
	_ngayXuatBan = ngayXuatBan;
	_nhaXuatBan = nhaXuatBan;
	_gia = gia;
}

istream& operator>>(istream& in, CEbook& src) {
	cout << "ISBN: ";
	in >> src._ISBN;
	cout << "Ten sach: ";
	in >> src._tenSach;
	cout << "Tac gia: ";
	in >> src._tacGia;
	cout << "Ngay xuat ban: ";
	in >> src._ngayXuatBan;
	cout << "The loai: ";
	in >> src._theLoai;
	cout << "Nha xuat ban: ";
	in >> src._nhaXuatBan;
	cout << "Gia: ";
	in >> src._gia;
	return in;
}
ostream& operator<<(ostream& out, const CEbook& src) {
	out << src._ISBN << " " << src._tenSach << " " << src._tacGia << " " << src._ngayXuatBan << " " << src._theLoai << " " << src._nhaXuatBan << " " << src._gia;
	return out;
}