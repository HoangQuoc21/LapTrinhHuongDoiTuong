//21120542 Lâm Hoàng Quốc
//21120570 Đặng Nguyễn Thanh Tín

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Lớp cha Nhân vật
class NhanVat {
protected:
    string maSo;
    int suc_luc;
public:
    int tinhLuongGao(int soNgayChinhChien) {
        return 0;
    }
};



// Lớp con Nông dân
class NongDan : public NhanVat {
private:
    string phai;
public:
    NongDan(string _maSo, string _phai, int _sucluc) : phai(_phai) {
        maSo = _maSo;
        suc_luc = _sucluc;
    }

    int tinhLuongGao(int soNgayChinhChien) {
        if (phai == "Nam") {
            if (suc_luc >= 80)
                return soNgayChinhChien * 10;
            else
                return soNgayChinhChien * 8;
        }
            
        else if (phai == "Nu") {
            if (suc_luc >= 70)
                return soNgayChinhChien * 8;
            else
                return soNgayChinhChien * 6;
        }
    }
};

// Lớp con Chiến binh
class ChienBinh : public NhanVat {
private:
    int sucAn;
    string tamTrang;
public:
    ChienBinh(string _maSo, int _sucAn, string _tamTrang, int _sucluc) : sucAn(_sucAn), tamTrang(_tamTrang) {
        maSo = _maSo;
        suc_luc = _sucluc;
    }
    int tinhLuongGao(int soNgayChinhChien) {
        double tyLeAn = 1;
        if (suc_luc > 100)
            return soNgayChinhChien * sucAn;
        else if (tamTrang == "Buon")
            tyLeAn = 0.5;
        return soNgayChinhChien * sucAn * tyLeAn;
    }
};

int main() {
    int soNgayChinhChien;
   
    string line;
    // Đọc file INPUT.TXT
    freopen("input.TXT", "rt", stdin);
    freopen("output.TXT", "wt", stdout);

    getline(cin, line);
    soNgayChinhChien = stoi(line);
    vector<NhanVat*> nv;

    int gao_nd = 0;
    int gao_cb = 0;
    double tongLuongGao = 0;
    while (!cin.eof()) {


       
        //cin.getline(line,' ');
        getline(cin, line);
        vector<string> buffer;
        stringstream ss(line);
        while (ss) {
            string b;
            getline(ss, b, ' ');
            buffer.push_back(b);
        }

        if (buffer[0][0] == 'N') {
            nv.push_back(new NongDan(buffer[0], buffer[1], stoi(buffer[2])));
            NongDan nongDan(buffer[0], buffer[1], stoi(buffer[2]));
            gao_nd = nongDan.tinhLuongGao(soNgayChinhChien);
            tongLuongGao += gao_nd;
        }
        else {
            nv.push_back(new ChienBinh(buffer[0], stoi(buffer[1]), buffer[2], stoi(buffer[3])));
            ChienBinh chienBinh(buffer[0], stoi(buffer[1]), buffer[2], stoi(buffer[3]));
            gao_cb = chienBinh.tinhLuongGao(soNgayChinhChien);
            tongLuongGao += gao_cb;
        }
        

    }
    double kgGao = (double)tongLuongGao / (15);
    cout << kgGao;




    /* while (!cin.eof()) {
         string line;
         getline(cin, line);
         stringstream s();
         string maSo;
         getline()

         if (maSo.erase(2,2) == "N") {
             string phai;
             cin >> phai;
             NongDan nongDan(maSo, phai);
             tongLuongGao += nongDan.tinhLuongGao(soNgayChinhChien);
         }
         else if (maSo.erase(2, 2) == "C") {
             string tamTrang;
             int sucAn;
             cin >> sucAn >> tamTrang;
             ChienBinh chienBinh(maSo, sucAn, tamTrang);
             tongLuongGao += chienBinh.tinhLuongGao(soNgayChinhChien);
         }
     }*/

     // Ghi kết quả vào file OUTPUT.TXT
   /*  freopen("output.TXT", "wt", stdout);
     double kgGao = (double)tongLuongGao / (15 * soNgayChinhChien);
     cout << kgGao;*/

    return 0;
}
