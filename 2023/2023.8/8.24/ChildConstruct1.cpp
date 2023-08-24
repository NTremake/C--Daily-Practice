#include <iostream>
using namespace std;

class AA {
public:
	AA(int x) : m_x(x), m_y(0) {
		cout << "AA(int x)  " << this->m_x << endl;
	}
	AA(int x, int y) : AA(x) {
		this->m_y = y;
		cout << "AA(int x, int y)  " << this->m_x << "  " << this->m_y << endl;
	}
	int m_x;
	int m_y;
};
class BB : public AA
{
public:
	//using AA::AA;
	// ¼Ì³Ð¹¹Ôìº¯Êý
	BB(int a, int b, int c) : AA(a, b) {
		this->m_z = c;
		cout << "BB(int a, int b, int c)  " << this->m_x << "  " << this->m_y << "  " << this->m_z << endl;
	}
	int m_z;
};
int main() {
	AA a1{ 1 };
	AA a2{ 1, 2 };
	BB b1{ 1, 2, 3 };
}