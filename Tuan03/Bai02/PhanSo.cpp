#include "PhanSo.h"
#include <iostream>
using namespace std;

//Hàm UCLN có điều chỉnh 1 chút để tìm được cho trường hợp số âm
int UCLN(int a, int b) {
    if (a == 0)
        return 1;
    if (a < 0 && b < 0)
        return -UCLN(-a, -b);
    else if (a < 0 && b > 0)
        return UCLN(-a, b);
    else if (a > 0 && b < 0)
        return UCLN(a, -b);

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

void PhanSo::rutGon() {
    int soChia = UCLN(_tu, _mau);
    _tu = _tu / soChia;
    _mau = _mau / soChia;
    if (_tu > 0 && _mau < 0) {
        _tu = -_tu;
        _mau = -_mau;
    }
}

PhanSo::PhanSo() {
    _tu = 0; _mau = 1;
}

PhanSo::PhanSo(int tu, int mau) {
    _tu = tu; _mau = mau;
    rutGon();
}

PhanSo::PhanSo(const PhanSo& other) {
    _tu = other._tu;
    _mau = other._mau;
    rutGon();
}

float PhanSo::giaTri() {
    return ((float)_tu / _mau);
}

void PhanSo::setPhanSo(int tu, int mau) {
    _tu = tu; _mau = mau;
    rutGon();
}

PhanSo& PhanSo::operator=(const PhanSo& other) {
    this->_tu = other._tu;
    this->_mau = other._mau;
    //this->rutGon();
    return *this;
}

PhanSo PhanSo::operator+(const PhanSo& other) {
    int tuMoi = _tu * other._mau + _mau * other._tu;
    int mauMoi = _mau * other._mau;
    PhanSo ketQua(tuMoi, mauMoi);
    return ketQua;
}

PhanSo PhanSo::operator-(const PhanSo& other) {
    int tuMoi = _tu * other._mau - _mau * other._tu;
    int mauMoi = _mau * other._mau;
    PhanSo ketQua(tuMoi, mauMoi);
    return ketQua;
}

PhanSo PhanSo::operator*(const PhanSo& other) {
    int tuMoi = _tu * other._tu;
    int mauMoi = _mau * other._mau;
    PhanSo ketQua(tuMoi, mauMoi);
    return ketQua;
}

PhanSo PhanSo::operator/(const PhanSo& other) {
    int tuMoi = _tu * other._mau;
    int mauMoi = _mau * other._tu;
    PhanSo ketQua(tuMoi, mauMoi);
    return ketQua;
}

istream& operator>>(istream& in, PhanSo& src) {
    cout << "Tu: ";
    in >> src._tu;
    cout << "Mau: ";
    in >> src._mau;
    src.rutGon();
    return in;
}

ostream& operator<<(ostream& out, const PhanSo& src) {
    out << "(" << src._tu << "/" << src._mau << ")";
    return out;
}