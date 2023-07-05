#include <iostream>
#include <string>
using namespace std;

class TaxPayer {
protected:
	string strName;
public:
	TaxPayer(string name = "") {
		this->strName = name;
	}
	virtual float calTax(){
		return 0.0;
	}
};

class BusinessOwner :public TaxPayer {
	static float toHaveTax; //to be 100 milions
	static float TaxRate; // to be 10% in total
protected:
	float fNetRevenue;
public:
	BusinessOwner(string name):TaxPayer(name) {
		//some code here
		this->fNetRevenue = 0.0;
	}
	BusinessOwner(string name, float fNetRev):TaxPayer(name) {
		this->fNetRevenue = fNetRev;
	}
	float calTax() {
		if (fNetRevenue >= toHaveTax)
			return (fNetRevenue - toHaveTax) * TaxRate;
		else
			return 0;
	}
};

//100 milions
float BusinessOwner::toHaveTax = 100000000.0F;
// 10% tax in total
float BusinessOwner::TaxRate = 0.1F;

class SoftwareEngineer:public TaxPayer {
	static float salaryHaveTax; //to be 8 milions
	static float TaxRate; // to be 12% tax per month
protected:
	float fMSalary;
public:
	SoftwareEngineer(string name):TaxPayer(name) {
		//some code here
		this->fMSalary = 0.0;
	}
	SoftwareEngineer(string name, float salary) :TaxPayer(name) {
		this->fMSalary = salary;
	}
	float calTax() {
		if (fMSalary >= salaryHaveTax)
			return 12 * (fMSalary - salaryHaveTax) * TaxRate;
		else
			return 0;
	}
};

//8 milions
float SoftwareEngineer::salaryHaveTax = 8000000.0F;
//12% tax per month
float SoftwareEngineer::TaxRate = 0.12F;

//Hàm sắp xếp danh sách các tax payer theo thứ tự tăng dần của số tiền thuế cần nộp
void sortPayers(TaxPayer* taxPayers[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (taxPayers[i]->calTax() > taxPayers[j]->calTax()) {
				/*TaxPayer* temp = taxPayers[i];
				taxPayers[i] = taxPayers[j];
				taxPayers[j] = temp;*/
				swap(taxPayers[i], taxPayers[j]);
			}
}

int main() {
	TaxPayer taxPayer("Nguyen A");
	const int N = 10;
	TaxPayer* taxPayers[N];
	taxPayers[0] = new SoftwareEngineer("Nguyen B", 10000000); //10.000.000
	taxPayers[1] = new BusinessOwner("Nguyen C", 200000000); //200.000.000

	cout << taxPayer.calTax() << endl; //0
	cout << taxPayers[0]->calTax() << endl; // 12* (10M - 8M) * 0.12 =  2.88M
	cout << taxPayers[1]->calTax() << endl; // (200M - 100M) * 0.1 = 10M

	cout << "=======================================\n";
	for (int i = 2; i < N; i++)
		taxPayers[i] = new TaxPayer();
	for (int i = 0; i < N; i++)
		cout << taxPayers[i]->calTax() << endl;
	cout << "---------------------------------------\n";
	sortPayers(taxPayers, N);
	for (int i = 0; i < N; i++)
		cout << taxPayers[i]->calTax() << endl;
	
	return 0;
}