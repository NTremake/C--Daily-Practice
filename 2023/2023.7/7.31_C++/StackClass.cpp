#include <iostream>
using namespace std;

//typedef string ItemsType;
template<class ItemsType>
class Stack {
private:
    ItemsType *items;//ջԪ������
    int StackSize;//ջ�Ĵ�С
    int top;//ջ��ָ��
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
        s.Push("����" + to_string(i));
    }
    string item;
    while(s.Pop(item)) {
        cout << item << "  ";
    }
    cout << endl;
    system("pause");
    return 0;
}