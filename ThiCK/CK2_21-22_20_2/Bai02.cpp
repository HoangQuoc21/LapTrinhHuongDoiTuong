#include <iostream>
using namespace std;

template<typename T>
struct node {
	T key;
	node* pLeft;
	node* pRight;
};

template<typename T>
node<T>* createNode(T x) {
	node<T>* newNode = new node<T>{ x,NULL,NULL };
	return newNode;
}

template<typename T>
class BST {
private:
	node<T>* pRoot;
	void insert(node<T>*& pRoot, T x);
	void searchStandFor(node<T>*& deleteNode, node<T>*& standForNode);
	void remove(node<T>*& pRoot, T x);
	void removeTree(node<T>*& pRoot);
	void _NLR(node<T>* pRoot);
public:
	BST();
	~BST();
	void addNode(T x);
	void deleteNode(T x);
	void NLR();
};

template<typename T>
void BST<T>::insert(node<T>*& pRoot, T x) {
	if (!pRoot) {
		node<T>* newNode = createNode(x);
		pRoot = newNode;
	}

	if (x < pRoot->key)
		insert(pRoot->pLeft, x);
	else if (x > pRoot->key)
		insert(pRoot->pRight, x);
}

template<typename T>
void BST<T>::searchStandFor(node<T>*& deleteNode, node<T>*& standForNode) {
	if (standForNode->pLeft)
		searchStandFor(deleteNode, standForNode->pLeft);
	else {
		deleteNode->key = standForNode->key;
		deleteNode = standForNode;
		standForNode = standForNode->pRight;
	}
}

template<typename T>
void BST<T>::remove(node<T>*& pRoot, T x) {
	if (!pRoot)
		return;
	else if (pRoot->key > x)
		remove(pRoot->pLeft, x);
	else if (pRoot->key < x)
		remove(pRoot->pRight, x);
	else {
		node<T>* deleteNode = pRoot;
		if (!pRoot->pLeft)
			pRoot = pRoot->pRight;
		else if (!pRoot->pRight)
			pRoot = pRoot->pLeft;
		else
			searchStandFor(deleteNode, pRoot->pRight);
		delete deleteNode;
	}
}

template<typename T>
void BST<T>::removeTree(node<T>*& pRoot) {
	if (pRoot) {
		removeTree(pRoot->pLeft);
		removeTree(pRoot->pRight);
		delete pRoot;
	}
}

template<typename T>
void BST<T>::_NLR(node<T>* pRoot) {
	if (pRoot) {
		cout << pRoot->key << " ";
		_NLR(pRoot->pLeft);
		_NLR(pRoot->pRight);
	}
}

template<typename T>
BST<T>::BST() {
	pRoot = NULL;
}

template<typename T>
BST<T>::~BST() {
	removeTree(pRoot);
	pRoot = NULL;
}

template<typename T>
void BST<T>::addNode(T x) {
	insert(pRoot, x);
}

template<typename T>
void BST<T>::deleteNode(T x) {
	remove(pRoot, x);
}

template<typename T>
void BST<T>::NLR(){
	_NLR(pRoot);
	cout << endl;
}

int main() {
	int nNode = 20;
	float Nodes[100] = { 9.1,5.2,3.3,20.4,60.5,81.6,14.7,4.8,7.0,56.9,13.2,1.3,15.4,8.5,6.6,100.8,99.0,101.1,102.2,103.3 };
	BST<float> bst;
	for (int i = 0; i < 20; i++)
		bst.addNode(Nodes[i]);

	bst.NLR();

	bst.deleteNode(9.1);
	bst.NLR();

	bst.deleteNode(5.2);
	bst.NLR();

	bst.deleteNode(103.3);
	bst.NLR();
	return 0;
}