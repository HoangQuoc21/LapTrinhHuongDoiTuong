#include <iostream>
using namespace std;

// I.Khởi tạo 1 class (lớp):
// Đây là Class Base: Class Cơ sở/ khởi nguồn
class Phu_nu{
    //Các phương thức chỉ định: public và private
    // Trong 1 class sẽ có các thuộc tính và phương thức
    //- thuộc tính được định nghĩa, khởi tạo như 1 biến;
    // -Phương thức được định nghĩa, khởi tạo như 1 hàm;
    //- Chỉ định: public, private. "protected" là lai giữa public, private. "protected" có thể truy cập và sửa đổi qua phương thức của class nhưng ko gọi trực tiếp thuộc tính
    //ra được

    public:
        //II. Các thuộc tính trong private có thể được truy cập trực tiếp/ thay đổi từ các hàm khác hay bên ngoài class
        //1. Thuộc tính:
        string ho_ten;
       
        //2. Hàm Khởi Tạo: Tạo các giá trị ban đầu cho những thuộc tính bên trong class
        //Hàm Khởi Tạo có thể có tham số đầu vào hoặc không, tùy vào hàm khởi tạo trong main mà hàm khởi tạo nào sẽ dc thực thi

        Phu_nu(){

        }

        //- 2a. Khai báo hàm khởi tạo tường minh
        Phu_nu(string ht, bool z, int t){
            ho_ten = ht;
            con_zin = z;
            tuoi = t;
        }

        //-2b. Một cách khai báo hàm khởi tạo khác gọn hơn:
        Phu_nu(string ht, bool z, int t): ho_ten(ht), con_zin(z), tuoi(t) {};

        //-2c. Một cách khai báo hàm khởi tạo với tham chiếu:
        Phu_nu(const string &ht, bool z, int t): ho_ten(ht), con_zin(z), tuoi(t) {};

        //-2d. Hàm khởi tạo với tham số mặc định
        Phu_nu(string ht, int t, bool z = true): ho_ten(ht), con_zin(z), tuoi(t) {};

        //3. Hàm Hủy: Dùng/ được gọi khi hủy đối tượng
        //-3a. Khởi tạo hàm hủy: 
        ~Phu_nu(){
            cout << "Chia tay " << ho_ten << endl;
        }


        //III. Phương thức ( thêm vitural vào để đảm bảo in ra đúng phương thức): 
        void trang_diem(){

        }

        virtual string choi_nhac_cu(string nhac_cu){

            return "AAAAAAA";
        }

        //1. Phương sửa đổi 1 object
        void va_zin(){
            //Trẻ hơn 25 tuổi thì mới vá zin, chứ già quá vá làm chi
            if ( tuoi < 25)
                con_zin = true;
        }

        //2. Phương thức in/ thể hiện ra một object
        void show_hang(){
            cout << ho_ten << " " << (con_zin ? "Con zin" : "Mat zin") << endl;
        }

    private:
        //Các thuộc tính trong private không thể truy cập trực tiếp từ các hàm khác
        bool con_zin;
        int tuoi;

};

//IV. Đây là những Class Con, sinh ra từ class cơ sở( class con : public base {}):
//1. Class mẹ có cái gì, class con có cái đó
//2. Hàm khởi tạo và hàm hủy lại ko dc kế thừa
class Gai_Ngoan : public Phu_nu {
    public: 
        Gai_Ngoan (const string &ht, bool z, int t): Phu_nu (ht, z, t){};
    
    //Class con có một số thuộc tính, phương thức mà class mẹ ko có:
        void noi_tro(){

        }
    //Định nghĩa lại hàm chơi nhạc cụ cho Gai_Ngoan khác với Phu_nu
        string choi_nhac_cu(string nhac_cu){

        return "OOOOOOOOO";
        }

};

//Những gì kế thừa thuộc kiểu private hết (ít người làm như này)
class Gai_Hu : private Phu_nu{
    public: 
        Gai_Hu (const string &ht, bool z, int t): Phu_nu (ht, z, t){};

        void di_bar(){

        }
    //Định nghĩa lại hàm chơi nhạc cụ cho Gai_Ngoan khác với Phu_nu
        string choi_nhac_cu(string nhac_cu){

        return "UUUUUUUUH";
        }
};

//Đa kế thừa: Kế thừa dc từ nhiều Class Mẹ (ít xài, nên tránh)
class Banh_Beo: public Gai_Ngoan, public Gai_Hu{

};

//Kế Thừa Nhiều Mức:
class Gai_Di_Tour: public Gai_Hu{
    // Gai_Di_Tour kế thừa từ Gai_Hu, Gai_Hu kế thừa từ phụ nữ
};

// Class Gai_Ngoan ko dùng được phương thức di_bar của Gai_Hu

int main(){
    system ("cls");


    //1. Khởi tạo một object (đối tượng) theo kiểu tĩnh:
    Phu_nu co_giao_thao;
    //2. Nhập thuộc tính cho đối tượng:
    co_giao_thao.ho_ten = "Nguyen Van Thao";

    //3. Khởi tạo một object (đối tượng) theo kiểu động:
    Phu_nu *maria_ozawa1 = new Phu_nu;
    //4. Nhập thuộc tính cho đối tượng:
    maria_ozawa1->ho_ten = "Le Van Wa";

    //5. Khởi tạo một object có hàm khởi tạo:
    //- Với class mẹ
    Phu_nu *maria_ozawa1 = new Phu_nu("Maria Ozawa", 22, false);
    //- Với class con
    Gai_Ngoan *maria_ozawa2 = new Gai_Ngoan("Maria Goluban", false, 22);

    //6. Gọi các phương thức:
    maria_ozawa1->choi_nhac_cu("ken");
    maria_ozawa1->va_zin();
    maria_ozawa1->show_hang();
    maria_ozawa2->noi_tro();
    maria_ozawa2->choi_nhac_cu("ken");

    //7. Con Trỏ Đa Hình:
    // Dùng cho con trỏ thôi, khởi tạo là 1 kiểu khác so với khai báo kiểu
    Phu_nu *maria_ozawa3 = new Gai_Ngoan("Maria Ố Zawa", 22, false);
    // In ra kết quả của phương thức choi_nhac_cu của Gai_Ngoan
    maria_ozawa3->choi_nhac_cu("ken");

    //7. New là khởi tạo object thì delete là xóa object:
    delete maria_ozawa1;
}