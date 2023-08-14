#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
	string m_name;
	Person() { cout << "Person()Ĭ�Ϲ���" << endl; }
	Person(const string& name) {
		this->m_name = name;
		cout << "Person()�вι���" << this->m_name << endl;
	}
	~Person() { cout << "~Person()����" << this->m_name << endl; }
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
}// unique_ptr��һЩҪ�㣬����ָ��Ҳ���ж�̬��
int main() {
	unique_ptr<Person> up1(new Person("�����"));
	//func1(up1.get());// get()����ԭʼָ��, ���ǲ����ͷ���Դ
	//func2(up1.release());// release()����ԭʼָ��, ���ͷ���Դ
	//func3(up1);// ��������, �����ͷ���Դ
	//func4(move(up1));// ������ֵ����, ���ͷ���Դ
	up1.reset(new Person("��˽�"));// �ͷž���Դ, ����ָ������Դ
	unique_ptr<Person> up2(new Person("ɳ����"));
	up1.swap(up2);// ������Դ
	unique_ptr<Person[]> uparr3(new Person[2]{ string("����"), string("����") });// ����ָ��Ҳ����ָ������
	cout << uparr3[0].m_name << endl;
	cout << uparr3[1].m_name << endl;
	//system("pause");
	return 0;
	//exit(0);// exit�Ƴ�ʱ���ֲ�������ָ���޷��ͷţ�ȫ�ֵ�����ָ������ͷţ�����unique_ptr���Ǿ��԰�ȫ��
}