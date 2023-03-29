#include "DaThuc.h"
#include "DonThuc.h"
#include <iostream>
using namespace std;

DaThuc::DaThuc() {
	_d = NULL;
	_n = 0;
}

DaThuc::DaThuc(int n) {
	_n = n;
	_d = new DonThuc[_n + 1];
	for (int i = 0; i <= _n; i++)
		_d[i].setDonThuc(0, i);
}

DaThuc::DaThuc(const DaThuc& other) {
	_n = other._n;
	_d = new DonThuc[_n + 1];
	for (int i = 0; i <= _n; i++)
		_d[i] = other._d[i];
}

DaThuc::~DaThuc() {
	if (_d != NULL)
		delete[]_d;
}

int DaThuc::bacCaoNhat() {
	return _n;
}

float DaThuc::giaTri(float x) {
	float ketQua = 0;
	for (int i = 0; i <= _n; i++)
		ketQua += _d[i].giaTri(x);
	return ketQua;
}

DaThuc& DaThuc::operator=(const DaThuc& other) {
	if (this->_d != NULL)
		delete[] this->_d;
	if (this != &other) {
		this->_n = other._n;
		this->_d = new DonThuc[_n + 1];
		for (int i = 0; i <= _n; i++)
			this->_d[i] = other._d[i];
	}
	
	return *this;
}

DaThuc DaThuc::operator+(DaThuc other) {
	int bd1 = this->bacCaoNhat();
	int bd2 = other.bacCaoNhat();
	DaThuc ketQua((bd1 > bd2) ? bd1 : bd2);

	if (bd1 > bd2) {
		for (int i = 0; i <= bd2; i++)
			ketQua._d[i] = this->_d[i] + other._d[i];
		for (int i = bd2 + 1; i <= bd1; i++)
			ketQua._d[i] = this->_d[i];
	}
	else if (bd1 < bd2) {
		for (int i = 0; i <= bd1; i++)
			ketQua._d[i] = this->_d[i] + other._d[i];
		for (int i = bd1 + 1; i <= bd2; i++)
			ketQua._d[i] = other._d[i];
	}
	else {
		for (int i = 0; i <= bd1; i++)
			ketQua._d[i] = this->_d[i] + other._d[i];
	}

	return ketQua;
}

DaThuc DaThuc::operator-(DaThuc other) {
	int bd1 = this->bacCaoNhat();
	int bd2 = other.bacCaoNhat();
	DaThuc ketQua((bd1 > bd2) ? bd1 : bd2);

	if (bd1 > bd2) {
		for (int i = 0; i <= bd2; i++)
			ketQua._d[i] = this->_d[i] - other._d[i];
		for (int i = bd2 + 1; i <= bd1; i++)
			ketQua._d[i] = this->_d[i];
	}
	else if (bd1 < bd2) {
		for (int i = 0; i <= bd1; i++)
			ketQua._d[i] = this->_d[i] - other._d[i];
		for (int i = bd1 + 1; i <= bd2; i++)
			ketQua._d[i] = other._d[i];
	}
	else {
		for (int i = 0; i <= bd1; i++)
			ketQua._d[i] = this->_d[i] - other._d[i];
	}

	return ketQua;
}

DaThuc DaThuc::operator*( DaThuc other) {
	int bd1 = this->bacCaoNhat();
	int bd2 = other.bacCaoNhat();

	DaThuc tich(bd1 + bd2);

	for (int i = 0; i <= bd1; i++) {
		//tongHangTu là tích của đơn thức đang xét với đa thức nhân
		DaThuc tongHangTu(bd1 + bd2);

		//Đơn thức thứ j của tongHangTu là tích của đơn thức thứ i đang xét của đơn thức bị nhân và đơn thức thứ j của đơn thức nhân
		for (int j = 0; j <= bd2; j++)
			tongHangTu._d[i + j] = this->_d[i] * other._d[j];

		//Cộng các tongHangTu của từng lần nhân (lặp) lại sẽ ra tích của 2 đa thức
		tich = tich + tongHangTu;
	}
	return tich;
}

//Phép chia thì cần lưu ý khá nhiều chỗ
DaThuc DaThuc::operator/( DaThuc other) {
	int bd1 = this->bacCaoNhat();
	int bd2 = other.bacCaoNhat();

	if (bd1 < bd2) {
		DaThuc biChia = *this;
		cerr << "Khong the chia " << biChia << " cho " << other << endl;
		exit(1);
	}
	else if (bd2 == -1 && other._d[0].heSo() == 0) {
		cerr << "Khong the chia " << this << " cho 0\n";
		exit(1);
	}

	DaThuc thuong(bd1 - bd2);

	while (bd1 >= bd2) {
		//hieuHangTu là thương của đơn thức có bậc cao nhất hiện tại của đa thức bị chia cho đơn thức có bậc cao nhất của đa thức chia
		DaThuc hieuHangTu(bd1 - bd2);
		hieuHangTu._d[bd1 - bd2] = this->_d[bd1] / other._d[bd2];

		//Đơn thức tại bậc bd1 - bd2 của thương bằng chính nó + hieuHangTu
		thuong._d[bd1 - bd2] = thuong._d[bd1 - bd2] + hieuHangTu._d[bd1 - bd2];

		//Trừ thương cho tích của hieuHangTu với số bị chia
		*this = *this - hieuHangTu * other;

		//Lặp cho đến khi nào bậc của đa thức bị chia nhỏ hơn đa thức chia
		bd1--;
	}

	//phần còn lại của đa thức bị chia chính là phần dư của phép chia 2 đa thức trên
	DaThuc phanDu = *this;
	cout << "Phan du cua phep chia la: " << phanDu << endl;
	cout << "(Khong co gi nghia la phep chia nay khong du)\n";

	return thuong;
}

istream& operator>>(istream& in, DaThuc& src) {
	if (src._d != NULL)
		delete[] src._d;
	cout << "Nhap vao bac lon nhat cua da thuc: ";
	in >> src._n;
	cout << "--------------------------------------\n";
	src._d = new DonThuc[src._n + 1];
	for (int i = src._n; i >= 0; i--) {
		float heSo;
		cout << "Nhap vao he so don thuc bac " << i << ": ";
		in >> heSo;
		src._d[i].setDonThuc(heSo, i);
	}
	return in;
}

ostream& operator<<(ostream& out, const DaThuc& src) {
	if (src._d[src._n].heSo() != 0)
		out << src._d[src._n];
	for (int i = src._n - 1; i >= 0; i--) {
		if (src._d[i].heSo() > 0)
			out << " + " << src._d[i];
		else if (src._d[i].heSo() < 0)
			out << " " << src._d[i];
	}
	return out;
}