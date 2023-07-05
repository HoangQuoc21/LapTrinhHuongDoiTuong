#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Stack sẽ được tổ chức như sau:

//   pTop ->   node 
//              |
//              v
//             node
//              |
//              v
//             node
//              |
//              v
//             NULL

//Cấu trúc Node dùng trong Danh Sách Liên Kết Đơn
struct Node{
    int data;
    Node* pNext;
};

//Lớp Stack sử dụng Danh Sách Liên Kết
class Stack{
private:
    Node* pTop;
    Node* createNode(int value);
public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    int getTop();
    bool isEmpty();
    int getSize();
    void show();
};

//Phương thức createNode để tạo một Node mới 
Node* Stack::createNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->pNext = NULL;
    return newNode;
}

//Hàm khởi tạo Stack
Stack::Stack(){
    pTop = NULL;
}

//Hàm hủy stack (pop cho đến khi nào Stack rỗng thì thôi)
Stack::~Stack(){
    while(pTop)
        pop();
}

//Hàm push để thêm một phần tử vào đỉnh Stack
void Stack::push(int data){
    Node* newNode = createNode(data);
    if (!pTop)
        pTop = newNode;
    else{
        newNode->pNext = pTop;
        pTop = newNode;
    }
}

//Hàm pop để lấy phần tử ở đỉnh Stack ra
void Stack::pop(){
    if(pTop){
        Node* deleteNode = pTop;
        pTop = pTop->pNext;
        deleteNode->pNext = NULL;
        delete deleteNode;
    }
}

//Hàm getTop trả vể giá trị của phần tử ở đỉnh Stack (nếu Stack rỗng thì trả về -1)
int Stack::getTop(){
    if (pTop)
        return pTop->data;
    else    
        return -1;
}

//Hàm isEmpty để kiểm tra xem Stack có rỗng hay không
bool Stack::isEmpty(){
    return (pTop == NULL);
}

//Hàm getSize trả về kích thước (số lượng phần tử) của Stack
int Stack::getSize(){
    Node* temp = pTop;
    int count = 0;
    while(temp){
        count++;
        temp = temp->pNext;
    }
    return count;
}

//Hàm show để xuất Stack ra dưới một định dạng dễ nhìn hơn 
void Stack::show(){
    Node* temp = pTop;
    while(temp){
        if (temp->pNext)
            cout << "\t\t|" << setw(4) << temp->data << setw(5) << "|\n";
        else{
            cout << "\t\t|" << setw(4) << temp->data << setw(5) << "|\n";
            cout << "\t\t---------\n";
        }

        temp = temp->pNext;
        //cout << temp->data << " ";
    }
    //cout << endl;
}

//Hàm main chứa chương trình chính bao gồm Menu các lựa chọn
int main(){
    string choice;
    int size;
    Stack stack;
    int top;
    bool isEmpty;
    int value;

    while(1){
        system("cls");

        isEmpty = stack.isEmpty();
        size = stack.getSize();
        top = stack.getTop();

        if (isEmpty)
            cout << "-The using stack is empty.\n";
        else{
            cout << "-Using stack: \n";
            stack.show();
            cout << "-Size: " << size << endl;
            cout << "-Current top note's data: " << top << endl;
        }
       
        cout << "========================== STACK MENU ======================\n";
        cout << "1. Push an element to the stack.\n";
        cout << "2. Pop the top element from the stack.\n";
        cout << "0. Exit the program.\n";
        cout << "============================= END ==========================\n";
        cout << "Your choice: ";
        fflush(stdin);
        getline(cin,choice);

        if (choice == "1"){
            cout << "Input the value you want to push: ";
            cin >> value;
            stack.push(value);
            cout << "Push the value successfully.\n";
        }
        else if (choice == "2"){
            if(isEmpty)
                cout << "The using stack is empty.\n";
            else{
                stack.pop();
                cout << "Pop the top element successfully.\n";
            }
        }
        else if (choice == "0"){
            cout << "Exit the program successfully.\n";
            break;
        }
        else
            cout << "Unvalid choice.\n";
        
        system("pause");
    }

    return 0;
}