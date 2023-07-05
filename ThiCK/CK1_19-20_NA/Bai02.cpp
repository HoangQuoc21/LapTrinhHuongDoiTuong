#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class taiKhoan;
class giaoDich;
class GDRutTien;
class GDNapTien;
class GDChuyenKhoan;
class nganHang;
//=================================

class date {
private:
    int ngay, thang, nam;
    bool namNhuan() const {
        if (nam % 4 == 0) {
            if (nam % 100 == 0) {
                return nam % 400 == 0;
            }
            else {
                return true;
            }
        }
        return false;
    }
    int tinhNgay() const {
        int monthDays[] = { 31, 28 + namNhuan(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int days = 0;
        for (int i = 0; i < thang - 1; i++) {
            days += monthDays[i];
        }
        days += ngay;
        days += (nam - 1) * 365;
        days += (nam - 1) / 4;
        days -= (nam - 1) / 100;
        days += (nam - 1) / 400;
        return days;
    }
public:
    date() {
        ngay = thang = nam = 0;
    }
    date(int ng, int th, int na) {
        ngay = ng;
        thang = th;
        nam = na;
    }
    date(const date& d) {
        ngay = d.ngay;
        thang = d.thang;
        nam = d.nam;
    }
    void set(int ng, int th, int na) {
        ngay = ng;
        thang = th;
        nam = na;
    }
    void set(string d) {
        stringstream ss(d);
        string buffer;
        getline(ss, buffer, '/');
        ngay = stoi(buffer);
        getline(ss, buffer, '/');
        thang = stoi(buffer);
        getline(ss, buffer);
        nam = stoi(buffer);
    }
    int getNgay() {
        return ngay;
    }
    int getThang() {
        return thang;
    }
    int getNam() {
        return nam;
    }
    int khoangCach(const date& other) const {
        return abs(tinhNgay() - other.tinhNgay());
    }
    date& operator=(const date& d) {
        this->ngay = d.ngay;
        this->thang = d.thang;
        this->nam = d.nam;
        return *this;
    }
    friend istream& operator>>(istream& in, date& d) {
        cout << "\n+Nhap ngay: ";
        in >> d.ngay;
        cout << "+Nhap thang: ";
        in >> d.thang;
        cout << "+Nhap nam: ";
        in >> d.nam;
        return in;
    }
    friend ostream& operator<<(ostream& out, const date& d) {
        out << d.ngay << "/" << d.thang << "/" << d.nam;
        return out;
    }
    bool operator==(const date& d2) {
        return (ngay == d2.ngay && thang == d2.thang && nam == d2.nam);
    }
    bool operator>(const date& d2) {
        if (nam > d2.nam)
            return true;
        else if (nam == d2.nam) {
            if (thang > d2.thang)
                return true;
            else if (thang == d2.thang) {
                return (ngay > d2.ngay);
            }
        }
        return false;
    }
};

//============================
class taiKhoan {
private:
    int maTK;
    int maKH;
    date ngayMoTK;
    float soDu;
public:
    taiKhoan() {
        maTK = maKH = soDu = -1;
        ngayMoTK.set(0, 0, 0);
    }
    int getMaTK() {
        return maTK;
    }
    float getSoDu() {
        return soDu;
    }
    void setSoDu(float sd) {
        soDu = sd;
    }
    void nhap() {
        cout << "-Nhap ma tai khoan: ";
        cin >> maTK;
        cout << "-Nhap ma khach hang: ";
        cin >> maKH;
        cout << "-Nhap ngay mo tai khoan: ";
        cin >> ngayMoTK;
        cout << "-Nhap so du: ";
        cin >> soDu;
    }
    void xuat() {
        cout << maTK << "|" << maKH << "|" << ngayMoTK << "|" << soDu;
    }
};
//============================
class giaoDich {
private:
    int maGD;
    int maTK;
    date ngayGD;
    float soTienGD;
    string trangThai;
public:
    int getMaTK() {
        return maTK;
    }
    giaoDich() {
        maGD = maTK = soTienGD = -1;
        ngayGD.set(0, 0, 0);
        trangThai = "ChoThucHien";
    }
    virtual void nhap() {
        cout << "-Nhap ma giao dich: ";
        cin >> maGD;
        cout << "-Nhap ma tai khoan: ";
        cin >> maTK;
        cout << "-Nhap ngay giao dich: ";
        cin >> ngayGD;
        cout << "-Nhap so tien giao dich: ";
        cin >> soTienGD;
    }
    virtual void xuat() {
        cout << maGD << "|" << maTK << "|" << ngayGD << "|" << soTienGD << "|" << trangThai;
    }
    virtual string kieu() {
        return "";
    }
    float getSoTienGD() {
        return soTienGD;
    }
    void setTrangThai(string tt) {
        trangThai = tt;
    }
    string getTrangThai() {
        return trangThai;
    }
};
//============================
class GDRutTien :public giaoDich {
public:
    string kieu() {
        return "GDRutTien";
    }
};
//============================
class GDNapTien : public giaoDich {
public:
    string kieu() {
        return "GDNapTien";
    }
};
//============================
class GDChuyenKhoan : public giaoDich {
private:
    int maTKNhan;
public:
    GDChuyenKhoan() :giaoDich::giaoDich() {
        maTKNhan = -1;
    }
    void nhap() {
        giaoDich::nhap();
        cout << "-Nhap ma tai khoan nhan: ";
        cin >> maTKNhan;
    }
    void xuat() {
        giaoDich::xuat();
        cout << "|" << maTKNhan;
    }
    string kieu() {
        return "GDChuyenKhoan";
    }
    int getMaTKNhan() {
        return maTKNhan;
    }
};

//============================
class nganHang {
private:
    vector<taiKhoan> tk;
    vector<giaoDich*> gd;
public:
    nganHang() {
        
    }
    ~nganHang() {
        tk.clear();
        for (auto& x : gd)
            delete x;
        gd.clear();
    }
    void themTK() {
        taiKhoan t;
        cout << "*Nhap vao thong tin tai khoan muon them:\n";
        cout << "--------------------------------\n";
        t.nhap();
        tk.push_back(t);
    }
    void themGD() {
        int loai;
        cout << "1. Giao dich rut tien.\n";
        cout << "2. Giao dich nap tien.\n";
        cout << "3. Giao dich chuyen khoan.\n";
        cout << "Nhap vao loai giao dich muon tao: ";
        cin >> loai;
        cout << "====================================\n";
        giaoDich* g = NULL;
        if (loai == 1)
            g = new GDRutTien();
        else if (loai == 2)
            g = new GDNapTien();
        else if (loai == 3)
            g = new GDChuyenKhoan();
        g->nhap();
        gd.push_back(g);
    }
    void xuatTK() {
        for (auto x : tk) {
            x.xuat();
            cout << "\n---------------------------------\n";
        }
    }
    void xuatGD() {
        for (auto x : gd) {
            x->xuat();
            cout << "\n---------------------------------\n";
        }
    }
    void khopLenh() {
        for (auto& x : gd) {
            if (x->getTrangThai() == "ChoThucHien") {
                taiKhoan* t = NULL;
                for (auto& y : tk)
                    if (y.getMaTK() == x->getMaTK()) {
                        t = &y;
                        break;
                    }
                if (x->kieu() == "GDRutTien") {
                    if (t->getSoDu() < x->getSoTienGD()) {
                        x->setTrangThai("ThatBai");
                    }
                    else {
                        x->setTrangThai("ThanhCong");
                        t->setSoDu(t->getSoDu() - x->getSoTienGD() - 1000);
                    }
                }
                else if (x->kieu() == "GDNapTien") {
                    x->setTrangThai("ThanhCong");
                    t->setSoDu(t->getSoDu() + x->getSoTienGD());
                }
                else if (x->kieu() == "GDChuyenKhoan") {
                    GDChuyenKhoan* ptr = dynamic_cast<GDChuyenKhoan*>(x);
                    int maNhan = ptr->getMaTKNhan();
                    taiKhoan* t2 = NULL;
                    for (auto& z : tk)
                        if (z.getMaTK() == maNhan) {
                            t2 = &z;
                            break;
                        }
                    if (t2 == NULL) {
                        x->setTrangThai("ThatBai");
                    }
                    else {
                        x->setTrangThai("ThanhCong");
                        float tienChuyen = x->getSoTienGD();
                        
                        t->setSoDu(t->getSoDu() - tienChuyen - tienChuyen / 100);
                        t2->setSoDu(t2->getSoDu() + tienChuyen);
                    }
                            
                }
            }
        }
    }
};
//============================

//============================

int main() {
    nganHang nh;
    for (int i = 0; i < 2; i++)
        nh.themTK();
    cout << "=================================\n";
    for (int i = 0; i < 3; i++)
        nh.themGD();
    system("cls");
    cout << "=================================\n";
    nh.xuatTK();
    cout << "=================================\n";
    nh.xuatGD();
    cout << "*********************************\n";
    nh.khopLenh();
    nh.xuatTK();
    cout << "=================================\n";
    nh.xuatGD();
	return 0;
}

//1
//1
//21
//6
//2003
//10000
//2
//2
//26
//6
//2003
//12000
//1
//3
//1
//1
//1
//2020
//5000
//2
//4
//2
//2
//2
//2020
//6000
//3
//5
//1
//3
//3
//2020
//2000
//69