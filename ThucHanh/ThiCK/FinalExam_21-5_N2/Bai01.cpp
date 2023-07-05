#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

class Point {
public:
	int x; int y;
	Point(const Point& P) {
		x = P.x;
		y = P.y;
	}
	Point() {
		x = y = 0;
	}
	Point(int X, int Y) {
		x = X;
		y = Y;
	}
	double distance(Point P) {
		return (double)sqrt(pow(x - P.x, 2) + pow(y - P.y, 2));
	}
	void set(int X, int Y) {
		x = X;
		y = Y;
	}
	void input() {
		cout << "+x: ";
		cin >> x;
		cout << "+y: ";
		cin >> y;
	}
	void ouput() {
		cout << "(" << x << "," << y << ")";
	}
	void writeFile(ofstream &fout) {
		fout << "(" << x << "," << y << ")";
	}
};

//==============================================
class Shape {
public:
	virtual Shape* clone() = 0;
	virtual double area() = 0;
	virtual void input() { };
	virtual void output() { };
	virtual string type() { return ""; };
	virtual void writeFile(ofstream& fout) {};
};
//==============================================
class Circle:public Shape {
private:
	Point C;
	double R;
public:
	Circle() {
		C.set(0, 0);
		R = 0;
	}
	Circle(Point c, double r) {
		C = c;
		R = r;
	}
	double area() {
		return 3.14* pow(R, 2);
	}
	Shape* clone() {
		Shape* cl = new Circle(C,R);
		return cl;
	}
	void input() {
		cout << "-Nhap tam: \n";
		C.input();
		cout << "-Nhap ban kinh:";
		cin >> R;
	}
	void output() {
		cout << type() << "|";
		C.ouput();
		cout << ":" << R << endl;
	}
	void writeFile(ofstream& fout) {
		fout << type() << "|";
		C.writeFile(fout);
		fout << ":" << R << endl;
	};
	string type() {
		return "Circle";
	}
	
};
//==============================================
class Triangle :public Shape {
private:
	Point A, B, C;
	static bool isTriangle(Point a, Point b, Point c) {
		double ab = a.distance(b);
		double ac = a.distance(c);
		double bc = b.distance(c);
		if ((ab >= ac + bc) || (ac >= ab + bc) || (bc >= ab + ac))
			return false;
		return true;

	}
public:
	Triangle() {
		A.set(0, 0);
		B.set(0, 0);
		C.set(0, 0);
	}
	Triangle(Point a, Point b, Point c) {
		A = a;
		B = b; 
		C = c;
	}
	double area() {
		double ab = A.distance(B);
		double ac = A.distance(C);
		double bc = B.distance(C);
		double p = (ab + ac + bc) / 2;
		double result = sqrt(p*(p - ab) * (p - ac) * (p - bc));
		return result;
	}
	Shape* clone() {
		Shape* cl = new Triangle(A, B, C);
		return cl;
	}
	void input() {
		cout << "-Nhap diem A:\n";
		A.input();
		cout << "-Nhap diem B:\n";
		B.input();
		cout << "-Nhap diem C:\n";
		C.input();
		while (!isTriangle(A, B, C)) {
			cout << "*Ba diem vua nhap khong tao thanh tam giac, hay nhap lai:\n";
			cout << "-Nhap diem A:\n";
			A.input();
			cout << "-Nhap diem B:\n";
			B.input();
			cout << "-Nhap diem C:\n";
			C.input();
		}
	}
	void output() {
		cout << type() << "|";
		A.ouput();
		cout << ":";
		B.ouput();
		cout << ":";
		C.ouput();
		cout << endl;
	}
	void writeFile(ofstream& fout) {
		fout << type() << "|";
		A.writeFile(fout);
		fout << ":";
		B.writeFile(fout);
		fout << ":";
		C.writeFile(fout);
		fout << endl;
	}
	string type() {
		return "Triangle";
	}
};
//==============================================
class Cpl_Shape:public Shape {
private:
	int n;
	Shape** Children;
public:
	Cpl_Shape() {
		n = 0;
		Children = NULL;
	}
	Cpl_Shape(Shape** children, int N):Cpl_Shape() {
		n = N;
		Children = new Shape * [N];
		for (int i = 0; i < N; i++) {
			Children[i] = children[i]->clone();
		}
	}
	~Cpl_Shape() {
		if (Children != NULL) {
			for (int i = 0; i < n; i++)
				delete Children[i];
			delete[]Children;
			n = 0;
			Children = NULL;
		}
	}
	double area() {
		double result = 0;
		for (int i = 0; i < n; i++)
			result += Children[i]->area();
		return result;
	}
	Shape* clone() {
		Shape* cl = new Cpl_Shape(Children, n);
		return cl;
	}
	void input() {
		cout << "-Nhap vao so luong hinh con: ";
		cin >> n;
		cout << "================================================================\n";
		Children = new Shape * [n];
		for (int i = 0; i < n; i++) {
			cout << "1.Hinh tron.\n";
			cout << "2.Hinh tam giac.\n";
			cout << "Chon loai hinh: ";
			int loai;
			cin >> loai;
			cout << "---------------\n";
			if (loai == 1)
				Children[i] = new Circle();
			else if (loai == 2)
				Children[i] = new Triangle();
			Children[i]->input();
			cout << "------------------------------------\n";
		}
	}
	void output() {
		for (int i = 0; i < n; i++) {
			Children[i]->output();
			cout << "------------------------------------\n";
		}
	}
	void writeFile(ofstream& fout) {
		for (int i = 0; i < n; i++)
			Children[i]->writeFile(fout);
	}
	void sumShapes() {
		double aC = 0;
		double aT = 0;
		for (int i = 0; i < n; i++) {
			if (Children[i]->type() == "Circle")
				aC += Children[i]->area();
			else if (Children[i]->type() == "Triangle")
				aT += Children[i]->area();
		}
		cout << "-Tong dien tich cac hinh tron la: " << aC << endl;
		cout << "-Tong dien tich cac hinh tam giac la: " << aT << endl;
	}
	void biggestArea() {
		Shape* cir = NULL;
		Shape* tri = NULL;
		for (int i = 0; i < n; i++)
			if (Children[i]->type() == "Circle") {
				cir = Children[i];
				break;
			}
		if (cir == NULL)
			cout << "*Khong co hinh tron.\n";
		else {
			for (int i = 0; i < n; i++)
				if (Children[i]->type() == "Circle") {
					if (Children[i]->area() > cir->area())
						cir = Children[i];
				}
			cout << "*Dien tich hinh tron lon nhat la: " << cir->area() << endl;
		}

		for (int i = 0; i < n; i++)
			if (Children[i]->type() == "Triangle") {
				tri = Children[i];
				break;
			}
		if (tri == NULL)
			cout << "*Khong co hinh tam giac.\n";
		else {
			for (int i = 0; i < n; i++)
				if (Children[i]->type() == "Triangle") {
					if (Children[i]->area() > tri->area())
						tri= Children[i];
				}
			cout << "*Dien tich hinh tam giac lon nhat la: " << tri->area() << endl;
		}
	}
	void addShape() {
		Shape* add = NULL;
		cout << "*Nhap thong tin hinh muon them:\n";
		cout << "------------------------------------\n";
		cout << "1.Hinh tron.\n";
		cout << "2.Hinh tam giac.\n";
		cout << "Chon loai hinh: ";
		int loai;
		cin >> loai;
		cout << "---------------\n";
		if (loai == 1)
			add = new Circle();
		else if (loai == 2)
			add = new Triangle();
		add->input();
		cout << "------------------------------------\n";
		Shape** b = new Shape * [n + 1];
		
		if (add->type() == "Circle") {
			int i = 0;
			for (i; i < n; i++) {
				if (Children[i]->type() == "Circle" && Children[i]->area() < add->area()) {
					b[i] = Children[i];
				}
				else
					break;
			}
			b[i] = add;

			while (i < n) {
				b[i + 1] = Children[i];
				i++;
			}
				
			delete[]Children;
			Children = b;
			n++;
		}
		else if (add->type() == "Triangle") {
			int i = 0;
			for (i; i < n; i++) {
				if (Children[i]->type() == "Circle") {
					b[i] = Children[i];
				}
				else
					break;
			}
			for (i; i < n; i++) {
				if (Children[i]->type() == "Triangle" && Children[i]->area() < add->area()) {
					b[i] = Children[i];
				}
				else
					break;
			}
			b[i] = add;
			while (i < n) {
				b[i + 1] = Children[i];
				i++;
			}
				
			delete[]Children;
			Children = b;
			n++;
		}
	}
};
//==============================================
int main() {
	Cpl_Shape cl;
	int luaChon;
	
	cl.input();
	
	while (1) {
		system("cls");
		cout << "*Danh sach hinh:\n";
		cout << "================================================================\n";
		cl.output();
		cout << "================================================================\n";
		cout << "============================== MENU ============================\n";
		cout << "1.Tinh tong dien tich moi loai hinh.\n";
		cout << "2.Tim dien tich lon nhat moi loai hinh .\n";
		cout << "3.Ghi danh sach cac hinh ra tap tin .\n";
		cout << "4.Them mot hinh .\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "============================== END =============================\n";
		cout << "Lua chon cua ban: ";
		cin >> luaChon;
		cout << "================================================================\n";
		if (luaChon == 1) {
			cl.sumShapes();
		}
		else if (luaChon == 2) {
			cl.biggestArea();
		}
		else if (luaChon == 3) {
			string fileName = "cpl_shape.dat";
			ofstream fout(fileName);
			cl.writeFile(fout);
			fout.close();
			cout << "*Da ghi danh sach cac hinh ra file " << fileName << endl;
		}
		else if (luaChon == 4) {
			cl.addShape();
			cout << "*Da them thanh cong hinh.\n";
		}
		else if (luaChon == 0) {
			break;
		}
		else
			cout << "*Lua chon khong hop le.\n";
		system("pause");
	}
	cout << "*Ket thuc chuong trinh.*\n";
	return 0;
}