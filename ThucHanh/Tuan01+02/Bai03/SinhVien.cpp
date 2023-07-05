#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <ctime>
#include "SinhVien.h"

using namespace std;

Date timNgayHienTai() {
    Date ketQua;
    // thời gian hiện tại tính theo hệ thống

    time_t now = time(0);
    tm* ltm = localtime(&now);

    ketQua.ngay = ltm->tm_mday;
    ketQua.thang = 1 + ltm->tm_mon;
    ketQua.nam = 1900 + ltm->tm_year;

    return ketQua;
}

void SinhVien::tinhDTB() {
    _diemTB = _cacDiem[0] * 0.25 + _cacDiem[1] * 0.25 + _cacDiem[2] * 0.5;
}

void SinhVien::tinhXepHang() {
    if (_diemTB > 9)
        strcpy(_xepHang, "Xuat Sac");
    else if (_diemTB > 8)
        strcpy(_xepHang, "Gioi");
    else if (_diemTB > 7)
        strcpy(_xepHang, "Kha");
    else if (_diemTB > 6)
        strcpy(_xepHang, "Trung Binh Kha");
    else if (_diemTB > 5)
        strcpy(_xepHang, "Trung Binh");
    else if (_diemTB > 4)
        strcpy(_xepHang, "Yeu");
    else
        strcpy(_xepHang, "Kem");
}

SinhVien::SinhVien() {
    strcpy(_hoTen, "");
    strcpy(_maSo, "");
    Date ngaySinh{ 0,0,0 };
    _ngaySinh = ngaySinh;
    for (int i = 0; i < 3; i++)
        _cacDiem[i] = 0;
    _diemTB = 0;
    strcpy(_xepHang, "");
}

SinhVien::SinhVien(char* hoTen, char* maSo, Date ngaySinh, float cacDiem[]) {
    strcpy(_hoTen, hoTen);
    strcpy(_maSo, maSo);
    _ngaySinh = ngaySinh;
    for (int i = 0; i < 3; i++)
        _cacDiem[i] = cacDiem[i];
    tinhDTB();
    tinhXepHang();
}

SinhVien::SinhVien(const SinhVien& svKhac) {
    strcpy(_hoTen, svKhac._hoTen);
    strcpy(_maSo, svKhac._maSo);
    _ngaySinh = svKhac._ngaySinh;
    for (int i = 0; i < 3; i++)
        _cacDiem[i] = svKhac._cacDiem[i];
    _diemTB = svKhac._diemTB;
    strcpy(_xepHang, svKhac._xepHang);
}

SinhVien::~SinhVien() {}

float SinhVien::dtb() {
    return _diemTB;
}

bool SinhVien::cungNgaySinh(Date ngayHienTai) {
    return (_ngaySinh.ngay == ngayHienTai.ngay) && (_ngaySinh.thang = ngayHienTai.thang);
}

SinhVien& SinhVien::operator=(const SinhVien& svKhac) {
    strcpy(this->_hoTen, svKhac._hoTen);
    strcpy(this->_maSo, svKhac._maSo);
    _ngaySinh = svKhac._ngaySinh;
    for (int i = 0; i < 3; i++)
        this->_cacDiem[i] = svKhac._cacDiem[i];
    this->_diemTB = svKhac._diemTB;
    strcpy(this->_xepHang, svKhac._xepHang);
    return *this;
}

ostream& operator<<(ostream& out, const SinhVien& sv) {
    out << sv._maSo << " " << setw(20) << sv._hoTen << " " << sv._ngaySinh.ngay << "/" << sv._ngaySinh.thang << "/" << sv._ngaySinh.nam << " " << setw(5) << sv._diemTB << " " << setw(9) << sv._xepHang;
    return out;
}

istream& operator>>(istream& in, SinhVien& sv) {
    cout << "-Ho ten: ";
    cin.getline(sv._hoTen, sizeof(sv._hoTen));
    cout << "-Ma so: ";
    cin.getline(sv._maSo, sizeof(sv._maSo));
    cout << "-Ngay Sinh (dinh dang dd/mm/yyyy): \n";
    cout << "+Ngay: ";
    cin >> sv._ngaySinh.ngay;
    cout << "+thang: ";
    cin >> sv._ngaySinh.thang;
    cout << "+Nam: ";
    cin >> sv._ngaySinh.nam;
    cout << "-Diem:\n";
    cout << "+Bai tap: ";
    in >> sv._cacDiem[0];
    cout << "+Giua ky: ";
    in >> sv._cacDiem[1];
    cout << "+Cuoi ky: ";
    in >> sv._cacDiem[2];
    sv.tinhDTB();
    sv.tinhXepHang();
    return in;
}