#include <iostream>
#include <map>
using namespace std;

class Person {
public:
    Person () {}
    Person(string name, int age) : m_name(name), m_age(age) {
        cout << "构造函数" << endl;
    }
    Person(const Person& p) : m_name(p.m_name), m_age(p.m_age) {
        cout << "拷贝构造函数" << endl;
    }
    string m_name;
    int m_age;
};//map容器内部是按照二叉树（红黑树）存储的，所以插入的元素是有序的
int main() {
    map<int, string> m{{1, "一号"}};
    pair<map<int, string>::iterator, bool> ret = m.insert(pair<int, string>(2, "二号"));
    //auto ret = m.emplace(2, "二号");//insert()返回值为pair<iterator, bool>；emplace的参数分段构造，效率更高
    if(ret.second == true) {
        cout << "插入的值为：" << ret.first->first << ", " << ret.first->second << endl;
    }
    Person p1;
    map<int, Person> m2;
    //m2.insert(pair<int, Person>(1, Person("张三", 18)));//调用了两次拷贝构造函数
    //m2.emplace(1, Person("张三", 18));//调用了一次拷贝构造函数
    m2.emplace(piecewise_construct, forward_as_tuple(1), forward_as_tuple("张三", 18));//没有调用拷贝构造函数
    m2.emplace_hint(m2.begin(), piecewise_construct, forward_as_tuple(2), forward_as_tuple("李四", 19));//第一个元素为提示位置
    //key为2应该在右边，虽然提示错误，但任然插入到了右边。提示位置是为了增加效率
    cout << m2[2].m_name << ", " << m2[2].m_age << endl;
    for(auto &val:m2) { //相当于(int i = 0; i < m2.size(); i++)
        cout << val.first << ", " << val.second.m_name << ", " << val.second.m_age << endl;
    }
    system("pause");
    return 0;
}