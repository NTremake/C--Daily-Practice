#include <iostream>
using namespace std;

class MyException {
public:
    MyException() {
        cout << "���캯��" << endl;
    }
    MyException(const MyException& e) {
        cout << "�������캯��" << endl;
    }
    ~MyException() {
        cout << "��������" << endl;
    }
};//�쳣����������ڣ�ָ�������Ƚ�����
int main() {
    try {
        throw new MyException();
    }
    catch(MyException* e) {
        cout << "�쳣����" << endl;
        delete e;
        e = nullptr;
    }
    system("pause");
    return 0;
}