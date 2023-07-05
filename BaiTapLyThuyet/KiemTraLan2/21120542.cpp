//21120542 - Lâm Hoàng Quốc
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <cmath>
using namespace std;

//========================================= CLASS DATE =========================================
class Date {
private:
	int _ngay, _thang, _nam;
	
public:
	Date();
	void setDate(int ng, int th, int n);
	friend istream& operator>>(istream& in, Date& src);
	friend ostream& operator<<(ostream& out, const Date& src);
	int dayOfYear();
	int khoangCach( Date b);

};

int Date::dayOfYear() {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((_nam % 4 == 0 && _nam % 100 != 0) || _nam % 400 == 0)) {
		days[1] = 29;
	}
	int totalDays = _ngay;
	for (int i = 0; i < _thang - 1; i++) {
		totalDays += days[i];
	}
	return totalDays;
}

Date::Date() {
	_ngay = _thang = _nam = 0;
}

void Date::setDate(int ng, int th, int n) {
	_ngay = ng;
	_thang = th;
	_nam = n;
}

istream& operator>>(istream& in, Date& src) {
	cout << "-Ngay: ";
	in >> src._ngay;
	cout << "-Thang: ";
	in >> src._thang;
	cout << "-Nam: ";
	in >> src._nam;
	return in;
}

ostream& operator<<(ostream& out, const Date& src) {
	out << src._ngay << "/" << src._thang << "/" << src._nam;
	return out;
}

int Date::khoangCach(Date b) {
	int daysInYear1 = dayOfYear();
	int daysInYear2 = b.dayOfYear();
	int daysInYear = abs(daysInYear2 - daysInYear1);
	int yearsInDays = abs(b._nam - _nam) * 365;
	int leapYears = 0;
	for (int i = _nam + 1; i < b._nam; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
			leapYears++;
		}
	}
	int totalDays = daysInYear + yearsInDays + leapYears;
	return totalDays;
}



//========================================= CLASS CASI =========================================

class CaSiChuaNoiTieng {
protected:
	string hoTen;
	string maSo;
	Date DOB;
	int slAlbum;
	int soBuoiTrinhDien;
	long soLuotTheoDoi;
public:
	CaSiChuaNoiTieng();
	CaSiChuaNoiTieng(string ten, string ma, Date d, int album, int trinhDien, long theoDoi);
	CaSiChuaNoiTieng(const CaSiChuaNoiTieng& b);
	void setCaSi(string ten, string ma, Date d, int album, int trinhDien, long theoDoi);
	virtual string kieuCaSi();
	virtual long tinhLuong();
	friend istream& operator>>(istream& in,CaSiChuaNoiTieng& src);
	friend ostream& operator<<(ostream& out, const CaSiChuaNoiTieng& src);
	virtual void nhap();
	virtual void xuat();
	string ma();
	Date dob();
};

CaSiChuaNoiTieng::CaSiChuaNoiTieng() {
	hoTen = maSo = "";
	DOB.setDate(0, 0, 0);
	slAlbum = soBuoiTrinhDien = soLuotTheoDoi = 0;
}

CaSiChuaNoiTieng::CaSiChuaNoiTieng(string ten, string ma, Date d, int album, int trinhDien, long theoDoi) {
	hoTen = ten;
	maSo = ma;
	this->DOB = d;
	slAlbum = album;
	soBuoiTrinhDien = trinhDien;
	soLuotTheoDoi = theoDoi;
}

CaSiChuaNoiTieng::CaSiChuaNoiTieng(const CaSiChuaNoiTieng& b) {
	hoTen = b.hoTen;
	maSo = b.maSo;
	this->DOB = b.DOB;
	slAlbum = b.slAlbum;
	soBuoiTrinhDien = b.soBuoiTrinhDien;
	soLuotTheoDoi = b.soLuotTheoDoi;
}

void CaSiChuaNoiTieng::setCaSi(string ten, string ma, Date d, int album, int trinhDien, long theoDoi) {
	hoTen = ten;
	maSo = ma;
	this->DOB = d;
	slAlbum = album;
	soBuoiTrinhDien = trinhDien;
	soLuotTheoDoi = theoDoi;
}


string CaSiChuaNoiTieng::kieuCaSi() {
	return "CaSiChuaNoiTieng";
}

long CaSiChuaNoiTieng::tinhLuong() {
	return 3000000 + 250000 * soBuoiTrinhDien;
}

istream& operator>>(istream& in, CaSiChuaNoiTieng& src) {
	cout << "Nhap ho ten: ";
	getline(cin, src.hoTen);
	cout << "Nhap ma so: ";
	in >> src.maSo;
	cout << "Nhap ngay sinh: \n";
	in >> src.DOB;
	cout << "Nhap so luong album: ";
	in >> src.slAlbum;
	cout << "Nhap so buoi trinh dien: ";
	in >> src.soBuoiTrinhDien;
	cout << "Nhap so luot theo doi: ";
	in >> src.soLuotTheoDoi;
	in.ignore();
	return in;
}

ostream& operator<<(ostream& out, const CaSiChuaNoiTieng& src) {
	out << "Ho ten: " << src.hoTen << endl;
	out << "Ma so: " << src.maSo << endl;
	out << "Ngay sinh: " << src.DOB << endl;
	out << "So luong album: " << src.slAlbum << endl;
	out << "So buoi trinh dien: " << src.soBuoiTrinhDien << endl;
	out << "So luot theo doi: " << src.soLuotTheoDoi << endl;
	return out;
}

void CaSiChuaNoiTieng::nhap() {
	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap ma so: ";
	cin >> maSo;
	cout << "Nhap ngay sinh: \n";
	cin >> DOB;
	cout << "Nhap so luong album: ";
	cin >> slAlbum;
	cout << "Nhap so buoi trinh dien: ";
	cin >> soBuoiTrinhDien;
	cout << "Nhap so luot theo doi: ";
	cin >> soLuotTheoDoi;
	cin.ignore();
}

void CaSiChuaNoiTieng::xuat() {
	cout << "Ho ten: " << hoTen << endl;
	cout << "Ma so: " << maSo << endl;
	cout << "Ngay sinh: " << DOB << endl;
	cout << "So luong album: " << slAlbum << endl;
	cout << "So buoi trinh dien: " << soBuoiTrinhDien << endl;
	cout << "So luot theo doi: " << soLuotTheoDoi << endl;
}

string CaSiChuaNoiTieng::ma() {
	return maSo;
}

Date CaSiChuaNoiTieng::dob() {
	return DOB;
}

//===================================== CLASS CASI NOI TIENG ====================================
class CaSiNoiTieng :public CaSiChuaNoiTieng {
private:
	int gameshowTG;
public:
	CaSiNoiTieng();
	CaSiNoiTieng(string ten, string ma, Date d, int album, int trinhDien, long theoDoi, int gameshow);
	CaSiNoiTieng(const CaSiNoiTieng& b);
	void setCaSi(string ten, string ma, Date d, int album, int trinhDien, long theoDoi, int gameshow);
	string kieuCaSi();
	long tinhLuong();
	friend istream& operator>>(istream& in, CaSiNoiTieng& src);
	friend ostream& operator<<(ostream& out, const CaSiNoiTieng& src);
	void nhap();
	void xuat();
	
};

CaSiNoiTieng::CaSiNoiTieng():CaSiChuaNoiTieng(){
	gameshowTG = 0;
}

CaSiNoiTieng::CaSiNoiTieng(string ten, string ma, Date d, int album, int trinhDien, long theoDoi, int gameshow):CaSiChuaNoiTieng(ten,ma,d,album, trinhDien, theoDoi) {
	gameshowTG = gameshow;
}

CaSiNoiTieng::CaSiNoiTieng(const CaSiNoiTieng& b):CaSiChuaNoiTieng(b) {
	gameshowTG = b.gameshowTG;
}

void CaSiNoiTieng::setCaSi(string ten, string ma, Date d, int album, int trinhDien, long theoDoi, int gameshow) {
	hoTen = ten;
	maSo = ma;
	this->DOB = d;
	slAlbum = album;
	soBuoiTrinhDien = trinhDien;
	soLuotTheoDoi = theoDoi;
	gameshowTG = gameshow;
}

istream& operator>>(istream& in, CaSiNoiTieng& src) {
	cout << "Nhap ho ten: ";
	getline(cin, src.hoTen);
	cout << "Nhap ma so: ";
	in >> src.maSo;
	cout << "Nhap ngay sinh: \n";
	in >> src.DOB;
	cout << "Nhap so luong album: ";
	in >> src.slAlbum;
	cout << "Nhap so buoi trinh dien: ";
	in >> src.soBuoiTrinhDien;
	cout << "Nhap so luot theo doi: ";
	in >> src.soLuotTheoDoi;
	cout << "Nhap so gameshow tham gia: ";
	in >> src.gameshowTG;
	in.ignore();
	return in;
}

ostream& operator<<(ostream& out, const CaSiNoiTieng& src) {
	out << "Ho ten: " << src.hoTen << endl;
	out << "Ma so: " << src.maSo << endl;
	out << "Ngay sinh: " << src.DOB << endl;
	out << "So luong album: " << src.slAlbum << endl;
	out << "So buoi trinh dien: " << src.soBuoiTrinhDien << endl;
	out << "So luot theo doi: " << src.soLuotTheoDoi << endl;
	out << "So gameshow tham gia: " << src.gameshowTG << endl;
	return out;
}

string CaSiNoiTieng::kieuCaSi() {
	return "CaSiNoiTieng";
}

long CaSiNoiTieng::tinhLuong() {
	return 20000000 + 500000 * soBuoiTrinhDien + 5000000 * gameshowTG;
}

void CaSiNoiTieng::nhap() {
	CaSiChuaNoiTieng::nhap();
	cout << "Nhap so gameshow tham gia: ";
	cin >> gameshowTG;
}

void CaSiNoiTieng::xuat() {
	CaSiChuaNoiTieng::xuat();
	cout << "So gameshow tham gia: " << gameshowTG << endl;
}

//======================================= CONG TY QUAN LY =======================================
int SNN(int min, int max) {
	return rand() % (max - min + 1) + min;
}

class CongTy {
private:
	vector<CaSiChuaNoiTieng*> a;
public:
	CongTy();
	CongTy(int n);
	CongTy(const CongTy& b);
	~CongTy();
	void nhapThuCong();
	void nhapRanDom();
	void xuat();
	void thongKe();
	void xoaCaSi();
	void tinhLuongCty();
	void ganNgaySinhNhat();
};

CongTy::CongTy() {}

CongTy::CongTy(int n) {
	for (int i = 0; i < n; i++) {
		int choice;
		cout << "Chon ca si muon nhap: \n";
		cout << "1. Ca si chua noi tieng.\n";
		cout << "2. Ca si noi tieng.\n";
		cout << "---------------------------\n";
		cin >> choice;
		if (choice == 1) {
			CaSiChuaNoiTieng* b = new CaSiChuaNoiTieng;
			cin.ignore();
			b->nhap();
			a.push_back(b);
		}
		else if (choice == 2) {
			CaSiNoiTieng* b = new CaSiNoiTieng;
			cin.ignore();
			b->nhap();
			a.push_back(b);
		}
	}
}

CongTy::CongTy(const CongTy& b) {
	for (int i = 0; i < b.a.size(); i++) {
		if (b.a[i]->kieuCaSi() == "CaSiChuaNoiTieng") {
			CaSiChuaNoiTieng* temp = new CaSiChuaNoiTieng;
			*temp = *b.a[i];
			a.push_back(temp);
		}
		else {
			CaSiChuaNoiTieng* temp = new CaSiNoiTieng;
			*temp = *b.a[i];
			a.push_back(temp);
		}
	}
}

CongTy::~CongTy() {
	while (a.size() > 0) {
		CaSiChuaNoiTieng* temp = a[a.size() - 1];
		a.pop_back();
		delete temp;
	}
}



void CongTy::nhapThuCong() {
	while (1) {
		int choice;
		cout << "Chon ca si muon nhap: \n";
		cout << "1. Ca si chua noi tieng.\n";
		cout << "2. Ca si noi tieng.\n";
		cout << "-1. Thoat viec nhap.\n";
		cout << "---------------------------\n";
		cin >> choice;
		if (choice == 1) {
			CaSiChuaNoiTieng* b = new CaSiChuaNoiTieng;
			cin.ignore();
			b->nhap();
			a.push_back(b);
		}
		else if (choice == 2) {
			CaSiNoiTieng* b = new CaSiNoiTieng;
			cin.ignore();
			b->nhap();
			a.push_back(b);
		}
		else if (choice == -1)
			break;
		cout << "================================================\n";
	}

}

void CongTy::nhapRanDom() {
	srand(time(NULL));
	string ho[] = {"Lam", "Nguyen", "Tran", "Dang", "Pham"};
	string tenDem[] = { "Hoang", "Anh", "Mai", "Minh", "Son" };
	string ten[] = {"Quoc", "Tai", "Tung", "Tin", "Tri"};
	string ma[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
	int n;
	
	cout << "Nhap vao so luong nhan vien muon tao random: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tenfull = ho[SNN(0, 4)] + " " + tenDem[SNN(0, 4)] + " " + ten[SNN(0, 4)];
		string maSo = ma[SNN(0, 9)] + ma[SNN(0, 9)] + ma[SNN(0, 9)];
		Date d;
		d.setDate(SNN(1, 28), SNN(1, 12), SNN(2000, 2030));
		int album = SNN(1, 10);
		int trinhDien = SNN(1, 10);
		long theoDoi = SNN(990000, 5000000);
		if (theoDoi > 1000000) {
			int gameshow = SNN(1, 10);
			CaSiNoiTieng* temp = new CaSiNoiTieng;
			temp->setCaSi(tenfull, maSo, d, album, trinhDien, theoDoi, gameshow);
			a.push_back(temp);
		}
		else {
			CaSiChuaNoiTieng* temp = new CaSiChuaNoiTieng;
			temp->setCaSi(tenfull, maSo, d, album, trinhDien, theoDoi);
			a.push_back(temp);
		}
	}
}

void CongTy::xuat() {
	for (auto x : a) {
		x->xuat();
		cout << "--------------------------------------------------------------\n";
	}
}

void CongTy::thongKe() {
	int chuaNoiTieng = 0;
	int noiTieng = 0;
	for (auto x : a)
		if (x->kieuCaSi() == "CaSiChuaNoiTieng")
			chuaNoiTieng++;
		else
			noiTieng++;
	cout << "-So ca si chua noi tieng trong cong ty: " << chuaNoiTieng << endl;
	cout << "-So ca si noi tieng trong cong ty: " << noiTieng << endl;
}

void CongTy::xoaCaSi() {
	string id;
	cout << "Nhap vao ma ca si muon xoa: ";
	cin >> id;
	CaSiChuaNoiTieng* temp = NULL;
	for (int i = 0; i < a.size(); i++) {
		if (a[i]->ma() == id) {
			temp = a[i];
			a.erase(a.begin() + i);
		}
	}
	if (temp == NULL)
		cout << "Khong tim duoc ca si co ma " << id << endl;
	else {
		delete temp;
		temp = NULL;
		cout << "Da xoa ca si co ma " << id << endl;
	}
}

void CongTy::tinhLuongCty() {
	int thang = 0;
	cout << "Nhap vao so thang: ";
	cin >> thang;
	for (auto x : a) {
		cout << "-Tong luong cua ca si co ma " << x->ma() << ": " << x->tinhLuong() * thang << endl;
	}
}

void CongTy::ganNgaySinhNhat() {
	Date d;
	cout << "Nhap vao ngay thang nam sinh: \n";
	cin >> d;
	cout << "================================================\n";
	for (int i = 0; i < a.size() - 1; i++)
		for (int j = i+1; j < a.size(); j++)
			if (a[i]->dob().khoangCach(d) > a[j]->dob().khoangCach(d))
				swap(*a[i], *a[j]);
	cout << "3 ca si co khoang cach gan " << d << " nhat la:\n";
	for (int i = 0; i < 3; i++) {
		a[i]->xuat();
		cout << "--------------------------------------------------------------\n";
	}
		
}

int main() {
	CongTy cty;
	int choice;

	srand(time(NULL));
	cout << "Ban muon nhap ca si theo cach nao?\n";
	cout << "1. Nhap thu cong.\n";
	cout << "2. Nhap random tu dong.\n";
	cout << "---------------------------------\n";
	cout << "Lua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
		cty.nhapThuCong();
	else if (choice == 2)
		cty.nhapRanDom();
	else {
		cout << "Lua chon khong hop le.\n";
		exit(1);
	}
	while (1) {
		system("cls");
		cout << "DANH SACH CA SI CUA CONG TY:\n";
		cout << "================================================\n";
		cty.xuat();
		cout << "================================================\n";
		cty.thongKe();
		cout << "======================= MENU ===================\n";
		cout << "1. Tinh tong tien luong cong ty phai tra.\n";
		cout << "2. Xoa mot ca si.\n";
		cout << "3. Nhap vao ngay sinh, tim 3 ca si co khoang cach gan nhat sinh nhat.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "======================  END ====================\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 1)
			cty.tinhLuongCty();
		else if (choice == 2)
			cty.xoaCaSi();
		else if (choice == 3)
			cty.ganNgaySinhNhat();
		else if (choice == 0)
			break;
		else
			cout << "Lua chon khong hop le.\n";
		system("pause");
	}
	cout << "* Ket thuc chuong trinh *.\n";
	return 0;
}