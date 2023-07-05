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

	while (1) {
		try {
			cout << "-Nhap ma(5 ky tu): ";
			in.getline(ma, 6);
			if (strlen(ma) != 5)
				throw length_error("*Loi Ma co so ky tu khac 5");
			break;
		}
		catch (exception & e) {
			cout << e.what() << ". Hay nhap lai:\n";
		}
	}

	cout << "-Nhap ho ten: ";
	in.getline(hoTen, 50);

	while (1) {
		try {
			cout << "-Nhap gioi tinh (Nam/Nu): ";
			in.getline(gioiTinh, 4);
			if (strcmp(gioiTinh, "Nam") && strcmp(gioiTinh, "Nu"))
				throw invalid_argument("*Loi gioi tinh khong hop le");
			break;
		}
		catch (exception& e) {
			cout << e.what() << ". Hay nhap lai:\n";
		}
	}

	while (1) {
		try {
			cout << "*Tuoi: Nam(18-60), Nu(18-55)\n";
			cout << "-Nhap ngay sinh (dd/mm/yyyy): ";
			in.getline(ngaySinh, 20);
			if (!strcmp(gioiTinh, "Nam") )
				if (tinhTuoi() < 18 || tinhTuoi() > 60)
					throw invalid_argument("*Loi tuoi nam khong hop le");
			if (!strcmp(gioiTinh, "Nu"))
				if (tinhTuoi() < 18 || tinhTuoi() > 55)
					throw invalid_argument("*Loi tuoi nu khong hop le");
			break;
		}
		catch (exception& e) {
			cout << e.what() << ". Hay nhap lai:\n";
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