#include <iostream>
#include <vector>
using namespace std;

//Mẫu State thể hiện hành vi xử lỷ dựa vào trạng thái của Object
//Mỗi trạng thái có một lớp kế thừa tương ứng

class CState {
public:
	virtual void handle() {};
};

class CPlayer {
public:
	CState* current;
};

class CStrong :public CState {
public:
	void handle() {
		cout << "Cau thu dang rat khoe.\n";
	}
};

class CWeak : public CState {
public:
	void handle() {
		cout << "Cau thu dang rat yeu.\n";
	}
};

class CNormal : public CState {
public:
	void handle() {
		cout << "Cau thu dang binh thuong.\n";
	}
};

//main.cpp
int main() {
	CPlayer Ronaldo, Messi;

	Ronaldo.current = new CStrong;

	cout << "Trang thai cua Ronaldo: \n";
	Ronaldo.current->handle();

	cout << "-------------------------------\n";

	Messi.current = new CNormal;
	cout << "Trang thai cua Messi: \n";
	Messi.current->handle();
	bool choiXau = true;
	if (choiXau == true) {
		Messi.current = new CWeak;

		cout << "Trang thai cua Messi sau khi chan thuong:\n";
		Messi.current->handle();
	}

	return 0;
}