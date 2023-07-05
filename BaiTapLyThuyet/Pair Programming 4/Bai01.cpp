#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

int ranNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool isPrime(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            count++;
    return (count == 2);
}

class MyStack {
private:
    int n;
    int size;
    int* a;
public:
    MyStack();
    ~MyStack();
    void push(int x);
    void print();
};

MyStack::MyStack() {
    size = 10;
    a = new int[size];
    n = 0;
}

MyStack::~MyStack() {
    delete[] a;
    a = NULL;
}

void MyStack::print() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void MyStack::push(int x) {
    if (!isPrime(x))
        throw "La So Nguyen To";
    if (n == 10)
        throw "Het Vung Nho";
    a[n] = x;
    n++;
}

int main() {
    srand(time(NULL));
    MyStack stack;
    system("cls");

    while (1) {
        int num = ranNum(1, 10);
        cout << "So vua tao: " << num << endl;
        try {
            stack.push(num);
        }
        catch (const char* str) {
            cout << "Thong bao: " << str << endl;
            if (!strcmp("Het Vung Nho", str))
                break;
        }
        cout << "------------------------------------------\n";
    }
    cout << "===================================================\n";
    cout << "Stack sau khi xu ly: \n";
    stack.print();
    return 0;
}