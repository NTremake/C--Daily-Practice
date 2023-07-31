#include <iostream>
using namespace std;
#include <cstring>
//#define MAXLEN 10

template<class T, int len = 10>
class Array {   //模板类静态数组
private:
    T items[len];
public:
    Array() {
        memset(items, 0, sizeof(items));
    }
    ~Array() {}
    T &operator[](int i) {
        return items[i];
    }
    const T &operator[](int i) const {
        return items[i];
    }
};
template<class T>
class Vector {   //模板类动态数组
private:
    T *items;
    int len;
public:
    Vector(int size = 10) : len(size) {
        items = new T[len];
    }
    ~Vector() {
        delete[] items;
        items = nullptr;
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
};
int main() {
    Array<int, 10> a;
    for(int i = 0; i < 10; ++i) {
        a[i] = i;
        cout << a[i] << "  ";
    }
    cout << endl;
    Array<string> b;//第二个参数有默认值，可以不用写
    for(int i = 0; i < 10; ++i) {
        b[i] = "姓名" + to_string(i);
        cout << b[i] << "  ";
    }
    cout << endl;
    Vector<int> c;
    for(int i = 0; i < 10; ++i) {
        c[i] = i;
        cout << c[i] << "  ";
    }
    cout << endl;
    c[11] = 11;
    cout << c[11] << endl;
    system("pause");
    return 0;
}