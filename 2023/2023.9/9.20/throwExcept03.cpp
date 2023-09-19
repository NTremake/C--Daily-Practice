#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person() :_Name("佚名"){};
    Person(string name) :_Name(name){};
    ~Person() {
        cout << "析构函数" << this->_Name << endl;
    }
    string _Name;
};
int main() {
    int a = 0;
    cout << "请输入：" << endl;
    cin >> a;
    try {
        Person p1("张三");//异常后会析构try里面的对象
        if(a == 1) {
            throw string("异常处理");
        }

    }
    catch (string& b) {
        cout << b << endl;
    }
    system("pause");
    return 0;
}