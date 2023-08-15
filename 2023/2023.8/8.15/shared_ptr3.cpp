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
struct deleteClass {
	void operator()(Person* p) {
		cout << "�º���ɾ����" << endl;
		delete p;
	}
};
void deleteShared(Person* p) {
	cout << "�Զ���ɾ����" << endl;
	delete p;
}
int main() {
	//shared_ptr<Person> sp1(new Person("����"), deleteShared);// �ڶ����������Զ���ɾ����
	//shared_ptr<Person> sp2(new Person("����"), deleteClass());// �ڶ��������Ƿº���ɾ����

	//unique_ptr<Person, decltype(deleteShared)*> up1(new Person("����"), deleteShared);
	//unique_ptr<Person, void(*)(Person*)> up2(new Person("����"), deleteShared);// unique_ptr���Զ���ɾ�����Ƚ��鷳
	unique_ptr<Person, deleteClass> up3(new Person("����"), deleteClass());
}