#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "CEbook.h"
using namespace std;

class QuanLyEbook
{
private:
	vector<CEbook> bookList;
public:
	void docDSTuFile(string file);
	void sapXepGiaGiamDan(ofstream &fout);
	void thongKeISBN(ofstream &fout);
	void sapXepNgaySanXuatTangDan(ofstream &fout);
};

