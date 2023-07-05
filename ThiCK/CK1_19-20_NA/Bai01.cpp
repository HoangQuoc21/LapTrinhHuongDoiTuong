#include <iostream>
#include <cmath>
using namespace std;

class ArmstrongNum {
private:
	long long armNum;
	static int NumNum(int num);
		
	static bool isArmstrong(int num) {
		if (num == 0)
			return false;

		int oldNum = num;
		int n = NumNum(num);
		long long sum = 0;
		while (num > 0) {
			sum += pow(num % 10, n);
			num /= 10;
		}
		return (sum == oldNum);
	}
public:
	ArmstrongNum() {
		armNum = 1;
	}
	ArmstrongNum(const ArmstrongNum& a) {
		armNum = a.armNum;
	}
	friend istream& operator>> (istream& in, ArmstrongNum& a) {
		in >> a.armNum;
		while (!ArmstrongNum::isArmstrong(a.armNum)) {
			a.armNum++;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const ArmstrongNum& a) {
		out << a.armNum;
		return out;
	}
	ArmstrongNum& operator=(const ArmstrongNum& a);
	bool operator==(const ArmstrongNum& a) {
		return (armNum == a.armNum);
	}
	//tiền tố: ++a
	ArmstrongNum& operator++() {
		armNum++;
		while (!isArmstrong(armNum))
			armNum++;
		return *this;
	}
	//Hậu tố: a++
	ArmstrongNum operator++(int) {
		ArmstrongNum temp = *this;
		++(*this);
		return temp;
	}
	//Phép cộng
	ArmstrongNum operator+(const ArmstrongNum& a);
};

int ArmstrongNum::NumNum(int num) {
	if (num == 0)
		return 1;
	int n = 0;
	while (num > 0) {
		n++;
		num /= 10;
	}
	return n;
}

ArmstrongNum& ArmstrongNum::operator=(const ArmstrongNum& b) {
	this->armNum = b.armNum;
	return *this;
}

ArmstrongNum ArmstrongNum::operator+(const ArmstrongNum& a) {
	ArmstrongNum result;
	result.armNum = this->armNum + a.armNum;
	while (!isArmstrong(result.armNum))
		result.armNum++;
	return result;
}

int main() {
	ArmstrongNum a;
	cin >> a;
	cout << a << endl;
	ArmstrongNum b = a;
	++b;
	a = b++;
	if (a == b)
		cout << a << " == " << b << endl;
	else
		cout << a << " != " << b << endl;

	cout << a << " + " << b << " = " << a + b << endl;
	return 0;
}