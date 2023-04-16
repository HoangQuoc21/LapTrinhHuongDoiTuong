#include <iostream>
#include <cmath>
using namespace std;

template<class T, class U>
class Point {
private:
	T x;
	U y;
public:
	Point();
	Point(T a, U b);
	double calDis(Point other);
	bool operator>(Point other);
	void print();
};

template<class T, class U>
Point<T, U>::Point() {
	x = T();
	y = U();
}

template<class T, class U>
Point<T, U>::Point(T a, U b) {
	x = a;
	y = b;
}

template<class T, class U>
double Point<T, U>::calDis(Point other) {
	double dx = x - other.x;
	double dy = y - other.y;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

template<class T, class U>
bool Point<T, U>::operator>(Point other) {
	if (y == other.y)
		return x > other.x;
	return y > other.y;
}

template<class T, class U>
void Point<T, U>::print() {
	cout << "(" << x << "," << y << ") ";
}

template<class T, class U>
void sort(Point<T, U>* a, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

template<class T, class U>
void twoFarthest(Point<T, U>* a, int n,double& maxDis, Point<T,U>&f1, Point<T,U>&f2) {
	maxDis = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			double dis = a[i].calDis(a[j]);
			//cout << dis << endl;
			if (dis > maxDis) {
				maxDis = dis;
				f1 = a[i];
				f2 = a[j];
			}
		}
}


int main() {
	
	int n = 4;
	Point<double, long long> a[4] = { {5.4,1}, {-0.5,-1}, {1e5,100}, {-1,-1} };

	cout << "Point Array:\n";
	for (int i = 0; i < n; i++)
		a[i].print();
	cout << "\n------------------------------------------------\n";

	cout << "Distance from ";
	a[0].print();
	cout << " to ";
	a[1].print();
	cout << "is: " << a[0].calDis(a[1]);
	cout << "\n------------------------------------------------\n";

	Point<double, long long> f1, f2;
	double maxDis;
	twoFarthest(a, n,maxDis, f1, f2);
	cout << "Two farthest points are:\n";
	f1.print();
	f2.print();
	cout << endl;
	cout << "Their distance is: " << maxDis;
	cout << "\n------------------------------------------------\n";

	sort(a, n);
	cout << "Point Array After Sorting:\n";
	for (int i = 0; i < n; i++)
		a[i].print();
	cout << "\n------------------------------------------------\n";

	return 0;
}