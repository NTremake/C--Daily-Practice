#include <iostream>
using namespace std;

template <typename T>
class Person
{
public:
    template <typename U>
    friend ostream& operator<<(ostream& os, const Person<U>& p);
    template <typename F>
    friend void PrintData(const Person<F>& p);
    Person(T name, T age) 
    {
        this->_Name = name;
        this->_Age = age;
    }

private:
    T _Name;
    T _Age;
};
template <typename U>
ostream& operator<<(ostream& os, const Person<U>& p)
{
    os << "������" << p._Name << "  ���䣺" << p._Age;
    return os;
}
template <typename F>
void PrintData(const Person<F>& p)
{
    cout << "������" << p._Name << "  ���䣺" << p._Age << endl;
}//����ʵ����Ԫ����ģ��
int main()
{
    Person<string> p1("����", "20");
    cout << p1 << endl;
    PrintData(p1);
    system("pause");
    return 0;
}