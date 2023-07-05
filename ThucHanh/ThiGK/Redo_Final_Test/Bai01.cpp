#include <iostream>
using namespace std;

class base {
public:
	base() {};
	virtual ~base() { cout << "it's destructor of base class!\n"; };
	virtual void mfunc() { cout << "it's mfunc of base class!\n"; };
};

class drived_1 :public base {
public:
	drived_1() {};
	~drived_1() { cout << "it's destructor of drived_1 class!\n"; };
	virtual void mfunc() { cout << "it's mfunc of drived_1 class!\n"; };
};

class drived_2 :public base {
public:
	drived_2() {};
	~drived_2() { cout << "it's destructor of drived_2 class!\n"; };
	virtual void mfunc() { cout << "it's mfunc of drived_2 class!\n"; };
};

int main() {
	base b;
	base* pb = new base();
	drived_1 d1;
	drived_2 d2;
	drived_1* pd1 = new drived_1();
	base* pbd1 = new drived_1();
	base** roster = new base * [3];
	for (int i = 0; i < 3; i++)
		roster[i] = NULL;
	roster[0] = new drived_1();
	roster[1] = new drived_2();
	roster[2] = new drived_1();
	for (int i = 0; i < 3; i++) {
		drived_1* ptr = dynamic_cast<drived_1*>(roster[i]);
		if (ptr)
			ptr->mfunc();
	}
	cout << "-------------------------------------------------------\n";
	return 0;
}