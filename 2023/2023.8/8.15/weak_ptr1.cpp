#include <iostream>
#include <memory>
using namespace std;

class BB;
class AA {
public:
	string m_name;
	AA() {
		cout << "AA()默认构造" << endl;
	}
	AA(const string name) :m_name(name) {
		cout << "AA()有参构造" << this->m_name << endl;
	}
	AA(const string name, const weak_ptr<BB>& wb) :m_name(name), m_b(wb) {
		cout << "AA()有参构造" << this->m_name << endl;
	}
	~AA() {
		cout << "~AA()析构" << this->m_name << endl;
	}
	weak_ptr<BB> m_b;
};
class BB {
public:
	string m_name;
	BB() {
		cout << "BB()默认构造" << endl;
	}
	BB(const string& name) :m_name(name) {
		cout << "BB()有参构造" << this->m_name << endl;
	}
	BB(const string& name, const weak_ptr<AA>& wa) :m_name(name), m_a(wa) {
		cout << "BB()有参构造" << this->m_name << endl;
	}
	~BB() {
		cout << "~BB()析构" << this->m_name << endl;
	}
	weak_ptr<AA> m_a;// weak_ptr是弱引用，不会增加引用计数。当AA对象被释放时，m_a会自动置空
};
int main() {
	shared_ptr<AA> spa = make_shared<AA>("张三");
	shared_ptr<BB> spb = make_shared<BB>("李四");
	cout << "spa.use_count() = " << spa.use_count() << endl;
	cout << "spb.use_count() = " << spb.use_count() << endl;
	spa->m_b = spb;
	spb->m_a = spa;
	cout << "spa.use_count() = " << spa.use_count() << endl;
	cout << "spb.use_count() = " << spb.use_count() << endl;
	if(spa->m_b.lock())// 判断弱引用是否有效,lock()返回一个shared_ptr
		cout << "spa->m_b.lock()有效" << endl;
	else
		cout << "spa->m_b.lock()无效" << endl;
	if(spa->m_b.expired())// 判断弱引用是否无效
		cout << "spa->m_b.expired()被销毁" << endl;
	else
		cout << "spa->m_b.expired()未被销毁" << endl;
}