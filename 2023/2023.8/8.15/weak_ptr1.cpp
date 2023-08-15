#include <iostream>
#include <memory>
using namespace std;

class BB;
class AA {
public:
	string m_name;
	AA() {
		cout << "AA()Ĭ�Ϲ���" << endl;
	}
	AA(const string name) :m_name(name) {
		cout << "AA()�вι���" << this->m_name << endl;
	}
	AA(const string name, const weak_ptr<BB>& wb) :m_name(name), m_b(wb) {
		cout << "AA()�вι���" << this->m_name << endl;
	}
	~AA() {
		cout << "~AA()����" << this->m_name << endl;
	}
	weak_ptr<BB> m_b;
};
class BB {
public:
	string m_name;
	BB() {
		cout << "BB()Ĭ�Ϲ���" << endl;
	}
	BB(const string& name) :m_name(name) {
		cout << "BB()�вι���" << this->m_name << endl;
	}
	BB(const string& name, const weak_ptr<AA>& wa) :m_name(name), m_a(wa) {
		cout << "BB()�вι���" << this->m_name << endl;
	}
	~BB() {
		cout << "~BB()����" << this->m_name << endl;
	}
	weak_ptr<AA> m_a;// weak_ptr�������ã������������ü�������AA�����ͷ�ʱ��m_a���Զ��ÿ�
};
int main() {
	shared_ptr<AA> spa = make_shared<AA>("����");
	shared_ptr<BB> spb = make_shared<BB>("����");
	cout << "spa.use_count() = " << spa.use_count() << endl;
	cout << "spb.use_count() = " << spb.use_count() << endl;
	spa->m_b = spb;
	spb->m_a = spa;
	cout << "spa.use_count() = " << spa.use_count() << endl;
	cout << "spb.use_count() = " << spb.use_count() << endl;
	if(spa->m_b.lock())// �ж��������Ƿ���Ч,lock()����һ��shared_ptr
		cout << "spa->m_b.lock()��Ч" << endl;
	else
		cout << "spa->m_b.lock()��Ч" << endl;
	if(spa->m_b.expired())// �ж��������Ƿ���Ч
		cout << "spa->m_b.expired()������" << endl;
	else
		cout << "spa->m_b.expired()δ������" << endl;
}