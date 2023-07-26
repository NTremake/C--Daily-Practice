#include <iostream>
using namespace std;
#include <cstring>

union uData {
    int a;
    double b;
    char c[25];
};//共同体
int main() {
    uData data;
    //共同体的大小是其最大成员的大小，这里char[25]是最大的，所以内存对齐后为32。
    cout << sizeof(data) << endl;

    //共同体的值为最后一个赋值的成员的值。这里是char[25]最后被赋值，所以输出hello world。
    data.a = 10;
    data.b = 20.5;
    strcpy(data.c, "hello world");//<cstring>
    cout << data.a << endl;
    cout << data.b << endl;
    cout << data.c << endl;
    system("pause");
    return 0;
}