#include "QuanLyEbook.h"

void QuanLyEbook::docDSTuFile(string file) {
	ifstream fin(file);
	if (!fin) {
		cout << "Khong the doc danh sach tu file " << file << endl;
		exit(1);
	}
	string ISBN;
	string tenSach;
	string tacGia;
	string date;
	CMyDate d;
	string theLoai;
	string nhaXuatBan;
	string gia;

	while (!fin.eof()) {
		getline(fin, ISBN);
		getline(fin, tenSach);
		getline(fin, tacGia);
		getline(fin, date);
		d.setDate(date);
		getline(fin, theLoai);
		getline(fin, nhaXuatBan);
		getline(fin, gia);
		CEbook book(ISBN, tenSach, tacGia, d, theLoai, nhaXuatBan, stof(gia));
		bookList.push_back(book);
	}
	fin.close();
}

void QuanLyEbook::sapXepGiaGiamDan(ofstream &fout) {
	for (int i = 0; i < bookList.size() - 1; i++)
		for (int j = i + 1; j < bookList.size(); j++)
			if (bookList[i] < bookList[j])
				swap(bookList[i], bookList[j]);

	fout << "YeuCau01: Danh sach Ebook giam dan theo gia la: \n";
	fout << "==========================================================================================================\n";
	for (auto book : bookList)
		fout << book.ISBN() << " " << book.gia() << endl;
		
	fout << "==========================================================================================================\n\n";;
}

void QuanLyEbook::thongKeISBN(ofstream &fout) {
	fout << "YeuCau02: Danh Sach cac sach co ISBN 3 so cuoi la 730:\n";
	fout << "==========================================================================================================\n";
	for (auto book : bookList) {
		string isbn = book.ISBN();
		if (isbn.substr(isbn.size()-3,3) == "730")
			fout << book << endl;
	}
	fout << "==========================================================================================================\n\n";;
}

void QuanLyEbook::sapXepNgaySanXuatTangDan(ofstream &fout) {
	for (int i = 0; i < bookList.size() - 1; i++)
		for (int j = i + 1; j < bookList.size(); j++)
			if (bookList[i].ngaySanXuat() > bookList[j].ngaySanXuat())
				swap(bookList[i], bookList[j]);

	fout << "YeuCau03: Danh sach Ebook theo thu tu ngay san xuat tang dan la: \n";
	fout << "==========================================================================================================\n";
	for (auto book : bookList)
		fout << book << endl;

	fout << "==========================================================================================================\n\n";;
}