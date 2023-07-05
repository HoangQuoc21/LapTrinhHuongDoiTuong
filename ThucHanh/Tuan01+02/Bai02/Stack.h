#ifndef STACK_H
#define STACK_H
#include "list.h"
#include <string>
using namespace std;

class Stack {
private:
    List list;
public:
    void push(const string& val);
    void pop();
    string top() const;
    int size() const;
};
#endif

