#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <ctime>
using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

Date timNgayHienTai();

class SinhVien {
private:
    char _hoTen[30];
    char _maSo[30];
    Date _ngaySinh;
    float _cacDiem[3];
    float _diemTB;
    char _xepHang[30];
    void tinhDTB();
    void tinhXepHang();
public:
    SinhVien();
    SinhVien(char* hoTen, char* maSo, Date ngaySinh, float cacDiem[]);
    SinhVien(const SinhVien& svKhac);
    ~SinhVien();

    float dtb();
    bool cungNgaySinh(Date ngayHienTai);
    SinhVien& operator=(const SinhVien& svKhac);
    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, const SinhVien& sv);
};