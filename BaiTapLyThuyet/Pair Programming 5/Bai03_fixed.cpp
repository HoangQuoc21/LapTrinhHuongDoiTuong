#include <iostream>
#include <vector>
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
	void set(T a, U b);
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
void Point<T, U>::set(T a, U b) {
	x = a;
	y = b;
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
void twoFarthest(Point<T, U>* a, int n) {
	double maxDis = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			double dis = a[i].calDis(a[j]);
			//cout << dis << endl;
			if (dis < maxDis && i != j) {
				maxDis = dis;
			}
		}
	vector<pair<int, int>> pairP;

	cout << "The nearest pair points are:\n";
	cout << "-----------------------------\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			double dis = a[i].calDis(a[j]);
			if (dis == maxDis) {
				bool exist = false;
				for (int k = 0; k < pairP.size(); k++) 
					if ((pairP[k].first == i && pairP[k].second == j) || (pairP[k].first == j && pairP[k].second == i) ) {
						exist = true;
						break;
					}
				if (!exist) {
					pairP.push_back({ i,j });
					a[i].print();
					cout << "and ";
					a[j].print();
					cout << endl;
				}
			}
		}
	cout << "Their distance is: " << maxDis;
}


int main() {

	int n = 4;
	int x;
	int y;
	Point<int, int>* a;
	
	cout << "nhap n: ";
	cin >> n;
	a = new Point<int, int>[n];
	for (int i = 0; i < n; i++) {
		cout << "Innput point:\n";
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		a[i].set(x,y);
	}

	cout << "Point Array:\n";
	for (int i = 0; i < n; i++)
		a[i].print();
	cout << "\n------------------------------------------------\n";
	int b, c;
	cout << "Index of Point 1: ";
	cin >> b;
	while (b < 0 || b >= n) {
		cout << "Reinput: ";
		cin >> b;
	}
	
	cout << "Index of Point 2: ";
	cin >> c;
	while (c < 0 || c >= n) {
		cout << "Reinput: ";
		cin >> c;
	}
	cout << "Point1: ";
	a[b].print();
	cout << endl;
	cout << "Point2: ";
	a[c].print();
	cout << endl;
	cout << "Their distances is : " << a[b].calDis(a[c]) << endl;
	cout << "\n------------------------------------------------\n";
	twoFarthest(a, n);
	cout << "\n------------------------------------------------\n";

	sort(a, n);
	cout << "Point Array After Sorting:\n";
	for (int i = 0; i < n; i++)
		a[i].print();
	cout << "\n------------------------------------------------\n";

	return 0;
}