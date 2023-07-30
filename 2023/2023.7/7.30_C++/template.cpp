#include <iostream>
using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};
template<typename T> 
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}//模板一般写在头文件，具体化模板一般写在源文件
template<> //函数模板的特化。
void Swap<Person>(Person &a, Person &b) {
    string temp_name = a.m_name;
    a.m_name = b.m_name;
    b.m_name = temp_name;
    int temp_age = a.m_age;
    a.m_age = b.m_age;
    b.m_age = temp_age;
}
int main() {
    Person p1("小明", 18);
    Person p2("小红", 19);
    cout << "交换前：" << endl;
    cout << "p1的姓名：" << p1.m_name << "  年龄：" << p1.m_age << endl;
    cout << "p2的姓名：" << p2.m_name << "  年龄：" << p2.m_age << endl;
    Swap(p1, p2);
    cout << "交换后：" << endl;
    cout << "p1的姓名：" << p1.m_name << "  年龄：" << p1.m_age << endl;
    cout << "p2的姓名：" << p2.m_name << "  年龄：" << p2.m_age << endl;
    system("pause");
    return 0;
}