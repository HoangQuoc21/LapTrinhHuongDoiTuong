#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main() {
	int km = 0;
	while (1) {
		system("cls");
		cout << km << endl;
		try {
			if (km == 20)
				throw "QUA TOC DO";
			if (_kbhit()) {
				char c = _getch();
				
				if ((int)(c) == 72)
					km++;
				else if ((int)c == 80) {
					if (km > 0)
						km--;
				}
				else if ((int)c == 27)
					break;
				
			}
		}
		catch (const char* str) {
			while (km > 0) {
				system("cls");
				cout << str << endl;
				cout << km-- << endl;
				Sleep(100);
			}
		}
		Sleep(100);
	}
	cout << "*Ket thuc chuong trinh.\n";
	return 0;
}