#include <iostream>
#include <cstring>

//============= CÁC CLASS ĐỀ CHO ==============

class Base {
private:
	char* m_ptr;
public:
	Base() {
		m_ptr = _strdup("default");
	}
	Base(const Base& b) {
		m_ptr = _strdup("copy");
	}
	~Base() {
		//Xóa thuộc tính của lớp cha
		delete m_ptr;
		std::cout << "Base destructor \n";
	}
	virtual void foo() {
		std::cout << m_ptr << "\n";
	}
	Base& operator=(const Base& b) {
		//Gán bằng các thuộc tính của lớp cha
		this->m_ptr = _strdup(b.m_ptr);
		return *this;
	}
};

class Derive :public Base {
public:
	void foo() {
		std::cout << "derive ";
		Base::foo();
	}
	~Derive() {
		//Xóa các thuộc tính khác của lớp con
		std::cout << "Derive destructor \n";
	}
	Derive& operator=(const Derive& d) {
		//Gán bằng các thuộc tính của lớp cha
		Base::operator=(d);
		//Gán bằng các thuộc tính của lớp con
		return*this;
	}
};

void bar(Base* obj1, Base obj2) {
	obj1->foo(); //derive default
	obj2.foo();  //copy
}

int main() {
	Derive d;
	bar(&d, d);
	//derive default
	//copy
	//==== GIẢI THÍCH ====
	//1. Về tham số đầu vào của hàm bar:
	//-Base* obj1 là con trỏ (tham chiếu) sẽ truyền trực tiếp địa chỉ của biến obj1. 
	//Không cần phải sao chép biến nào vào bộ nhớ tạm
	//-Base obj2 là truyền tham trị. 
	//Sẽ sao chép những thuộc tính của biến obj2 vào bộ nhớ tạm. (Tạm gọi là obj2C)

	//2. Về trình tự hoạt động:
	//B1: Khi truyền đầu vào:
	//- obj1 sẽ giữ trực tiếp địa chỉ biến truyền vào của nó. Đây là con trỏ lớp cha
	//- obj2C (biến được sao chép tạm) sẽ giữ các thuộc tính biến truyền vào của nó. Đây là kiểu dữ liệu lớp cha
	//B2: obj1->foo()
	//-Vì là con trỏ lớp cha nên khi gọi một phương thức virtual thì con trỏ 
	// sẽ điều hướng nó đến phương thức của lớp con tương ứng.
	//->Gọi phương thức foo() của lớp Derive
	//B3: obj2.foo()
	//-Vì là kiểu dữ liệu lớp cha nên dù gọi phương thức virtual thì biến
	//Vẫn sẽ gọi phương thức của lớp cha
	//->Gọi phương thức foo() của lớp Base
	//B4: Kết thúc hàm:
	//-Biến Base*obj1 giữ địa chỉ (tham trị) nên sẽ không thu hồi lại gì sau khi kết thúc hàm
	//-Biến obj2C sẽ được thu hồi khỏi bộ nhớ tạm sau khi kết thúc hàm
	//B5: Kết thúc chương trình:
	//-Thu hồi các biến toàn cục và biến trong hàm main theo cơ chế stack: Biến nào khởi tạo sau thì thu hồi trước
	//-Thu hồi biến Derive d:
	//	+Gọi destructor của lớp con (Derive) trước
	//	+Gọi destructor của lơp cha (base) sau

	//========== GIẢI QUYẾT VẤN ĐỀ CON TRỎ ========== 
	//-Viết thêm destructor
	//-Viết thêm toán tử gán bằng
	std::cout << "-----------------------------\n";
	Base b2;
	Base b3 = b2;
	b2.foo();
	b3.foo();
	Base b4;
	b4 = b3;
	b4.foo();
	std::cout << "-----------------------------\n";
	Derive d1;
	Derive d2 = d1;
	Derive d3;
	d3 = d2;
	d1.foo();
	d2.foo();
	d3.foo();
	std::cout << "-----------------------------\n";
	return 0;
}