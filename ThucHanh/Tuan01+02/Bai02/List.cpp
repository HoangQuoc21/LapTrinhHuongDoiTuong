#include "List.h"
#include <string>
#include <cassert>
using namespace std;

// Hàm tạo (constructor)
List::List() {
    Head = nullptr;
    count = 0;
}

// Hàm hủy (destructor)
List::~List() {
    while (Head != nullptr) {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
}

// Hàm tạo một Node mới với giá trị và con trỏ next đã cho
Node* List::makeNode(const string& val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Phương thức insert: thêm một phần tử mới vào danh sách tại vị trí chỉ định.
void List::insert(int pos, const string& val) {
    assert(pos >= 0 && pos <= count);
    Node* newNode = makeNode(val);
    if (pos == 0) {
        newNode->next = Head;
        Head = newNode;
    }
    else {
        Node* prev = Head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    count++;
}

// Phương thức erase: xóa một phần tử khỏi danh sách tại vị trí chỉ định.
void List::erase(int pos) {
    if (count == 0) {
        cout << "Stack is empty.\n";
        return;
    }
    if (pos == 0) {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
    else {
        Node* prev = Head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    count--;
}

// Phương thức get: lấy giá trị của phần tử tại vị trí chỉ định.
string List::get(int pos) const {
    assert(pos >= 0 && pos < count);
    Node* curr = Head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    return curr->data;
}

// Phương thức print: in ra tất cả các phần tử trong danh sách.
void List::print() const {
    Node* curr = Head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Phương thức size: trả về số lượng phần tử trong danh sách.
int List::size() const {
    return count;
}