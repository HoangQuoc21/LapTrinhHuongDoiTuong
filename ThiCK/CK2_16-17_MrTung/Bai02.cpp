#include <iostream>
#include <vector>
#include <string>
using namespace std;

class date {
private:
    int day;
    int month;
    int year;

public:
    date() :day(0), month(0), year(0) {}
    date(int d, int m, int y) : day(d), month(m), year(y) {}
    void set(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    void nhap() {
        cout << "+Ngay: ";
        cin >> day;
        cout << "+Thang: ";
        cin >> month;
        cout << "+Nam: ";
        cin >> year;
    }
    void xuat() {
        cout << day << "/" << month << "/" << year;
    }
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    bool isLeapYear() const {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                return year % 400 == 0;
            }
            else {
                return true;
            }
        }
        return false;
    }

    int tinhNgay() const {
        int monthDays[] = { 31, 28 + isLeapYear(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int days = 0;
        for (int i = 0; i < month - 1; i++) {
            days += monthDays[i];
        }
        days += day;
        days += (year - 1) * 365;
        days += (year - 1) / 4;
        days -= (year - 1) / 100;
        days += (year - 1) / 400;
        return days;
    }

    int getDistance(const date& other) const {
        return abs(tinhNgay() - other.tinhNgay());
    }
};

//==================================
class tauVuTru {
protected:
    string ma;
    string ten;
    string nhiemVu;
    float tocDo;
    date ngayPhong;
public:
    tauVuTru() {
        ma = ten = nhiemVu = "";
        tocDo = 0;
        ngayPhong.set(0, 0, 0);
    }
    virtual void nhap() {
        cin.ignore();
        cout << "-Nhap ma tau: ";
        getline(cin, ma);
        cout << "-Nhap ten tau: ";
        getline(cin, ten);
        cout << "-Nhap ten nhiem vu: ";
        getline(cin, nhiemVu);
        cout << "-Nhap toc do tau: ";
        cin >> tocDo;
        cout << "-Nhap ngay phong: \n";
        ngayPhong.nhap();
    }
    virtual void xuat() {
        cout << "-Ma tau: " << ma << endl;
        cout << "-Ten tau: " << ten << endl;
        cout << "-Ten nhiem vu: " << nhiemVu << endl;
        cout << "-Toc do: " << tocDo << endl;
        cout << "-Ngay phong: ";
        ngayPhong.xuat();
        cout << endl;
    }
    virtual int tinhSoNgayBay() {
        return 0;
    }
};
//==================================
class tauKhongNguoiLai :public tauVuTru {
private:
    int soNgayBay;
public:
    tauKhongNguoiLai():tauVuTru::tauVuTru(){
        soNgayBay = 0;
    }
    void nhap() {
        tauVuTru::nhap();
        cout << "-Nhap so ngay bay: ";
        cin >> soNgayBay;
    }
    void xuat() {
        tauVuTru::xuat();
        cout << "-So ngay bay: " << soNgayBay << endl;
    }
    int tinhSoNgayBay() {
        return soNgayBay;
    }
};
//==================================
class phiHanhGia {
private:
    string ten;
    string quocTich;
    float soGioBay;
public:
    phiHanhGia() {
        ten = quocTich = "";
        soGioBay = 0;
    }
    void nhap() {
        cin.ignore();
        cout << "+Ten phg: ";
        getline(cin, ten);
        cout << "+Quoc tich phg: ";
        getline(cin, quocTich);
        cout << "+So gio bay phg: ";
        cin >> soGioBay;
    }
    void xuat() {
        cout << ten << "|" << quocTich << "|" << soGioBay << endl;
    }
    float GetSoGioBay() {
        return soGioBay;
    }
};

class thucAn {
private:
    string ten;
    float trongLuong;
    date ngaySanXuat;
    date ngayHetHan;
public:
    thucAn() {
        ten = "";
        trongLuong = 0;
        ngaySanXuat.set(0, 0, 0);
        ngayHetHan.set(0, 0, 0);
    }
    void nhap() {
        cin.ignore();
        cout << "+Nhap ten thuc an: ";
        getline(cin, ten);
        cout << "+Nhap trong luong: ";
        cin >> trongLuong;
        cout << "+Nhap ngay san xuat: \n";
        ngaySanXuat.nhap();
        cout << "+Nhap ngay het han: \n";
        ngayHetHan.nhap();
    }
    void xuat() {
        cout << ten << "|" << trongLuong << "|";
        ngaySanXuat.xuat();
        cout << "|";
        ngayHetHan.xuat();
        cout << endl;
    }
};
//==================================
class tauCoNguoiLai :public tauVuTru {
private:
    int soPHG;
    vector<phiHanhGia> phg;
    vector<thucAn> ta;
    date ngayDapXuong;
public:
    tauCoNguoiLai() :tauVuTru::tauVuTru() {
        soPHG = 0;
        ngayDapXuong.set(0, 0, 0);
    }
    void nhap() {
        tauVuTru::nhap();
        cout << "-Nhap vao so phi hanh gia: ";
        cin >> soPHG;
        for (int i = 0; i < soPHG; i++) {
            cout << "*Nhap vao thong tin PHG thu " << i + 1 << ":\n";
            phiHanhGia a;
            a.nhap();
            phg.push_back(a);
            cout << "----------------------------------------\n";
        }
        cout << "-Nhap vao so thuc an: ";
        int soTA;
        cin >> soTA;
        for (int i = 0; i < soTA; i++) {
            cout << "*Nhap vao thong tin thuc an thu " << i + 1 << ":\n";
            thucAn a;
            a.nhap();
            ta.push_back(a);
            cout << "----------------------------------------\n";
        }
        cout << "-Nhap vao ngay dap xuong TD: \n";
        ngayDapXuong.nhap();
    }
    int tinhSoNgayBay() {
        return ngayDapXuong.getDistance(ngayPhong);
    }
    float tinhKGThucAn() {
        float soNgayBay = tinhSoNgayBay();
        float soCal =  soNgayBay*  2000;
        float soKG = soCal / 10000;
        if (soKG > 1000)
            return 1000;
        return soKG;
    }
    void xuat() {
        tauVuTru::xuat();
        cout << "-Thong tin cac phg:\n";
        for (auto x : phg)
            x.xuat();
        cout << "-Thong tin cac thuc an:\n";
        for (auto x : ta)
            x.xuat();
        cout << "-Ngay dap xuong TD:";
        ngayDapXuong.xuat();
        cout << endl;
        cout << "-Tong kg thuc an can thiet: " << tinhKGThucAn() << endl;
    }
    
   
};
//==================================
class QuanLyTau {
private:
    vector<tauVuTru*> tau;
public:
    QuanLyTau() {
       
    }
    ~QuanLyTau() {
        for (auto& x : tau)
            delete x;
        tau.clear();
    }
    void nhap() {
        int soTau;
        cout << "-Nhap vao so luong tau: ";
        cin >> soTau;
        cout << "==========================================\n";
        for (int i = 0; i < soTau; i++) {
            cout << "1. Tau khong nguoi lai.\n";
            cout << "2. Tau co nguoi lai.\n";
            cout << "Hay chon loai tau: ";
           
            int loai;
            cin >> loai;
            cout << "-----------------------\n";
            tauVuTru* t = NULL;
            if (loai == 1)
                t = new tauKhongNguoiLai();
            else if (loai == 2)
                t = new tauCoNguoiLai();
            t->nhap();
            tau.push_back(t);
            cout << "-----------------------------------------\n";
            cout << "==========================================\n";
        }
    }
    void xuat() {
        cout << "==========================================\n";
        for (auto x : tau) {
            x->xuat();
            cout << "---------------------------------------------------\n";
        }
    }
    int tongTGBay() {
        int tong = 0;
        for (auto x : tau)
            tong += x->tinhSoNgayBay();
        return tong;
    }
};
//==================================

int main() {
    QuanLyTau ql;
    ql.nhap();
    cout << "===================================================\n";
    ql.xuat();
    cout << "===================================================\n";
    cout << "*Tong thoi gian bay: " << ql.tongTGBay() << endl;
	return 0;
}

//2
//1
//A
//Appolo
//Searching metetor
//10.5
//21
//6
//2003
//13
//2
//B
//Beta
//Taking picture
//11
//22
//6
//2008
//2
//lam hoang quoc
// viet nam
// 6
// hoang khanh van
// viet nam
// 8
// 2
// dua hau
// 10
// 1
// 1
// 2020
// 2
// 2
// 2023
// chuoi
// 60
// 5
// 6
// 2003
// 7
// 8
// 2005
// 31
// 12
// 2009
//