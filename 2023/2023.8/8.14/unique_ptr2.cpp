#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
	//int m_count;
	string m_name;
	Person() {
	cout << "Person()Ĭ�Ϲ���" << endl;
	}
	Person(const string& name) {
		this->m_name = name;
		cout << "Person()����(" << this->m_name << ")" << endl;
	}
	~Person() {
		cout << "~Person()����(" << this->m_name << ")" << endl;
	}
};
unique_ptr<Person> func1() {
	unique_ptr<Person> p1(new Person("��ʩ3"));
	return p1;
}// unique_ptr����֪ʶ
int main() {
	unique_ptr<Person> up1(new Person("��ʩ1"));
	unique_ptr<Person> up2;
	up2 = unique_ptr<Person>(new Person("��ʩ2"));
	cout << "func1()����ǰ" << endl;
	up2 = func1();
	cout << "func1()���ú�" << endl;
	unique_ptr<Person> up3(new Person("����"));
	if (up3) {
		cout << "up3��Ϊ��" << endl;
	}
	up3 = nullptr;
	if (!up3) {
		cout << "up3Ϊ��" << endl;
	}
}
