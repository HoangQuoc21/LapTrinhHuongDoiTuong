#include <iostream>
using   namespace std;

// *Lớp HCN:
class Rectangle {
    //Mọi biến khai báo trong class đều mặc định là private.
    int length;
    int width;

    // Khai báo hàm public
    public:

    //Lấy giá trị và thiết lập giá trị cho thuộc tính length
    // set: Thiết lập giá trị
    void setLength(int l);
    // get: Lấy giá trị
    int getLength();
    //Lấy giá trị và thiết lập giá trị cho thuộc tính width
    void setWidth(int w);
    int getWidth();
    //Hàm nè
    int area();
};


//* Toán tử phân giải phạm vi: (::):
// Toán tử phân giải phạm vi (::) cho phép chúng ta chỉ cần khai báo các hàm thành viên trong lớp và định nghĩa 
// chúng ở nơi khác trong mã. Để sử dụng toán tử phân giải phạm vi, chúng ta làm theo một cú pháp như sau:

void Rectangle::setLength(int l){ 
  length = l;
}
int Rectangle::getLength(){ 
  return length;
}

void Rectangle::setWidth(int w){ 
  width = w;
}
int Rectangle::getWidth(){ 
  return width;
}

int Rectangle::area(){
  return length * width; 
}



int main(){

}