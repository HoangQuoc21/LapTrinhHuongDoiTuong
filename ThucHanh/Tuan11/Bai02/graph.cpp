#include "graph.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

graph::graph() {
	vertexNum = edgeNum = 0;
	edges = NULL;
}

void graph::input() {
	cout << "*Nhap vao so dinh: ";
	cin >> vertexNum;
	edges = new vector<int>[vertexNum+1];
	cout << "*Nhap vao so canh: ";
	cin >> edgeNum;
	for (int i = 1; i <= edgeNum; i++) {
		cout << "- Nhap Canh " << i << ": ";
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);	
	}
}

void graph::bfs(int start) {
	bool* mark = new bool[vertexNum + 1] {0};
	queue<int> vertexQueue;
	vertexQueue.enqueue(start);
	mark[start] = 1;
	while (!vertexQueue.empty()) {
		int curVertex = vertexQueue.front();
		vertexQueue.dequeue();
		cout << curVertex << " ";

		for (int x : edges[curVertex]) {
			if (!mark[x]) {
				vertexQueue.enqueue(x);
				mark[x] = 1;
			}
		}
	}
	cout << endl;
	delete[] mark;
}

graph::~graph() {
	if (edges != NULL) {
		for (int i = 1; i < vertexNum; i++) {
			edges[i].clear();
		}
		delete[]edges;
	}
	vertexNum = edgeNum = 0;
	edges = NULL;
}