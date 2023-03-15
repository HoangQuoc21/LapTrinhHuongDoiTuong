#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string reverseStr(string str) {
	string result;
	int n = str.size();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);

	result = str;
	return result;
}

class Time {
private:
	int _gio;
	int _phut;
public:
	Time();
	void setTime(string thoiGian);

	int toPhut();
};

Time::Time() {
	_gio = _phut = 0;
}

void Time::setTime(string thoiGian) {
	stringstream ss(thoiGian);
	string buffer;
	getline(ss, buffer, ':');
	_gio = stoi(buffer);
	getline(ss, buffer);
	_phut = stoi(buffer);
}

int Time::toPhut() {
	int ketQua = 0;
	ketQua += _gio * 60 + _phut;
	return ketQua;
}

bool coHopLe(Time startVoting, Time endVoting, Time thoiDiem) {
	return (startVoting.toPhut() < thoiDiem.toPhut()) && (thoiDiem.toPhut() < endVoting.toPhut());
}

class CaSi {
private:
	string _ma;
	string _ten;
	int _soPhieuHopLe;
public:
	CaSi();
	void setCaSi(string thongTin);
	void capNhatPhieu();
	string ma();
	string ten();
	int soPhieu();
};

CaSi::CaSi() {
	_ma = _ten = "";
	_soPhieuHopLe = 0;
}

void CaSi::setCaSi(string thongTin) {
	thongTin = thongTin.substr(0, thongTin.size() - 6);
	stringstream ss(thongTin);
	string buffer;
	getline(ss, buffer, ' ');
	_ma = buffer;
	getline(ss, buffer);
	_ten = buffer;
	//_soPhieuHopLe = 10;
}

void CaSi::capNhatPhieu() {
	_soPhieuHopLe++;
}

string CaSi::ma() {
	return _ma;
}

string CaSi::ten() {
	return _ten;
}

int CaSi::soPhieu() {
	return _soPhieuHopLe;
}

bool daXuatHien(vector<CaSi> cacCaSi, CaSi caSi) {
	for (auto x : cacCaSi) {
		if (x.ten() == caSi.ten())
			return true;
	}
	return false;
}

Time startVoting, endVoting;

vector<CaSi> docFile(string fileDoc) {
	vector<CaSi> cacCaSi;
	string line;
	ifstream fin(fileDoc);
	CaSi buffer;
	string strBuffer;

	if (!fin) {
		cout << "*Khong the mo file " << fileDoc << " de doc.\n";
		exit(1);
	}

	getline(fin, line);
	stringstream ss1(line);
	getline(ss1, strBuffer, ' ');
	startVoting.setTime(strBuffer);
	getline(ss1, strBuffer);
	endVoting.setTime(strBuffer);

	while (!fin.eof()) {
		getline(fin, line);
		buffer.setCaSi(line);
		if (!daXuatHien(cacCaSi, buffer))
			cacCaSi.push_back(buffer);
	}

	fin.seekg(0, ios::beg);
	getline(fin, line);

	while (!fin.eof()) {
		getline(fin, line);

		stringstream ss2(line);
		getline(ss2, strBuffer, ' ');

		string maBC = strBuffer;
		strBuffer = line.substr(line.size() - 6, line.size() - 1);

		Time thoiDiem;
		thoiDiem.setTime(strBuffer);

		if (coHopLe(startVoting, endVoting, thoiDiem)) 
			for (auto &x : cacCaSi) 
				if (maBC == x.ma()) {
					x.capNhatPhieu();
					break;
				}
	}

	fin.close();
	cout << "*Da doc file " << fileDoc << " va luu danh sach cac ca si.\n";
	return cacCaSi;
}

void ghiFile(vector<CaSi> cacCaSi) {
	string fileGhi = "output.txt";
	ofstream fout(fileGhi);

	if (!fout) {
		cout << "*Khong the mo file " << fileGhi << " de ghi.\n";
		exit(1);
	}

	int nhieuPhieuNhat = 0;
	for (auto x : cacCaSi) {
		if (x.soPhieu() > nhieuPhieuNhat)
			nhieuPhieuNhat = x.soPhieu();
	}

	fout << "*Cac ca si duoc binh chon nhieu nhat la:\n";
	for (auto x : cacCaSi)
		if (x.soPhieu() == nhieuPhieuNhat)
			fout << x.ten() << " " << x.soPhieu() << endl;

	fout.close();
	cout << "*Da ghi danh sach nhung ca si duoc binh chon nhieu nhat vao file " << fileGhi << endl;
}


int main() {
	system("cls");
	
	string fileDoc = "input.txt";
	vector<CaSi> cacCaSi = docFile(fileDoc);
	ghiFile(cacCaSi);
	
	return 0;
}