#include "NVSanXuat.h"

NVSanXuat::NVSanXuat():NhanVien::NhanVien() {
	soSanPham = 0;
}

NVSanXuat::NVSanXuat(char* m, char* ten,char* gioi, char* ns, char* dc, int sanPham) :NhanVien::NhanVien(m, ten,gioi, ns, dc) {
	soSanPham = sanPham;
}

NVSanXuat::NVSanXuat(const NVSanXuat& nv):NhanVien::NhanVien(nv) {
	soSanPham = nv.soSanPham;
}

void NVSanXuat::nhap(istream& in) {
	NhanVien::nhap(in);
	cout << "-Nhap so luong san pham (10-15): ";
	in >> soSanPham;
	while (soSanPham < 10 || soSanPham > 15) {
		cout << "*So luong san pham khong hop le. Hay nhap lai: ";
		in >> soSanPham;
	}
}

void NVSanXuat::xuat(ostream& out) {
	NhanVien::xuat(out);
	out << "-So san pham: " << soSanPham << endl;
}

long NVSanXuat::tinhLuong() {
	return soSanPham * 50000;
}

char* NVSanXuat::kieuNV() {
	char kieu[] = "NVSanXuat";
	return kieu;
}

void NVSanXuat::ghiFile(ofstream& fout) {
	char kieu[20];
	strcpy(kieu, this->kieuNV());
	fout << kieu << "|";
	NhanVien::ghiFile(fout);
	fout << soSanPham << endl;
}

int NVSanXuat::getSL() {
	return soSanPham;
}