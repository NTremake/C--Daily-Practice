#include <iostream>
using namespace std;

//A类型指针->转换成void*->转换成B类型指针
//还有dynamic_cast、const_cast、reinterpret_cast
int main() {
    int a = 1;
    void *p1 = &a;
    long *p2 = static_cast<long *>(p1);
    cout << *p2 << endl;
    system("pause");
    return 0;
}