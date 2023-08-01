#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <vector>

template<class ItemsType>
class Stack {
private:
    ItemsType *items;//栈元素数组
    int StackSize;//栈的大小
    int top;//栈顶指针
public:
    Stack(int size = 3) : StackSize(size), top(0) {
        items = new ItemsType[StackSize];
    }
    ~Stack() {
        delete[] items;
        items = nullptr;
    }
    //重载深拷贝
    Stack &operator=(const Stack &s) {
        delete[] items;
        items = nullptr;
        StackSize = s.StackSize;
        items = new ItemsType[StackSize];
        for(int i = 0; i < StackSize; ++i) {
            items[i] = s.items[i];
        }
        top = s.top;
        return *this;
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

template<class T>
class Vector {   //模板类动态数组
private:
    T *items;
    int len;
public:
    Vector(int size = 2) : len(size) {
        items = new T[len];
    }
    ~Vector() {
        delete[] items;
        items = nullptr;
    }
    Vector &operator=(const Vector &v) {
        delete[] items;
        items = nullptr;
        len = v.len;
        items = new T[len];
        for(int i = 0; i < len; ++i) {
            items[i] = v.items[i];
        }
        return *this;
    }
    void reSize(int size) {
        if(size <= len) {
            return;
        }
        T *temp = new T[size];
        for(int i = 0; i < len; ++i) {
            temp[i] = items[i];
        }
        delete[] items;
        items = nullptr;
        len = size;
        items = temp;
    }
    T &operator[](int i) {
        if(i >= len) {
            reSize(i + 5);//多分配5个空间，避免每次都分配空间
        }
        return items[i];
    }
    const T &operator[](int i) const {
        return items[i];
    }
    int size() const {
        return len;
    }
};//模板类动态数组的嵌套
int main() {
    Vector<Stack<string>> vs;
    vs[0].Push("西施1");vs[0].Push("西施2");vs[0].Push("西施3");
    vs[1].Push("貂蝉1");vs[1].Push("貂蝉2");vs[1].Push("貂蝉3");
    vs[2].Push("西瓜1");vs[2].Push("西瓜2");vs[2].Push("西瓜3");
    for(int i = 0; i < vs.size(); ++i) {
        while(!vs[i].isempty()) {
            string item;
            vs[i].Pop(item);
            cout << item << "  ";
        }
    }
    cout << endl;
    Stack<Vector<string>> sv;
    Vector<string> temp;
    temp[0] = "西施1";temp[1] = "西施2";temp[2] = "西施3";sv.Push(temp);
    temp[0] = "貂蝉1";temp[1] = "貂蝉2";temp[2] = "貂蝉3";sv.Push(temp);
    while (!sv.isempty()) {
        Vector<string> item;
        sv.Pop(item);
        for(int i = 0; i < item.size(); ++i) {
            cout << item[i] << "  ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}