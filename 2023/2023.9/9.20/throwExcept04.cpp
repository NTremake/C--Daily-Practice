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
    throw 1;//抛出int类型异常
}
void func2() {
    throw "char*";//抛出char*异常
}
void func3() {
    throw MyException("其他异常");//自定义异常类
}
int main() {
    try {
        func1();
        func2();
        func3();
    }
    catch(int i) {
        cout << "int类型异常:" << i << endl;
    }
    try {
        func2();
    }
    catch(const char* a) {
        cout << "char*类型异常:" << a << endl;
    }
    try {
        func3();
    }//深拷贝也能解决double free
    catch(MyException& e) {
        e.Catch01();
    }
    system("pause");
    return 0;
}