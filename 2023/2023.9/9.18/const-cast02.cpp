#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int &b = a;
    //���const
    const int &c = const_cast<const int &>(b);//const_cast������ӻ�ȥ��ָ������õ�const����
    cout << c << endl;
    cout << a << endl;
    cout << b << endl;
    //��ȥconst
    int &d = const_cast<int &>(b);
    d = 10;
    cout << a << endl;
    cout << d << endl;
    system("pause");
    return 0;
}
//����reinterpret_cast��ǿ��ת�����ͣ����á�