#include <iostream>
#include "QuanLyEbook.h"
using namespace std;

int main() {
	system("cls");

	string inFile = "input.txt";
	string outFile = "ouput.txt";
	QuanLyEbook ql;

	ql.docDSTuFile(inFile);

	ofstream fout(outFile);
	if (!fout) {
		cout << "Khong the mo file " << outFile << " de ghi.\n";
		exit(1);
	}

	ql.sapXepGiaGiamDan(fout);
	cout << "-Da thuc hien xong YeuCau01.\n";
	ql.thongKeISBN(fout);
	cout << "-Da thuc hien xong YeuCau02.\n";
	ql.sapXepNgaySanXuatTangDan(fout);
	cout << "-Da thuc hien xong YeuCau03.\n";
	
	fout.close();
	cout << "* Ket thuc chuong trinh *\n";
	return 0;
}