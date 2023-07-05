#include <iostream>
#include <queue>
using namespace std;

//Cấu trúc Node của cây AVL sử dụng template
struct node {
    int key;
    node* left;
    node* right;
    int height;
};

//Hàm Tạo Node
node* createNode(int data) {
    node* newNode = new node{data,NULL,NULL,1};
    return newNode;
}

//Khai báo class AVLTree
class AVLTree {
private:
    node* root;
    int _height(node* Node);
    void rightRotate(node*& y);
    void leftRotate(node*& x);
    int getBalance(node* Node);
    void _insert(node*& pRoot, int x);
    node* maxValueNode(node* pRoot);
    void _remove(node*& pRoot, int x);
    bool _exist(node* pRoot, int x);
    void _NLR(node* pRoot);
    void _LNR(node* pRoot);
    void _LRN(node* pRoot);
    void _levelOrder(node* pRoot);
    int _countNode(node* pRoot);
public:
    AVLTree();
    ~AVLTree();
   
    void insert(int key);
    void remove(int key);
    bool exist(int value);
    void NLR();
    void LNR();
    void LRN();
    void levelOrder();
    int countNode();
};

//constructor
AVLTree::AVLTree() {
    root = NULL;
}

//destructor
AVLTree::~AVLTree() {
    while (_countNode(root) != 0)
        _remove(root, root->key);
    root = NULL;
}

//Hàm tìm chiều cao của Node truyền vào
int AVLTree::_height(node* Node) {
    if (Node == NULL)
        return 0;
    return Node->height;
}

//Hàm xoay phải
void AVLTree::rightRotate(node*& y) {
    node* x = y->left;
    node* T2 = x->right;

    //Xoay
    x->right = y;
    y->left = T2;

    //Cập nhật lại chiều cao
    y->height = max(_height(y->left), _height(y->right)) + 1;
    x->height = max(_height(x->left), _height(x->right)) + 1;

    //Cập nhật con trỏ gốc
    y = x;
}

//Hàm xoay trái
void AVLTree::leftRotate(node*& x) {
    node* y = x->right;
    node* T2 = y->left;

    //Xoay
    y->left = x;
    x->right = T2;

    //Cập nhật lại chiều cao
    x->height = max(_height(x->left), _height(x->right)) + 1;
    y->height = max(_height(y->left), _height(y->right)) + 1;

    //Cập nhật con trỏ gốc
    x = y;
}

//Hàm trả về chỉ số cân bằng của Node truyền vào (tính bằng: chiều cao cây con trái - chiều cao cây con phải)
int AVLTree::getBalance(node* Node) {
    if (Node == NULL)
        return 0;
    return _height(Node->left) - _height(Node->right);
}
//balance = 0 => 2 cây con cân bằng
//balance = 1 => cân bằng lệch trái (cây con trái cao hơn)
//balance = -1 => cân bằng lệch phải (cây con phải cao hơn)

//Hàm thêm 1 Node vào cây
void AVLTree::_insert(node*& pRoot, int x) {
    // Có các bước:
    // B1: Thêm Node vào như cây BST
    if (pRoot == NULL)
        pRoot = createNode(x);

    if (x < pRoot->key)
        _insert(pRoot->left, x);
    else if (x > pRoot->key)
        _insert(pRoot->right, x);
    else
        return;

    // B2: cập nhật lại chiều cao cho Node gốc
    pRoot->height = max(_height(pRoot->left), _height(pRoot->right)) + 1;

    // B3: Tìm chỉ số cân bằng để xem cây có bị mất cân bằng không
    int balance = getBalance(pRoot);

    //Nếu mất cân bằng, có 4 trường hợp có thể xảy ra:

    // -TH1: mất cân bằng trái trái (xoay phải cây gốc)
    if (balance > 1 && x < pRoot->left->key) {
        rightRotate(pRoot);
        return;
    }

    // -TH2: mất cân bằng phải phải (xoay trái cây gốc)
    if (balance < -1 && x > pRoot->right->key) {
        leftRotate(pRoot);
        return;
    }

    // -TH3: mất cân bằng trái phải (xoay trái cây con trái - xoay phải cây gốc)
    if (balance > 1 && x > pRoot->left->key) {
        leftRotate(pRoot->left);
        rightRotate(pRoot);
        return;
    }

    // -TH4: mất cân bằng phải trái (xoay phải cây con phải - xoay trái cây gốc)
    if (balance < -1 && x < pRoot->right->key) {
        rightRotate(pRoot->right);
        leftRotate(pRoot);
        return;
    }
}

//Lấy phần tử thế mạng là phần tử phải nhất bên cây con trái
node* AVLTree::maxValueNode(node* pRoot) {
    node* current = pRoot;
    while (current->right != NULL)
        current = current->right;

    return current;
}

//Hàm xóa 1 Node ra khỏi cây AVL
void AVLTree::_remove(node*& pRoot, int x) {
    //Gồm các bước: 
    // B1: xóa 1 Node như cây BST
    if (pRoot == NULL)
        return;

    if (x < pRoot->key)
        _remove(pRoot->left, x);

    else if (x > pRoot->key)
        _remove(pRoot->right, x);

    // x == pRoot->key
    else {
        //Trường hợp node muốn xóa có 1 con hoặc không có con 
        if ((pRoot->left == NULL) || (pRoot->right == NULL)) {
            node* deleteNode = pRoot->left ? pRoot->left : pRoot->right;

            //TH không có con 
            if (deleteNode == NULL) {
                deleteNode = pRoot;
                pRoot = NULL;
            }
            //Trường hợp có 1 con
            else
                *pRoot = *deleteNode;

            delete deleteNode;
        }
        else {
            //Tìm phần tử thế mạng
            node* standingNode = maxValueNode(pRoot->left);

            //Đưa giá trị của phần tử thế mạng lên node xóa
            pRoot->key = standingNode->key;

            //Xóa phần tử thế mạng
            _remove(pRoot->left, standingNode->key);
        }
    }

    //Nếu cây chỉ còn 1 Node thì return 
    if (pRoot == NULL)
        return;

    // B2: cập nhật chiều cao của Node gốc 
    pRoot->height = max(_height(pRoot->left), _height(pRoot->right)) + 1;

    // B3: Tìm chỉ số cân bằng để xem cây có bị mất cân bằng không
    int balance = getBalance(pRoot);

    //Nếu mất cân bằng, có 4 trường hợp có thể xảy ra:

    // -TH1: mất cân bằng trái trái (xoay phải cây gốc)
    if (balance > 1 && getBalance(pRoot->left) >= 0) {
        rightRotate(pRoot);
        return;
    }

    // -TH2: mất cân bằng phải phải (xoay trái cây gốc)
    if (balance < -1 && getBalance(pRoot->right) <= 0) {
        leftRotate(pRoot);
        return;
    }

    // -TH3: mất cân bằng trái phải (xoay trái cây con trái - xoay phải cây gốc)
    if (balance > 1 && getBalance(pRoot->left) < 0) {
        leftRotate(pRoot->left);
        rightRotate(pRoot);
        return;
    }

    // -TH4: mất cân bằng phải trái (xoay phải cây con phải - xoay trái cây gốc)
    if (balance < -1 && getBalance(pRoot->right) > 0) {
        rightRotate(pRoot->right);
        leftRotate(pRoot);
        return;
    }
}

// Duyệt tiền thứ tự
void AVLTree::_NLR(node* pRoot) {
    if (!pRoot)
        return;
    else {
        cout << pRoot->key << " ";
        _NLR(pRoot->left);
        _NLR(pRoot->right);
    }
}

// Duyệt trung thứ tự
void AVLTree::_LNR(node* pRoot) {
    if (pRoot) {
        _LNR(pRoot->left);
        cout << pRoot->key << " ";
        _LNR(pRoot->right);
    }
}

// Duyệt hậu thứ tự
void AVLTree::_LRN(node* pRoot) {
    if (pRoot) {
        _LRN(pRoot->left);
        _LRN(pRoot->right);
        cout << pRoot->key << " ";
    }
}

// Duyệt theo mức
void AVLTree::_levelOrder(node* pRoot) {
    if (!pRoot)
        return;

    queue<node*> nodeQueue;
    nodeQueue.push(pRoot);
    while (!nodeQueue.empty()) {
        node* currNode = nodeQueue.front();
        cout << currNode->key << " ";
        nodeQueue.pop();
        if (currNode->left)
            nodeQueue.push(currNode->left);
        if (currNode->right)
            nodeQueue.push(currNode->right);
    }
}

//Hàm kiểm tra 1 giá trị có tồn tại trong cây AVL không
bool AVLTree::_exist(node* pRoot, int x) {
    if (!pRoot)
        return false;
    bool result;
    if (pRoot->key == x)
        result = true;
    else if (pRoot->key > x)
        result = _exist(pRoot->left, x);
    else if (pRoot->key < x)
        result = _exist(pRoot->right, x);
    return result;
}

// Hàm đếm số Node có trong cây
int AVLTree::_countNode(node* pRoot) {
    if (!pRoot)
        return 0;

    int a = _countNode(pRoot->left);
    int b = _countNode(pRoot->right);
    return 1 + a + b;
}

void AVLTree::insert(int key) {
    _insert(root, key);
}

void AVLTree::remove(int key) {
    _remove(root, key);
}

bool AVLTree::exist(int value) {
    return (_exist(root, value));
}

void AVLTree::NLR() {
    _NLR(root);
    cout << endl;
}

void AVLTree::LNR() {
    _LNR(root);
    cout << endl;
}

void AVLTree::LRN() {
    _LRN(root);
    cout << endl;
}

void AVLTree::levelOrder() {
    _levelOrder(root);
    cout << endl;
}

int AVLTree::countNode() {
    return _countNode(root);
}


int main() {
    AVLTree avl;

    //=== Vài TH Nhập tự động trước 1 số node (Nếu muốn, thầy hãy mở khóa những dòng dưới và chỉnh sửa ạ) ====
    //-- Case1: --
    /*int nNode = 13;
    int a[13] = {45,36,15,29,57,78,60,83,79,96,20,99,97};*/
    // -- Case2: --
    // int nNode = 11;
    // int a[11] = {33,14,15,92,64,35,79,27,38,105,99};
    // -- Case3: --
    /*int nNode = 10;
    int a[10] = {22,1,13,11,24,33,18,42,31,32};*/

    //-- 2 dòng dưới đây để tự động thêm node dựa theo case ở trên --
    /*for (int i = 0; i < nNode; i++)
        avl.insert(a[i]);*/

    while (1) {
        string choice;
        system("cls");
        cout << "*******************************************************\n";
        cout << "*                HOME WORK 3: AVL TREE                *\n";
        cout << "*******************************************************\n";
        cout << "-Cay da nhap in theo tien thu tu: ";
        avl.NLR();
        cout << "-Cay da nhap in theo trung thu tu: ";
        avl.LNR();
        cout << "-Cay da nhap in theo hau thu tu: ";
        avl.LRN();
        cout << "-Cay da nhap in theo muc: ";
        avl.levelOrder();
        if (avl.countNode() == 0)
            cout << "-Cay hien tai chua co Node nao het.\n";
        else {
            cout << "-Cay hien tai co " << avl.countNode() << " Node.\n";
        }
        cout << "======================== MENU ========================\n";
        cout << "1. Them 1 Node vao cay.\n";
        cout << "2. Xoa 1 Node khoi cay.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "======================== END =========================\n";
        cout << "Nhap vao lua chon cua ban: ";
        cin >> choice;
        cout << "-------------------------------------------------------\n";
        if (choice == "1") {
            int data;
            cout << "Nhap vao gia tri muon them vao cay: ";
            cin >> data;
            if (avl.exist(data))
                cout << "Da ton tai gia tri " << data << " san trong cay nen khong can them.\n";
            else {
                cout << "Da them Node mang gia tri " << data << " vao cay.\n";
                avl.insert(data);
            }
        }
        else if (choice == "2") {
            int data;
            cout << "Nhap vao gia tri muon xoa khoi cay: ";
            cin >> data;
            if (avl.exist(data)) {
                cout << "Da xoa Node mang gia tri " << data << " khoi cay.\n";
                avl.remove(data);
            }
            else
                cout << "Khong ton tai gia tri " << data << " de xoa trong cay.\n";
        }
        else if (choice == "0") {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        else
            cout << "Lua chon khong hop le.\n";

        system("pause");
    }
    return 0;
}