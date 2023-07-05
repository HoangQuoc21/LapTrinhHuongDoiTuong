#include "QL_Phim.h"
#define _CRT_SECURE_NO_WARNINGS

template<typename T>
QL_Phim<T>::QL_Phim() {}

template<typename T>
QL_Phim<T>::~QL_Phim() {
	for (int i = 0; i < ds_phim.size(); i++)
		delete ds_phim[i];
}

template<typename T>
void QL_Phim<T>::nhap() {
	int n;
	cout << "Nhap vao so luong phim: ";
	cin >> n;
	cout << "==============================================================\n";
	for (int i = 1; i <= n; i++) {
		cout << "*Nhap vao phim thu " << i << endl;
		Phim* p = new Phim();
		cin >> *p;
		cout << "--------------------------------------------------------------\n";
		ds_phim.push(p);
	}
	sapXepTheoNamSanXuat();
}

template<typename T>
void QL_Phim<T>::xuat() {
	for (int i = 0; i < ds_phim.size(); i++) {
		cout << "*Thong tin phim thu " << i + 1 << ":\n";
		cout << *ds_phim[i] << endl;
		cout << "--------------------------------------------------------------\n";
	}
}

template<typename T>
void QL_Phim<T>::sapXepTheoNamSanXuat() {
	int sz = ds_phim.size();
	for (int i = 0; i < sz - 1; i++)
		for (int j = i + 1; j < sz; j++)
			if (ds_phim[i]->getNamXS() > ds_phim[j]->getNamXS())
				swap(ds_phim[i], ds_phim[j]);
}

template<typename T>
void QL_Phim<T>::themPhim() {
	Phim* them = new Phim;
	cout << "*Nhap thong tin phim muon them:\n";
	cin >> *them;
	ds_phim.push(them);
	sapXepTheoNamSanXuat();
}

template<typename T>
void QL_Phim<T>::docFile(char* tenFile) {
	ifstream fin(tenFile);
	char line[100];
	while (!fin.eof()) {
		fin.getline(line, 100);
		stringstream ss(line);

		char ma[6];
		char ten[50];
		char theLoai[50];
		char nhaXS[50];
		char namXS[10];
		char xepHang[10];

		ss.getline(ma, 6, '|');
		ss.getline(ten, 50, '|');
		ss.getline(theLoai, 50, '|');
		ss.getline(nhaXS, 50, '|');
		ss.getline(namXS, 10, '|');
		ss.getline(xepHang, 10, '|');

		Phim* them = new Phim(ma, ten, theLoai, nhaXS, atoi(namXS), atof(xepHang));
		ds_phim.push(them);
	}
	sapXepTheoNamSanXuat();
	fin.close();
}

template<typename T>
void QL_Phim<T>::ghiFile(char* tenFile) {
	ofstream fout(tenFile);
	for (int i = 0; i < ds_phim.size(); i++)
		if (i == ds_phim.size() - 1)
			fout << *ds_phim[i];
		else
			fout << *ds_phim[i] << endl;
	fout.close();
}

template<typename T>
void QL_Phim<T>::xoaPhimNXSHBO() {
	vector<Phim*> ds_phimB;
	for (int i = 0; i < ds_phim.size(); i++)
		if (strcmp(ds_phim[i]->getNhaXS(), "HBO")) {
			Phim* them = new Phim;
			*them = *ds_phim[i];
			ds_phimB.push(them);
		}
	for (int i = 0; i < ds_phim.size(); i++)
		delete ds_phim[i];
	ds_phim.~vector();
	for (int i = 0; i < ds_phimB.size(); i++)
		ds_phim.push(ds_phimB[i]);
}