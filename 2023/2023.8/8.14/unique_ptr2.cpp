#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
	//int m_count;
	string m_name;
	Person() {
	cout << "Person()默认构造" << endl;
	}
	Person(const string& name) {
		this->m_name = name;
		cout << "Person()构造(" << this->m_name << ")" << endl;
	}
	~Person() {
		cout << "~Person()析构(" << this->m_name << ")" << endl;
	}
};
unique_ptr<Person> func1() {
	unique_ptr<Person> p1(new Person("西施3"));
	return p1;
}// unique_ptr进阶知识
int main() {
	unique_ptr<Person> up1(new Person("西施1"));
	unique_ptr<Person> up2;
	up2 = unique_ptr<Person>(new Person("西施2"));
	cout << "func1()调用前" << endl;
	up2 = func1();
	cout << "func1()调用后" << endl;
	unique_ptr<Person> up3(new Person("张三"));
	if (up3) {
		cout << "up3不为空" << endl;
	}
	up3 = nullptr;
	if (!up3) {
		cout << "up3为空" << endl;
	}
}
