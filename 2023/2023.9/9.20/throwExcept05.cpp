#include <iostream>
using namespace std;

class MyException {
public:
    MyException() {
        cout << "构造函数" << endl;
    }
    MyException(const MyException& e) {
        cout << "拷贝构造函数" << endl;
    }
    ~MyException() {
        cout << "析构函数" << endl;
    }
};//异常类的生命周期，指针的情况比较特殊
int main() {
    try {
        throw new MyException();
    }
    catch(MyException* e) {
        cout << "异常捕获" << endl;
        delete e;
        e = nullptr;
    }
    system("pause");
    return 0;
}