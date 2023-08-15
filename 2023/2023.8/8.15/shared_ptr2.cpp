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
	shared_ptr<Person> sp1(new Person("����"));
	shared_ptr<Person> sp2(sp1);
	shared_ptr<Person> sp3(sp1);
	cout << "sp1.use_count() = " << sp1.use_count() << endl;

	shared_ptr<Person> spp1(new Person("����"));
	shared_ptr<Person> spp2(spp1);
	cout << "spp1.use_count() = " << spp1.use_count() << endl;

	spp2 = sp1;// 1.��sp1�����ü���+1��2.��spp1�����ü���-1��3.��spp1ָ��sp1���ڴ�ռ�
	spp1 = sp1;// ����spp1����Ϊ0���������ġ�����sp1����Ϊ5
	cout << "sp1.use_count() = " << sp1.use_count() << endl;

}