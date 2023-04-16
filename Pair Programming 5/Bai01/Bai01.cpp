#include <iostream>
using namespace std;

template<class T>
class MyArray {
private:
	T* a;
	int n;
public:
	MyArray();
	~MyArray();
	void MyPush(T x);
	void MyPop();
	void MySwap(int i1, int i2);
	void MyRe();
	void MyPrint();
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
void MyArray<T>::MyPush(T x) {
	T* b = new T[n + 1];
	for (int i = 0; i < n; i++)
		b[i + 1] = a[i];
	b[0] = x;
	if (a != NULL)
		delete a;
	a = b;
	n++;
}

template<class T>
void MyArray<T>::MyPop() {
	//Tìm phần tử lớn nhất
	T max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	

	//Tìm phần tử lớn thứ 2
	T max2 = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != max) {
			max2 = a[i];
			break;
		}

	for (int i = 0; i < n; i++)
		if (a[i] > max2 && a[i] != max)
			max2 = a[i];


	//Tạo mảng mới không có phần tử lớn thứ 2
	int nb = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != max2)
			nb++;

	//Tạo mảng b mới không có phần tử lớn thứ 2 từ mảng a
	T* b = new T [nb];
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
void MyArray<T>::MyRe() {
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
	MyArray<float> a;
	for (int i = -10; i <= 10; i++)
		a.MyPush(i);
	cout << "------------------------------------------------------------\n";
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	cout << "My pop:\n";
	a.MyPop();
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	int i1 = 0, i2 = 1;
	cout << "My Swap: i1 = " << i1 << ", i2 = " << i2 << endl;
	a.MySwap(i1, i2);
	a.MyPrint();
	cout << "------------------------------------------------------------\n";

	cout << "My Re:\n";
	a.MyRe();
	a.MyPrint();
	cout << "------------------------------------------------------------\n";
	return 0;
}