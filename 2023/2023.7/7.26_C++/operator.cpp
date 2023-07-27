#include <iostream>
using namespace std;

//返回值必须是void*，参数必须size_t
void* operator new(size_t size) {
    cout << "new的重载：" << size << "字节。" << endl;
    void* ptr = malloc(size);
    cout << "申请到的内存地址为：" << ptr << endl;
    return ptr;
}
//参数必须void*
void operator delete(void* ptr) {
    cout << "delete的重载。\n";
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
        cout << "Girl的构造函数。" << endl;
    }
    ~Girl() {
        cout << "Girl的析构函数。" << endl;
    }
};
//使用c语言的malloc和free重载new和delete
int main() {
    // int* p = new int(10);
    // cout << "内存地址：" << (void *)p << endl;
    // cout << "值：" << *p << endl;
    // delete p;
    Girl* p1 = new Girl("小红", 18);
    cout << "内存地址：" << (void *)p1 << endl;
    cout << "姓名：" << p1->name << "年龄："<< p1->age << endl;
    delete p1;
    system("pause");
    return 0;
}