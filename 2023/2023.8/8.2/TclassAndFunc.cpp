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
{   //普通函数版本
    a.Print();
    cout << "Func()函数的调用" << endl;
    return a;
}
template <typename T1, typename T2>
AA<T1, T2> Func(AA<T1, T2> &a) 
{   //函数模板版本
    a.Print();
    cout << "Func()模板函数的调用" << endl;
    return a;
}
template <typename T>
T Func(T &a) 
{   //函数模板，返回值和参数可以是任意类型。这种模板更规范和通用
    a.Print();
    cout << "Func()T模板函数的调用" << endl;
    return a;
}
int main() {
    AA<char, string> a('1', "hello");
    Func(a);//会优先调用AA类模板函数
    BB b;
    Func(b);//调用通用模板函数
    system("pause");
    return 0;
}