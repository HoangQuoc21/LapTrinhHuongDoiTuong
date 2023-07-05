#include <iostream>
#include <sstream>
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

//drive* ptr = dynamic_cast<drive*>(base[i]); 
//Ép kiểu động con trỏ đúng kiểu vùng nhớ drive để sử dụng các phương thức chỉ drive mới có
//Còn base không có (mặc dù đã cho kế thừa)
//(Phải đúng kiểu vùng nhớ muốn ép thì ptr mới khác NULL)