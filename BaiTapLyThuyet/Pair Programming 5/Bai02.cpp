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
	void tong3NhoNhat() {
		if (n < 3)
			return;
		else {
			int min = -1;
			int min2 = -1;
			int min3 = -1;
			int i = n - 1;
			while (i > 0) {
				if (a[i].weight != a[i - 1].weight) {
					min = i;
					break;
				}
				if (i -1 == 0)
					break;
				i--;
			}
			i--;
			while (i > 0) {
				if (a[i].weight != a[i - 1].weight) {
					min2 = i;
					break;
				}
				if (i -1 == 0)
					break;
				i--;
			}
			i--;
			while (i > 0) {
				if (a[i].weight != a[i - 1].weight) {
					min3 = i;
					break;
				}
				if (i - 1 == 0)
					break;
				i--;
			}
			//cout << "haha\n";
			if (min == -1 || min2 == -1 || min3 == -1)
				return;
			else
				this->Enqueue("E", a[min].weight + a[min2].weight + a[min3].weight);
		}
	}
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
	string code;
	int weight = 0;
	while (1) {
		cout << "Enqueue weight (-9999 to exit): ";
		cin >> weight;
		if (weight == -9999)
			break;
		cout << "Enqueue code: ";
		cin.ignore();
		getline(cin, code);
		pq.Enqueue(code, weight);
		cout << "-------------------------------------\n";
	}
	cout << "============================================\n";
	Node<int> top = pq.Top();
	

	pq.Print();
	cout << "Queue's size: " << pq.Size() << endl;
	cout << "-------------------------------------\n";
	cout << "Sum 3 smallest:\n";
	pq.tong3NhoNhat();
	pq.Print();
	
	cout << "------------------------------------\n";

	cout << "Dequeue:\n";
	cout << "Top: (" << top.code << "," << top.weight << ")\n";
	pq.Dequeue();
	pq.Print();
	cout << "Queue's size: " << pq.Size() << endl;
	cout << "------------------------------------\n";
	return 0;
}