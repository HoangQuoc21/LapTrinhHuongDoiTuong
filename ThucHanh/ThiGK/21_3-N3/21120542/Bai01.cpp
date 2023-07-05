#include <iostream>
using namespace std;

static int DesCnt = 0;

class ObjTest {
protected:
	int Val;
public:
	ObjTest() {
		Val = -1;
	}
	virtual~ObjTest() {
		DesCnt += 2;
	}
};

class ChildObj : public ObjTest {
public:
	ChildObj(int pVal = 0) {
		Val = pVal;
	}
	~ChildObj() {
		DesCnt += 3;
	}
};

int main() {
	int n = 8;
	ObjTest* obj = new ChildObj[n];			//Lệnh (N1)
	delete[]obj;							//Lệnh (D1)
	obj = new ChildObj(n);					//Lệnh (N2)
	delete obj;								//Lệnh (D2)
	cout << "DesCnt = " << DesCnt << endl;
	return 0;
}

//a)
//Điểm khác nhau giữa N1 và N2:
//-N1 để cấp phát vùng nhớ có n ô nhớ liên tiếp trên bộ nhớ Heap có kiểu dữ liệu là ChildObj,
// các ô nhớ này được khởi tạo giá trị sử dụng hàm constructor không có tham số đầu vào (constructor mặc định mà ide cung cấp)
// cho con trỏ obj (obj giữ địa chỉ của ô nhớ đầu tiên của dãy được cấp)

//-N2 để cấp phát một ô nhớ trên bộ nhớ Heap có kiểu dữ liệu là ChildObj,
//Ô nhớ này được khởi tạo giá trị sử dụng hàm constructor có một tham số đầu vào

//Điểm khác nhau giữa D1 và D2:
//-D1 để giải phóng vùng nhớ gồm n ô nhớ được tạo từ lệnh N1
//-D2 để giải phóng một ô nhớ được tạo từ lệnh N2

//b) DesCnt = 45 vì:
//Khi khởi tạo đối tượng
//Mỗi khi có một đối tượng có kiểu dữ liệu ChildObj được tạo thì trước tiên nó 
//sẽ tạo các thuộc tính và phương của một đối tượng ObjTest rồi mới đến
//các thuộc tính và phương thức của ChilObj vì ChilObj là lớp dẫn xuất từ lớp ObjTest

//*Quy tắc hủy một đối tượng có kiểu lớp dẫn xuất*
//Khi giải phóng vùng nhớ (hủy) một đối tượng ChilObj
//Thì IDE sẽ gọi hàm hủy của lớp ChilObj (lớp dẫn xuất)
//rồi sau đó gọi hàm hủy của lớp ObjTest (lớp cơ sở)

//*Với cặp lệnh N1,D1:
//Sau khi thực hiện lệnh N1 ta có 8 ô nhớ kiểu ChilObj trên heap
//Khi thực hiện lệnh D1, thì như quy tắc hủy ở trên với mỗi lần xóa một ô nhớ
//DesCnt sẽ tăng 3 đơn vị (hàm hủy của ChilObj) rồi tăng 2 đơn vị (hàm hủy của ObjTest)
//Tổng cộng là 1 lần xóa DesCnt sẽ tăng thêm 5 đơn vị
//Sau 8 lần hủy thì DesCnt = 0 + 8*5 = 40

//Với cặp lệnh N2,D2:
//Tương tự như cặp lệnh N1,D1, sau khi thực hiện xong D2 thì:
//DesCnt = 40 + 5 = 45
//Do đó sau  khi thực hiện chương trình thì DesCnt = 45