#include <iostream>
#include "graph.h"
using namespace std;

//Test case duyệt BFS: Tìm kiếm chiều rộng
//10
//11
//1 2
//1 3
//1 5
//1 10
//2 4
//3 6
//3 7
//3 9
//5 8
//6 7
//8 9
// start = 1 -> Duyệt BFS: 1 2 3 5 10 4 6 7 9 8


int main() {
	graph g;
	int start;
	g.input();
	cout << "--------------------------------------------------------------\n";

	cout << "*Nhap vao dinh muon bat dau duyet BFS: ";
	cin >> start;
	cout << "--------------------------------------------------------------\n";

	cout << "*Thu tu duyet BFS cua do thi tren la: ";
	g.bfs(start);
	cout << "--------------------------------------------------------------\n";

	return 0;
}