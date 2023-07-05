#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

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

//=================================
class KhachHang {
private:
    string ma;
    string ten;
    date ngayRaHD;
    int soLuong;
    float donGia;
public:
    KhachHang() {
        ma = ten = "";
        ngayRaHD.set(0, 0, 0);
        soLuong = donGia = 0;
    }
    string getMa() {
        return ma;
    }
    int getSL() {
        return soLuong;
    }
    float getGia() {
        return donGia;
    }
    void virtual nhap() {
        cin.ignore();
        cout << "-Nhap ma: ";
        getline(cin, ma);
        while (ma.length() != 6) {
            cout << "*Do dai ma khong hop le. Hay nhap lai: ";
            getline(cin, ma);
        }
        cout << "-Nhap ten: ";
        getline(cin, ten);
        cout << "-Nhap ngay ra hoa don: ";
        cin >> ngayRaHD;
        cout << "-Nhap so luong: ";
        cin >> soLuong;
        cout << "-Nhap vao don gia: ";
        cin >> donGia;
        while(!(donGia >= 2000 && donGia <= 3000)){
            cout << "*Don gia khong hop le. Hay nhap lai: ";
            cin >> donGia;
        }
    }
    void virtual xuat() {
        cout << ma << "|" << ten << "|" << ngayRaHD << "|" << soLuong << "|" << donGia;
    }
    virtual void ghiFile(ostream& fout) {
        fout << ma << "|" << ten << "|" << ngayRaHD << "|" << soLuong << "|" << donGia;
    }
    virtual float thanhTien() {
        return 0;
    }
    virtual string kieu() {
        return "";
    }
    
};
//=================================
struct diaChi {
    string soNha;
    string tenDuong;
    string phuong;
    string quan;
    string tp;
};

void nhapDC(diaChi& d) {
    cout << "+So nha: ";
    getline(cin, d.soNha);
    cout << "+Ten duong: ";
    getline(cin, d.tenDuong);
    cout << "+Phuong: ";
    getline(cin, d.phuong);
    cout << "+Quan: ";
    getline(cin, d.quan);
    cout << "+Thanh pho: ";
    getline(cin, d.tp);
}

void ghiDC(diaChi d, ostream& fout) {
    fout << d.soNha << ":" << d.tenDuong << ":" << d.phuong << ":" << d.quan << ":" << d.tp;
}

void xuatDC(diaChi d) {
    cout << d.soNha << ":" << d.tenDuong << ":" << d.phuong << ":" << d.quan << ":" << d.tp;
}

class KH_VietNam:public KhachHang {
private:
    string doiTuong;
    int dinhMuc;
    diaChi dc;
public:
    KH_VietNam() : KhachHang::KhachHang() {
        doiTuong = "";
        dinhMuc = 0;
    }
    void nhap() {
        KhachHang::nhap();
        cin.ignore();
        cout << "-Doi tuong (SinhHoat,KinhDoanh,SanXuat): ";
        getline(cin, doiTuong);
        if (doiTuong == "SinhHoat")
            dinhMuc = 150;
        else if (doiTuong == "KinhDoanh")
            dinhMuc = 300;
        else if (doiTuong == "SanXuat")
            dinhMuc = 500;
        cout << "-Nhap dia chi:\n";
        nhapDC(dc);
    }
    void xuat() {
        KhachHang::xuat();
        cout << "|" << doiTuong << "|" << dinhMuc << "|";
        xuatDC(dc);
        cout << endl;
    }
    void ghiFile(ostream& fout) {
        KhachHang::ghiFile(fout);
        fout << "|" << doiTuong << "|" << dinhMuc << "|";
        ghiDC(dc, fout);
        fout << endl;
    }
    float thanhTien() {
        if (getSL() <= dinhMuc)
            return (float)(getSL() * getGia());
        else {
            return (float)(getGia() * dinhMuc) + (float)((getSL() - dinhMuc) * getGia() * 1.5);
        }
    }
    string kieu() {
        return "KH_VietNam" + doiTuong;
    }
};
//=================================
class KH_NuocNgoai:public KhachHang {
private:
    string quocTich;
public:
    KH_NuocNgoai() :KhachHang::KhachHang() {
        quocTich = "";
    }
    void nhap() {
        KhachHang::nhap();
        cin.ignore();
        cout << "-Nhap vao quoc tich: ";
        getline(cin, quocTich);
    }
    void xuat() {
        KhachHang::xuat();
        cout << "|" << quocTich << endl;
    }
    void ghiFile(ostream& fout) {
        KhachHang::ghiFile(fout);
        fout << "|" << quocTich << endl;
    }
    float thanhTien() {
        return (float)(getSL() * getGia());
    }
    string kieu() {
        return "KH_NuocNgoai";
    }
};
//=================================
class QL_KhachHang {
private:
    int n;
    KhachHang** a;
public:
    QL_KhachHang() {
        n = 0;
        a = NULL;
    }
    ~QL_KhachHang() {
        if (a != NULL) {
            for (int i = 0; i < n; i++)
                delete a[i];
            delete[]a;
            a = NULL;
            n = 0;
        }
    }
    void nhap() {
        cout << "*Nhap vao so luong :";
        cin >> n;
        a = new KhachHang * [n];
        cout << "====================================\n";
        int loai;
        for (int i = 0; i < n; i++) {
            cout << "1.Khach Hang Viet Nam.\n";
            cout << "2.Khach Hang Nuoc Ngoai.\n";
            cout << "Chon loai khach hang: ";
            cin >> loai;
            cout << "----------------------\n";
            if (loai == 1)
                a[i] = new KH_VietNam();
            else if (loai == 2)
                a[i] = new KH_NuocNgoai();
            a[i]->nhap();
            cout << "---------------------------------\n";
        }
    }
    void xuat() {
        for (int i = 0; i < n; i++) {
            a[i]->xuat();
            cout << "-----------------------------------------------------------------------\n";
        }
    }
    void ghiFile() {
        ofstream fout("DSKH.dat");
        for (int i = 0; i < n; i++) {
            if (a[i]->getSL() < 150)
                a[i]->ghiFile(fout);
        }
        fout.close();
    }
    void trungBinhThanhTien() {
        float tongVN = 0;
        float tongNN = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamSinhHoat" || a[i]->kieu() == "KH_VietNamKinhDoanh" || a[i]->kieu() == "KH_VietNamSanXuat")
                tongVN += a[i]->thanhTien();
            else if (a[i]->kieu() == "KH_NuocNgoai")
                tongNN += a[i]->thanhTien();
        }
        cout << "*Tong thanh tien khach hang Viet Nam la: " << tongVN << endl;
        cout << "*Tong thanh tien khach hang nuoc ngoai la: " << tongNN << endl;
    }
    void them() {
        KhachHang** b = new KhachHang*[n + 1];
        KhachHang* t = NULL;
        cout << "*Nhap thong tin hoa don muon them\n";
        int loai;
        cout << "1.Khach Hang Viet Nam.\n";
        cout << "2.Khach Hang Nuoc Ngoai.\n";
        cout << "Chon loai khach hang: ";
        cin >> loai;
        cout << "----------------------\n";
        if (loai == 1)
            t = new KH_VietNam();
        else if (loai == 2)
            t = new KH_NuocNgoai();
        t->nhap();
        cout << "---------------------------------\n";
        int i;
        for (i = 0; i < n; i++) {
            if (stoi(a[i]->getMa()) < stoi(t->getMa()))
                b[i] = a[i];
            else
                break;
        }
       
        b[i] = t;
        while (i < n) {
            b[i+1] = a[i];
            i++;
        }
        
        delete[]a;
        a = b;
        n++;
    }
    void hoaDonLonNhatDoiTuong(){
        KhachHang* sh = NULL;
        KhachHang* kd = NULL;
        KhachHang* sx = NULL;
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamSinhHoat") {
                sh = a[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamSinhHoat") {
                if (a[i]->thanhTien() > sh->thanhTien())
                sh = a[i];
            }
        }
        if (sh) {
            cout << "*Hoa don khach hang viet nam doi tuong sinh hoat lon nhat la:\n";
            sh->xuat();
        }
        else {
            cout << "*Khong co hoa don khach hang viet nam doi tuong sinh hoat.\n";
        }
        //-------------------------------
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamKinhDoanh") {
                kd = a[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamKinhDoanh") {
                if (a[i]->thanhTien() > kd->thanhTien())
                    kd = a[i];
            }
        }
        if (kd) {
            cout << "*Hoa don khach hang viet nam doi tuong kinh doanh lon nhat la:\n";
            kd->xuat();
        }
        else {
            cout << "*Khong co hoa don khach hang viet nam doi tuong kinh doanh.\n";
        }
        //--------------------------------------------
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamSanXuat") {
                sx = a[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i]->kieu() == "KH_VietNamSanXuat") {
                if (a[i]->thanhTien() > sh->thanhTien())
                sx = a[i];
            }
        }
        if (sx) {
            cout << "*Hoa don khach hang viet nam doi tuong san xuat lon nhat la:\n";
            sx->xuat();
        }
        else {
            cout << "*Khong co hoa don khach hang viet nam doi tuong san xuat.\n";
        }
    }
};

//=================================
int main() {
    QL_KhachHang ql;
    ql.nhap();
    ql.ghiFile();
    while (1) {
        system("cls");
        cout << "*Danh Sach hoa don khach hang:\n";
        ql.xuat();
        cout << "============================== MENU ============================\n";
        cout << "1.Tinh trung binh thanh tien cua moi loai khach hang .\n";
        cout << "2.Hoa don tien lon nhat cua KHVN theo doi tuong .\n";
        cout << "3.Them hoa don .\n";
        cout << "4.Ghi danh sach KH co sl dien nho hon 150 vao file .\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "============================== END =============================\n";
        cout << "Lua chon cua ban: ";
        int luaChon;
        cin >> luaChon;
        cout << "================================================================\n";
        if (luaChon == 1) {
            ql.trungBinhThanhTien();
        }
        else if (luaChon == 2) {
            ql.hoaDonLonNhatDoiTuong();
        }
        else if (luaChon == 3) {
            ql.them();
        }
        else if (luaChon == 4) {
            ql.ghiFile();
            cout << "*Ghi file thanh cong.\n";
        }
        else if (luaChon == 0) {
            break;
        }
        else
            cout << "*Lua chon khong hop le.\n";
        system("pause");
    }
    cout << "*Ket thuc chuong trinh.*\n";
    return 0;
}

//3
//1
//123456
//lam hoang quoc
//1
//1
//2003
//12
//100
//2000
//SinhHoat
//122b/1
//Doc Mo 1
//Gia Tan 1
//Thong Nhat
//Dong Nai
//2
//123458
//Mike The King
//3
//4
//2005
//15
//3000
//America
//2
//123457
//Megusta
//5
//6
//2015
//10
//2500
//Mexico