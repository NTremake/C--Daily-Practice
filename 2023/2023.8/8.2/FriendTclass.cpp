#include <iostream>
using namespace std;
#include <vector>

template <typename T>
void show(T &a); // 约束型函数模板，只能接受AA类的对象。第一步：先在类模板前面声明

template <typename T1, typename T2>
class AA {
private:
    T1 m_x;
    T2 m_y;
public:
    AA(T1 x, T2 y) : m_x(x), m_y(y) {}
    friend void show<>(AA<T1, T2> &a);//第二步：在类模板中声明为友元函数。注意：<>不能省略
};
template <typename T>
void show(T &a) {   //第三步：在类模板后面定义
    cout << "通用模板show():" << a.m_x << "  " << a.m_y << endl;
}
template <>
void show(AA<char, string> &a) {    //具体化版本
    cout << "AA具体化模板show():" << a.m_x << "  " << a.m_y << endl;
}
//--------------------------------------------
template <typename T1, typename T2>
class BB {
private:
    T1 m_x;
    T2 m_y;
public:
    BB(T1 x, T2 y) : m_x(x), m_y(y) {}
    friend void show<>(BB<T1, T2> &a);//第二步：在类模板中声明为友元函数。注意：<>不能省略
};
template <>
void show(BB<char, string> &a) {    //具体化版本
    cout << "BB具体化模板show():" << a.m_x << "  " << a.m_y << endl;
}
int main() {
    AA<int, string> a(1, "hello");
    show(a);
    AA<char, string> b('1', "hello");
    show(b);
    BB<int, string> c(1, "hello");
    show(c);
    BB<char, string> d('1', "hello");
    show(d);
    system("pause");
    return 0;
}