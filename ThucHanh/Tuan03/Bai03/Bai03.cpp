#include <iostream>
#include "DaThuc.h"
#include "DonThuc.h"
using namespace std;

void testDonThuc() {
	cout << "TEST DON THUC\n";
	//*INPUT mẫu: 
	//donThuc1 = 3x^3
	//donThuc2 = 5x^3
	//x = 7.6

	//*OUTPUT sẽ nhận được: 
	//donThuc1(7.6) =  1316.93
	//donThuc1 + donThuc2 = 8x^3
	//donThuc1 - donThuc2 = -2x^3
	//donThuc1 * donThuc2 = 15x^3
	//donThuc1 / donThuc2 = 0.6
	cout << "==================================\n";

	//Test hàm consuctor 2 đối số (heSo, bac)
	DonThuc donThuc1(3, 3);
	cout << "Don thuc 1: " << donThuc1 << endl;
	cout << "==================================\n";

	//Test hàm constructor ko đối số
	DonThuc donThuc2;
	cout << "Nhap vao don thuc 2: \n";
	//Test overloaded operator cin >>
	cin >> donThuc2;

	

	//Test assignment operator
	DonThuc donThuc3;
	donThuc3 = donThuc1;

	//Test conpy constructor
	DonThuc donThuc4(donThuc2);

	cout << "==================================\n";
	//Test overloaded operator cout << 
	
	cout << "Don thuc 2: " << donThuc2 << endl;
	cout << "Don thuc 3: " << donThuc3 << endl;
	cout << "Don thuc 4: " << donThuc4 << endl;

	cout << "==================================\n";
	//Test hàm tính giá trị đơn thức
	float x;
	cout << "Nhap vao x de tinh gia tri don thuc: ";
	cin >> x;
	cout << "donThuc1(" << x << ")= " << donThuc1.giaTri(x) << endl;

	cout << "==================================\n";
	//Test overloaded operator *
	cout << "donThuc1 * donThuc2 = " << donThuc1 * donThuc2 << endl;
	cout << "----------------------------------\n";

	//Test overloaded operator /
	cout << "donThuc1 / donThuc2 = " << donThuc1 / donThuc2 << endl;
	cout << "----------------------------------\n";\

	//Test overloaded operator +
	cout << "donThuc1 + donThuc2 = " << donThuc1 + donThuc2 << endl;
	cout << "----------------------------------\n";

	//Test overloaded operator -
	cout << "donThuc1 - donThuc2 = " << donThuc1 - donThuc2 << endl;
	cout << "----------------------------------\n";
}

void testDaThuc() {
	cout << "TEST DA THUC\n";
	//*INPUT mẫu: 
	//daThuc1 = 3x^4 + x^3 + 6x -5
	//daThuc2 = x^2 + 1
	//x = 7.6
	
	//*OUTPUT sẽ nhận được: 
	//daThuc1(7.6) =  10488.2
	//daThuc1 + daThuc2 = 3x^4 + x^3 + x^2 + 6x -4
	//daThuc1 - daThuc2 = 3x^4 + x^3 - x^2 + 6x -6
	//daThuc1 * daThuc2 = 3x^6 + x^5 + 3x^4 + 7x^3 -5x^2 + 6x -5
	//daThuc1 / daThuc2 = 3x^2 + x - 3. Phần dư = 5x -2

	cout << "==================================\n";

	//Test constructor không đối số
	DaThuc daThuc1;

	//Test constuctor có 1 đối số n
	DaThuc daThuc2(10);

	//Test overloaded operator cin >>
	cout << "Nhap vao da thuc 1: \n";
	cin >> daThuc1;
	cout << "==================================\n";
	cout << "Nhap vao da thuc 2: \n";
	cin >> daThuc2;

	//Test copy constructtor
	DaThuc daThuc3(daThuc1);

	//Test assignment operator
	DaThuc daThuc4;
	daThuc4 = daThuc2;

	cout << "==================================\n";
	//Test overloaded operator cout <<
	cout << "Da thuc 1: " << daThuc1 << endl;
	cout << "Da thuc 2: " << daThuc2 << endl;
	cout << "Da thuc 3: " << daThuc3 << endl;
	cout << "Da thuc 4: " << daThuc4 << endl;

	cout << "==================================\n";
	//Test hàm tính giá trị đa thức
	float x;
	cout << "Nhap vao x de tinh gia tri da thuc: ";
	cin >> x;
	cout << "daThuc1(" << x << ")= " << daThuc1.giaTri(x) << endl;

	cout << "==================================\n";
	//Test overloaded operator +
	cout << "daThuc1 + daThuc2 = " << daThuc1 + daThuc2 << endl;
	cout << "----------------------------------\n";

	//Test overloaded operator -
	cout << "daThuc1 - daThuc2 = " << daThuc1 - daThuc2 << endl;
	cout << "----------------------------------\n";

	//Test overloaded operator *
	cout << "daThuc1 * daThuc2 = " << daThuc1 * daThuc2 << endl;
	cout << "----------------------------------\n";

	//Test overloaded operator /
	cout << "daThuc1 / daThuc2 = " << daThuc1 / daThuc2 << endl;
	cout << "----------------------------------\n";
	
}

int main() {
	system("cls");
	testDonThuc();
	testDaThuc();
	return 0;
}