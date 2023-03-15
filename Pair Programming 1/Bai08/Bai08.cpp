#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class ToaDo {
private:
	float _x, _y;
public:
	ToaDo();
	ToaDo(float x, float y);
	void setToaDo(float x, float y);
	float khoangCach(ToaDo b);
	string xuat();
};

ToaDo::ToaDo() {
	_x = _y = 0;
}

ToaDo::ToaDo(float x, float y) {
	_x = x; _y = y;
}

void ToaDo::setToaDo(float x, float y) {
	_x = x; _y = y;
}

float ToaDo::khoangCach(ToaDo b) {
	float dx = _x - b._x;
	float dy = _y - b._y;
	float ketQua = sqrt(pow(dx, 2) + pow(dy, 2));
	return ketQua;
}

string ToaDo::xuat() {
	stringstream builder;
	builder << "(" << _x << ", " << _y << ")";
	return builder.str();
}

ToaDo traiDat(0, 0);

class ThienThach {
private:
	string _ma;
	ToaDo _tam;
	float _banKinh;
	float _tocDo;
public:
	ThienThach();
	ThienThach(string thongTin);
	ThienThach(const ThienThach& khac);

	string ma();
	string tam();
	float banKinh();
	float tocDo();
	float thoiGianVaCham();
};

ThienThach::ThienThach() {
	_ma = "";
	_tam.setToaDo(0, 0);
	_banKinh = _tocDo = 0;
}

ThienThach::ThienThach(string thongTin) {
	stringstream ss(thongTin);
	string buffer;
	string x, y;
	getline(ss, buffer, ' ');
	_ma = buffer;
	getline(ss, buffer, ',');
	x = buffer.substr(1, buffer.size() - 1);
	getline(ss, buffer, ')');
	y = buffer.substr(1,buffer.size()-1);
	_tam.setToaDo(stof(x), stof(y));
	getline(ss, buffer, ' ');
	getline(ss, buffer, ' ');
	_banKinh = stof(buffer);
	getline(ss, buffer);
	_tocDo = stof(buffer);
}

ThienThach::ThienThach(const ThienThach& khac) {
	_ma = khac._ma;
	_tam = khac._tam;
	_banKinh = khac._banKinh;
	_tocDo = khac._tocDo;
}

string ThienThach::ma() {
	return _ma;
}

string ThienThach::tam() {
	return _tam.xuat();
}

float ThienThach::banKinh() {
	return _banKinh;
}

float ThienThach::tocDo() {
	return _tocDo;
}

float ThienThach::thoiGianVaCham() {
	float quangDuong = _tam.khoangCach(traiDat);
	//quangDuong -= _banKinh;

	float thoiGian = quangDuong / _tocDo;
	
	return thoiGian;
}

vector<ThienThach> docFile(string tenFileDoc) {
	fstream fin(tenFileDoc);
	string line;
	
	vector<ThienThach> cacThienThach;

	if (!fin) {
		cout << "Khong the mo file " << tenFileDoc << " de doc.\n";
		exit(1);
	}

	while (!fin.eof()) {
		getline(fin, line);
		ThienThach buffer(line);
		cacThienThach.push_back(buffer);
	}

	fin.close();
	cout << "*Da doc thanh cong file " << tenFileDoc << " va luu danh sach cac thienThach.\n";
	return cacThienThach;
}

void ghiFile(vector<ThienThach> cacThienThach) {
	string tenFileGhi = "output.txt";
	ofstream fout("output.txt");
	if (!fout) {
		cout << "Khong the mo file " << tenFileGhi << " de ghi.\n";
		exit(1);
	}
	float vaChamDauTien = 100;
	for (auto x : cacThienThach) {
		if (x.thoiGianVaCham() < vaChamDauTien)
			vaChamDauTien = x.thoiGianVaCham();
	}

	fout << "*Thien thach va cham Trai Dat dau tien la:\n";
	for (auto x : cacThienThach) {
		if (x.thoiGianVaCham() == vaChamDauTien)
			fout << x.ma() << " " << x.thoiGianVaCham() << endl;
	}
	fout.close();
	cout << "*Da ghi Thien thach va cham Trai Dat dau tien vao file " << tenFileGhi << endl;
}

int main() {
	system("cls");
	string fileDoc = "input.txt";
	vector<ThienThach> cacThienThach = docFile(fileDoc);
	for (auto x : cacThienThach)
		cout << x.ma() << " " << x.tam() << " " << x.banKinh() << " " << x.tocDo() << ": " << x.thoiGianVaCham() << endl;
	ghiFile(cacThienThach);
	return 0;
}