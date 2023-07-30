#include <iostream>
using namespace std;
#include <typeinfo>

template<typename T1, typename T2>
// auto Add(T1 a, T2 b) -> decltype(a + b) {
//     return a + b;
// }
auto Add(T1 a, T2 b) {
    decltype(a + b) c = a + b;
    return c;
}
int Func() {
    cout << "Func函数的调用" << endl;
    return 1;
}//auto和decltype都能推导出函数的返回值类型
int main() {
    //auto d = Func();//auto推导类型，会调用函数
    //decltype(Func) a;//decltype推导类型，不会调用函数
    decltype((Func)) a = Func;//加上括号，就是引用类型
    a();
    cout << "a + b = " << Add(1, 2.5) << endl;
    system("pause");
    return 0;
}