#include <iostream>
using namespace std;

//CMario.h
class CMario {
private:
	static CMario* ConMario;
	CMario();
	~CMario();
public:
	static CMario* lenh_tao_Mario();
};

//CMario.cpp
CMario* CMario::ConMario = NULL;

CMario* CMario::lenh_tao_Mario() {
	if (ConMario == NULL)
		ConMario = new CMario;
	return ConMario;
}

CMario::CMario() {
	cout << "Da tao ra Mario va hien thi len man hinh.\n";
}

CMario::~CMario() {
	if (ConMario != NULL) {
		delete ConMario;
		ConMario = NULL;
	}
	cout << "Da xoa Mario.\n";
}

//main.cpp
int main() {
	//Dù khai báo 3 Mario nhưng chỉ có một lệnh tạo được thực thi.
	CMario* Mario1, *Mario2, *Mario3;
	Mario1 = CMario::lenh_tao_Mario();
	Mario2 = CMario::lenh_tao_Mario();
	Mario3 = CMario::lenh_tao_Mario();

	return 0;
}