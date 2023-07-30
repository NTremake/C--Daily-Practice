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
}//ģ��һ��д��ͷ�ļ������廯ģ��һ��д��Դ�ļ�
template<> //����ģ����ػ���
void Swap<Person>(Person &a, Person &b) {
    string temp_name = a.m_name;
    a.m_name = b.m_name;
    b.m_name = temp_name;
    int temp_age = a.m_age;
    a.m_age = b.m_age;
    b.m_age = temp_age;
}
int main() {
    Person p1("С��", 18);
    Person p2("С��", 19);
    cout << "����ǰ��" << endl;
    cout << "p1��������" << p1.m_name << "  ���䣺" << p1.m_age << endl;
    cout << "p2��������" << p2.m_name << "  ���䣺" << p2.m_age << endl;
    Swap(p1, p2);
    cout << "������" << endl;
    cout << "p1��������" << p1.m_name << "  ���䣺" << p1.m_age << endl;
    cout << "p2��������" << p2.m_name << "  ���䣺" << p2.m_age << endl;
    system("pause");
    return 0;
}