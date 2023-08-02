#include <iostream>
using namespace std;

template <class T1, class T2>
class AA {
public:
    T1 m_x;
    T2 m_y;
    AA(const T1 x, const T2 y) : m_x(x), m_y(y) {}
    void Print() {
        cout << "Print():" << m_x << "  " << m_y << endl;
    }
};
class BB {
public:
void Print() {cout << "BB::show()" << endl;}
};
AA<int, string> Func(AA<int, string> &a) 
{   //��ͨ�����汾
    a.Print();
    cout << "Func()�����ĵ���" << endl;
    return a;
}
template <typename T1, typename T2>
AA<T1, T2> Func(AA<T1, T2> &a) 
{   //����ģ��汾
    a.Print();
    cout << "Func()ģ�庯���ĵ���" << endl;
    return a;
}
template <typename T>
T Func(T &a) 
{   //����ģ�壬����ֵ�Ͳ����������������͡�����ģ����淶��ͨ��
    a.Print();
    cout << "Func()Tģ�庯���ĵ���" << endl;
    return a;
}
int main() {
    AA<char, string> a('1', "hello");
    Func(a);//�����ȵ���AA��ģ�庯��
    BB b;
    Func(b);//����ͨ��ģ�庯��
    system("pause");
    return 0;
}