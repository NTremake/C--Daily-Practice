#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
	string m_name;
	Person() {
		cout << "Person()Ĭ�Ϲ���" << endl;
	}
	Person(const string& name) :m_name(name) {
		cout << "Person()�вι���" << this->m_name << endl;
	}
	~Person() {
		cout << "~Person()����" << this->m_name << endl;
	}
};
int main() {
	//shared_ptr<Person> sp1(new Person("����"));// 1
	//shared_ptr<Person> sp1 = make_shared<Person>("����");// �Ƽ�2��c++11
	Person* p1 = new Person("����");// 3
	shared_ptr<Person> sp1(p1);
	shared_ptr<Person> sp2(sp1);// 4,���ü���+1
	shared_ptr<Person> sp3 = sp2;// 4,���ü���+1

	cout << "sp1.use_count() = " << sp1.use_count() << endl;
	cout <<"sp1.name = "<< sp1->m_name << endl;
	cout << "sp1��ַ" << sp1.get() << endl;

	cout << "sp2.use_count() = " << sp2.use_count() << endl;
	cout << "sp2.name = " << sp2->m_name << endl;
	cout << "sp2��ַ" << sp2.get() << endl;

	cout << "sp3.use_count() = " << sp3.use_count() << endl;
	cout << "sp3.name = " << sp3->m_name << endl;
	cout << "sp3��ַ" << sp3.get() << endl;

	if(sp1.unique())// �ж����ü����Ƿ�Ϊ1
		cout << "sp1��Ψһ��" << endl;
	else
		cout << "sp1����Ψһ��" << endl;
}