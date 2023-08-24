#include <iostream>
using namespace std;

class AA {
public:
	int* m_data = nullptr;
	AA() = default;
	void alloc() {
		this->m_data = new int;
		memset(this->m_data, 0, sizeof(int));
	}
	AA(const AA& other) {
		cout << "调用了拷贝构造函数" << endl;
		if (this->m_data == nullptr) {
			this->alloc();
			memcpy(this->m_data, other.m_data, sizeof(int));
		}
	}
	AA(AA&& other) {
		cout << "调用了移动构造函数" << endl;
		if (this->m_data != nullptr) {
			delete this->m_data;
		}
		this->m_data = other.m_data;
		other.m_data = nullptr;
	}
	AA& operator=(const AA& other) {
		cout << "调用了赋值运算符" << endl;
		if (this == &other) {
			return *this;
		}
		if (this->m_data == nullptr) {
			this->alloc();
			memcpy(this->m_data, other.m_data, sizeof(int));
		}
		return *this;
	}
	AA& operator=(AA&& other) {
		cout << "调用了移动赋值运算符" << endl;
		if (this == &other) {
			return *this;
		}
		if (this->m_data != nullptr) {
			delete this->m_data;
		}
		this->m_data = other.m_data;
		other.m_data = nullptr;
		return *this;
	}
	~AA() {
		if (this->m_data != nullptr) {
			delete this->m_data;
			this->m_data = nullptr;
		}
	}
};
int main() {
	AA a1;
	a1.alloc();
	*a1.m_data = 3;
	cout << "*a1.m_data = " << *a1.m_data << endl;

	AA a2 = a1;// 调用拷贝构造函数
	cout << "*a2.m_data = " << *a2.m_data << endl;

	AA a3;
	a3 = a1;// 调用赋值运算符
	cout << "*a3.m_data = " << *a3.m_data << endl;

	auto func1 = [] {
		AA aa;
		aa.alloc();
		*aa.m_data = 5;
		return move(aa);
	};
	AA a4 = func1();// 调用移动构造函数
	cout << "*a4.m_data = " << *a4.m_data << endl;

	AA a5;
	a5 = func1();// 调用移动赋值运算符
	cout << "*a5.m_data = " << *a5.m_data << endl;
}