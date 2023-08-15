#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
	string m_name;
	Person() {
		cout << "Person()默认构造" << endl;
	}
	Person(const string& name) :m_name(name) {
		cout << "Person()有参构造" << this->m_name << endl;
	}
	~Person() {
		cout << "~Person()析构" << this->m_name << endl;
	}
};
int main() {
	//shared_ptr<Person> sp1(new Person("张三"));// 1
	//shared_ptr<Person> sp1 = make_shared<Person>("张三");// 推荐2。c++11
	Person* p1 = new Person("张三");// 3
	shared_ptr<Person> sp1(p1);
	shared_ptr<Person> sp2(sp1);// 4,引用计数+1
	shared_ptr<Person> sp3 = sp2;// 4,引用计数+1

	cout << "sp1.use_count() = " << sp1.use_count() << endl;
	cout <<"sp1.name = "<< sp1->m_name << endl;
	cout << "sp1地址" << sp1.get() << endl;

	cout << "sp2.use_count() = " << sp2.use_count() << endl;
	cout << "sp2.name = " << sp2->m_name << endl;
	cout << "sp2地址" << sp2.get() << endl;

	cout << "sp3.use_count() = " << sp3.use_count() << endl;
	cout << "sp3.name = " << sp3->m_name << endl;
	cout << "sp3地址" << sp3.get() << endl;

	if(sp1.unique())// 判断引用计数是否为1
		cout << "sp1是唯一的" << endl;
	else
		cout << "sp1不是唯一的" << endl;
}