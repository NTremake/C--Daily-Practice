#include <iostream>
using namespace std;

//typedef string ItemsType;
template<class ItemsType>
class Stack {
private:
    ItemsType *items;//栈元素数组
    int StackSize;//栈的大小
    int top;//栈顶指针
public:
    Stack(int size) : StackSize(size), top(0) {
        items = new ItemsType[StackSize];
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
    bool Push(const ItemsType &item) {
        if (isFull()) {
            return false;
        }
        items[top++] = item;
        return true;
    }
    bool Pop(ItemsType &item) {
        if (isempty()) {
            return false;
        }
        item = items[--top];
        return true;
    }
};
int main() {
    Stack<string> s(5);
    for(int i = 1; i <= 5; ++i) {
        //s.Push(i);
        s.Push("姓名" + to_string(i));
    }
    string item;
    while(s.Pop(item)) {
        cout << item << "  ";
    }
    cout << endl;
    system("pause");
    return 0;
}