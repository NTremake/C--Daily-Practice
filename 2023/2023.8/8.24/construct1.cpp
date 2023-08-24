#include <iostream>
using namespace std;

class AA {
public:
	AA() {
		cout << "AA()" << endl;
	}
	AA(float a) : m_a(a) {
		this->m_a = a;
		cout << "AA(float a)  " << this->m_a << endl;
	}
	AA(int b, int c) {
		this->m_b = b;
		this->m_c = c;
		cout << "AA(int b, int c)  " << this->m_b << "  " << this->m_c << endl;
	}
	AA(int b, int c, const string& d) : AA(b, c) {
		this->m_d = d;
		cout << "AA(int b, int c, string d)  " << this->m_b << "  " << this->m_c << "  " << this->m_d << endl;
	}// 委托构造函数, 用来初始化成员变量,减少重复代码
	AA(float a, const string& d) : AA(a) {
		this->m_d = d;
		cout << "AA(float a, string d)  " << this->m_a << "  " << this->m_d << endl;
	}
	float m_a = 0;
	int m_b = 0;
	int m_c = 0;
	string m_d = "0";
};
int main() {
	AA a1{ 1, 2, "hello" };
	AA a2{ 1.1, "hello" };
}