#include <iostream>
using namespace std;

string Function() {
    return "Hello World!";
}
void Print(int a, short b, double c, string d) {
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;
}//��Ҫ����auto���ή�ʹ���Ŀɶ���
int main() {
    auto a = 10 + 1;
    cout << "a=" << a << endl;
    auto b = 1.2;
    cout << "b=" << b << endl;
    auto c = "Hello World!";
    cout << "c=" << c << endl;
    auto d = Function();
    cout << "d=" << d << endl;
    void (*p1)(int, short, double, string) = Print;
    p1(1, 2, 3.3, "Hello World!");
    auto p2 = Print;//ʹ��auto���Լ򻯺���ָ����������������
    p2(11, 22, 33.3, "Hello World!");
    system("pause");
    return 0;
}