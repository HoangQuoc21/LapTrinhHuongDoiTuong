#include <iostream>
#include <string>
using namespace std;

struct Date {
	int ngay, thang, nam;
};


class GiaoDich {
private:
	string maGD;
	Date ngayGD;
	long donGia;
	int soLuong;
public:
	GiaoDich() {
		maGD = "";
		ngayGD = { 0,0,0 };
		donGia = 0;
		soLuong = 0;
	}
	GiaoDich(string ma, Date ngay, long gia, int sl) {
		maGD = ma;
		ngayGD = ngay;
		donGia = gia;
		soLuong = sl;
	}
	GiaoDich(const GiaoDich& other) {
		maGD = other.maGD;
		ngayGD = other.ngayGD;
		donGia = other.donGia;
		soLuong = other.soLuong;
	}
	virtual void nhap() {
		cin.ignore();
		cout << "-Nhap ma giao dich: ";
		cin >> maGD;
		cout << "-Nhap ngay giao dich: \n";
		cout << "+Ngay: ";
		cin >> ngayGD.ngay;
		cout << "+Thang: ";
		cin >> ngayGD.thang;
		cout << "+Nam: ";
		cin >> ngayGD.nam;
		cout << "-Nhap don gia: ";
		cin >> donGia;
		cout << "-Nhap so luong: ";
		cin >> soLuong;
	}
	virtual void xuat() {
		cout << "-Ma giao dich: " << maGD << endl;
		cout << "-Ngay giao dich: " << ngayGD.ngay << "/" << ngayGD.thang << "/" << ngayGD.nam << endl;
		cout << "-Don gia: " << donGia << endl;
		cout << "-So luong: " << soLuong << endl;
	}
	virtual long thanhTien() {
		return soLuong * donGia;
	}
	string getMa() const {
		return maGD;
	}
	virtual Date getDate() {
		return ngayGD;
	}
	long getDonGia() const {
		return donGia;
	}
	int getSoLuong() const {
		return soLuong;
	}
	void setMa(string ma) {
		maGD = ma;
	}
	void setDate(Date ngay) {
		ngayGD = ngay;
	}
	void setDonGia(long gia) {
		donGia = gia;
	}
	void setSoLuong(int sl) {
		soLuong = sl;
	}
	virtual string loai() = 0;
};

class GDVang :private GiaoDich {
private:
	string loaiVang;
public:
	GDVang() :GiaoDich::GiaoDich() {
		loaiVang = "";
	}
	GDVang(string ma, Date ngay, long gia, int sl, string loai) : GiaoDich(ma, ngay, gia, sl) {
		loaiVang = loai;
	}
	void nhap() {
		GiaoDich::nhap();
		cin.ignore();
		cout << "-Nhap loai vang: ";
		getline(cin, loaiVang);
	}
	void xuat() {
		GiaoDich::xuat();
		cout << "-Loai vang: " << loaiVang << endl;
	}
	long thanhTien() {
		return GiaoDich::thanhTien();
	}
	string loai() {
		return "GDVang";
	}
	Date getDate() {
		return GiaoDich::getDate();
	}
};

class GDTienTe :private GiaoDich {
private:
	int tiGia;
	string loaiTien;
public:
	GDTienTe() :GiaoDich::GiaoDich() {
		tiGia = 0;
		loaiTien = "";
	}
	GDTienTe(string ma, Date ngay, long gia, int sl, int tg, string loai) : GiaoDich(ma, ngay, gia, sl) {
		tiGia = tg;
		loaiTien = loai;
	}
	void nhap() {
		GiaoDich::nhap();
		cout << "-Ti gia: ";
		cin >> tiGia;
		cout << "-Loai tien (VN, USD, Euro): ";
		cin >> loaiTien;
	}
	void xuat() {
		GiaoDich::xuat();
		cout << "-Ti gia: " << tiGia << endl;
		cout << "-Loai tien: " << loaiTien << endl;
	}
	long thanhTien() {
		if (loaiTien == "VN")
			return GiaoDich::thanhTien();
		else
			return GiaoDich::thanhTien() * tiGia;
	}
	string loaiGiaoDich() {
		return loaiTien;
	}
	string loai() {
		return "GDTienTe";
	}
	Date getDate() {
		return GiaoDich::getDate();
	}
};

class QLGiaoDich {
private:
	GDVang* gdv;
	int ngdv;
	GDTienTe* gdtt;
	int ngdtt;
public:
	QLGiaoDich() {
		gdv = NULL;
		ngdv = 0;
		gdtt = NULL;
		ngdtt = 0;
	}
	~QLGiaoDich() {
		if (gdv != NULL) {

			delete[]gdv;
			gdv = NULL;
			ngdv = 0;
		}
		if (gdtt != NULL) {
			delete[]gdtt;
			gdtt = NULL;
			ngdtt = 0;
		}
	}
	void nhap() {
		cout << "-Nhap vao so luong giao dich vang: ";
		cin >> ngdv;
		cout << "-Nhap vao so luong giao dich tien te: ";
		cin >> ngdtt;
		cout << "=======================================\n";
		gdv = new GDVang[ngdv];
		gdtt = new GDTienTe[ngdtt];
		for (int i = 0; i < ngdv; i++) {
			cout << "Nhap vao thong tin giao dich vang thu: " << i + 1 << endl;
			gdv[i].nhap();
			cout << "----------------------------------------------\n";
		}
		for (int i = 0; i < ngdtt; i++) {
			cout << "Nhap vao thong tin giao dich tien te thu: " << i + 1 << ":";
			gdtt[i].nhap();
			cout << "----------------------------------------------\n";
		}
	}
	void xuat() {
		cout << "GIAO DICH VANG: \n";
		cout << "=======================================\n";
		for (int i = 0; i < ngdv; i++) {
			cout << "Thong tin giao dich vang thu " << i + 1 << endl;
			gdv[i].xuat();
			cout << "----------------------------------------------\n";
		}
		cout << "==============================================\n";
		cout << "GIAO DICH TIEN TE: \n";
		cout << "=======================================\n";
		for (int i = 0; i < ngdtt; i++) {
			cout << "Thong tin giao dich tien te thu " << i + 1 << endl;
			gdtt[i].xuat();
			cout << "----------------------------------------------\n";
		}
	}

	void soLuong() {
		cout << "-So luong giao dich vang la: " << ngdv << endl;
		cout << "-So luong giao dich tien te la: " << ngdtt << endl;
	}
	void GDTTNhieuTienNhat() {
		GDTienTe max;
		for (int i = 0; i < ngdtt; i++)
			if (gdtt[i].loaiGiaoDich() == "VN") {
				max = gdtt[i];
				break;
			}

		for (int i = 0; i < ngdtt; i++)
			if (gdtt[i].thanhTien() > max.thanhTien() && gdtt[i].loaiGiaoDich() == "VN")
				max = gdtt[i];
		//if (max.loaiGiaoDich == "VN") {
			//cout << "*Giao dich tien te co so tien lon nhat theo loai tien VN la: ";
			//max.xuat();
		//}
		cout << "*Giao dich tien te co so tien lon nhat theo loai tien VN la: ";
		max.xuat();


		for (int i = 0; i < ngdtt; i++)
			if (gdtt[i].loaiGiaoDich() == "USD") {
				max = gdtt[i];
				break;
			}

		for (int i = 0; i < ngdtt; i++)
			if (gdtt[i].thanhTien() > max.thanhTien() && gdtt[i].loaiGiaoDich() == "USD")
				max = gdtt[i];
		//if (max.loaiGiaoDich == "USD") {
			//cout << "*Giao dich tien te co so tien lon nhat theo loai tien USD la: ";
			//max.xuat();
		//}
		cout << "*Giao dich tien te co so tien lon nhat theo loai tien USD la: ";
		max.xuat();


		for (int i = 0; i < ngdtt; i++)
			if (gdtt[i].loaiGiaoDich() == "Euro") {
				max = gdtt[i];
				break;
			}

		for (int i = 0; i < ngdtt; i++)
			if (gdtt[i].thanhTien() > max.thanhTien() && gdtt[i].loaiGiaoDich() == "Euro")
				max = gdtt[i];
		//if (max.loaiGiaoDich == "Euro") {
			//cout << "*Giao dich tien te co so tien lon nhat theo loai tien Euro la: ";
			//max.xuat();
		//}
		cout << "*Giao dich tien te co so tien lon nhat theo loai tien Euro la: ";
		max.xuat();
	}

	void giaoDichTrong12023() {
		cout << "Nhung giao dich vang trong thang 1 nam 2023 \n";
		cout << "============================================\n";
		for (int i = 0; i < ngdv; i++) {
			Date d = gdv[i].getDate();
			if ((d.thang == 1) && d.nam == 2023)
				gdv[i].xuat();
			cout << "----------------------------------------\n";
		}

		cout << "Nhung giao dich vang trong thang 1 nam 2023 \n";
		cout << "============================================\n";
		for (int i = 0; i < ngdtt; i++) {
			Date d = gdtt[i].getDate();
			if ((d.thang == 1) && d.nam == 2023)
				gdtt[i].xuat();
			cout << "----------------------------------------\n";
		}
	}
};



int main() {
	QLGiaoDich ql;
	ql.nhap();
	int choice;
	while (1) {
		system("cls");
		cout << "CAC GIAO DICH:\N";
		ql.xuat();
		cout << "====================== MENU ======================\n";
		cout << "1. Tim tong so luong cac loai giao dich\n";
		cout << "2. Giao dich tien te co so tien lon nhat theo loai\n";
		cout << "3. Xuat ra cac giao dich trong thang 1 nam 2023\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "==================================================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 1) {
			ql.soLuong();
		}
		else if (choice == 2) {
			ql.GDTTNhieuTienNhat();
		}
		else if (choice == 3) {
			ql.giaoDichTrong12023();
		}
		else if (choice == 0) {
			break;
		}
		else
			cout << "Lua chon khong hop le.\n";
		system("pause");
	}

	cout << "*Ket thuc chuong trinh.\n";
	return 0;
}