#include <iostream>
using namespace std;
#include <cstring>

union uData {
    int a;
    double b;
    char c[25];
};//��ͬ��
int main() {
    uData data;
    //��ͬ��Ĵ�С��������Ա�Ĵ�С������char[25]�����ģ������ڴ�����Ϊ32��
    cout << sizeof(data) << endl;

    //��ͬ���ֵΪ���һ����ֵ�ĳ�Ա��ֵ��������char[25]��󱻸�ֵ���������hello world��
    data.a = 10;
    data.b = 20.5;
    strcpy(data.c, "hello world");//<cstring>
    cout << data.a << endl;
    cout << data.b << endl;
    cout << data.c << endl;
    system("pause");
    return 0;
}