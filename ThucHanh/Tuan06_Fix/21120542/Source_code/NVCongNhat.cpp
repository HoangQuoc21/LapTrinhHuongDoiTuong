#include "NVCongNhat.h"

NVCongNhat::NVCongNhat():NhanVien::NhanVien() {
	soNgay = 0;
}

NVCongNhat::NVCongNhat(char* m, char* ten, char* gioi, char* ns, char* dc, int ngay):NhanVien::NhanVien(m,ten,gioi,ns,dc) {
	soNgay = ngay;
}

NVCongNhat::NVCongNhat(const NVCongNhat& nv):NhanVien::NhanVien(nv) {
	soNgay = nv.soNgay;
}

void NVCongNhat::nhap(istream& in) {
	NhanVien::nhap(in);
	cout << "-Nhap so ngay (22-26): ";
	in >> soNgay;
	while (soNgay < 22 || soNgay > 26) {
		cout << "*So ngay khong hop le. Hay nhap lai: ";
		in >> soNgay;
	}
}

void NVCongNhat::xuat(ostream& out) {
	NhanVien::xuat(out);
	out << "-So ngay: " << soNgay << endl;
}

long NVCongNhat::tinhLuong() {
	return soNgay * 500000;
}

char* NVCongNhat::kieuNV() {
	char kieu[] = "NVCongNhat" ;
	return kieu;
}

void NVCongNhat::ghiFile(ofstream& fout) {
	char kieu[20];
	strcpy(kieu, this->kieuNV());
	fout << kieu << "|";
	NhanVien::ghiFile(fout);
	fout << this->soNgay << endl;
}

int NVCongNhat::getSL() {
	return soNgay;
}