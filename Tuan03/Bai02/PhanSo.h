#pragma once
#include <iostream>
using namespace std;

class PhanSo {
private:
    int _tu, _mau;
    void rutGon();
public:
    PhanSo();
    PhanSo(int, int);
    PhanSo(const PhanSo&);
    float giaTri();
    void setPhanSo(int tu, int mau);

    PhanSo& operator=(const PhanSo&);
    PhanSo operator+(const PhanSo&);
    PhanSo operator-(const PhanSo&);
    PhanSo operator*(const PhanSo&);
    PhanSo operator/(const PhanSo&);

    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&, const PhanSo&);
};

int UCLN(int a, int b);




