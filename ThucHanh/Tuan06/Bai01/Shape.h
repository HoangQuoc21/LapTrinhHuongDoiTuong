#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Cau truc Diem
struct Point {
	double X;
	double Y;
};

// Lop doi tuong hinh ve tong quat 'Shape'
class Shape {
public:
	Shape();
	~Shape();
	Shape(const Shape& s);
	/* Se cai dat lai trong tung lop dan xuat */
	virtual Shape* Clone() = 0;
	virtual bool IsSelectedPoint(Point p) = 0;
	// others
	virtual void input() = 0;
	virtual void print() = 0;
	virtual string type() = 0;
};

