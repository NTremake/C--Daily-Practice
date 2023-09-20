#include <iostream>
#include <cstring>
using namespace std;

class MyException {
public:
    MyException() {
        this->_error = nullptr;
    };
    MyException(const char* str) {
        this->_error = new char[strlen(str) + 1];
        strcpy(this->_error, str);
    }
    void Catch01() {
        cout << this->_error << endl;
    }
    ~MyException() {
        if(this->_error != nullptr) {
            delete[] this->_error;
            this->_error = nullptr;
        }
    }
public:
    char *_error;
};
void func1() {
    throw 1;//�׳�int�����쳣
}
void func2() {
    throw "char*";//�׳�char*�쳣
}
void func3() {
    throw MyException("�����쳣");//�Զ����쳣��
}
int main() {
    try {
        func1();
        func2();
        func3();
    }
    catch(int i) {
        cout << "int�����쳣:" << i << endl;
    }
    try {
        func2();
    }
    catch(const char* a) {
        cout << "char*�����쳣:" << a << endl;
    }
    try {
        func3();
    }//���Ҳ�ܽ��double free
    catch(MyException& e) {
        e.Catch01();
    }
    system("pause");
    return 0;
}