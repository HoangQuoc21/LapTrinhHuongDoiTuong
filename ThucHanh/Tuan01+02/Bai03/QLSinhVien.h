#pragma once
#include "SinhVien.h"

class QLSinhVien {
private:
    SinhVien* _sv;
    int _n;
    float _dtbLop;
    void tinhDTBLop();
public:
    QLSinhVien();
    QLSinhVien(int n);
    ~QLSinhVien();
    void docFile(char* tenFileDoc);
    void ghiFile();
    void xuatLop();
    void dtbNhoHon();
    void themSinhVien();
    void cungNgaySinh(Date ngayHienTai);
};

