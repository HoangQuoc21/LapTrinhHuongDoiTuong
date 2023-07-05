#include <iostream>
#include <limits>
using namespace std;

template<class T>
class MyArray {
private:
	T* a;
	int n;
public:
	MyArray();
	~MyArray();
	void MyPush2(T x, int i);
	void MyPop2();
	void MySwap(int i1, int i2);
	void MyRo();
	void MyPrint();
	void MyRe() {
		T* b = new T[n];
		for (int i = 0; i < n; i++)
			b[i] = a[n - 1 - i];
		delete[]a;
		a = b;
	}
	int getN() {
		return n;
	}
};

template<class T>
MyArray<T>::MyArray() {
	a = NULL;
	n = 0;
}

template<class T>
MyArray<T>::~MyArray() {
	if (a != NULL)
		delete[]a;
	a = NULL;
	n = 0;
}

template<class T>
void MyArray<T>::MyPush2(T x, int i) {
	T* b = new T[n + 1];
	if ((i >= 0) && (i <= n)) {
		b[i] = x;
		for (int j = 0; j < i; j++) {
			b[j] = a[j];
		}
		for (int j = i; j < n; j++)
			b[j + 1] = a[j];
		if (a != NULL)
			delete[]a;
		a = b;
		n++;
	}
	else {
		cout << "Khong co vi tri hop le.\n";
	}
}

template<class T>
void MyArray<T>::MyPop2() {
	//Tìm phần tử lớn nhất
	T max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];



	//Tìm phần tử lớn thứ 2
	T max2 = INT_MIN;
	for (int i = 0; i < n; i++)
		if (a[i] > max2 && a[i] != max)
			max2 = a[i];


	//Tạo mảng mới không có phần tử lớn thứ 2
	int nb = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != max2)
			nb++;

	//Tạo mảng b mới không có phần tử lớn thứ 2 từ mảng a
	T* b = new T[nb];
	int ib = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != max2) {
			b[ib] = a[i];
			ib++;
		}

	//Xóa mảng a đi
	if (a != NULL)
		delete[]a;

	//Gán mảng b cho a
	a = b;
	n = nb;
}

template<class T>
void MyArray<T>::MySwap(int i1, int i2) {
	if (i1 >= n || i2 >= n)
		return;
	swap(a[i1], a[i2]);
}

template<class T>
void MyArray<T>::MyRo() {
	T* b;

	//Tìm số lượng phần tử không âm
	int nb = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= 0)
			nb++;

	//Tạo mảng b gồm các phẩn tử không âm của mảng a
	b = new T[nb];
	int ib = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= 0) {
			b[ib] = a[i];
			ib++;
		}

	//Xóa mảng a đi
	if (a != NULL)
		delete[]a;

	//Gán mảng b cho a
	a = b;
	n = nb;
}

template<class T>
void MyArray<T>::MyPrint() {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}



int main() {
	MyArray<int> a;
	cout << "------------------------------------------------------------\n";
	cout << "My Push:\n";
	//for (int i = -10; i <= 10; i++)
		//a.MyPush2(i, 0);


	int i = 0;
	int x = 0;
	while (i != -99) {
		cout << "Nhap gia tri muon push: ";
		cin >> x;
		cout << "Nhap vi tri (-99) de ket thuc : ";
		cin >> i;
		cout << "---------------------------------\n";
		if (i < 0 || i > a.getN())
			cout << "Vi tri khong hop le: ";
		else {
			a.MyPush2(x, i);
		}
	}

	cout << "------------------------------------------------------------\n";
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	cout << "My pop:\n";
	a.MyPop2();
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	int i1 = 3, i2 = 1;
	cout << "My Swap: i1 = " << i1 << ", i2 = " << i2 << endl;
	a.MySwap(i1, i2);
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	cout << "My Ro:\n";
	a.MyRo();
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	cout << "My Re:\n";
	a.MyRe();
	a.MyPrint();
	cout << "------------------------------------------------------------\n";
	return 0;
}