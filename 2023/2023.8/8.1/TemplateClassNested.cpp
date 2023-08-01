#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <vector>

template<class ItemsType>
class Stack {
private:
    ItemsType *items;//ջԪ������
    int StackSize;//ջ�Ĵ�С
    int top;//ջ��ָ��
public:
    Stack(int size = 3) : StackSize(size), top(0) {
        items = new ItemsType[StackSize];
    }
    ~Stack() {
        delete[] items;
        items = nullptr;
    }
    //�������
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
class Vector {   //ģ���ද̬����
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
            reSize(i + 5);//�����5���ռ䣬����ÿ�ζ�����ռ�
        }
        return items[i];
    }
    const T &operator[](int i) const {
        return items[i];
    }
    int size() const {
        return len;
    }
};//ģ���ද̬�����Ƕ��
int main() {
    Vector<Stack<string>> vs;
    vs[0].Push("��ʩ1");vs[0].Push("��ʩ2");vs[0].Push("��ʩ3");
    vs[1].Push("����1");vs[1].Push("����2");vs[1].Push("����3");
    vs[2].Push("����1");vs[2].Push("����2");vs[2].Push("����3");
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
    temp[0] = "��ʩ1";temp[1] = "��ʩ2";temp[2] = "��ʩ3";sv.Push(temp);
    temp[0] = "����1";temp[1] = "����2";temp[2] = "����3";sv.Push(temp);
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