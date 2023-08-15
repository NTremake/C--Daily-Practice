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
struct deleteClass {
	void operator()(Person* p) {
		cout << "仿函数删除器" << endl;
		delete p;
	}
};
void deleteShared(Person* p) {
	cout << "自定义删除器" << endl;
	delete p;
}
int main() {
	//shared_ptr<Person> sp1(new Person("张三"), deleteShared);// 第二个参数是自定义删除器
	//shared_ptr<Person> sp2(new Person("李四"), deleteClass());// 第二个参数是仿函数删除器

	//unique_ptr<Person, decltype(deleteShared)*> up1(new Person("张三"), deleteShared);
	//unique_ptr<Person, void(*)(Person*)> up2(new Person("李四"), deleteShared);// unique_ptr的自定义删除器比较麻烦
	unique_ptr<Person, deleteClass> up3(new Person("王五"), deleteClass());
}