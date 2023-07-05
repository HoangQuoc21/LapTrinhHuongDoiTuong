#include "Stack.h"

// Thêm phần tử vào đầu danh sách
void Stack::push(const string& val) {
    list.insert(0, val);
}

// Xóa phần tử đầu danh sách
void Stack::pop() {
    list.erase(0);
}

// Lấy giá trị phần tử đầu danh sách
string Stack::top() const {
    return list.get(0);
}

// Trả về số lượng phần tử trong danh sách
int Stack::size() const {
    return list.size();
}