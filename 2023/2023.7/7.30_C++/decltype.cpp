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
    cout << "Func�����ĵ���" << endl;
    return 1;
}//auto��decltype�����Ƶ��������ķ���ֵ����
int main() {
    //auto d = Func();//auto�Ƶ����ͣ�����ú���
    //decltype(Func) a;//decltype�Ƶ����ͣ�������ú���
    decltype((Func)) a = Func;//�������ţ�������������
    a();
    cout << "a + b = " << Add(1, 2.5) << endl;
    system("pause");
    return 0;
}