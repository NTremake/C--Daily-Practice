#include <iostream>
#include <map>
using namespace std;

class Person {
public:
    Person () {}
    Person(string name, int age) : m_name(name), m_age(age) {
        cout << "���캯��" << endl;
    }
    Person(const Person& p) : m_name(p.m_name), m_age(p.m_age) {
        cout << "�������캯��" << endl;
    }
    string m_name;
    int m_age;
};//map�����ڲ��ǰ��ն���������������洢�ģ����Բ����Ԫ���������
int main() {
    map<int, string> m{{1, "һ��"}};
    pair<map<int, string>::iterator, bool> ret = m.insert(pair<int, string>(2, "����"));
    //auto ret = m.emplace(2, "����");//insert()����ֵΪpair<iterator, bool>��emplace�Ĳ����ֶι��죬Ч�ʸ���
    if(ret.second == true) {
        cout << "�����ֵΪ��" << ret.first->first << ", " << ret.first->second << endl;
    }
    Person p1;
    map<int, Person> m2;
    //m2.insert(pair<int, Person>(1, Person("����", 18)));//���������ο������캯��
    //m2.emplace(1, Person("����", 18));//������һ�ο������캯��
    m2.emplace(piecewise_construct, forward_as_tuple(1), forward_as_tuple("����", 18));//û�е��ÿ������캯��
    m2.emplace_hint(m2.begin(), piecewise_construct, forward_as_tuple(2), forward_as_tuple("����", 19));//��һ��Ԫ��Ϊ��ʾλ��
    //keyΪ2Ӧ�����ұߣ���Ȼ��ʾ���󣬵���Ȼ���뵽���ұߡ���ʾλ����Ϊ������Ч��
    cout << m2[2].m_name << ", " << m2[2].m_age << endl;
    for(auto &val:m2) { //�൱��(int i = 0; i < m2.size(); i++)
        cout << val.first << ", " << val.second.m_name << ", " << val.second.m_age << endl;
    }
    system("pause");
    return 0;
}