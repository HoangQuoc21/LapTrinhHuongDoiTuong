#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Queue sẽ được tổ chức như sau:

//   pFront                            pRear
//      |                                |
//      v                                v
//     node  -> node -> node -> node -> node -> NULL

//Cấu trúc Node dùng trong Danh Sách Liên Kết Đơn
struct Node{
    int data;
    Node* pNext;
};

//Lớp Queue sử dụng Danh Sách Liên Kết
class Queue{
private:
    Node* pFront, *pRear;
    Node* createNode(int value);
public:
    Queue();
    ~Queue();
    void enqueue(int data);
    void dequeue();
    int getFront();
    bool isEmpty();
    int getSize();
    void show();
};

//Phương thức createNode để tạo một Node mới 
Node* Queue::createNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->pNext = NULL;
    return newNode;
}

//Hàm khởi tạo Queue
Queue::Queue(){
    pFront = pRear = NULL;
}

//Hàm hủy Queue (dequeue cho đến khi nào Queue rỗng thì thôi)
Queue::~Queue(){
    while(pFront)
        dequeue();
}

//Hàm enqueue để thêm một phần tử vào cuối Queue
void Queue::enqueue(int data){
    Node* newNode = createNode(data);
    bool isEmpty = this->isEmpty();
    if (isEmpty){
        pFront = newNode;
        pRear = newNode;
    }
    else{
        pRear->pNext = newNode;
        pRear = newNode;
    }
}

//Hàm dequeue để lấy phần tử ở đầu Queue ra
void Queue::dequeue(){
    bool isEmpty = this->isEmpty();
    if (isEmpty)
        return;
    else{
        Node* deleteNode = pFront;
        pFront = pFront->pNext;
        delete deleteNode;

        if (pFront == NULL)
            pRear = NULL;
    }
}

//Hàm getFront trả vể giá trị của phần tử ở đầu Queue (nếu Queue rỗng thì trả về -1)
int Queue::getFront(){
    if (pFront)
        return pFront->data;
    else    
        return -1;
}

//Hàm isEmpty để kiểm tra xem Queue có rỗng hay không
bool Queue::isEmpty(){
    return (pFront == NULL && pRear == NULL);
}

//Hàm getSize trả về kích thước (số lượng phần tử) của Queue
int Queue::getSize(){
    Node* temp = pFront;
    int count = 0;
    while(temp){
        count++;
        temp = temp->pNext;
    }
    return count;
}

//Hàm show để xuất Queue ra dưới một định dạng dễ nhìn hơn 
void Queue::show(){
    Node* tempNode1, *tempNode2, *tempNode3;
    tempNode1 = tempNode2 = tempNode3 = pFront;
    cout << "\t";
    while (tempNode1 != NULL){
        cout << "--";
        tempNode1 = tempNode1->pNext;
    }
    cout << endl;
    cout << "\t";
    while (tempNode2 != NULL){
        cout << tempNode2->data << " ";
        tempNode2 = tempNode2->pNext;
    }
    cout << endl;
    cout << "\t";
    while (tempNode3 != NULL){
        cout << "--";
        tempNode3 = tempNode3->pNext;
    }
    cout << endl;

    Node* temp = pFront;
    while(temp)
        cout << temp->data << " ";
    cout << endl;
}

//Hàm main chứa chương trình chính bao gồm Menu các lựa chọn
int main(){
    string choice;
    int size;
    Queue queue;
    int top;
    bool isEmpty;
    int value;

    while(1){
        system("cls");

        isEmpty = queue.isEmpty();
        size = queue.getSize();
        top = queue.getFront();

        if (isEmpty)
            cout << "-The using queue is empty.\n";
        else{
            cout << "-Using queue: \n";
            queue.show();
            cout << "-Size: " << size << endl;
            cout << "-Current front note's data: " << top << endl;
        }

        cout << "========================== QUEUE MENU ======================\n";
        cout << "1. Enqueue an element to the queue.\n";
        cout << "2. Dequeue the top element from the queue.\n";
        cout << "0. Exit the program.\n";
        cout << "============================= END ==========================\n";
        cout << "Your choice: ";
        fflush(stdin);
        getline(cin,choice);

        if (choice == "1"){
            cout << "Input the value you want to push: ";
            cin >> value;
            queue.enqueue(value);
            cout << "Enqueue the value successfully.\n";
        }
        else if (choice == "2"){
            if (isEmpty)
                cout << "The using queue is empty.\n";
            else{
                queue.dequeue();
                cout << "Dequeue the top element successfully.\n";
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