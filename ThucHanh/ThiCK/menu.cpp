#include <iostream>
using namespace std;

int main(){
    int luaChon;
    while(1){
        system("cls");
        cout << "*Danh sach:\n";
        cout << "================================================================\n";
        cout << "============================== MENU ============================\n";
        cout << "1. .\n";
        cout << "2. .\n";
        cout << "3. .\n";
        cout << "4. .\n";
        cout << "5. .\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "============================== END =============================\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;
        cout << "================================================================\n";
        if (luaChon == 1){

        }
        else if (luaChon == 2){

        }
        else if (luaChon == 3){

        }
        else if (luaChon == 4){

        }
        else if (luaChon == 5){

        }
        else if (luaChon == 0){
            break;
        }
        else
            cout << "*Lua chon khong hop le.\n";
        system("pause");
    }
    cout << "*Ket thuc chuong trinh.*\n";
    return 0;
}