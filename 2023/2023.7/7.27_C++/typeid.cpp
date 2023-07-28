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
    if(typeid(AA) == typeid(aa)) cout << "������ͬ" << endl;
    if(typeid(AA *) == typeid(paa)) cout << "������ͬ" << endl;
    if(typeid(AA) == typeid(raa)) cout << "������ͬ" << endl;
} // typeid�����������һ��type_info���󣬰����˱���ѯ�����������Ϣ;�ڲ�������==��!=����������������Ƚ�����type_info�����Ƿ���ȡ�
//��Ҫ���ڶ�̬���͵��жϣ����縸��ָ��ָ��������󣬿�����typeid���ж�ָ��ָ��Ķ�������͡�
int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}