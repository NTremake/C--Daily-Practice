#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
	string m_name;
	Person() { cout << "Person()默认构造" << endl; }
	Person(const string& name) {
		this->m_name = name;
		cout << "Person()有参构造" << this->m_name << endl;
	}
	~Person() { cout << "~Person()析构" << this->m_name << endl; }
};
void func1(const Person* p) {
	cout << p->m_name << endl;
}
void func2(Person* p) {
	cout << p->m_name << endl;
	delete p;
}
void func3(const unique_ptr<Person>& p) {
	cout << p->m_name << endl;
}
void func4(unique_ptr<Person> p) {
	cout << p->m_name << endl;
}// unique_ptr的一些要点，智能指针也具有多态性
int main() {
	unique_ptr<Person> up1(new Person("孙悟空"));
	//func1(up1.get());// get()返回原始指针, 但是不会释放资源
	//func2(up1.release());// release()返回原始指针, 并释放资源
	//func3(up1);// 传递引用, 不会释放资源
	//func4(move(up1));// 传递右值引用, 会释放资源
	up1.reset(new Person("猪八戒"));// 释放旧资源, 重新指向新资源
	unique_ptr<Person> up2(new Person("沙和尚"));
	up1.swap(up2);// 交换资源
	unique_ptr<Person[]> uparr3(new Person[2]{ string("张三"), string("李四") });// 智能指针也可以指向数组
	cout << uparr3[0].m_name << endl;
	cout << uparr3[1].m_name << endl;
	//system("pause");
	return 0;
	//exit(0);// exit推出时，局部的智能指针无法释放，全局的智能指针可以释放，所以unique_ptr不是绝对安全的
}