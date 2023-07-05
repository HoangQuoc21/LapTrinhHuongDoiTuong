#include <iostream>
using namespace std;

//Class ATM =================================================================
class ATM {
private:
    int to500;
    int to200;
    int to100;
    int to50;
    int soDu;
    void tinhSoDu();
public:
    ATM();
    int getTo500();
    int getTo200();
    int getTo100();
    int getTo50();
    int getSoDu();
    void rutTien();
};

ATM::ATM() {
    to500 = 10;
    to200 = 20;
    to100 = 10;
    to50 = 2;
    soDu = 10100;
}

int ATM::getTo500() {
    return to500;
}

int ATM::getTo200() {
    return to200;
}

int ATM::getTo100() {
    return to100;
}

int ATM::getTo50() {
    return to50;
}

int ATM::getSoDu() {
    return soDu;
}

void ATM::tinhSoDu() {
    soDu = 500 * to500 + 200 * to200 + 100 * to100 + 50 * to50;
}

void ATM::rutTien() {
    int rut500, rut200, rut100, rut50;
    int soTienRut;
    cout << "Nhap so tien muon rut (VND): ";
    cin >> soTienRut;

    //Vì thuộc tính các tờ tiền của ATM tính bằng ngàn(VND) nên cần chia soTienRut(VND) cho 1000 để xử lý rút tiền được
    soTienRut /= 1000;


    //Tìm bộ bốn loại tiền đầu tiên thỏa số tiền rút
    //Ưu tiên rút tờ tiền nhỏ hơn
    for (int i = 0; i <= soTienRut / 500; i++) {
        rut500 = i;
        for (int j = 0; j <= (soTienRut - rut500 * 500) / 200; j++) {
            rut200 = j;
            for (int k = 0; k <= (soTienRut - rut500 * 500 - rut200 * 200) / 100; k++) {
                rut100 = k;
                for (int u = 0; u <= (soTienRut - rut500 * 500 - rut200 * 200 - rut100 * 100) / 50; u++) {
                    rut50 = u;
                    if ((rut500 * 500 + rut200 * 200 + rut100 * 100 + rut50 * 50 == soTienRut) && (rut500 >= 1 && rut200 >= 1 && rut100 >= 1 && rut50 >= 1)
                        && (rut500 <= to500 && rut200 <= to200 && rut100 <= to100 && rut50 <= to50)) {

                        //Nếu tìm được bộ các tờ tiền rút đầu tiên thỏa số tiền rút và chưa hết loại tiền nào, thì thực hiện rút và kết thúc phương thức
                        to500 -= rut500;
                        to200 -= rut200;
                        to100 -= rut100;
                        to50 -= rut50;
                        tinhSoDu();
                        cout << "*Rut thanh cong: \n";
                        cout << "- " << rut500 << " to 500000\n";
                        cout << "- " << rut200 << " to 200000\n";
                        cout << "- " << rut100 << " to 100000\n";
                        cout << "- " << rut50 << " to 50000\n";
                        return;
                    }
                }
            }
        }
    }

    //Nếu không thể tìm được bộ nào thỏa, hoặc hết ít nhất một loại tiền thì throw lỗi về
    throw "Khong the doi tien le menh gia nay.";
}

//==================================== MAIN ===================================

int main() {
    ATM atm;
    char choice;

    //Cho phép rút nhiều lần
    while (1) {
        system("cls");
        try {
            cout << "*So tien con lai cua ATM: " << atm.getSoDu() << "000 VND.\n";
            cout << "- " << atm.getTo500() << " to 500000\n";
            cout << "- " << atm.getTo200() << " to 200000\n";
            cout << "- " << atm.getTo100() << " to 100000\n";
            cout << "- " << atm.getTo50() << " to 50000\n";
            cout << "==================================================\n";
            atm.rutTien();
        }
        catch (const char* str) {
            cout << "*Thong bao loi: " << str << endl;
        }
        cout << "--------------------------------------------------\n";
        cout << "Ban co muon tiep tuc rut? (y/n): ";
        cin >> choice;
        if (tolower(choice) == 'n')
            break;
    }

    cout << "--------------------------------------------------\n";
    cout << "*Ket thuc chuong trinh.*\n";
    return 0;
}