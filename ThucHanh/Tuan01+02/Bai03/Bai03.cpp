#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "QLSinhVien.h"



int main() {
    Date ngayHienTai = timNgayHienTai();
    char fileDoc[] = "input.txt";
    cout << fileDoc << endl;
    QLSinhVien ql;
    char luaChon[10];

    while (1) {
        system("cls");
        cout << "================================================================\n";
        cout << "=                        QUAN LY SINH VIEN                     =\n";
        cout << "================================================================\n";
        cout << "============================== MENU ============================\n";
        cout << "1. Ghi DSSV ra file \"dssv.txt\".\n";
        cout << "2. Doc dssv tu file " << fileDoc << ".\n";
        cout << "3. In ra dssv.\n";
        cout << "4. Them mot sv vao dssv & cap nhat vao file \"dssv.txt\".\n";
        cout << "5. Tim dssv co dtb thap hon dtb lop.\n";
        cout << "6. Tim dssv co cung ngay sinh voi ngay hien tai.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "============================== END =============================\n";
        cout << "-Lua chon cua ban: ";
        fflush(stdin);
        cin.getline(luaChon, 10);

        if (!strcmp(luaChon, "1")) {
            ql.ghiFile();
            cout << "*Da ghi dssv ra file \"dssv.txt\".\n ";
        }
        else if (!strcmp(luaChon, "2")) {
            ql.docFile(fileDoc);
            cout << "*Da doc dssv tu file " << fileDoc << endl;
        }
        else if (!strcmp(luaChon, "3")) {
            ql.xuatLop();
        }
        else if (!strcmp(luaChon, "4")) {
            ql.themSinhVien();
            ql.ghiFile();
            cout << "*Da them mot sv vao dssv va cap nhat vao file \"dssv.txt\".\n";
        }
        else if (!strcmp(luaChon, "5")) {
            ql.dtbNhoHon();
        }
        else if (!strcmp(luaChon, "6")) {
            cout << "*Ngay hien tai la: " << ngayHienTai.ngay << "/" << ngayHienTai.thang << "/" << ngayHienTai.nam << endl;
            ql.cungNgaySinh(ngayHienTai);
        }
        else if (!strcmp(luaChon, "0"))
            break;
        else
            cout << "-Lua chon khong hop le.\n";

        system("pause");
    }

    cout << "*Thoat chuong trinh thanh cong.\n";
    return 0;
}