#pragma once
#include <vector>
using namespace std;

class graph
{
private:
	int vertexNum;
	int edgeNum;
	//Đồ thị sử dụng danh sách kề
	vector<int>* edges;
public:
	graph();
	void input();
	void bfs(int start);
	~graph();
};