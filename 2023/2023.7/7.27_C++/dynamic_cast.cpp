#include <iostream>
using namespace std;

class Father {
public:
    virtual void print() = 0;
};
class Son1 : public Father {
public:
    void print() {
        cout << "Son1的print函数。" << endl;
    }
    void show() {
        cout << "Son1的dynamic_cast测试函数" << endl;
    }
};
class Son2 : public Father {
public:
    void print() {
        cout << "Son2的print函数。" << endl;
    }
    void show() {
        cout << "Son2的强转测试函数" << endl;
    }
};//dynamic_cast只能用于多态类型，即有虚函数的类
int main() {
    cout << "请输入一个数字：" << endl;
    int num;
    cin >> num;
    Father *p1 = nullptr;
    switch(num) {
        case 1: {
            p1 = new Son1;
            p1->print();
            Son1 *p2 = dynamic_cast<Son1 *>(p1);
            p2->show();//dynamic_cast的用法
            delete p2;
            break;
        }
        case 2: {
            p1 = new Son2();
            p1->print();
            Son2 *p2 = (Son2 *)p1;//c风格的强转
            p2->show();
            delete p2;
            break;
        }
    }
    delete p1;
    system("pause");
    return 0;
}