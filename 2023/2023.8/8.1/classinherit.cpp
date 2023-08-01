#include <iostream>
using namespace std;

template <class T1, class T2>
class B
{
public:
    T1 m_x;
    T2 m_y;
    B(const T1 x, const T2 y) :m_x(x), m_y(y) {
        cout << "B构造函数的调用" << endl;
    }
    void func2() {
        cout << "func2的调用,m_x=" << m_x << "  m_y=" << m_y << endl;
    }
};
class A : public B<int, string>
{   //普通类继承模板类，继承时需要指明参数列表
public:
    int m_a;
    A(int a, int x, string y) : B(x, y), m_a(a) {
        cout << "A构造函数的调用" << endl;
    }
    void func1() {
        cout << "func1的调用,m_a=" << m_a << endl;
    }
};
template <class T1, class T2>
class C : public B<T1, T2>
{   //用继承把普通类变成模板类
public:
    int m_c;
    C(int c, const T1 x, const T2 y) : B<T1, T2>(x, y), m_c(c) {
        cout << "C构造函数的调用" << endl;
    }
    void func3() {
        cout << "func3的调用,m_c=" << m_c << endl;
    }
};
template <class T, class T1, class T2>
class D : public B<T1, T2>
{   //模板类继承模板类，要把所有模板类型写在上面
public:
    T m_d;
    D() {}
    D(const T d, const T1 x, const T2 y) : B<T1, T2>(x, y), m_d(d) {
        cout << "D构造函数的调用" << endl;
    }
    void func4() {
        cout << "func4的调用,m_d=" << m_d << endl;
    }
};
int main() {
    A a(1, 2, "hello");
    a.func2();
    a.func1();
    C<int, string> c(3, 4, "hello");//只需要指明模板的参数类型。不要把参数写漏
    c.func2();
    c.func3();
    D<int, int, string> d(3, 4, "hello");
    d.func2();
    d.func4();
    system("pause");
    return 0;
}