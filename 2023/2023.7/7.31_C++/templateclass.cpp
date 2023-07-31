#include <iostream>
using namespace std;

template<class T1,class T2>
class AA
{
public:
    AA() {}
    AA(T1 a, T2 b) : m_a(a), m_b(b){}
    T1 geta() {
        T1 a = 1;
        return m_a + a;
    }
    T2 getb();
    // T2 getb() {
    //     return m_b;
    // }
    T1 m_a;
    T2 m_b;
};
template<class T1, class T2>
T2 AA<T1, T2>::getb() {
    return m_b;
}//类外定义模板类的成员函数
int main() {
    //AA<int, string> aa(1, "hello");
    AA<int, string> *bb;//没有创建对象，只是定义了一个指针，就不会调用构造函数
    AA<int, string> *aa = new AA<int, string>(1, "hello");//可以用new来创建模板类的对象
    cout << "a = " << aa->geta() << endl;
    cout << "b = " << aa->getb() << endl;
    delete aa;
    system("pause");
    return 0;
}