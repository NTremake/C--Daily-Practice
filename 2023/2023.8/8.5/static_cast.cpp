#include <iostream>
using namespace std;

//A����ָ��->ת����void*->ת����B����ָ��
//����dynamic_cast��const_cast��reinterpret_cast
int main() {
    int a = 1;
    void *p1 = &a;
    long *p2 = static_cast<long *>(p1);
    cout << *p2 << endl;
    system("pause");
    return 0;
}