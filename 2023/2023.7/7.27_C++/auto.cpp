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
}//不要滥用auto，会降低代码的可读性
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
    auto p2 = Print;//使用auto可以简化函数指针的声明，这个有用
    p2(11, 22, 33.3, "Hello World!");
    system("pause");
    return 0;
}