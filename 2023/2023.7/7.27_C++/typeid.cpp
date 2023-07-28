#include <iostream>
using namespace std;
#include <typeinfo>

class AA {
public:
    AA() {};
};
void test01() {
    int ii = 3;
    int *pii = &ii;
    int &rii = ii;
    cout << "typeid(int)=" << typeid(int).name() << endl;
    cout << "typeid(ii)=" << typeid(ii).name() << endl;
    cout << "typeid(int *)=" << typeid(int *).name() << endl;
    cout << "typeid(pii)=" << typeid(pii).name() << endl;
    cout << "typeid(int &)=" << typeid(int &).name() << endl;
    cout << "typeid(rii)=" << typeid(rii).name() << endl;
}
void test02() {
    AA aa;
    AA *paa = &aa;
    AA &raa = aa;
    cout << "typeid(AA)=" << typeid(AA).name() << endl;
    cout << "typeid(aa)=" << typeid(aa).name() << endl;
    cout << "typeid(AA *)=" << typeid(AA *).name() << endl;
    cout << "typeid(paa)=" << typeid(paa).name() << endl;
    cout << "typeid(AA &)=" << typeid(AA &).name() << endl;
    cout << "typeid(raa)=" << typeid(raa).name() << endl;
    if(typeid(AA) == typeid(aa)) cout << "类型相同" << endl;
    if(typeid(AA *) == typeid(paa)) cout << "类型相同" << endl;
    if(typeid(AA) == typeid(raa)) cout << "类型相同" << endl;
} // typeid运算符，返回一个type_info对象，包含了被查询对象的类型信息;内部重载了==和!=运算符，可以用来比较两个type_info对象是否相等。
//主要用于多态类型的判断，比如父类指针指向子类对象，可以用typeid来判断指针指向的对象的类型。
int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}