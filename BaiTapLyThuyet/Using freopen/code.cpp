#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    system("cls");

    //Đọc file
    if(!freopen("in.txt", "r", stdin)){
        cout << "Cant open file to read.\n";
        exit(1);
    }
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //Ghi file
    if(!freopen("out.txt", "w", stdout)){
        cout << "Cant open file to write.\n";
        exit(1);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    //Chuyển stream cin về console (chịu, dòng dưới không đúng)
    freopen("CON", "r", stdin);
    int c,d;
    cin >> c >> d;

    //Chuyển stream cout về console
    freopen("CON", "w", stdout);
    cout << c << " " << d << endl;

    cout << "end of program" << endl;
    return 0;
}