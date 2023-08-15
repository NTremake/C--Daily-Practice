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
	shared_ptr<Person> sp1(new Person("张三"));
	shared_ptr<Person> sp2(sp1);
	shared_ptr<Person> sp3(sp1);
	cout << "sp1.use_count() = " << sp1.use_count() << endl;

	shared_ptr<Person> spp1(new Person("李四"));
	shared_ptr<Person> spp2(spp1);
	cout << "spp1.use_count() = " << spp1.use_count() << endl;

	spp2 = sp1;// 1.将sp1的引用计数+1，2.将spp1的引用计数-1，3.将spp1指向sp1的内存空间
	spp1 = sp1;// 李四spp1引用为0，析构李四。张三sp1引用为5
	cout << "sp1.use_count() = " << sp1.use_count() << endl;

}