#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node {
	string code;
	T weight;
};

template <class T>
class PriorityQueue {
private:
	Node<T>* a;
	int n;
	void ReArrange();
public:
	PriorityQueue();
	~PriorityQueue();
	void Enqueue(string c, T w);
	void Dequeue();
	Node<T> Top();
	void Print();
	int Size();
};

template<class T>
void PriorityQueue<T>::ReArrange() {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].weight < a[j].weight) {
				swap(a[i], a[j]);
			}
}

template<class T>
PriorityQueue<T>::PriorityQueue() {
	a = NULL;
	n = 0;
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
	if (a != NULL) {
		delete[]a;
		a = NULL;
	}
	n = 0;
}

template<class T>
void PriorityQueue<T>::Enqueue(string c, T w) {
	//Tạo mảng b có các phần tử của mảng a và phần tử mới muốn chèn vào
	Node<T>* b = new Node<T>[n + 1];
	for (int i = 0; i < n; i++)
		b[i] = a[i];

	//Thêm phần tử mới vào cuối mảng b
	b[n].code = c;
	b[n].weight = w;
	
	//Xóa mảng a đi
	if (a != NULL) {
		delete[]a;
	}

	//Gán mảng b cho a
	a = b;
	n++;

	//Sắp xếp lại mảng a dựa vào trọng số
	ReArrange();
}

template<class T>
void PriorityQueue<T>::Dequeue() {
	//Tạo mảng b có các phần tử trừ phẩn tử đầu của mảng a
	Node<T>* b = new Node<T>[n - 1];
	for (int i = 0; i < n - 1; i++)
		b[i] = a[i + 1];
	
	//Xóa mảng a đi
	if (a != NULL) {
		delete[]a;
	}

	//Gán mảng b cho a
	a = b;
	n--;
}

template<class T>
Node<T> PriorityQueue<T>::Top() {
	return a[0];
}

template<class T>
void PriorityQueue<T>::Print() {
	for (int i = 0; i < n; i++)
		cout << "(" << a[i].code << "," << a[i].weight << ") ";
	cout << endl;
}

template<class T>
int PriorityQueue<T>::Size() {
	return n;
}

int main() {
	PriorityQueue<int> pq;
	pq.Enqueue("A", 3);
	pq.Enqueue("B", 1);
	pq.Enqueue("C", 7);
	Node<int> top = pq.Top();
	cout << "----------------------------------\n";
	cout << "Top: (" << top.code << "," << top.weight << ")\n";
	cout << "----------------------------------\n";

	pq.Print();
	cout << "Queue's size: " << pq.Size() << endl;
	cout << "----------------------------------\n";

	cout << "Enqueue:\n";
	pq.Enqueue("D", 5);
	pq.Print();
	cout << "Queue's size: " << pq.Size() << endl;
	cout << "----------------------------------\n";

	cout << "Dequeue:\n";
	pq.Dequeue();
	pq.Print();
	cout << "Queue's size: " << pq.Size() << endl;
	cout << "----------------------------------\n";
	return 0;
}