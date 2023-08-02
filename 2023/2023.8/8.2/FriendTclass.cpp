#include <iostream>
using namespace std;
#include <vector>

template <typename T>
void show(T &a); // Լ���ͺ���ģ�壬ֻ�ܽ���AA��Ķ��󡣵�һ����������ģ��ǰ������

template <typename T1, typename T2>
class AA {
private:
    T1 m_x;
    T2 m_y;
public:
    AA(T1 x, T2 y) : m_x(x), m_y(y) {}
    friend void show<>(AA<T1, T2> &a);//�ڶ���������ģ��������Ϊ��Ԫ������ע�⣺<>����ʡ��
};
template <typename T>
void show(T &a) {   //������������ģ����涨��
    cout << "ͨ��ģ��show():" << a.m_x << "  " << a.m_y << endl;
}
template <>
void show(AA<char, string> &a) {    //���廯�汾
    cout << "AA���廯ģ��show():" << a.m_x << "  " << a.m_y << endl;
}
//--------------------------------------------
template <typename T1, typename T2>
class BB {
private:
    T1 m_x;
    T2 m_y;
public:
    BB(T1 x, T2 y) : m_x(x), m_y(y) {}
    friend void show<>(BB<T1, T2> &a);//�ڶ���������ģ��������Ϊ��Ԫ������ע�⣺<>����ʡ��
};
template <>
void show(BB<char, string> &a) {    //���廯�汾
    cout << "BB���廯ģ��show():" << a.m_x << "  " << a.m_y << endl;
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