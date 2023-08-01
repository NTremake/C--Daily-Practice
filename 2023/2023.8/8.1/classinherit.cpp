#include <iostream>
using namespace std;

template <class T1, class T2>
class B
{
public:
    T1 m_x;
    T2 m_y;
    B(const T1 x, const T2 y) :m_x(x), m_y(y) {
        cout << "B���캯���ĵ���" << endl;
    }
    void func2() {
        cout << "func2�ĵ���,m_x=" << m_x << "  m_y=" << m_y << endl;
    }
};
class A : public B<int, string>
{   //��ͨ��̳�ģ���࣬�̳�ʱ��Ҫָ�������б�
public:
    int m_a;
    A(int a, int x, string y) : B(x, y), m_a(a) {
        cout << "A���캯���ĵ���" << endl;
    }
    void func1() {
        cout << "func1�ĵ���,m_a=" << m_a << endl;
    }
};
template <class T1, class T2>
class C : public B<T1, T2>
{   //�ü̳а���ͨ����ģ����
public:
    int m_c;
    C(int c, const T1 x, const T2 y) : B<T1, T2>(x, y), m_c(c) {
        cout << "C���캯���ĵ���" << endl;
    }
    void func3() {
        cout << "func3�ĵ���,m_c=" << m_c << endl;
    }
};
template <class T, class T1, class T2>
class D : public B<T1, T2>
{   //ģ����̳�ģ���࣬Ҫ������ģ������д������
public:
    T m_d;
    D() {}
    D(const T d, const T1 x, const T2 y) : B<T1, T2>(x, y), m_d(d) {
        cout << "D���캯���ĵ���" << endl;
    }
    void func4() {
        cout << "func4�ĵ���,m_d=" << m_d << endl;
    }
};
int main() {
    A a(1, 2, "hello");
    a.func2();
    a.func1();
    C<int, string> c(3, 4, "hello");//ֻ��Ҫָ��ģ��Ĳ������͡���Ҫ�Ѳ���д©
    c.func2();
    c.func3();
    D<int, int, string> d(3, 4, "hello");
    d.func2();
    d.func4();
    system("pause");
    return 0;
}