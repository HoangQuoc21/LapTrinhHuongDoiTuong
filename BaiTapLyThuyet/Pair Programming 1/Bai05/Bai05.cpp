#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

string reverseStr(string str){   
    string result;
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    result = str;
    return result;
}

class Date {
private:
    int _ngay;
    int _thang;
    int _nam;
public:
    Date();
    Date(int ngay, int thang, int nam);

    void setNgaySinh(string thongTin);
    int ngay();
    int thang();
    int nam();
};

Date::Date() {
    _ngay = _thang = _nam = 0;
}

Date::Date(int ngay, int thang, int nam) {
    _ngay = ngay;
    _thang = thang;
    _nam = nam;
}


void Date::setNgaySinh(string thongTin) {
    stringstream ss(thongTin);
    string buffer;
    getline(ss, buffer, '/');
    _ngay = stoi(buffer);
    getline(ss, buffer, '/');
    _thang = stoi(buffer);
    getline(ss, buffer);
    _nam = stoi(buffer);
}


int Date::ngay() {
    return _ngay;
}

int Date::thang() {
    return _thang;
}

int Date::nam() {
    return _nam;
}

Date timNgayHienTai() {
    int ngay, thang, nam;
    // thời gian hiện tại tính theo hệ thống

    time_t now = time(0);
    tm* ltm = localtime(&now);

    
    ngay = ltm->tm_mday;
    thang = 1 + ltm->tm_mon;
    nam = 1900 + ltm->tm_year;

    Date ketQua(ngay,thang,nam);
    return ketQua;
}

Date ngayHienTai = timNgayHienTai();

ostream& operator<<(ostream& out, Date src) {
    if (src.ngay() < 10)
        out << "0" << src.ngay() << "/";
    else
        out << src.ngay() << "/";

    if (1 + src.thang() < 10)
        out << "0" << src.thang() << "/";
    else
        out << src.thang() << "/";

    out << src.nam();

    return out;
}

class CauThu {
private:
	string _ten;
	Date _ngaySinh;
	int _tuoi;
    string _phai;
	void tinhTuoi();
public:
    CauThu();
    void setCauThu(string thongTin);
	string getTen();
	int getTuoi();
    string phai();
};

string CauThu::phai(){
    return _phai;
}

void CauThu::tinhTuoi() {
    _tuoi = ngayHienTai.nam() - _ngaySinh.nam();
    // if (ngayHienTai.thang() > _ngaySinh.thang())
    //     _tuoi++;
    // else if (ngayHienTai.thang() == _ngaySinh.thang()) {
    //     if (ngayHienTai.ngay() >= _ngaySinh.ngay())
    //         _tuoi++;
    // }
}

CauThu::CauThu() {
    _ten = "";
    _ngaySinh;
    _tuoi = 0;
}

void CauThu::setCauThu(string thongTin){
    thongTin = reverseStr(thongTin);
    string c;
    string buffer;
    stringstream ss(thongTin);
    getline(ss, c, ' ');
    _phai = c;
    getline(ss, buffer, ' ');
    buffer = reverseStr(buffer);
    _ngaySinh.setNgaySinh(buffer);
    getline(ss, buffer);
    buffer = reverseStr(buffer);
    _ten = buffer;

    tinhTuoi();
}

string CauThu::getTen() {
    return _ten;
}

int CauThu::getTuoi() {
    return _tuoi;
}

vector<CauThu> docFile() {
    string line;
    CauThu buffer;
    vector<CauThu> cacCauThu;

    
    freopen("input.txt", "rt", stdin);
    while (!cin.eof()) {
        getline(cin, line);
        buffer.setCauThu(line);
        cacCauThu.push_back(buffer);
    }
    
    return cacCauThu;
}

void ghiFile(vector<CauThu> cacCauThu) {
    freopen("output.txt", "wt", stdout);
    int tuoiLonNhat = 0;
    for (auto &x : cacCauThu) {
        if (x.phai() == "F"){
            if (x.getTuoi() > tuoiLonNhat){
                tuoiLonNhat = x.getTuoi();

            }
                
        }
        
    }

    cout << "*Nhung cau thu nu lon tuoi nhat la:\n";
    for (auto &x : cacCauThu) {
        if (x.phai() == "F"){
            if (x.getTuoi() == tuoiLonNhat)
                cout << x.getTen() << " " << x.getTuoi() << endl;
        }
           
    }
}


int main() {
    system("cls");
    
    cout << "*Ngay Hien Tai: " << ngayHienTai << endl;

    string tenFileDoc("input.txt");
    vector<CauThu> cacCauThu = docFile();
    // for (auto x: cacCauThu)
    //     cout << "_"<< x.phai() <<"_" << endl;
    ghiFile(cacCauThu);
    
    return 0;
}