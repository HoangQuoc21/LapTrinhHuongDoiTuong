#define _CRT_SECURE_NO_WARNINGS

#include "NhanVien.h"

NhanVien::NhanVien() {
	strcpy(ma, "");
	strcpy(hoTen, "");
	strcpy(gioiTinh, "");
	strcpy(ngaySinh, "");
	strcpy(diaChi, "");
}

NhanVien::NhanVien(char* m, char* ten,char* gioi, char* ns, char* dc) {
	strcpy(ma, m);
	strcpy(hoTen, ten);
	strcpy(gioiTinh, gioi);
	strcpy(ngaySinh, ns);
	strcpy(diaChi, dc);
}

NhanVien::NhanVien(const NhanVien& nv) {
	strcpy(ma, nv.ma);
	strcpy(hoTen, nv.hoTen);
	strcpy(gioiTinh, nv.gioiTinh);
	strcpy(ngaySinh, nv.ngaySinh);
	strcpy(diaChi, nv.diaChi);
}

char* NhanVien::getMa() {
	return ma;
}

char* NhanVien::getTen() {
	return hoTen;
}

char* NhanVien::getGioiTinh() {
	return gioiTinh;
}

char* NhanVien::getNgaySinh() {
	return ngaySinh;
}

char* NhanVien::getDiaChi() {
	return diaChi;
}

int NhanVien::tinhTuoi() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int ngayHT = ltm->tm_mday;
	int thangHT = 1 + ltm->tm_mon;
	int namHT = 1900 + ltm->tm_year;
	stringstream ss(this->ngaySinh);
	char buffer[10];
	int ngay, thang, nam;
	ss.getline(buffer,10, '/');
	ngay = atoi(buffer);
	ss.getline(buffer,10, '/');
	thang = atoi(buffer);
	ss.getline(buffer,10);
	nam = atoi(buffer);
	int tuoi = namHT - nam;
	if (thangHT < thang)
		tuoi--;
	else if (thang == thangHT)
		if (ngayHT < ngay)
			tuoi--;
	return tuoi;
}

void NhanVien::nhap(istream& in){
	in.ignore();
	cout << "-Nhap ma (5 ky tu): ";
	in.getline(ma, 6);
	while (strlen(ma) != 5) {
		cout << "*Ma khong hop le.Hay nhap lai: ";
		in.getline(ma, 6);
	}

	cout << "-Nhap ho ten: ";
	in.getline(hoTen, 50);
	cout << "-Nhap gioi tinh (Nam/Nu): ";
	in.getline(gioiTinh, 4);
	while (strcmp(gioiTinh, "Nam") && strcmp(gioiTinh, "Nu")) {
		cout << "*Gioi tinh khong hop le. Hay nhap lai: ";
		in.getline(gioiTinh, 4);
	}

	cout << "*Tuoi: Nam(18-60), Nu(18-55)\n";
	cout << "-Nhap ngay sinh (dd/mm/yyyy): ";
	in.getline(ngaySinh, 20);
	if (!strcmp(gioiTinh, "Nam")) {
		while (tinhTuoi() < 18 || tinhTuoi() > 60) {
			cout << "*Tuoi khong hop le. Nhap lai ngay sinh (dd/mm/yyyy): ";
			in.getline(ngaySinh, 20);
		}
	}
	else if (!strcmp(gioiTinh, "Nu")) {
		while (tinhTuoi() < 18 || tinhTuoi() > 55) {
			cout << "*Tuoi khong hop le. Nhap lai ngay sinh: ";
			cout << "-Nhap ngay sinh (dd/mm/yyyy): ";
			in.getline(ngaySinh, 20);
		}
	}

	cout << "-Nhap dia chi: ";
	in.getline(diaChi, 50);
}

void NhanVien::xuat(ostream& out) {
	out << "-Ma: " << ma << endl;
	out << "-Ho ten: " << hoTen << endl;
	out << "-Gioi tinh: " << gioiTinh << endl;
	out << "-Ngay sinh: " << ngaySinh << endl;
	out << "-Tuoi: " << tinhTuoi() << endl;
	out << "-Dia chi: " << diaChi << endl;
}

long NhanVien::tinhLuong() {
	return 0;
}

char* NhanVien::kieuNV() {
	char kieu[] = "NhanVien";
	return kieu;
}

void NhanVien::ghiFile(ofstream& fout) {
	fout << ma << "|" << hoTen << "|" << gioiTinh << "|" << ngaySinh << "|" << diaChi << "|";
}

istream& operator>>(istream& in, NhanVien*& nv) {
	nv->nhap(in);
	return in;
}

ostream& operator<<(ostream& out, NhanVien* nv) {
	nv->xuat(out);
	return out;
}