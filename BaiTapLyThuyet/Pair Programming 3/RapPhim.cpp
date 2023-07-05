#include <iostream>
using namespace std;

class RapThuong {
public:
	char ghe[100][100];
	int _m, _n;
	RapThuong(int m, int n) {
		_m = m; _n = n;

		for (int i = 0; i < _m; i++)
			for (int j = 0; j < n; j++)
				ghe[i][j] = 'V';
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < _n; j++)
					ghe[i][j] = 'T';
	}
	virtual void in() {
		cout << "  ";
		for (int i = 0; i < _n; i++)
			cout << i << " ";
		cout << endl;
		for (int i = 0; i < _m; i++) {
			cout << i << " ";
			for (int j = 0; j < _n; j++) {
					cout << ghe[i][j] << " ";
			}
				
			cout << endl;
		}
	}

	virtual float datVe() {

		float gia = 0;
		while (1) {
			system("cls");
			in();
			cout << "----------------------------------------\n";
			int i, j;
			cout << "Nhap -1-1 de dung.\n";
			cout << "dong: ";
			cin >> i;
			cout << "cot: ";
			cin >> j;
			if (i == -1 && j == -1) {
				in();
				break;
			}
			if (ghe[i][j] == 'X') {
				cout << "Ghe nay da duoc dat.\n";
			}
			else if (ghe[i][j] == 'T') {
				ghe[i][j] = 'X';
				gia += 60;
			}
			else if (ghe[i][j] == 'V') {
				ghe[i][j] = 'X';
				gia += 80;
			}
		}
		return gia;
	}
	virtual int giaVe(int i, int j) {
		if (ghe[i][j] == 'T')
			return 60;
		else if (ghe[i][j] == 'V')
			return 80;
	}

	virtual int gheTrong() {
		int dem = 0;
		for (int i = 0; i < _m; i++)
			for (int j = 0; j < _n; j++)
				if (ghe[i][j] != 'X')
					dem++;
		return dem;
	}
};

class RapVip : public RapThuong {
public:
	RapVip(int m ,int n):RapThuong(m, n){
		for (int j = 0; j < _n; j+=2)
			ghe[_m - 1][j] = 'D';
		for (int j = 1; j <_n; j+=2)
			ghe[_m - 1][j] = 'K';
	};

	void in() {
		cout << "  ";
		for (int i = 0; i < _n; i++)
			cout << i << " ";
		cout << endl;
		for (int i = 0; i < _m - 1; i++) {
			cout << i << " ";
			for (int j = 0; j < _n; j++) {
				cout << ghe[i][j] << " ";
			}

			cout << endl;
		}
		cout << _m - 1 << " ";
		for (int j = 0; j < _n; j += 2) {
			cout << ghe[_m - 1][j] << "   ";
		}
		cout << endl;
	};
	 float datVe() {

		float gia = 0;
		while (1) {
			system("cls");
			in();
			cout << "----------------------------------------\n";
			int i, j;
			cout << "Nhap -1-1 de dung.\n";
			cout << "dong: ";
			cin >> i;
			cout << "cot: ";
			cin >> j;
			if (i == -1 && j == -1) {
				in();
				break;
			}
		
				
			if (ghe[i][j] == 'X') {
				cout << "Ghe nay da duoc dat.\n";
			}
			else if (ghe[i][j] == 'T') {
				ghe[i][j] = 'X';
				gia += 90;
			}
			else if (ghe[i][j] == 'V') {
				ghe[i][j] = 'X';
				gia += 120;
			}
			else if (ghe[i][j] == 'D') {
				ghe[i][j] = 'X';
				gia += 200;
			}
			else if (ghe[i][j] == 'K') {
				cout << "Ghe khong ton tai.\n";
			}
		}
		return gia;
	}
	 int giaVe(int i, int j) {
		if (ghe[i][j] == 'T')
			return 90;
		else if (ghe[i][j] == 'V')
			return 120;
		else if (ghe[i][j] == 'D')
			return 200;
	}

	 int gheTrong() {
		int dem = 0;
		for (int i = 0; i < _m; i++)
			for (int j = 0; j < _n; j++)
				if (ghe[i][j] != 'X' && ghe[i][j] != 'K')
					dem++;
		return dem;
	}
};


int main() {
	
	int m, n;
	int c;
	cout << "Chon rap: \n";
	cout << "1. rap thuong\n";
	cout << "2. rap vip\n";
	cin >> c;
	if (c == 1) {
		cout << "RAP THUONG:\n";
		cout << "m: ";
		cin >> m;
		cout << "n: ";
		cin >> n;
		RapThuong r(m, n);
		cout << r.datVe() << "000 VND" << endl;
		cout << "So ghe con lai: " << r.gheTrong();
		
	}
	
	else {
		//int m, n;
		cout << "RAP VIP:\n";
		cout << "m: ";
		cin >> m;
		cout << "n: ";
		cin >> n;
		RapVip r2(m, n);
		cout << r2.datVe() << "000 VND" << endl;
		cout << "So ghe con lai: " << r2.gheTrong();
		
	}
	
	

	
	
	return 0;
}