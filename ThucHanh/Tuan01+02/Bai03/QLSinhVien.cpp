#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "QLSinhVien.h"
using namespace std;

void QLSinhVien::tinhDTBLop() {
    _dtbLop = 0;
    for (int i = 0; i < _n; i++)
        _dtbLop += _sv[i].dtb();
    _dtbLop /= _n;
}

QLSinhVien::QLSinhVien() {
    _n = 0;
    _sv = NULL;
    _dtbLop = 0;
}

QLSinhVien::QLSinhVien(int n) {
    _n = n;
    _sv = new SinhVien[n];
    for (int i = 0; i < _n; i++) {
        cout << "* Nhap vao sinh vien thu " << i + 1 << endl;
        cin >> _sv[i];
    }
    tinhDTBLop();
}

QLSinhVien::~QLSinhVien() {
    delete[] _sv;
}

void QLSinhVien::docFile(char* tenFileDoc) {
    int soLuongSinhVienDoc = 0;
    ifstream fin(tenFileDoc);
    if (!fin) {
        cout << "Khong doc duoc file " << tenFileDoc << endl;
        exit(1);
    }

    char line[100];

    fin.getline(line, '\n');
    soLuongSinhVienDoc = atoi(line);

    SinhVien* svDoc = new SinhVien[_n + soLuongSinhVienDoc];
    for (int i = 0; i < _n; i++)
        svDoc[i] = _sv[i];

    char hoTen[30];
    char maSo[30];
    Date ngaySinh;
    char buffer[5];
    float cacDiem[3];

    for (int i = _n; i < _n + soLuongSinhVienDoc; i++) {
        fin.getline(line, 100);

        stringstream ss(line);
        ss.getline(hoTen, 30, '|');
        ss.getline(maSo, 30, '|');

        ss.getline(buffer, 5, '/');
        ngaySinh.ngay = atoi(buffer);
        ss.getline(buffer, 5, '/');
        ngaySinh.thang = atoi(buffer);
        ss.getline(buffer, 5, '|');
        ngaySinh.nam = atoi(buffer);

        ss.getline(buffer, 5, ',');
        cacDiem[0] = atof(buffer);
        ss.getline(buffer, 5, ',');
        cacDiem[1] = atof(buffer);
        ss.getline(buffer, 5, '\n');
        cacDiem[2] = atof(buffer);

        SinhVien sv(hoTen, maSo, ngaySinh, cacDiem);
        svDoc[i] = sv;
    }
    delete[]_sv;
    _n = _n + soLuongSinhVienDoc;
    _sv = svDoc;

    fin.close();
    tinhDTBLop();
}


void QLSinhVien::ghiFile() {
    char fileGhi[] = "dssv.txt";
    ofstream fout(fileGhi);
    if (!fout) {
        cout << "Khong the mo file " << fileGhi << " de ghi.\n";
        exit(1);
    }

    fout << "DSSV: \n";
    fout << "----------------------------------------------------------------\n";
    fout << setw(8) << "MSSV" << "|" << setw(20) << "Ho Ten" << "|" << "Ngay Sinh " << "|" << setw(5) << "DTB" << "|" << setw(9) << "Xep Hang\n";
    fout << "----------------------------------------------------------------\n";
    for (int i = 0; i < _n; i++)
        fout << _sv[i] << endl;

    fout.close();
}

void QLSinhVien::xuatLop() {
    cout << "*Danh Sach Lop: \n";
    cout << "----------------------------------------------------------------\n";
    cout << setw(8) << "MSSV" << "|" << setw(20) << "Ho Ten" << "|" << "Ngay Sinh " << "|" << setw(5) << "DTB" << "|" << setw(9) << "Xep Hang\n";
    cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < _n; i++) {
        cout << _sv[i] << endl;
    }
}

void QLSinhVien::dtbNhoHon() {
    cout << "*DSSV co dtb nho hon dtb lop(dtb lop la " << _dtbLop << " ):\n";
    cout << "----------------------------------------------------------------\n";
    cout << setw(8) << "MSSV" << "|" << setw(20) << "Ho Ten" << "|" << "Ngay Sinh " << "|" << setw(5) << "DTB" << "|" << setw(9) << "Xep Hang\n";
    cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < _n; i++)
        if (_sv[i].dtb() < _dtbLop)
            cout << _sv[i] << endl;
}

void QLSinhVien::themSinhVien() {
    SinhVien* dssvMoi = new SinhVien[_n + 1];
    for (int i = 0; i < _n; i++)
        dssvMoi[i] = _sv[i];
    delete[] _sv;
    cout << "*Nhap vao thong tin sinh vien them vao: \n";

    cin >> dssvMoi[_n];

    _n++;
    _sv = dssvMoi;
    cout << "*Da them thanh cong sinh vien vao dssv.\n";
    tinhDTBLop();
    ghiFile();
}

void QLSinhVien::cungNgaySinh(Date ngayHienTai) {
    int dem = 0;
    for (int i = 0; i < _n; i++)
        if (_sv[i].cungNgaySinh(ngayHienTai))
            dem++;
    if (dem == 0)
        cout << "*Khong co sinh vien nao co cung ngay sinh voi ngay hien tai" << endl;
    else {
        cout << "*Danh sach sinh vien cung ngay sinh voi ngay " << ngayHienTai.ngay << "/" << ngayHienTai.thang << " la : \n";
        cout << "----------------------------------------------------------------\n";
        cout << setw(8) << "MSSV" << "|" << setw(20) << "Ho Ten" << "|" << "Ngay Sinh " << "|" << setw(5) << "DTB" << "|" << setw(9) << "Xep Hang\n";
        cout << "----------------------------------------------------------------\n";
        for (int i = 0; i < _n; i++)
            if (_sv[i].cungNgaySinh(ngayHienTai))
                cout << _sv[i] << endl;
    }
}
