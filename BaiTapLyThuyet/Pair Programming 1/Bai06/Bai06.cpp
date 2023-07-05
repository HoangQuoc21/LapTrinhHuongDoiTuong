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

	int toGiay();
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

int Time::toGiay() {
	int ketQua = 0;
	ketQua += _gio * 60 + _phut;
	return ketQua;
}

bool coHopLe(Time startVoting, Time endVoting, Time thoiDiem) {
	return (startVoting.toGiay() < thoiDiem.toGiay()) && (thoiDiem.toGiay() < endVoting.toGiay());
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

vector<CaSi> docFile() {
	vector<CaSi> cacCaSi;
	string line;
	
	CaSi buffer;
	string strBuffer;

	
	freopen("input.txt", "rt", stdin);
	getline(cin, line);
	stringstream ss1(line);
	getline(ss1, strBuffer, ' ');
	startVoting.setTime(strBuffer);
	getline(ss1, strBuffer);
	endVoting.setTime(strBuffer);

	while (!cin.eof()) {
		getline(cin, line);
		buffer.setCaSi(line);
		if (!daXuatHien(cacCaSi, buffer))
			cacCaSi.push_back(buffer);
	}

	cin.seekg(0);
	getline(cin, line);
	while (!cin.eof()) {
		getline(cin, line);

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

	return cacCaSi;
}

void ghiFile(vector<CaSi> cacCaSi) {
	freopen("output.txt", "wt", stdout);

	int nhieuPhieuNhat = 0;
	for (auto x : cacCaSi) {
		if (x.soPhieu() > nhieuPhieuNhat)
			nhieuPhieuNhat = x.soPhieu();
	}

	cout << "*Cac ca si duoc binh chon nhieu nhat la:\n";
	for (auto x : cacCaSi)
		if (x.soPhieu() == nhieuPhieuNhat)
			cout << x.ten() << " " << x.soPhieu() << endl;
}


int main() {
	system("cls");
	
	string fileDoc = "input.txt";
	vector<CaSi> cacCaSi = docFile();
	ghiFile(cacCaSi);
	
	return 0;
}