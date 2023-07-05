#include <iostream>
#include <string>
#include "MangPhanSo.h"
using namespace std;

int main() {
    system("cls");
    MangPhanSo a;
    string choice, fileName;
    while (1) {
        system("cls");
        cout << "========================== MENU ========================\n";
        cout << "1. Nhap mang phan so.\n";
        cout << "2. Xuat mang phan so.\n";
        cout << "3. Tinh tong cua mang phan so.\n";
        cout << "4. Sap xep mang phan so tang dan.\n";
        cout << "5. Ghi mang phan so len file.\n";
        cout << "6. Doc mang phan so tu file, sau do xuat ra man hinh.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "========================================================\n";
        cout << "Lua chon cua ban: ";
        fflush(stdin);
        getline(cin, choice);

        if (choice == "1") {
            a.nhapMang();
        }
        else if (choice == "2") {
            a.xuatMang();
        }
        else if (choice == "3") {
            cout << "Tong cua mang phan so la: " << a.tong() << endl;
        }
        else if (choice == "4") {
            a.sapXepTangDan();
            cout << "Da sap xep mang phan so theo thu tu tang dan.\n";
        }
        else if (choice == "5") {
            cout << "Nhap vao ten file muon ghi mang phan so ra: ";
            fflush(stdin);
            getline(cin, fileName);
            a.ghiFile(fileName);
            cout << "Da ghi mang phan so ra file " << fileName << endl;
        }
        else if (choice == "6") {
            cout << "Nhap vao ten file muon doc mang phan so: ";
            fflush(stdin);
            getline(cin, fileName);
            a.docFile(fileName);
            cout << "Da doc mang phan so tu file " << fileName << endl;
            cout << "Mang phan so hien tai:\n";
            a.xuatMang();
        }
        else if (choice == "0")
            break;
        else
            cout << "Lua chon khong hop le.\n";

        system("pause");
    }
    cout << "Ket thuc chuong trinh.\n";
    return 0;
}