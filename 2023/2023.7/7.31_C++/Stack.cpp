#include <iostream>
using namespace std;

typedef int ItemsType;

class Stack {
private:
    int *items;//栈元素数组
    int StackSize;//栈的大小
    int top;//栈顶指针
public:
    Stack(int size) : StackSize(size), top(0) {
        items = new int[StackSize];
    }
    ~Stack() {
        delete[] items;
        items = nullptr;
    }
    bool isempty() const {
        return top == 0;
    }
    bool isFull() const {
        return top == StackSize;
    }
    bool Push(const int &item) {
        if (isFull()) {
            return false;
        }
        items[top++] = item;
        return true;
    }
    bool Pop(int &item) {
        if (isempty()) {
            return false;
        }
        item = items[--top];
        return true;
    }
};
int main() {
    Stack s(5);
    for(int i = 1; i <= 5; ++i) {
        s.Push(i);
    }
    int item;
    while(s.Pop(item)) {
        cout << item << "  ";
    }
    system("pause");
    return 0;
}