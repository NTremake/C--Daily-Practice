#include <iostream>
using namespace std;

//����ֵ������void*����������size_t
void* operator new(size_t size) {
    cout << "new�����أ�" << size << "�ֽڡ�" << endl;
    void* ptr = malloc(size);
    cout << "���뵽���ڴ��ַΪ��" << ptr << endl;
    return ptr;
}
//��������void*
void operator delete(void* ptr) {
    cout << "delete�����ء�\n";
    if(ptr == nullptr)
        return;
    free(ptr);
}
class Girl {
public:
    string name;
    int age;
    Girl(string name, int age) {
        this->name = name;
        this->age = age;
        cout << "Girl�Ĺ��캯����" << endl;
    }
    ~Girl() {
        cout << "Girl������������" << endl;
    }
};
//ʹ��c���Ե�malloc��free����new��delete
int main() {
    // int* p = new int(10);
    // cout << "�ڴ��ַ��" << (void *)p << endl;
    // cout << "ֵ��" << *p << endl;
    // delete p;
    Girl* p1 = new Girl("С��", 18);
    cout << "�ڴ��ַ��" << (void *)p1 << endl;
    cout << "������" << p1->name << "���䣺"<< p1->age << endl;
    delete p1;
    system("pause");
    return 0;
}