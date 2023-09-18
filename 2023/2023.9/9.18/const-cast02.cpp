#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int &b = a;
    //添加const
    const int &c = const_cast<const int &>(b);//const_cast可以添加或去除指针或引用的const属性
    cout << c << endl;
    cout << a << endl;
    cout << b << endl;
    //除去const
    int &d = const_cast<int &>(b);
    d = 10;
    cout << a << endl;
    cout << d << endl;
    system("pause");
    return 0;
}
//还有reinterpret_cast，强制转换类型，慎用。