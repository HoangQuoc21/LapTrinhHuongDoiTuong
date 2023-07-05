#include "myArray.h"
#include <iostream>
using namespace std;
//Nếu Không có toán tử = hoặc copy contructor thì mặc định sẽ copy vùng nhớ giữa 2 đối tượng

MyIntArray::MyIntArray() {
	size = 0;
	pArr = NULL;
}

MyIntArray::MyIntArray(int sz) {
	size = sz;
	pArr = new int[size];
}

MyIntArray::MyIntArray(const MyIntArray& other) {
	cout << "*Day la copy constructor.\n";
	size = other.size;
	delete[] pArr;
	pArr = new int[size];
	for (int i = 0; i < size; i++)
		pArr[i] = other.pArr[i];
}
//Copy Constructor:
//-Tác dụng: Khởi tạo một đối tượng mới hoàn toàn từ một đối tượng truyền vào. Dù sử dụng () hay = thì khi khởi tạo nó đều gọi copy constructor
//-Được Gọi: khi khởi tạo một đối tượng mới
//-Ko được gọi với các nhu cầu truyền tham số đầu vào là một đối tượng hoặc trả về giá trị là một đối tượng
//-Dùng để copy 1 đối tượng cho 1 đối tượng khác chứ không phải copy vùng nhớ


MyIntArray::~MyIntArray() {
	delete[] pArr;
}

int& MyIntArray::operator[](int i){
	return pArr[i];
}

MyIntArray& MyIntArray::operator=(const MyIntArray& other) {
	cout << "*Day la toan tu =.\n";
	if (this != &other) {
		this->size = other.size;
		delete[] pArr;
		this->pArr = new int[size];
		for (int i = 0; i < size; i++)
			this->pArr[i] = other.pArr[i];
	}
	return *this;
}
//Assignment Operator:
//-Tác dụng: gán giá trị từ một đối tượng truyền vào cho một đối tượng đã được khởi tạo sẵn rồi
//-Được Gọi: khi muốn gán dữ liệu khác với dữ liệu đã có cho một đối tượng đã được khởi tạo
//-Được gọi với các nhu cầu truyền tham số đầu vào là một đối tượng hoặc trả về giá trị là một đối tượng

void MyIntArray::print() {
	for (int i = 0; i < size; i++)
		cout << pArr[i] << " ";
	cout << endl;
}